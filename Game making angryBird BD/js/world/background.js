/**
 * KAESARZ: CSE WARS — Parallax Background System
 * Multi-layer scrolling backgrounds per world theme.
 */

import { MathUtils } from '../utils/math.js';

/** Background layer definition */
class BGLayer {
    constructor(drawFn, scrollFactor, yOffset = 0) {
        this.draw = drawFn;
        this.scrollFactor = scrollFactor;
        this.yOffset = yOffset;
        this._cache = null;
        this._cacheWidth = 0;
    }
}

export class Background {
    constructor() {
        this.layers = [];
        this.skyColors = { top: '#1E90FF', bottom: '#B0E0E6' };
        this.groundY = 580;
    }

    /** Set world theme */
    setWorld(worldId) {
        this.layers = [];
        switch (worldId) {
            case 1: this._setupMirpur(); break;
            case 2: this._setupBUBT(); break;
            default: this._setupMirpur(); break;
        }
    }

    /** World 1: Mirpur Moholla */
    _setupMirpur() {
        this.skyColors = { top: '#1565C0', bottom: '#90CAF9' };

        // Layer 0: Clouds (8% scroll)
        this.layers.push(new BGLayer((ctx, w, h, camX) => {
            ctx.fillStyle = 'rgba(255,255,255,0.6)';
            const time = Date.now() * 0.00005;
            for (let i = 0; i < 8; i++) {
                const cx = (i * 250 + time * 200 + camX * 0.08) % (w + 400) - 100;
                const cy = 60 + Math.sin(i * 1.7) * 40;
                this._drawCloud(ctx, cx, cy, 40 + i * 8);
            }
        }, 0.08));

        // Layer 1: Far skyline (15% scroll)
        this.layers.push(new BGLayer((ctx, w, h, camX) => {
            ctx.fillStyle = '#546E7A';
            const baseY = 380;
            for (let x = -200; x < w + 400; x += 60) {
                const bh = 60 + Math.sin(x * 0.02) * 30 + Math.cos(x * 0.037) * 20;
                ctx.fillRect(x - camX * 0.15, baseY - bh, 45, bh + 20);
            }
        }, 0.15));

        // Layer 2: Mid buildings (30% scroll)
        this.layers.push(new BGLayer((ctx, w, h, camX) => {
            const baseY = 430;
            const colors = ['#795548', '#8D6E63', '#6D4C41', '#5D4037'];
            for (let x = -100; x < w + 600; x += 80) {
                const bh = 80 + Math.sin(x * 0.03) * 40 + Math.cos(x * 0.05) * 25;
                ctx.fillStyle = colors[Math.floor(x / 80) % colors.length];
                ctx.fillRect(x - camX * 0.3, baseY - bh, 55, bh + 30);
                // Windows
                ctx.fillStyle = 'rgba(255,235,59,0.6)';
                for (let wy = baseY - bh + 10; wy < baseY - 5; wy += 18) {
                    for (let wx = x - camX * 0.3 + 8; wx < x - camX * 0.3 + 48; wx += 15) {
                        ctx.fillRect(wx, wy, 8, 10);
                    }
                }
            }
        }, 0.3));

        // Layer 3: Near buildings + rickshaws (60% scroll)
        this.layers.push(new BGLayer((ctx, w, h, camX) => {
            const baseY = 510;
            // Buildings
            const colors = ['#4E342E', '#3E2723', '#5D4037'];
            for (let x = -50; x < w + 800; x += 100) {
                const bh = 100 + Math.sin(x * 0.02) * 50;
                ctx.fillStyle = colors[Math.floor(x / 100) % colors.length];
                ctx.fillRect(x - camX * 0.6, baseY - bh, 70, bh + 20);
                // Neon signs
                ctx.fillStyle = `hsl(${(x * 7) % 360}, 70%, 60%)`;
                ctx.fillRect(x - camX * 0.6 + 10, baseY - bh + 15, 50, 12);
            }
            // Street
            ctx.fillStyle = '#37474F';
            ctx.fillRect(-camX * 0.6 - 100, baseY + 15, w + 1000, 30);
        }, 0.6));
    }

