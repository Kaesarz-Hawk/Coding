/**
 * KAESARZ: CSE WARS — Physics Engine
 * Custom rigid body physics with semi-implicit Euler integration.
 * No third-party libraries.
 */

import { Vec2 } from '../utils/vec2.js';

let _nextBodyId = 0;

/** Shape types */
export const ShapeType = {
    CIRCLE: 'circle',
    POLYGON: 'polygon'
};

/** Create a circle shape */
export function createCircleShape(radius) {
    return { type: ShapeType.CIRCLE, radius };
}

/** Create a box polygon shape (centered) */
export function createBoxShape(width, height) {
    const hw = width / 2, hh = height / 2;
    return {
        type: ShapeType.POLYGON,
        vertices: [
            { x: -hw, y: -hh }, { x: hw, y: -hh },
            { x: hw, y: hh }, { x: -hw, y: hh }
        ],
        width, height
    };
}

/** Create a polygon shape from vertices (centered) */
export function createPolygonShape(vertices) {
    return { type: ShapeType.POLYGON, vertices: vertices.map(v => Vec2.clone(v)) };
}

/** Compute moment of inertia for a shape */
function computeInertia(shape, mass) {
    if (shape.type === ShapeType.CIRCLE) {
        return 0.5 * mass * shape.radius * shape.radius;
    }
    // Polygon: use shoelace-based formula
    const verts = shape.vertices;
    let numerator = 0, denominator = 0;
    for (let i = 0; i < verts.length; i++) {
        const a = verts[i];
        const b = verts[(i + 1) % verts.length];
        const cross = Math.abs(Vec2.cross(a, b));
        numerator += cross * (Vec2.dot(a, a) + Vec2.dot(a, b) + Vec2.dot(b, b));
        denominator += cross;
    }
    return (mass * numerator) / (6 * denominator) || mass * 10;
}

/** Compute AABB for a shape at given position and angle */
function computeAABB(shape, position, angle) {
    const aabb = { minX: Infinity, minY: Infinity, maxX: -Infinity, maxY: -Infinity };
    if (shape.type === ShapeType.CIRCLE) {
        aabb.minX = position.x - shape.radius;
        aabb.minY = position.y - shape.radius;
        aabb.maxX = position.x + shape.radius;
        aabb.maxY = position.y + shape.radius;
    } else {
        const cos = Math.cos(angle), sin = Math.sin(angle);
        for (const v of shape.vertices) {
            const wx = position.x + v.x * cos - v.y * sin;
            const wy = position.y + v.x * sin + v.y * cos;
            if (wx < aabb.minX) aabb.minX = wx;
            if (wy < aabb.minY) aabb.minY = wy;
            if (wx > aabb.maxX) aabb.maxX = wx;
            if (wy > aabb.maxY) aabb.maxY = wy;
        }
    }
    return aabb;
}

/** Get world-space vertices for a polygon body */
export function getWorldVertices(body) {
    if (body.shape.type !== ShapeType.POLYGON) return [];
    const cos = Math.cos(body.angle), sin = Math.sin(body.angle);
    return body.shape.vertices.map(v => ({
        x: body.position.x + v.x * cos - v.y * sin,
        y: body.position.y + v.x * sin + v.y * cos
    }));
}

/** Rigid body class */
export class Body {
    constructor(options = {}) {
        this.id = _nextBodyId++;
        this.position = Vec2.clone(options.position || { x: 0, y: 0 });
        this.prevPosition = Vec2.clone(this.position);
        this.velocity = Vec2.clone(options.velocity || { x: 0, y: 0 });
        this.acceleration = Vec2.create();
        this.force = Vec2.create();

        this.angle = options.angle || 0;
        this.prevAngle = this.angle;
        this.angularVelocity = options.angularVelocity || 0;
        this.torque = 0;

        this.mass = options.mass || 1;
        this.inverseMass = options.isStatic ? 0 : 1 / this.mass;
        this.inertia = 0;
        this.inverseInertia = 0;

        this.restitution = options.restitution !== undefined ? options.restitution : 0.2;
        this.staticFriction = options.staticFriction !== undefined ? options.staticFriction : 0.6;
        this.dynamicFriction = options.dynamicFriction !== undefined ? options.dynamicFriction : 0.4;

        this.isStatic = options.isStatic || false;
        this.isSleeping = false;
        this.isSensor = options.isSensor || false;
        this.sleepTimer = 0;

        this.shape = options.shape || createCircleShape(10);
        this.aabb = { minX: 0, minY: 0, maxX: 0, maxY: 0 };

        this.userData = options.userData || {};
        this.collisionGroup = options.collisionGroup || 0;
        this.collisionMask = options.collisionMask !== undefined ? options.collisionMask : 0xFFFF;

        this.damping = options.damping !== undefined ? options.damping : 0.01;
        this.angularDamping = options.angularDamping !== undefined ? options.angularDamping : 0.01;

        this.gravityScale = options.gravityScale !== undefined ? options.gravityScale : 1;

        if (!this.isStatic) {
            this.inertia = computeInertia(this.shape, this.mass);
            this.inverseInertia = 1 / this.inertia;
        }
        this.updateAABB();
    }

