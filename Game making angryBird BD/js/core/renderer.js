/**
 * KAESARZ: CSE WARS — Renderer
 * Canvas 2D rendering with camera, shake, and interpolation.
 */

import { Vec2 } from '../utils/vec2.js';
import { MathUtils } from '../utils/math.js';
import { ShapeType, getWorldVertices } from './physics.js';

export class Renderer {
    constructor(canvas) {
        this.canvas = canvas;
        this.ctx = canvas.getContext('2d');
        this.width = 1280;
        this.height = 720;
        this.camera = { x: 0, y: 0, targetX: 0, zoom: 1 };
        this.shake = { x: 0, y: 0, intensity: 0, decay: 0.9 };
        this.slowMoVignette = 0;
        this._resize();
        this._boundResize = this._resize.bind(this);
        window.addEventListener('resize', this._boundResize);
    }

    _resize() {
        const dpr = window.devicePixelRatio || 1;
        const rect = this.canvas.getBoundingClientRect();
        this.canvas.width = this.width * dpr;
        this.canvas.height = this.height * dpr;
        this.ctx.setTransform(dpr, 0, 0, dpr, 0, 0);
        this.displayWidth = rect.width;
        this.displayHeight = rect.height;
    }

    destroy() {
        window.removeEventListener('resize', this._boundResize);
    }

    /** Start frame rendering */
    begin() {
        const ctx = this.ctx;
        ctx.save();
        ctx.clearRect(0, 0, this.width, this.height);
        // Apply camera
        if (this.shake.intensity > 0.5) {
            this.shake.x = (Math.random() - 0.5) * this.shake.intensity;
            this.shake.y = (Math.random() - 0.5) * this.shake.intensity;
            this.shake.intensity *= this.shake.decay;
        } else {
            this.shake.x = 0; this.shake.y = 0; this.shake.intensity = 0;
        }
        ctx.translate(-this.camera.x + this.shake.x, -this.camera.y + this.shake.y);
    }

    /** End frame rendering */
    end() {
        this.ctx.restore();
        // Vignette overlay for slow-mo
        if (this.slowMoVignette > 0.01) {
            const ctx = this.ctx;
            const grd = ctx.createRadialGradient(
                this.width / 2, this.height / 2, this.width * 0.3,
                this.width / 2, this.height / 2, this.width * 0.7
            );
            grd.addColorStop(0, 'rgba(0,0,0,0)');
            grd.addColorStop(1, `rgba(0,0,0,${this.slowMoVignette * 0.4})`);
            ctx.fillStyle = grd;
            ctx.fillRect(0, 0, this.width, this.height);
        }
    }

    /** Update camera to follow target */
    updateCamera(targetX, dt) {
        this.camera.targetX = Math.max(0, targetX - this.width * 0.3);
        this.camera.x = MathUtils.lerp(this.camera.x, this.camera.targetX, 1 - Math.exp(-4 * dt));
    }

    /** Trigger camera shake */
    addShake(intensity) {
        this.shake.intensity = Math.min(this.shake.intensity + intensity, 25);
    }

    /** Draw sky gradient */
    drawSky(colors) {
        const ctx = this.ctx;
        ctx.save();
        ctx.setTransform(1, 0, 0, 1, 0, 0);
        const grd = ctx.createLinearGradient(0, 0, 0, this.height);
        grd.addColorStop(0, colors.top);
        grd.addColorStop(1, colors.bottom);
        ctx.fillStyle = grd;
        ctx.fillRect(0, 0, this.width * 2, this.height);
        ctx.restore();
    }

    /** Draw a parallax layer */
    drawParallaxLayer(drawFn, scrollFactor) {
        const ctx = this.ctx;
        ctx.save();
        const offsetX = this.camera.x * (scrollFactor - 1);
        ctx.translate(offsetX, 0);
        drawFn(ctx, this.width, this.height);
        ctx.restore();
    }

    /** Draw ground plane */
    drawGround(groundY, color = '#4A7C2E', grassColor = '#5C9E31') {
        const ctx = this.ctx;
        // Grass
        ctx.fillStyle = grassColor;
        ctx.fillRect(this.camera.x - 50, groundY - 4, this.width + 100, 8);
        // Ground
        ctx.fillStyle = color;
        ctx.fillRect(this.camera.x - 50, groundY + 4, this.width + 100, 200);
        // Dirt texture
        ctx.fillStyle = '#3D6624';
        for (let x = this.camera.x - 50; x < this.camera.x + this.width + 50; x += 40) {
            ctx.fillRect(x, groundY + 20, 20, 3);
        }
    }