    /** World 2: BUBT Campus */
    _setupBUBT() {
        this.skyColors = { top: '#0D47A1', bottom: '#64B5F6' };

        // Clouds
        this.layers.push(new BGLayer((ctx, w, h, camX) => {
            ctx.fillStyle = 'rgba(255,255,255,0.5)';
            const time = Date.now() * 0.00004;
            for (let i = 0; i < 6; i++) {
                const cx = (i * 300 + time * 150 + camX * 0.08) % (w + 400) - 100;
                this._drawCloud(ctx, cx, 50 + i * 25, 35 + i * 6);
            }
        }, 0.08));

        // BUBT Main building silhouette (far)
        this.layers.push(new BGLayer((ctx, w, h, camX) => {
            ctx.fillStyle = '#78909C';
            // Main building block
            const bx = w * 0.3 - camX * 0.2;
            ctx.fillRect(bx, 320, 300, 180);
            ctx.fillRect(bx + 80, 280, 140, 40);
            // Flag
            ctx.fillStyle = '#C62828';
            ctx.fillRect(bx + 140, 260, 30, 20);
            ctx.fillStyle = '#2E7D32';
            ctx.fillRect(bx + 140, 260, 10, 20);
        }, 0.2));

        // Trees and campus area
        this.layers.push(new BGLayer((ctx, w, h, camX) => {
            for (let x = -50; x < w + 600; x += 90) {
                const tx = x - camX * 0.4;
                // Tree trunk
                ctx.fillStyle = '#5D4037';
                ctx.fillRect(tx + 15, 470, 10, 40);
                // Canopy
                ctx.fillStyle = '#2E7D32';
                ctx.beginPath();
                ctx.arc(tx + 20, 460, 28, 0, Math.PI * 2);
                ctx.fill();
                ctx.fillStyle = '#388E3C';
                ctx.beginPath();
                ctx.arc(tx + 25, 455, 22, 0, Math.PI * 2);
                ctx.fill();
            }
        }, 0.4));

        // Near: desks and lab tables
        this.layers.push(new BGLayer((ctx, w, h, camX) => {
            ctx.fillStyle = '#455A64';
            for (let x = -50; x < w + 800; x += 120) {
                const dx = x - camX * 0.6;
                // Desk
                ctx.fillRect(dx, 530, 60, 8);
                ctx.fillRect(dx + 5, 538, 5, 25);
                ctx.fillRect(dx + 50, 538, 5, 25);
                // Monitor on desk
                ctx.fillStyle = '#263238';
                ctx.fillRect(dx + 15, 510, 30, 20);
                ctx.fillStyle = '#00E5FF';
                ctx.fillRect(dx + 17, 512, 26, 16);
                ctx.fillStyle = '#455A64';
            }
        }, 0.6));
    }

    _drawCloud(ctx, x, y, size) {
        ctx.beginPath();
        ctx.arc(x, y, size * 0.5, 0, Math.PI * 2);
        ctx.arc(x + size * 0.4, y - size * 0.15, size * 0.4, 0, Math.PI * 2);
        ctx.arc(x + size * 0.8, y, size * 0.45, 0, Math.PI * 2);
        ctx.arc(x + size * 0.3, y + size * 0.1, size * 0.3, 0, Math.PI * 2);
        ctx.fill();
    }

    /** Draw all background layers */
    draw(ctx, width, height, cameraX) {
        // Sky gradient
        const grd = ctx.createLinearGradient(0, 0, 0, height);
        grd.addColorStop(0, this.skyColors.top);
        grd.addColorStop(1, this.skyColors.bottom);
        ctx.save();
        ctx.setTransform(1, 0, 0, 1, 0, 0);
        ctx.fillStyle = grd;
        ctx.fillRect(0, 0, width, height);
        ctx.restore();

        // Draw each parallax layer
        for (const layer of this.layers) {
            ctx.save();
            layer.draw(ctx, width, height, cameraX);
            ctx.restore();
        }
    }
}
