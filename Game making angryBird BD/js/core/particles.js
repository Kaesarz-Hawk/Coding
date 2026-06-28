/**
 * KAESARZ: CSE WARS — Particle System
 * Object-pooled particle emitter with multiple effect types.
 */

import { MathUtils } from '../utils/math.js';

const MAX_PARTICLES = 2000;

class Particle {
    constructor() {
        this.reset();
    }
    reset() {
        this.active = false;
        this.x = 0; this.y = 0;
        this.vx = 0; this.vy = 0;
        this.life = 0; this.maxLife = 1;
        this.size = 3; this.startSize = 3; this.endSize = 0;
        this.color = '#fff';
        this.alpha = 1; this.startAlpha = 1; this.endAlpha = 0;
        this.rotation = 0; this.rotationSpeed = 0;
        this.gravity = 0;
        this.type = 'circle'; // 'circle', 'rect', 'triangle', 'line'
        this.width = 1;
    }
}

export class ParticleSystem {
    constructor(qualityMultiplier = 1) {
        this.particles = [];
        this.qualityMultiplier = qualityMultiplier;
        for (let i = 0; i < MAX_PARTICLES; i++) {
            this.particles.push(new Particle());
        }
        this._activeCount = 0;
    }

    _getParticle() {
        for (let i = 0; i < this.particles.length; i++) {
            if (!this.particles[i].active) return this.particles[i];
        }
        // Kill oldest
        let oldest = this.particles[0], oldestLife = 0;
        for (const p of this.particles) {
            if (p.active && p.life > oldestLife) { oldest = p; oldestLife = p.life; }
        }
        oldest.reset();
        return oldest;
    }

    /** Emit particles with configuration */
    emit(config) {
        const count = Math.ceil((config.count || 10) * this.qualityMultiplier);
        for (let i = 0; i < count; i++) {
            const p = this._getParticle();
            p.active = true;
            p.x = config.x + (config.spreadX || 0) * (Math.random() - 0.5);
            p.y = config.y + (config.spreadY || 0) * (Math.random() - 0.5);

            const angle = (config.angle || 0) + (config.angleSpread || Math.PI * 2) * (Math.random() - 0.5);
            const speed = MathUtils.random(config.speedMin || 20, config.speedMax || 100);
            p.vx = Math.cos(angle) * speed;
            p.vy = Math.sin(angle) * speed;

            p.life = 0;
            p.maxLife = MathUtils.random(config.lifeMin || 0.3, config.lifeMax || 1.0);
            p.size = MathUtils.random(config.sizeMin || 2, config.sizeMax || 5);
            p.startSize = p.size;
            p.endSize = config.endSize !== undefined ? config.endSize : 0;
            p.color = Array.isArray(config.colors) ? MathUtils.randomChoice(config.colors) : (config.color || '#fff');
            p.startAlpha = config.alpha || 1;
            p.endAlpha = config.endAlpha !== undefined ? config.endAlpha : 0;
            p.alpha = p.startAlpha;
            p.rotation = Math.random() * Math.PI * 2;
            p.rotationSpeed = (config.rotationSpeed || 0) * (Math.random() - 0.5) * 2;
            p.gravity = config.gravity !== undefined ? config.gravity : 200;
            p.type = config.type || 'circle';
            p.width = config.width || 1;
        }
    }

    /** Pre-built effect: impact sparks */
    impactSparks(x, y, colors, intensity = 1) {
        this.emit({
            x, y, count: Math.floor(12 * intensity),
            speedMin: 50, speedMax: 200,
            sizeMin: 1, sizeMax: 3,
            lifeMin: 0.2, lifeMax: 0.5,
            colors, gravity: 300,
            angleSpread: Math.PI * 2
        });
    }

    /** Pre-built effect: destruction dust */
    destructionDust(x, y, color) {
        this.emit({
            x, y, count: 20,
            spreadX: 20, spreadY: 10,
            speedMin: 10, speedMax: 50,
            angle: -Math.PI / 2, angleSpread: Math.PI * 0.8,
            sizeMin: 3, sizeMax: 8,
            lifeMin: 0.5, lifeMax: 1.2,
            color, gravity: -30,
            alpha: 0.6, endAlpha: 0
        });
    }

    /** Pre-built effect: glass shatter */
    glassShatter(x, y) {
        this.emit({
            x, y, count: 15,
            speedMin: 80, speedMax: 250,
            sizeMin: 3, sizeMax: 8,
            lifeMin: 0.4, lifeMax: 1.0,
            colors: ['#87CEEB', '#B0E0F0', '#E0F4FF', '#5CACDE'],
            gravity: 400,
            type: 'triangle',
            rotationSpeed: 10
        });
    }