    updateAABB() {
        const a = computeAABB(this.shape, this.position, this.angle);
        this.aabb.minX = a.minX;
        this.aabb.minY = a.minY;
        this.aabb.maxX = a.maxX;
        this.aabb.maxY = a.maxY;
    }

    applyForce(fx, fy) {
        this.force.x += fx;
        this.force.y += fy;
    }

    applyImpulse(ix, iy, contactX, contactY) {
        if (this.isStatic) return;
        this.velocity.x += ix * this.inverseMass;
        this.velocity.y += iy * this.inverseMass;
        if (contactX !== undefined) {
            const rx = contactX - this.position.x;
            const ry = contactY - this.position.y;
            this.angularVelocity += (rx * iy - ry * ix) * this.inverseInertia;
        }
    }

    setStatic(isStatic) {
        this.isStatic = isStatic;
        if (isStatic) {
            this.inverseMass = 0;
            this.inverseInertia = 0;
            this.velocity.x = 0;
            this.velocity.y = 0;
            this.angularVelocity = 0;
        } else {
            this.inverseMass = 1 / this.mass;
            this.inertia = computeInertia(this.shape, this.mass);
            this.inverseInertia = 1 / this.inertia;
        }
    }

    wake() {
        this.isSleeping = false;
        this.sleepTimer = 0;
    }

    getSpeed() {
        return Vec2.len(this.velocity);
    }

    getKineticEnergy() {
        const v2 = Vec2.lenSq(this.velocity);
        return 0.5 * this.mass * v2 + 0.5 * this.inertia * this.angularVelocity * this.angularVelocity;
    }
}

/** Contact/collision info */
export class Contact {
    constructor() {
        this.bodyA = null;
        this.bodyB = null;
        this.normal = Vec2.create();
        this.depth = 0;
        this.contactPoint = Vec2.create();
        this.contactPoint2 = null;
        this.impulse = 0;
    }
}

const SLEEP_VELOCITY_THRESHOLD = 3;
const SLEEP_TIME_THRESHOLD = 0.5;
const BAUMGARTE_FACTOR = 0.2;
const SLOP = 0.5;
const VELOCITY_ITERATIONS = 8;

/** Main physics world */
export class PhysicsWorld {
    constructor(options = {}) {
        this.gravity = Vec2.clone(options.gravity || { x: 0, y: 980 });
        this.bodies = [];
        this.contacts = [];
        this._contactPool = [];
        for (let i = 0; i < 200; i++) this._contactPool.push(new Contact());
        this._spatialHash = new SpatialHash(100);
        this.onCollision = null;
        this.worldBounds = options.worldBounds || null;
    }

    _getContact() {
        return this._contactPool.length > 0 ? this._contactPool.pop() : new Contact();
    }

    _returnContact(c) {
        this._contactPool.push(c);
    }

    addBody(body) {
        this.bodies.push(body);
        return body;
    }

    removeBody(body) {
        const idx = this.bodies.indexOf(body);
        if (idx !== -1) this.bodies.splice(idx, 1);
    }

    clear() {
        for (const c of this.contacts) this._returnContact(c);
        this.contacts.length = 0;
        this.bodies.length = 0;
    }

