/**
 * KAESARZ: CSE WARS — Vec2 Module
 * Zero-allocation 2D vector math using plain {x, y} objects.
 * All mutation operations take an 'out' parameter to avoid GC pressure.
 */

// Pre-allocated temporary vectors for intermediate calculations
const _tmp = [
    { x: 0, y: 0 }, { x: 0, y: 0 }, { x: 0, y: 0 }, { x: 0, y: 0 },
    { x: 0, y: 0 }, { x: 0, y: 0 }, { x: 0, y: 0 }, { x: 0, y: 0 }
];
let _tmpIdx = 0;

export const Vec2 = {
    /** Get a temporary vector (cycles through pool of 8) */
    tmp() {
        const t = _tmp[_tmpIdx];
        _tmpIdx = (_tmpIdx + 1) & 7;
        t.x = 0; t.y = 0;
        return t;
    },

    /** Create a new vector */
    create(x = 0, y = 0) {
        return { x, y };
    },

    /** Set vector components */
    set(out, x, y) {
        out.x = x;
        out.y = y;
        return out;
    },

    /** Copy vector a into out */
    copy(out, a) {
        out.x = a.x;
        out.y = a.y;
        return out;
    },

    /** Clone vector a */
    clone(a) {
        return { x: a.x, y: a.y };
    },

    /** out = a + b */
    add(out, a, b) {
        out.x = a.x + b.x;
        out.y = a.y + b.y;
        return out;
    },

    /** out = a - b */
    sub(out, a, b) {
        out.x = a.x - b.x;
        out.y = a.y - b.y;
        return out;
    },

    /** out = a * scalar */
    scale(out, a, s) {
        out.x = a.x * s;
        out.y = a.y * s;
        return out;
    },

    /** out = a + b * scalar (scale-add, very common in physics) */
    scaleAdd(out, a, b, s) {
        out.x = a.x + b.x * s;
        out.y = a.y + b.y * s;
        return out;
    },

    /** Component-wise multiply: out = a * b */
    mul(out, a, b) {
        out.x = a.x * b.x;
        out.y = a.y * b.y;
        return out;
    },

    /** Dot product: a · b */
    dot(a, b) {
        return a.x * b.x + a.y * b.y;
    },

    /** 2D cross product (scalar): a × b */
    cross(a, b) {
        return a.x * b.y - a.y * b.x;
    },

    /** Cross product with scalar: out = scalar × a (rotate 90°) */
    crossScalarVec(out, s, a) {
        out.x = -s * a.y;
        out.y = s * a.x;
        return out;
    },

    /** Cross product vec × scalar */
    crossVecScalar(out, a, s) {
        out.x = s * a.y;
        out.y = -s * a.x;
        return out;
    },

    /** Length of vector */
    len(a) {
        return Math.sqrt(a.x * a.x + a.y * a.y);
    },

    /** Squared length (avoids sqrt) */
    lenSq(a) {
        return a.x * a.x + a.y * a.y;
    },

    /** Distance between two points */
    dist(a, b) {
        const dx = a.x - b.x;
        const dy = a.y - b.y;
        return Math.sqrt(dx * dx + dy * dy);
    },

    /** Squared distance (avoids sqrt) */
    distSq(a, b) {
        const dx = a.x - b.x;
        const dy = a.y - b.y;
        return dx * dx + dy * dy;
    },

    /** Normalize vector (unit length) */
    normalize(out, a) {
        const len = Math.sqrt(a.x * a.x + a.y * a.y);
        if (len > 1e-10) {
            const inv = 1.0 / len;
            out.x = a.x * inv;
            out.y = a.y * inv;
        } else {
            out.x = 0;
            out.y = 0;
        }
        return out;
    },

    /** Negate vector */
    negate(out, a) {
        out.x = -a.x;
        out.y = -a.y;
        return out;
    },

    /** Perpendicular vector (90° counter-clockwise) */
    perp(out, a) {
        out.x = -a.y;
        out.y = a.x;
        return out;
    },

    /** Perpendicular vector (90° clockwise) */
    perpCW(out, a) {
        out.x = a.y;
        out.y = -a.x;
        return out;
    },

    /** Rotate vector by angle (radians) */
    rotate(out, a, angle) {
        const c = Math.cos(angle);
        const s = Math.sin(angle);
        out.x = a.x * c - a.y * s;
        out.y = a.x * s + a.y * c;
        return out;
    },

    /** Rotate vector around a center point */
    rotateAround(out, a, center, angle) {
        const c = Math.cos(angle);
        const s = Math.sin(angle);
        const dx = a.x - center.x;
        const dy = a.y - center.y;
        out.x = center.x + dx * c - dy * s;
        out.y = center.y + dx * s + dy * c;
        return out;
    },

    /** Linear interpolation: out = a + (b - a) * t */
    lerp(out, a, b, t) {
        out.x = a.x + (b.x - a.x) * t;
        out.y = a.y + (b.y - a.y) * t;
        return out;
    },

    /** Component-wise min */
    min(out, a, b) {
        out.x = Math.min(a.x, b.x);
        out.y = Math.min(a.y, b.y);
        return out;
    },

    /** Component-wise max */
    max(out, a, b) {
        out.x = Math.max(a.x, b.x);
        out.y = Math.max(a.y, b.y);
        return out;
    },

    /** Clamp vector length to maxLen */
    clampLen(out, a, maxLen) {
        const lsq = a.x * a.x + a.y * a.y;
        if (lsq > maxLen * maxLen) {
            const inv = maxLen / Math.sqrt(lsq);
            out.x = a.x * inv;
            out.y = a.y * inv;
        } else {
            out.x = a.x;
            out.y = a.y;
        }
        return out;
    },

    /** Create unit vector from angle */
    fromAngle(out, angle, length = 1) {
        out.x = Math.cos(angle) * length;
        out.y = Math.sin(angle) * length;
        return out;
    },

    /** Get angle of vector (atan2) */
    angle(a) {
        return Math.atan2(a.y, a.x);
    },

    /** Angle between two vectors */
    angleBetween(a, b) {
        return Math.atan2(
            a.x * b.y - a.y * b.x,
            a.x * b.x + a.y * b.y
        );
    },

    /** Reflect vector off a normal: out = a - 2 * dot(a, n) * n */
    reflect(out, a, normal) {
        const d = 2 * (a.x * normal.x + a.y * normal.y);
        out.x = a.x - d * normal.x;
        out.y = a.y - d * normal.y;
        return out;
    },

    /** Project a onto b: out = b * (dot(a,b) / dot(b,b)) */
    project(out, a, b) {
        const d = (a.x * b.x + a.y * b.y) / (b.x * b.x + b.y * b.y);
        out.x = b.x * d;
        out.y = b.y * d;
        return out;
    },

    /** Check if vectors are approximately equal */
    equals(a, b, epsilon = 1e-6) {
        return Math.abs(a.x - b.x) < epsilon && Math.abs(a.y - b.y) < epsilon;
    },

    /** Zero vector constant */
    ZERO: Object.freeze({ x: 0, y: 0 }),

    /** Unit X */
    UNIT_X: Object.freeze({ x: 1, y: 0 }),

    /** Unit Y */
    UNIT_Y: Object.freeze({ x: 0, y: 1 }),

    /** Gravity direction (down in screen space) */
    GRAVITY: Object.freeze({ x: 0, y: 1 })
};