    /** Draw a physics body (debug/fallback) */
    drawBody(body, color = '#fff', alpha = 1) {
        const ctx = this.ctx;
        ctx.save();
        ctx.globalAlpha = alpha;
        ctx.translate(body.position.x, body.position.y);
        ctx.rotate(body.angle);

        if (body.shape.type === ShapeType.CIRCLE) {
            ctx.beginPath();
            ctx.arc(0, 0, body.shape.radius, 0, Math.PI * 2);
            ctx.fillStyle = color;
            ctx.fill();
            ctx.strokeStyle = 'rgba(0,0,0,0.3)';
            ctx.lineWidth = 1;
            ctx.stroke();
            // Direction indicator
            ctx.beginPath();
            ctx.moveTo(0, 0);
            ctx.lineTo(body.shape.radius * 0.7, 0);
            ctx.strokeStyle = 'rgba(255,255,255,0.5)';
            ctx.stroke();
        } else if (body.shape.type === ShapeType.POLYGON) {
            const verts = body.shape.vertices;
            ctx.beginPath();
            ctx.moveTo(verts[0].x, verts[0].y);
            for (let i = 1; i < verts.length; i++) {
                ctx.lineTo(verts[i].x, verts[i].y);
            }
            ctx.closePath();
            ctx.fillStyle = color;
            ctx.fill();
            ctx.strokeStyle = 'rgba(0,0,0,0.3)';
            ctx.lineWidth = 1;
            ctx.stroke();
        }
        ctx.restore();
    }

    /** Draw a block with material visuals and cracks */
    drawBlock(block) {
        const ctx = this.ctx;
        const body = block.body;
        const mat = block.materialData;
        const hpRatio = block.hp / block.maxHp;

        ctx.save();
        ctx.translate(body.position.x, body.position.y);
        ctx.rotate(body.angle);

        const verts = body.shape.vertices;
        const w = body.shape.width || 40;
        const h = body.shape.height || 40;

        // Main fill
        ctx.beginPath();
        ctx.moveTo(verts[0].x, verts[0].y);
        for (let i = 1; i < verts.length; i++) ctx.lineTo(verts[i].x, verts[i].y);
        ctx.closePath();

        // Gradient fill for depth
        const grd = ctx.createLinearGradient(-w / 2, -h / 2, w / 2, h / 2);
        grd.addColorStop(0, mat.color);
        grd.addColorStop(1, mat.crackColor);
        ctx.fillStyle = hpRatio > 0.5 ? mat.color : grd;
        ctx.fill();

        // Border
        ctx.strokeStyle = mat.crackColor;
        ctx.lineWidth = 1.5;
        ctx.stroke();

        // Cracks at low HP
        if (hpRatio < 0.5) {
            ctx.strokeStyle = mat.crackColor;
            ctx.lineWidth = 1;
            ctx.globalAlpha = 1 - hpRatio;
            const cx = (Math.random() - 0.5) * w * 0.6;
            const cy = (Math.random() - 0.5) * h * 0.6;
            ctx.beginPath();
            ctx.moveTo(cx - w * 0.2, cy);
            ctx.lineTo(cx, cy - h * 0.15);
            ctx.lineTo(cx + w * 0.15, cy + h * 0.1);
            ctx.stroke();
            if (hpRatio < 0.25) {
                ctx.beginPath();
                ctx.moveTo(cx + w * 0.1, cy - h * 0.2);
                ctx.lineTo(cx - w * 0.1, cy + h * 0.15);
                ctx.stroke();
            }
            ctx.globalAlpha = 1;
        }

        // Material-specific details
        if (mat.glowEffect) {
            ctx.shadowColor = mat.color;
            ctx.shadowBlur = 10 + Math.sin(Date.now() * 0.005) * 5;
            ctx.strokeStyle = mat.color;
            ctx.lineWidth = 2;
            ctx.stroke();
            ctx.shadowBlur = 0;
        }

        ctx.restore();
    }