    step(dt) {
        const substeps = 4;
        const subDt = dt / substeps;
        for (let s = 0; s < substeps; s++) {
            this._integrate(subDt);
            this._broadPhase();
            this._narrowPhase();
            this._resolveCollisions(subDt);
            this._updateSleeping(subDt);
        }
    }

    _integrate(dt) {
        for (const body of this.bodies) {
            if (body.isStatic || body.isSleeping) continue;

            body.prevPosition.x = body.position.x;
            body.prevPosition.y = body.position.y;
            body.prevAngle = body.angle;

            // Apply gravity
            body.velocity.x += (this.gravity.x * body.gravityScale + body.force.x * body.inverseMass) * dt;
            body.velocity.y += (this.gravity.y * body.gravityScale + body.force.y * body.inverseMass) * dt;
            body.angularVelocity += body.torque * body.inverseInertia * dt;

            // Damping
            body.velocity.x *= (1 - body.damping);
            body.velocity.y *= (1 - body.damping);
            body.angularVelocity *= (1 - body.angularDamping);

            // Integrate position
            body.position.x += body.velocity.x * dt;
            body.position.y += body.velocity.y * dt;
            body.angle += body.angularVelocity * dt;

            // Clear forces
            body.force.x = 0;
            body.force.y = 0;
            body.torque = 0;

            body.updateAABB();

            // World bounds
            if (this.worldBounds) {
                const b = this.worldBounds;
                if (body.position.y > b.maxY) {
                    body.position.y = b.maxY;
                    body.velocity.y *= -body.restitution;
                }
                if (body.position.x < b.minX) {
                    body.position.x = b.minX;
                    body.velocity.x *= -body.restitution;
                }
                if (body.position.x > b.maxX) {
                    body.position.x = b.maxX;
                    body.velocity.x *= -body.restitution;
                }
            }
        }
    }

    _broadPhase() {
        for (const c of this.contacts) this._returnContact(c);
        this.contacts.length = 0;

        this._spatialHash.clear();
        for (const b of this.bodies) {
            this._spatialHash.insert(b);
        }
        this._pairs = this._spatialHash.getPairs();
    }

    _narrowPhase() {
        for (const [a, b] of this._pairs) {
            if (a.isStatic && b.isStatic) continue;
            if (a.isSleeping && b.isSleeping) continue;

            const contact = detectCollision(a, b);
            if (contact) {
                contact.bodyA = a;
                contact.bodyB = b;
                this.contacts.push(contact);

                if (a.isSleeping) a.wake();
                if (b.isSleeping) b.wake();

                if (this.onCollision) {
                    this.onCollision(contact);
                }
            }
        }
    }

    _resolveCollisions(dt) {
        for (let iter = 0; iter < VELOCITY_ITERATIONS; iter++) {
            for (const contact of this.contacts) {
                if (contact.bodyA.isSensor || contact.bodyB.isSensor) continue;
                resolveContact(contact, dt);
            }
        }
    }

    _updateSleeping(dt) {
        for (const body of this.bodies) {
            if (body.isStatic) continue;
            const speed = body.getSpeed() + Math.abs(body.angularVelocity) * 10;
            if (speed < SLEEP_VELOCITY_THRESHOLD) {
                body.sleepTimer += dt;
                if (body.sleepTimer > SLEEP_TIME_THRESHOLD) {
                    body.isSleeping = true;
                    body.velocity.x = 0;
                    body.velocity.y = 0;
                    body.angularVelocity = 0;
                }
            } else {
                body.sleepTimer = 0;
                body.isSleeping = false;
            }
        }
    }

    /** Get interpolated position for rendering */
    getInterpolatedPosition(body, alpha) {
        return {
            x: body.prevPosition.x + (body.position.x - body.prevPosition.x) * alpha,
            y: body.prevPosition.y + (body.position.y - body.prevPosition.y) * alpha
        };
    }

    getInterpolatedAngle(body, alpha) {
        return body.prevAngle + (body.angle - body.prevAngle) * alpha;
    }

    /** Raycast against all bodies. Returns closest hit. */
    raycast(origin, direction, maxDist = 2000) {
        let closest = null;
        let closestDist = maxDist;

        for (const body of this.bodies) {
            const hit = raycastBody(origin, direction, body, closestDist);
            if (hit && hit.distance < closestDist) {
                closestDist = hit.distance;
                closest = { body, ...hit };
            }
        }
        return closest;
    }
}

