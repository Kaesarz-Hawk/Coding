/**
 * KAESARZ: CSE WARS — Math Utilities
 * Common math functions used throughout the engine.
 */

export const MathUtils = {
    /** Two PI constant */
    TAU: Math.PI * 2,

    /** Degrees to radians */
    DEG2RAD: Math.PI / 180,

    /** Radians to degrees */
    RAD2DEG: 180 / Math.PI,

    /** Clamp value between min and max */
    clamp(value, min, max) {
        return value < min ? min : value > max ? max : value;
    },

    /** Linear interpolation */
    lerp(a, b, t) {
        return a + (b - a) * t;
    },

    /** Smooth interpolation (ease in/out) */
    smoothstep(a, b, t) {
        t = t < 0 ? 0 : t > 1 ? 1 : t;
        t = t * t * (3 - 2 * t);
        return a + (b - a) * t;
    },

    /** Smoother step (Ken Perlin's improved version) */
    smootherstep(a, b, t) {
        t = t < 0 ? 0 : t > 1 ? 1 : t;
        t = t * t * t * (t * (t * 6 - 15) + 10);
        return a + (b - a) * t;
    },

    /** Map value from one range to another */
    map(value, inMin, inMax, outMin, outMax) {
        return outMin + (value - inMin) * (outMax - outMin) / (inMax - inMin);
    },

    /** Random float in range [min, max) */
    random(min = 0, max = 1) {
        return min + Math.random() * (max - min);
    },

    /** Random integer in range [min, max] (inclusive) */
    randomInt(min, max) {
        return Math.floor(min + Math.random() * (max - min + 1));
    },

    /** Random item from array */
    randomChoice(arr) {
        return arr[Math.floor(Math.random() * arr.length)];
    },

    /** Random float with normal distribution (Box-Muller) */
    randomGaussian(mean = 0, stddev = 1) {
        const u1 = Math.random();
        const u2 = Math.random();
        const n = Math.sqrt(-2 * Math.log(u1)) * Math.cos(2 * Math.PI * u2);
        return mean + stddev * n;
    },

    /** Wrap angle to [-PI, PI] */
    wrapAngle(angle) {
        while (angle > Math.PI) angle -= Math.PI * 2;
        while (angle < -Math.PI) angle += Math.PI * 2;
        return angle;
    },

    /** Check if value is approximately zero */
    isZero(value, epsilon = 1e-6) {
        return Math.abs(value) < epsilon;
    },

    /** Approximately equal */
    approxEqual(a, b, epsilon = 1e-6) {
        return Math.abs(a - b) < epsilon;
    },

    /** Ease out cubic */
    easeOutCubic(t) {
        return 1 - Math.pow(1 - t, 3);
    },

    /** Ease in cubic */
    easeInCubic(t) {
        return t * t * t;
    },

    /** Ease in-out cubic */
    easeInOutCubic(t) {
        return t < 0.5 ? 4 * t * t * t : 1 - Math.pow(-2 * t + 2, 3) / 2;
    },

    /** Ease out back (overshoot) */
    easeOutBack(t) {
        const c1 = 1.70158;
        const c3 = c1 + 1;
        return 1 + c3 * Math.pow(t - 1, 3) + c1 * Math.pow(t - 1, 2);
    },

    /** Ease out elastic (bounce) */
    easeOutElastic(t) {
        if (t === 0 || t === 1) return t;
        return Math.pow(2, -10 * t) * Math.sin((t * 10 - 0.75) * (2 * Math.PI / 3)) + 1;
    },

    /** Exponential decay: value * e^(-rate * dt) */
    expDecay(value, rate, dt) {
        return value * Math.exp(-rate * dt);
    },

    /** Sign function returning -1, 0, or 1 */
    sign(x) {
        return x > 0 ? 1 : x < 0 ? -1 : 0;
    },

    /** Convert HSL to RGB hex string */
    hslToHex(h, s, l) {
        s /= 100;
        l /= 100;
        const a = s * Math.min(l, 1 - l);
        const f = (n) => {
            const k = (n + h / 30) % 12;
            const color = l - a * Math.max(Math.min(k - 3, 9 - k, 1), -1);
            return Math.round(255 * color).toString(16).padStart(2, '0');
        };
        return `#${f(0)}${f(8)}${f(4)}`;
    },

    /** Lerp between two hex colors */
    lerpColor(color1, color2, t) {
        const r1 = parseInt(color1.slice(1, 3), 16);
        const g1 = parseInt(color1.slice(3, 5), 16);
        const b1 = parseInt(color1.slice(5, 7), 16);
        const r2 = parseInt(color2.slice(1, 3), 16);
        const g2 = parseInt(color2.slice(3, 5), 16);
        const b2 = parseInt(color2.slice(5, 7), 16);
        const r = Math.round(r1 + (r2 - r1) * t);
        const g = Math.round(g1 + (g2 - g1) * t);
        const b = Math.round(b1 + (b2 - b1) * t);
        return `#${r.toString(16).padStart(2, '0')}${g.toString(16).padStart(2, '0')}${b.toString(16).padStart(2, '0')}`;
    },

    /** Create RGBA string */
    rgba(r, g, b, a = 1) {
        return `rgba(${r},${g},${b},${a})`;
    },

    /** Seeded random number generator (mulberry32) */
    createRNG(seed) {
        let s = seed | 0;
        return () => {
            s = (s + 0x6D2B79F5) | 0;
            let t = Math.imul(s ^ (s >>> 15), 1 | s);
            t = (t + Math.imul(t ^ (t >>> 7), 61 | t)) ^ t;
            return ((t ^ (t >>> 14)) >>> 0) / 4294967296;
        };
    }
};