    /** Pre-built effect: explosion */
    explosion(x, y, intensity = 1) {
        // Core blast
        this.emit({
            x, y, count: Math.floor(50 * intensity),
            speedMin: 100, speedMax: 400,
            sizeMin: 2, sizeMax: 6,
            lifeMin: 0.3, lifeMax: 0.8,
            colors: ['#FF6B00', '#FF8F00', '#FFD600', '#FF3D00'],
            gravity: 200
        });
        // Smoke
        this.emit({
            x, y, count: Math.floor(20 * intensity),
            speedMin: 20, speedMax: 80,
            sizeMin: 8, sizeMax: 20,
            lifeMin: 0.5, lifeMax: 1.5,
            colors: ['#424242', '#616161', '#757575'],
            gravity: -50,
            alpha: 0.5, endAlpha: 0,
            endSize: 30
        });
    }

    /** Pre-built effect: bird trail */
    birdTrail(x, y, color) {
        this.emit({
            x, y, count: 2,
            speedMin: 5, speedMax: 20,
            sizeMin: 2, sizeMax: 4,
            lifeMin: 0.2, lifeMax: 0.4,
            color, gravity: 50,
            alpha: 0.6
        });
    }

    /** Pre-built effect: confetti burst */
    confetti(x, y) {
        this.emit({
            x, y, count: 100,
            speedMin: 100, speedMax: 400,
            angle: -Math.PI / 2, angleSpread: Math.PI * 0.6,
            sizeMin: 4, sizeMax: 8,
            lifeMin: 1.0, lifeMax: 3.0,
            colors: ['#FF1744', '#2979FF', '#00E676', '#FFD600', '#FF9100', '#D500F9'],
            gravity: 200,
            type: 'rect',
            rotationSpeed: 8
        });
    }

    /** Pre-built effect: star burst */
    starBurst(x, y) {
        this.emit({
            x, y, count: 30,
            speedMin: 50, speedMax: 200,
            sizeMin: 2, sizeMax: 5,
            lifeMin: 0.5, lifeMax: 1.0,
            colors: ['#FFD700', '#FFC107', '#FFEB3B', '#FFFFFF'],
            gravity: -20
        });
    }

    /** Pre-built effect: score popup particles */
    scoreParticles(x, y) {
        this.emit({
            x, y, count: 8,
            speedMin: 30, speedMax: 80,
            angle: -Math.PI / 2, angleSpread: Math.PI * 0.4,
            sizeMin: 1, sizeMax: 3,
            lifeMin: 0.3, lifeMax: 0.6,
            colors: ['#FFD700', '#FFFFFF'],
            gravity: -50
        });
    }

    update(dt) {
        this._activeCount = 0;
        for (const p of this.particles) {
            if (!p.active) continue;
            p.life += dt;
            if (p.life >= p.maxLife) { p.active = false; continue; }

            const t = p.life / p.maxLife;
            p.x += p.vx * dt;
            p.y += p.vy * dt;
            p.vy += p.gravity * dt;
            p.rotation += p.rotationSpeed * dt;
            p.size = MathUtils.lerp(p.startSize, p.endSize, t);
            p.alpha = MathUtils.lerp(p.startAlpha, p.endAlpha, t);
            this._activeCount++;
        }
    }

    draw(ctx) {
        for (const p of this.particles) {
            if (!p.active || p.alpha < 0.01 || p.size < 0.5) continue;

            ctx.save();
            ctx.globalAlpha = p.alpha;
            ctx.translate(p.x, p.y);
            ctx.rotate(p.rotation);
            ctx.fillStyle = p.color;

            switch (p.type) {
                case 'circle':
                    ctx.beginPath();
                    ctx.arc(0, 0, p.size, 0, Math.PI * 2);
                    ctx.fill();
                    break;
                case 'rect':
                    ctx.fillRect(-p.size / 2, -p.size / 4, p.size, p.size / 2);
                    break;
                case 'triangle':
                    ctx.beginPath();
                    ctx.moveTo(0, -p.size);
                    ctx.lineTo(-p.size * 0.7, p.size * 0.5);
                    ctx.lineTo(p.size * 0.7, p.size * 0.5);
                    ctx.closePath();
                    ctx.fill();
                    break;
                case 'line':
                    ctx.strokeStyle = p.color;
                    ctx.lineWidth = p.width;
                    ctx.beginPath();
                    ctx.moveTo(0, 0);
                    ctx.lineTo(0, p.size);
                    ctx.stroke();
                    break;
            }
            ctx.restore();
        }
    }

    get activeCount() { return this._activeCount; }
}