/** Spatial hash for broad-phase collision */
class SpatialHash {
    constructor(cellSize) {
        this.cellSize = cellSize;
        this.cells = new Map();
        this._pairSet = new Set();
    }

    _key(x, y) {
        return `${x},${y}`;
    }

    clear() {
        this.cells.clear();
        this._pairSet.clear();
    }

    insert(body) {
        const cs = this.cellSize;
        const x0 = Math.floor(body.aabb.minX / cs);
        const y0 = Math.floor(body.aabb.minY / cs);
        const x1 = Math.floor(body.aabb.maxX / cs);
        const y1 = Math.floor(body.aabb.maxY / cs);

        for (let x = x0; x <= x1; x++) {
            for (let y = y0; y <= y1; y++) {
                const key = this._key(x, y);
                let cell = this.cells.get(key);
                if (!cell) {
                    cell = [];
                    this.cells.set(key, cell);
                }
                cell.push(body);
            }
        }
    }

    getPairs() {
        const pairs = [];
        this._pairSet.clear();

        for (const cell of this.cells.values()) {
            for (let i = 0; i < cell.length; i++) {
                for (let j = i + 1; j < cell.length; j++) {
                    const a = cell[i], b = cell[j];
                    const pairId = a.id < b.id ? `${a.id}:${b.id}` : `${b.id}:${a.id}`;
                    if (!this._pairSet.has(pairId)) {
                        this._pairSet.add(pairId);
                        // AABB overlap check
                        if (a.aabb.maxX > b.aabb.minX && a.aabb.minX < b.aabb.maxX &&
                            a.aabb.maxY > b.aabb.minY && a.aabb.minY < b.aabb.maxY) {
                            pairs.push([a, b]);
                        }
                    }
                }
            }
        }
        return pairs;
    }
}

/** Detect collision between two bodies */
function detectCollision(a, b) {
    const sa = a.shape, sb = b.shape;
    if (sa.type === ShapeType.CIRCLE && sb.type === ShapeType.CIRCLE) {
        return circleVsCircle(a, b);
    }
    if (sa.type === ShapeType.CIRCLE && sb.type === ShapeType.POLYGON) {
        const c = circleVsPolygon(a, b);
        return c;
    }
    if (sa.type === ShapeType.POLYGON && sb.type === ShapeType.CIRCLE) {
        const c = circleVsPolygon(b, a);
        if (c) {
            // Swap bodies and flip normal
            const tmp = c.bodyA;
            c.bodyA = c.bodyB;
            c.bodyB = tmp;
            c.normal.x = -c.normal.x;
            c.normal.y = -c.normal.y;
        }
        return c;
    }
    if (sa.type === ShapeType.POLYGON && sb.type === ShapeType.POLYGON) {
        return polygonVsPolygon(a, b);
    }
    return null;
}

/** Circle vs Circle collision */
function circleVsCircle(a, b) {
    const dx = b.position.x - a.position.x;
    const dy = b.position.y - a.position.y;
    const distSq = dx * dx + dy * dy;
    const radiusSum = a.shape.radius + b.shape.radius;

    if (distSq >= radiusSum * radiusSum) return null;

    const dist = Math.sqrt(distSq);
    const contact = new Contact();
    contact.bodyA = a;
    contact.bodyB = b;

    if (dist > 0.0001) {
        contact.normal.x = dx / dist;
        contact.normal.y = dy / dist;
    } else {
        contact.normal.x = 0;
        contact.normal.y = 1;
    }

    contact.depth = radiusSum - dist;
    contact.contactPoint.x = a.position.x + contact.normal.x * a.shape.radius;
    contact.contactPoint.y = a.position.y + contact.normal.y * a.shape.radius;

    return contact;
}