    /** Draw a pig */
    drawPig(pig) {
        const ctx = this.ctx;
        const body = pig.body;
        const r = body.shape.radius;
        const hpRatio = pig.hp / pig.maxHp;

        ctx.save();
        ctx.translate(body.position.x, body.position.y);

        // Body (green circle)
        ctx.beginPath();
        ctx.arc(0, 0, r, 0, Math.PI * 2);
        const pigGreen = hpRatio > 0.5 ? '#7CB342' : hpRatio > 0.25 ? '#9E9D24' : '#E53935';
        ctx.fillStyle = pigGreen;
        ctx.fill();
        ctx.strokeStyle = '#33691E';
        ctx.lineWidth = 2;
        ctx.stroke();

        // Snout
        ctx.beginPath();
        ctx.ellipse(0, r * 0.15, r * 0.4, r * 0.3, 0, 0, Math.PI * 2);
        ctx.fillStyle = '#8BC34A';
        ctx.fill();
        ctx.strokeStyle = '#33691E';
        ctx.lineWidth = 1;
        ctx.stroke();
        // Nostrils
        ctx.fillStyle = '#33691E';
        ctx.beginPath();
        ctx.arc(-r * 0.12, r * 0.15, r * 0.06, 0, Math.PI * 2);
        ctx.arc(r * 0.12, r * 0.15, r * 0.06, 0, Math.PI * 2);
        ctx.fill();

        // Eyes
        const eyeY = -r * 0.15;
        const eyeSpacing = r * 0.25;
        // Whites
        ctx.fillStyle = '#fff';
        ctx.beginPath();
        ctx.arc(-eyeSpacing, eyeY, r * 0.2, 0, Math.PI * 2);
        ctx.arc(eyeSpacing, eyeY, r * 0.2, 0, Math.PI * 2);
        ctx.fill();
        // Pupils
        ctx.fillStyle = '#000';
        ctx.beginPath();
        ctx.arc(-eyeSpacing + r * 0.05, eyeY, r * 0.08, 0, Math.PI * 2);
        ctx.arc(eyeSpacing + r * 0.05, eyeY, r * 0.08, 0, Math.PI * 2);
        ctx.fill();

        // Damage bruises
        if (hpRatio < 0.5) {
            ctx.fillStyle = 'rgba(100,0,100,0.3)';
            ctx.beginPath();
            ctx.arc(-r * 0.3, -r * 0.1, r * 0.15, 0, Math.PI * 2);
            ctx.fill();
        }

        // Helmet for armored pigs
        if (pig.type === 'senior' || pig.type === 'thesis') {
            ctx.fillStyle = pig.type === 'thesis' ? '#455A64' : '#78909C';
            ctx.beginPath();
            ctx.ellipse(0, -r * 0.5, r * 0.8, r * 0.4, 0, Math.PI, 0);
            ctx.fill();
            ctx.strokeStyle = '#263238';
            ctx.lineWidth = 1.5;
            ctx.stroke();
        }

        ctx.restore();
    }

    /** Draw a bird */
    drawBird(bird) {
        const ctx = this.ctx;
        const body = bird.body;
        const r = body.shape.radius;

        ctx.save();
        ctx.translate(body.position.x, body.position.y);
        ctx.rotate(body.angle);

        // Bird body
        ctx.beginPath();
        ctx.arc(0, 0, r, 0, Math.PI * 2);
        ctx.fillStyle = bird.color;
        ctx.fill();
        ctx.strokeStyle = bird.strokeColor || '#000';
        ctx.lineWidth = 2;
        ctx.stroke();

        // Eyes
        const eyeY = -r * 0.1;
        ctx.fillStyle = '#fff';
        ctx.beginPath();
        ctx.arc(-r * 0.2, eyeY, r * 0.22, 0, Math.PI * 2);
        ctx.arc(r * 0.2, eyeY, r * 0.22, 0, Math.PI * 2);
        ctx.fill();
        // Angry eyebrows
        ctx.strokeStyle = '#000';
        ctx.lineWidth = 2;
        ctx.beginPath();
        ctx.moveTo(-r * 0.45, eyeY - r * 0.25);
        ctx.lineTo(-r * 0.05, eyeY - r * 0.1);
        ctx.moveTo(r * 0.05, eyeY - r * 0.1);
        ctx.lineTo(r * 0.45, eyeY - r * 0.25);
        ctx.stroke();
        // Pupils
        ctx.fillStyle = '#000';
        ctx.beginPath();
        ctx.arc(-r * 0.15, eyeY + r * 0.05, r * 0.08, 0, Math.PI * 2);
        ctx.arc(r * 0.15, eyeY + r * 0.05, r * 0.08, 0, Math.PI * 2);
        ctx.fill();

        // Beak
        ctx.fillStyle = '#FF8F00';
        ctx.beginPath();
        ctx.moveTo(r * 0.5, r * 0.05);
        ctx.lineTo(r * 0.9, r * 0.15);
        ctx.lineTo(r * 0.5, r * 0.3);
        ctx.closePath();
        ctx.fill();

        // Tail feathers
        ctx.fillStyle = bird.tailColor || bird.color;
        ctx.beginPath();
        ctx.moveTo(-r * 0.7, -r * 0.3);
        ctx.lineTo(-r * 1.1, -r * 0.5);
        ctx.lineTo(-r * 1.0, -r * 0.1);
        ctx.lineTo(-r * 1.2, r * 0.0);
        ctx.lineTo(-r * 0.9, r * 0.1);
        ctx.lineTo(-r * 1.1, r * 0.3);
        ctx.lineTo(-r * 0.7, r * 0.2);
        ctx.closePath();
        ctx.fill();

        // Bird-specific decorations drawn by subclass
        if (bird.drawDecoration) {
            bird.drawDecoration(ctx, r);
        }

        ctx.restore();
    }

