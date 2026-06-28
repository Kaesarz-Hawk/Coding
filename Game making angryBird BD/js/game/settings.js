/**
 * KAESARZ: CSE WARS — Settings Manager
 * User-configurable game settings with defaults.
 */

export const DEFAULT_SETTINGS = {
    bgmVolume: 0.8,
    sfxVolume: 1.0,
    masterVolume: 1.0,
    bgmMuted: false,
    sfxMuted: false,
    particleQuality: 'high',
    weatherEffects: true,
    trajectoryPreview: true,
    slowMotion: true,
    language: 'en',
    colorblind: false,
    largeTouchTargets: false,
    showFPS: false
};

export class Settings {
    constructor() {
        this.values = { ...DEFAULT_SETTINGS };
        this._listeners = new Map();
    }

    get(key) {
        return this.values[key];
    }

    set(key, value) {
        const old = this.values[key];
        if (old === value) return;
        this.values[key] = value;
        this._notify(key, value, old);
    }

    getAll() {
        return { ...this.values };
    }

    load(data) {
        if (!data) return;
        for (const key of Object.keys(DEFAULT_SETTINGS)) {
            if (data[key] !== undefined) {
                this.values[key] = data[key];
            }
        }
    }

    toJSON() {
        return { ...this.values };
    }

    reset() {
        const old = { ...this.values };
        this.values = { ...DEFAULT_SETTINGS };
        for (const key of Object.keys(this.values)) {
            if (old[key] !== this.values[key]) {
                this._notify(key, this.values[key], old[key]);
            }
        }
    }

    onChange(key, callback) {
        if (!this._listeners.has(key)) {
            this._listeners.set(key, []);
        }
        this._listeners.get(key).push(callback);
    }

    _notify(key, newVal, oldVal) {
        const listeners = this._listeners.get(key);
        if (listeners) {
            for (const cb of listeners) {
                cb(newVal, oldVal);
            }
        }
    }

    /** Particle count multiplier based on quality setting */
    get particleMultiplier() {
        switch (this.values.particleQuality) {
            case 'low': return 0.3;
            case 'medium': return 0.6;
            case 'high': return 1.0;
            default: return 1.0;
        }
    }
}