/** Circle vs Polygon collision using SAT */
function circleVsPolygon(circle, polygon) {
    const verts = getWorldVertices(polygon);
    const center = circle.position;
    const radius = circle.shape.radius;

    let minOverlap = Infinity;
    let bestNormal = { x: 0, y: 0 };
    let closestVertex = null;
    let minVertDist = Infinity;

    // Find closest vertex to circle center
    for (const v of verts) {
        const dx = center.x - v.x;
        const dy = center.y - v.y;
        const d = dx * dx + dy * dy;
        if (d < minVertDist) {
            minVertDist = d;
            closestVertex = v;
        }
    }

    // Test edge normals
    for (let i = 0; i < verts.length; i++) {
        const v1 = verts[i];
        const v2 = verts[(i + 1) % verts.length];
        const edgeX = v2.x - v1.x;
        const edgeY = v2.y - v1.y;
        const len = Math.sqrt(edgeX * edgeX + edgeY * edgeY);
        if (len < 0.0001) continue;
        const nx = -edgeY / len;
        const ny = edgeX / len;

        let minA = Infinity, maxA = -Infinity;
        for (const v of verts) {
            const p = v.x * nx + v.y * ny;
            if (p < minA) minA = p;
            if (p > maxA) maxA = p;
        }
        const circleProj = center.x * nx + center.y * ny;
        const minB = circleProj - radius;
        const maxB = circleProj + radius;

        if (maxA < minB || maxB < minA) return null;

        const overlap = Math.min(maxA - minB, maxB - minA);
        if (overlap < minOverlap) {
            minOverlap = overlap;
            bestNormal.x = nx;
            bestNormal.y = ny;
        }
    }

    // Test axis from closest vertex to circle center
    if (closestVertex) {
        let ax = center.x - closestVertex.x;
        let ay = center.y - closestVertex.y;
        const al = Math.sqrt(ax * ax + ay * ay);
        if (al > 0.0001) {
            ax /= al; ay /= al;
            let minA = Infinity, maxA = -Infinity;
            for (const v of verts) {
                const p = v.x * ax + v.y * ay;
                if (p < minA) minA = p;
                if (p > maxA) maxA = p;
            }
            const circleProj = center.x * ax + center.y * ay;
            const minB = circleProj - radius;
            const maxB = circleProj + radius;

            if (maxA < minB || maxB < minA) return null;

            const overlap = Math.min(maxA - minB, maxB - minA);
            if (overlap < minOverlap) {
                minOverlap = overlap;
                bestNormal.x = ax;
                bestNormal.y = ay;
            }
        }
    }

    // Ensure normal points from polygon to circle
    const dirX = center.x - polygon.position.x;
    const dirY = center.y - polygon.position.y;
    if (bestNormal.x * dirX + bestNormal.y * dirY < 0) {
        bestNormal.x = -bestNormal.x;
        bestNormal.y = -bestNormal.y;
    }

    const contact = new Contact();
    contact.bodyA = circle;
    contact.bodyB = polygon;
    contact.normal.x = bestNormal.x;
    contact.normal.y = bestNormal.y;
    contact.depth = minOverlap;
    contact.contactPoint.x = center.x - bestNormal.x * radius;
    contact.contactPoint.y = center.y - bestNormal.y * radius;

    return contact;
}