    /** Draw the slingshot */
    drawSlingshot(slingshot) {
        const ctx = this.ctx;
        const { x, y } = slingshot.position;
        const forkW = 25;
        const forkH = 60;
        const baseH = 80;

        // Back fork (behind bird)
        ctx.save();
        // Base post
        ctx.fillStyle = '#5D4037';
        ctx.strokeStyle = '#3E2723';
        ctx.lineWidth = 2;
        ctx.beginPath();
        ctx.moveTo(x - 8, y);
        ctx.lineTo(x + 8, y);
        ctx.lineTo(x + 6, y + baseH);
        ctx.lineTo(x - 6, y + baseH);
        ctx.closePath();
        ctx.fill();
        ctx.stroke();

        // Left fork
        ctx.beginPath();
        ctx.moveTo(x - 6, y + 10);
        ctx.lineTo(x - forkW, y - forkH);
        ctx.lineTo(x - forkW + 10, y - forkH);
        ctx.lineTo(x, y + 10);
        ctx.closePath();
        ctx.fillStyle = '#6D4C41';
        ctx.fill();
        ctx.stroke();

        // Right fork
        ctx.beginPath();
        ctx.moveTo(x, y + 10);
        ctx.lineTo(x + forkW - 10, y - forkH);
        ctx.lineTo(x + forkW, y - forkH);
        ctx.lineTo(x + 6, y + 10);
        ctx.closePath();
        ctx.fill();
        ctx.stroke();

        // Rubber band
        if (slingshot.isStretched && slingshot.birdPos) {
            const bp = slingshot.birdPos;
            const leftFork = { x: x - forkW, y: y - forkH };
            const rightFork = { x: x + forkW, y: y - forkH };

            // Back band
            ctx.strokeStyle = '#4E342E';
            ctx.lineWidth = 5;
            ctx.beginPath();
            ctx.moveTo(leftFork.x, leftFork.y);
            ctx.lineTo(bp.x, bp.y);
            ctx.stroke();

            // Front band (drawn over bird)
            ctx.strokeStyle = '#6D4C41';
            ctx.lineWidth = 5;
            ctx.beginPath();
            ctx.moveTo(rightFork.x, rightFork.y);
            ctx.lineTo(bp.x, bp.y);
            ctx.stroke();
        }

        ctx.restore();
    }

    /** Draw trajectory preview dots */
    drawTrajectory(points, maxPoints = 40) {
        const ctx = this.ctx;
        const count = Math.min(points.length, maxPoints);
        for (let i = 0; i < count; i++) {
            const alpha = 1 - (i / count) * 0.8;
            const size = 3 - (i / count) * 2;
            ctx.beginPath();
            ctx.arc(points[i].x, points[i].y, Math.max(size, 1), 0, Math.PI * 2);
            ctx.fillStyle = `rgba(255,255,255,${alpha})`;
            ctx.fill();
        }
    }

    /** Draw score popup text */
    drawScorePopup(x, y, text, age, color = '#FFD700') {
        const ctx = this.ctx;
        const alpha = Math.max(0, 1 - age / 1.5);
        const scale = 1 + MathUtils.easeOutBack(Math.min(age * 3, 1)) * 0.5;
        ctx.save();
        ctx.translate(x, y - age * 40);
        ctx.scale(scale, scale);
        ctx.font = 'bold 20px "Segoe UI", Arial, sans-serif';
        ctx.textAlign = 'center';
        ctx.fillStyle = `rgba(0,0,0,${alpha * 0.5})`;
        ctx.fillText(text, 2, 2);
        ctx.fillStyle = color.replace(')', `,${alpha})`).replace('rgb', 'rgba');
        if (!color.startsWith('rgba')) {
            ctx.globalAlpha = alpha;
            ctx.fillStyle = color;
        }
        ctx.fillText(text, 0, 0);
        ctx.restore();
    }

    /** Convert screen position to world position */
    screenToWorld(screenX, screenY) {
        return { x: screenX + this.camera.x, y: screenY + this.camera.y };
    }

    worldToScreen(worldX, worldY) {
        return { x: worldX - this.camera.x, y: worldY - this.camera.y };
    }
}