/** Polygon vs Polygon collision using SAT */
function polygonVsPolygon(a, b) {
    const vertsA = getWorldVertices(a);
    const vertsB = getWorldVertices(b);

    let minOverlap = Infinity;
    let bestNormal = { x: 0, y: 0 };

    // Test normals from polygon A
    for (let i = 0; i < vertsA.length; i++) {
        const v1 = vertsA[i];
        const v2 = vertsA[(i + 1) % vertsA.length];
        const edgeX = v2.x - v1.x;
        const edgeY = v2.y - v1.y;
        const len = Math.sqrt(edgeX * edgeX + edgeY * edgeY);
        if (len < 0.0001) continue;
        const nx = -edgeY / len;
        const ny = edgeX / len;

        const projA = projectVertices(vertsA, nx, ny);
        const projB = projectVertices(vertsB, nx, ny);

        if (projA.max < projB.min || projB.max < projA.min) return null;

        const overlap = Math.min(projA.max - projB.min, projB.max - projA.min);
        if (overlap < minOverlap) {
            minOverlap = overlap;
            bestNormal.x = nx;
            bestNormal.y = ny;
        }
    }

    // Test normals from polygon B
    for (let i = 0; i < vertsB.length; i++) {
        const v1 = vertsB[i];
        const v2 = vertsB[(i + 1) % vertsB.length];
        const edgeX = v2.x - v1.x;
        const edgeY = v2.y - v1.y;
        const len = Math.sqrt(edgeX * edgeX + edgeY * edgeY);
        if (len < 0.0001) continue;
        const nx = -edgeY / len;
        const ny = edgeX / len;

        const projA = projectVertices(vertsA, nx, ny);
        const projB = projectVertices(vertsB, nx, ny);

        if (projA.max < projB.min || projB.max < projA.min) return null;

        const overlap = Math.min(projA.max - projB.min, projB.max - projA.min);
        if (overlap < minOverlap) {
            minOverlap = overlap;
            bestNormal.x = nx;
            bestNormal.y = ny;
        }
    }

    // Ensure normal points from A to B
    const dirX = b.position.x - a.position.x;
    const dirY = b.position.y - a.position.y;
    if (bestNormal.x * dirX + bestNormal.y * dirY < 0) {
        bestNormal.x = -bestNormal.x;
        bestNormal.y = -bestNormal.y;
    }

    const contact = new Contact();
    contact.bodyA = a;
    contact.bodyB = b;
    contact.normal.x = bestNormal.x;
    contact.normal.y = bestNormal.y;
    contact.depth = minOverlap;

    // Find contact point (deepest penetrating vertex)
    let deepest = -Infinity;
    for (const v of vertsB) {
        const d = v.x * bestNormal.x + v.y * bestNormal.y;
        if (-d > -deepest) ; // project onto normal
    }
    // Use average of penetrating vertices from B into A
    let cx = 0, cy = 0, count = 0;
    for (const v of vertsB) {
        // Check if vertex is inside A (simple containment)
        if (pointInPolygon(v, vertsA)) {
            cx += v.x; cy += v.y; count++;
        }
    }
    for (const v of vertsA) {
        if (pointInPolygon(v, vertsB)) {
            cx += v.x; cy += v.y; count++;
        }
    }
    if (count > 0) {
        contact.contactPoint.x = cx / count;
        contact.contactPoint.y = cy / count;
    } else {
        contact.contactPoint.x = (a.position.x + b.position.x) / 2;
        contact.contactPoint.y = (a.position.y + b.position.y) / 2;
    }

    return contact;
}

/** Project vertices onto an axis */
function projectVertices(vertices, nx, ny) {
    let min = Infinity, max = -Infinity;
    for (const v of vertices) {
        const p = v.x * nx + v.y * ny;
        if (p < min) min = p;
        if (p > max) max = p;
    }
    return { min, max };
}

/** Point in polygon test (crossing number) */
function pointInPolygon(point, vertices) {
    let inside = false;
    const n = vertices.length;
    for (let i = 0, j = n - 1; i < n; j = i++) {
        const vi = vertices[i], vj = vertices[j];
        if ((vi.y > point.y) !== (vj.y > point.y) &&
            point.x < (vj.x - vi.x) * (point.y - vi.y) / (vj.y - vi.y) + vi.x) {
            inside = !inside;
        }
    }
    return inside;
}

/** Resolve a collision contact with impulse */
function resolveContact(contact, dt) {
    const a = contact.bodyA;
    const b = contact.bodyB;
    const normal = contact.normal;

    // Position correction (Baumgarte stabilization)
    if (contact.depth > SLOP) {
        const correction = (contact.depth - SLOP) * BAUMGARTE_FACTOR / (a.inverseMass + b.inverseMass);
        if (!a.isStatic) {
            a.position.x -= normal.x * correction * a.inverseMass;
            a.position.y -= normal.y * correction * a.inverseMass;
        }
        if (!b.isStatic) {
            b.position.x += normal.x * correction * b.inverseMass;
            b.position.y += normal.y * correction * b.inverseMass;
        }
    }

    // Relative velocity at contact point
    const rax = contact.contactPoint.x - a.position.x;
    const ray = contact.contactPoint.y - a.position.y;
    const rbx = contact.contactPoint.x - b.position.x;
    const rby = contact.contactPoint.y - b.position.y;

    const velAx = a.velocity.x + (-a.angularVelocity * ray);
    const velAy = a.velocity.y + (a.angularVelocity * rax);
    const velBx = b.velocity.x + (-b.angularVelocity * rby);
    const velBy = b.velocity.y + (b.angularVelocity * rbx);

    const relVelX = velBx - velAx;
    const relVelY = velBy - velAy;

    const relVelNormal = relVelX * normal.x + relVelY * normal.y;

    // Don't resolve if separating
    if (relVelNormal > 0) return;

    // Restitution
    const e = Math.min(a.restitution, b.restitution);

    // Impulse denominator
    const raCrossN = rax * normal.y - ray * normal.x;
    const rbCrossN = rbx * normal.y - rby * normal.x;
    const invMassSum = a.inverseMass + b.inverseMass +
        raCrossN * raCrossN * a.inverseInertia +
        rbCrossN * rbCrossN * b.inverseInertia;

    // Normal impulse
    const j = -(1 + e) * relVelNormal / invMassSum;
    contact.impulse = Math.abs(j);

    const impulseX = normal.x * j;
    const impulseY = normal.y * j;

    if (!a.isStatic) {
        a.velocity.x -= impulseX * a.inverseMass;
        a.velocity.y -= impulseY * a.inverseMass;
        a.angularVelocity -= (rax * impulseY - ray * impulseX) * a.inverseInertia;
    }
    if (!b.isStatic) {
        b.velocity.x += impulseX * b.inverseMass;
        b.velocity.y += impulseY * b.inverseMass;
        b.angularVelocity += (rbx * impulseY - rby * impulseX) * b.inverseInertia;
    }

    // Friction impulse
    let tangentX = relVelX - relVelNormal * normal.x;
    let tangentY = relVelY - relVelNormal * normal.y;
    const tangentLen = Math.sqrt(tangentX * tangentX + tangentY * tangentY);
    if (tangentLen > 0.0001) {
        tangentX /= tangentLen;
        tangentY /= tangentLen;
    }

    const frictionCoeff = Math.sqrt(
        a.dynamicFriction * a.dynamicFriction +
        b.dynamicFriction * b.dynamicFriction
    ) * 0.5 + Math.sqrt(
        a.staticFriction * a.staticFriction +
        b.staticFriction * b.staticFriction
    ) * 0.5;

    const raCrossT = rax * tangentY - ray * tangentX;
    const rbCrossT = rbx * tangentY - rby * tangentX;
    const invMassSumT = a.inverseMass + b.inverseMass +
        raCrossT * raCrossT * a.inverseInertia +
        rbCrossT * rbCrossT * b.inverseInertia;

    let jt = -(relVelX * tangentX + relVelY * tangentY) / invMassSumT;

    // Coulomb's law
    if (Math.abs(jt) > Math.abs(j) * frictionCoeff) {
        jt = j > 0 ? -Math.abs(j) * frictionCoeff : Math.abs(j) * frictionCoeff;
    }

    const frictionImpX = tangentX * jt;
    const frictionImpY = tangentY * jt;

    if (!a.isStatic) {
        a.velocity.x -= frictionImpX * a.inverseMass;
        a.velocity.y -= frictionImpY * a.inverseMass;
        a.angularVelocity -= (rax * frictionImpY - ray * frictionImpX) * a.inverseInertia;
    }
    if (!b.isStatic) {
        b.velocity.x += frictionImpX * b.inverseMass;
        b.velocity.y += frictionImpY * b.inverseMass;
        b.angularVelocity += (rbx * frictionImpY - rby * frictionImpX) * b.inverseInertia;
    }
}

/** Simple raycast against a single body */
function raycastBody(origin, direction, body, maxDist) {
    if (body.shape.type === ShapeType.CIRCLE) {
        const dx = body.position.x - origin.x;
        const dy = body.position.y - origin.y;
        const tca = dx * direction.x + dy * direction.y;
        if (tca < 0) return null;
        const d2 = dx * dx + dy * dy - tca * tca;
        const r2 = body.shape.radius * body.shape.radius;
        if (d2 > r2) return null;
        const thc = Math.sqrt(r2 - d2);
        const t = tca - thc;
        if (t < 0 || t > maxDist) return null;
        return {
            distance: t,
            point: { x: origin.x + direction.x * t, y: origin.y + direction.y * t },
            normal: { x: 0, y: -1 }
        };
    }
    return null;
}

export { detectCollision };
