/**
 * KAESARZ: CSE WARS — Audio System
 * Web Audio API synthesis for all BGM and SFX. No external audio files.
 */

export class AudioManager {
    constructor() {
        this.ctx = null;
        this.masterGain = null;
        this.bgmGain = null;
        this.sfxGain = null;
        this.initialized = false;
        this.bgmMuted = false;
        this.sfxMuted = false;
        this._currentBGM = null;
        this._bgmNodes = [];
    }

    init() {
        if (this.initialized) return;
        try {
            this.ctx = new (window.AudioContext || window.webkitAudioContext)();
            this.masterGain = this.ctx.createGain();
            this.masterGain.connect(this.ctx.destination);
            this.bgmGain = this.ctx.createGain();
            this.bgmGain.connect(this.masterGain);
            this.sfxGain = this.ctx.createGain();
            this.sfxGain.connect(this.masterGain);
            this.initialized = true;
        } catch (e) {
            console.warn('Web Audio not supported:', e);
        }
    }

    resume() {
        if (this.ctx && this.ctx.state === 'suspended') {
            this.ctx.resume();
        }
    }

    setMasterVolume(v) { if (this.masterGain) this.masterGain.gain.value = v; }
    setBGMVolume(v) { if (this.bgmGain) this.bgmGain.gain.value = v; }
    setSFXVolume(v) { if (this.sfxGain) this.sfxGain.gain.value = v; }

    toggleBGMMute() {
        this.bgmMuted = !this.bgmMuted;
        if (this.bgmGain) this.bgmGain.gain.value = this.bgmMuted ? 0 : 0.8;
    }

    toggleSFXMute() {
        this.sfxMuted = !this.sfxMuted;
        if (this.sfxGain) this.sfxGain.gain.value = this.sfxMuted ? 0 : 1;
    }

    /** Play a synthesized SFX */
    playSFX(name, pan = 0) {
        if (!this.initialized || this.sfxMuted) return;
        this.resume();
        const t = this.ctx.currentTime;
        const sfxFn = SFX[name];
        if (sfxFn) sfxFn(this.ctx, this.sfxGain, t, pan);
    }

    /** Start background music loop */
    playBGM(name) {
        if (!this.initialized) return;
        this.stopBGM();
        this.resume();
        this._currentBGM = name;
        const bgmFn = BGM[name];
        if (bgmFn) {
            this._bgmInterval = bgmFn(this.ctx, this.bgmGain);
        }
    }

    stopBGM() {
        this._currentBGM = null;
        if (this._bgmInterval) {
            clearInterval(this._bgmInterval);
            this._bgmInterval = null;
        }
        for (const node of this._bgmNodes) {
            try { node.stop(); } catch (e) { /* already stopped */ }
        }
        this._bgmNodes = [];
    }
}

/** Helper: create oscillator note */
function playNote(ctx, dest, freq, startTime, duration, type = 'sine', volume = 0.15) {
    const osc = ctx.createOscillator();
    const gain = ctx.createGain();
    osc.type = type;
    osc.frequency.setValueAtTime(freq, startTime);
    gain.gain.setValueAtTime(volume, startTime);
    gain.gain.exponentialRampToValueAtTime(0.001, startTime + duration);
    osc.connect(gain);
    gain.connect(dest);
    osc.start(startTime);
    osc.stop(startTime + duration + 0.05);
    return osc;
}

/** Helper: noise burst */
function playNoise(ctx, dest, startTime, duration, volume = 0.1) {
    const bufferSize = ctx.sampleRate * duration;
    const buffer = ctx.createBuffer(1, bufferSize, ctx.sampleRate);
    const data = buffer.getChannelData(0);
    for (let i = 0; i < bufferSize; i++) data[i] = (Math.random() * 2 - 1);
    const source = ctx.createBufferSource();
    source.buffer = buffer;
    const gain = ctx.createGain();
    gain.gain.setValueAtTime(volume, startTime);
    gain.gain.exponentialRampToValueAtTime(0.001, startTime + duration);
    source.connect(gain);
    gain.connect(dest);
    source.start(startTime);
    return source;
}

/** Note frequency lookup */
const NOTE = {
    C3: 130.81, D3: 146.83, E3: 164.81, F3: 174.61, G3: 196.00, A3: 220.00, B3: 246.94,
    C4: 261.63, D4: 293.66, E4: 329.63, F4: 349.23, G4: 392.00, A4: 440.00, B4: 493.88,
    C5: 523.25, D5: 587.33, E5: 659.25, F5: 698.46, G5: 783.99, A5: 880.00, B5: 987.77,
    C6: 1046.50
};

/** SFX library - all synthesized */
const SFX = {
    slingshotStretch(ctx, dest, t) {
        const osc = ctx.createOscillator();
        const gain = ctx.createGain();
        osc.type = 'sine';
        osc.frequency.setValueAtTime(200, t);
        osc.frequency.linearRampToValueAtTime(500, t + 0.15);
        gain.gain.setValueAtTime(0.08, t);
        gain.gain.exponentialRampToValueAtTime(0.001, t + 0.2);
        osc.connect(gain); gain.connect(dest);
        osc.start(t); osc.stop(t + 0.25);
    },

    birdLaunch(ctx, dest, t) {
        // Whoosh - filtered noise sweep
        const bufLen = ctx.sampleRate * 0.4;
        const buf = ctx.createBuffer(1, bufLen, ctx.sampleRate);
        const d = buf.getChannelData(0);
        for (let i = 0; i < bufLen; i++) d[i] = Math.random() * 2 - 1;
        const src = ctx.createBufferSource(); src.buffer = buf;
        const filter = ctx.createBiquadFilter();
        filter.type = 'bandpass'; filter.frequency.setValueAtTime(800, t);
        filter.frequency.linearRampToValueAtTime(2000, t + 0.15);
        filter.Q.value = 2;
        const gain = ctx.createGain();
        gain.gain.setValueAtTime(0.15, t);
        gain.gain.exponentialRampToValueAtTime(0.001, t + 0.35);
        src.connect(filter); filter.connect(gain); gain.connect(dest);
        src.start(t);
    },

    woodHit(ctx, dest, t) {
        playNote(ctx, dest, 150, t, 0.15, 'sine', 0.2);
        playNote(ctx, dest, 100, t + 0.02, 0.1, 'triangle', 0.1);
    },

    woodBreak(ctx, dest, t) {
        playNoise(ctx, dest, t, 0.25, 0.15);
        playNote(ctx, dest, 80, t, 0.2, 'sine', 0.15);
        playNote(ctx, dest, 60, t + 0.05, 0.15, 'sine', 0.1);
    },

    glassHit(ctx, dest, t) {
        playNote(ctx, dest, 2000, t, 0.3, 'sine', 0.08);
        playNote(ctx, dest, 3000, t + 0.01, 0.2, 'sine', 0.05);
    },

    glassBreak(ctx, dest, t) {
        playNote(ctx, dest, 2500, t, 0.15, 'sine', 0.1);
        playNote(ctx, dest, 3500, t + 0.02, 0.1, 'sine', 0.08);
        playNoise(ctx, dest, t, 0.3, 0.12);
    },

    brickHit(ctx, dest, t) {
        playNote(ctx, dest, 120, t, 0.12, 'sine', 0.2);
        playNoise(ctx, dest, t, 0.1, 0.06);
    },

    brickBreak(ctx, dest, t) {
        playNote(ctx, dest, 80, t, 0.25, 'sine', 0.2);
        playNoise(ctx, dest, t, 0.3, 0.15);
    },

    steelHit(ctx, dest, t) {
        // Metallic clang - FM synthesis
        const osc1 = ctx.createOscillator();
        const osc2 = ctx.createOscillator();
        const gain1 = ctx.createGain();
        const gain2 = ctx.createGain();
        osc1.type = 'sine'; osc1.frequency.value = 800;
        osc2.type = 'sine'; osc2.frequency.value = 1200;
        gain1.gain.setValueAtTime(0.12, t);
        gain1.gain.exponentialRampToValueAtTime(0.001, t + 0.4);
        gain2.gain.setValueAtTime(0.08, t);
        gain2.gain.exponentialRampToValueAtTime(0.001, t + 0.3);
        osc1.connect(gain1); gain1.connect(dest);
        osc2.connect(gain2); gain2.connect(dest);
        osc1.start(t); osc1.stop(t + 0.5);
        osc2.start(t); osc2.stop(t + 0.4);
    },

    steelBreak(ctx, dest, t) {
        SFX.steelHit(ctx, dest, t);
        playNoise(ctx, dest, t + 0.1, 0.3, 0.1);
    },

    pigHit(ctx, dest, t) {
        // Squeal
        const osc = ctx.createOscillator();
        const gain = ctx.createGain();
        osc.type = 'sine';
        osc.frequency.setValueAtTime(600, t);
        osc.frequency.linearRampToValueAtTime(900, t + 0.1);
        osc.frequency.linearRampToValueAtTime(500, t + 0.2);
        gain.gain.setValueAtTime(0.12, t);
        gain.gain.exponentialRampToValueAtTime(0.001, t + 0.25);
        osc.connect(gain); gain.connect(dest);
        osc.start(t); osc.stop(t + 0.3);
    },

    pigPop(ctx, dest, t) {
        // Comedic pop + squeal
        SFX.pigHit(ctx, dest, t);
        playNote(ctx, dest, 400, t, 0.08, 'sine', 0.15);
        playNote(ctx, dest, 800, t + 0.02, 0.05, 'sine', 0.1);
    },

    explosion(ctx, dest, t) {
        // Deep boom
        const osc = ctx.createOscillator();
        const gain = ctx.createGain();
        osc.type = 'sine';
        osc.frequency.setValueAtTime(100, t);
        osc.frequency.exponentialRampToValueAtTime(30, t + 0.5);
        gain.gain.setValueAtTime(0.3, t);
        gain.gain.exponentialRampToValueAtTime(0.001, t + 0.6);
        osc.connect(gain); gain.connect(dest);
        osc.start(t); osc.stop(t + 0.7);
        playNoise(ctx, dest, t, 0.5, 0.2);
    },

    levelComplete(ctx, dest, t) {
        playNote(ctx, dest, NOTE.C5, t, 0.2, 'square', 0.1);
        playNote(ctx, dest, NOTE.E5, t + 0.15, 0.2, 'square', 0.1);
        playNote(ctx, dest, NOTE.G5, t + 0.3, 0.2, 'square', 0.1);
        playNote(ctx, dest, NOTE.C6, t + 0.45, 0.4, 'square', 0.12);
    },

    starEarned(ctx, dest, t) {
        playNote(ctx, dest, NOTE.E5, t, 0.15, 'sine', 0.1);
        playNote(ctx, dest, NOTE.G5, t + 0.05, 0.15, 'sine', 0.08);
        playNote(ctx, dest, NOTE.C6, t + 0.1, 0.2, 'sine', 0.1);
    },

    defeat(ctx, dest, t) {
        // Wah-wah trombone
        playNote(ctx, dest, NOTE.B4, t, 0.3, 'sawtooth', 0.08);
        playNote(ctx, dest, NOTE.A4, t + 0.3, 0.3, 'sawtooth', 0.08);
        playNote(ctx, dest, NOTE.G3, t + 0.6, 0.5, 'sawtooth', 0.1);
    },

    buttonClick(ctx, dest, t) {
        playNote(ctx, dest, 800, t, 0.06, 'sine', 0.08);
    },

    menuSwish(ctx, dest, t) {
        const buf = ctx.createBuffer(1, ctx.sampleRate * 0.15, ctx.sampleRate);
        const d = buf.getChannelData(0);
        for (let i = 0; i < d.length; i++) d[i] = Math.random() * 2 - 1;
        const src = ctx.createBufferSource(); src.buffer = buf;
        const flt = ctx.createBiquadFilter();
        flt.type = 'highpass'; flt.frequency.setValueAtTime(2000, t);
        flt.frequency.linearRampToValueAtTime(6000, t + 0.1);
        const g = ctx.createGain();
        g.gain.setValueAtTime(0.06, t);
        g.gain.exponentialRampToValueAtTime(0.001, t + 0.12);
        src.connect(flt); flt.connect(g); g.connect(dest);
        src.start(t);
    },

    bambooHit(ctx, dest, t) {
        playNote(ctx, dest, 200, t, 0.12, 'triangle', 0.15);
        playNote(ctx, dest, 350, t + 0.01, 0.08, 'sine', 0.08);
    },

    bambooBreak(ctx, dest, t) {
        SFX.bambooHit(ctx, dest, t);
        playNoise(ctx, dest, t + 0.05, 0.2, 0.1);
    },

    concreteHit(ctx, dest, t) {
        playNote(ctx, dest, 90, t, 0.15, 'sine', 0.25);
        playNoise(ctx, dest, t, 0.12, 0.08);
    },

    concreteBreak(ctx, dest, t) {
        playNote(ctx, dest, 60, t, 0.3, 'sine', 0.25);
        playNoise(ctx, dest, t, 0.4, 0.18);
    },

    shieldHit(ctx, dest, t) {
        playNote(ctx, dest, 1500, t, 0.2, 'sine', 0.1);
        playNote(ctx, dest, 2000, t + 0.05, 0.15, 'sine', 0.07);
    },

    shieldBreak(ctx, dest, t) {
        SFX.shieldHit(ctx, dest, t);
        playNote(ctx, dest, 500, t + 0.1, 0.3, 'sine', 0.12);
    },

    mudHit(ctx, dest, t) {
        playNote(ctx, dest, 100, t, 0.15, 'sine', 0.15);
        playNoise(ctx, dest, t, 0.08, 0.05);
    },

    mudBreak(ctx, dest, t) {
        SFX.mudHit(ctx, dest, t);
        playNoise(ctx, dest, t + 0.05, 0.25, 0.12);
    },

    birdSpecialRed(ctx, dest, t) {
        playNote(ctx, dest, 400, t, 0.1, 'square', 0.1);
        playNote(ctx, dest, 600, t + 0.05, 0.15, 'square', 0.12);
    },

    birdSpecialBlues(ctx, dest, t) {
        playNote(ctx, dest, 800, t, 0.08, 'sine', 0.08);
        playNote(ctx, dest, 1000, t + 0.03, 0.08, 'sine', 0.08);
        playNote(ctx, dest, 1200, t + 0.06, 0.08, 'sine', 0.08);
    },

    birdSpecialChuck(ctx, dest, t) {
        const osc = ctx.createOscillator();
        const g = ctx.createGain();
        osc.type = 'sawtooth';
        osc.frequency.setValueAtTime(300, t);
        osc.frequency.linearRampToValueAtTime(1200, t + 0.15);
        g.gain.setValueAtTime(0.1, t);
        g.gain.exponentialRampToValueAtTime(0.001, t + 0.2);
        osc.connect(g); g.connect(dest);
        osc.start(t); osc.stop(t + 0.25);
    },

    birdSpecialBomb(ctx, dest, t) {
        // Countdown beep then explosion
        playNote(ctx, dest, 1000, t, 0.05, 'square', 0.08);
        playNote(ctx, dest, 1000, t + 0.15, 0.05, 'square', 0.08);
        playNote(ctx, dest, 1500, t + 0.3, 0.05, 'square', 0.1);
        SFX.explosion(ctx, dest, t + 0.4);
    }
};

/** BGM library - looping synthesized music */
const BGM = {
    menu(ctx, dest) {
        const melody = [
            NOTE.E4, NOTE.G4, NOTE.A4, NOTE.B4, NOTE.A4, NOTE.G4, NOTE.E4, NOTE.D4,
            NOTE.E4, NOTE.G4, NOTE.A4, NOTE.B4, NOTE.C5, NOTE.B4, NOTE.A4, NOTE.G4
        ];
        const bass = [
            NOTE.C3, NOTE.C3, NOTE.G3, NOTE.G3, NOTE.A3, NOTE.A3, NOTE.E3, NOTE.E3,
            NOTE.C3, NOTE.C3, NOTE.G3, NOTE.G3, NOTE.F3, NOTE.F3, NOTE.G3, NOTE.G3
        ];
        let beat = 0;
        const bpm = 120;
        const beatDur = 60 / bpm;

        const loop = () => {
            if (!ctx || ctx.state === 'closed') return;
            const t = ctx.currentTime + 0.05;
            const idx = beat % melody.length;
            playNote(ctx, dest, melody[idx], t, beatDur * 0.8, 'triangle', 0.06);
            playNote(ctx, dest, bass[idx], t, beatDur * 0.9, 'sine', 0.05);
            // Light percussion
            if (beat % 2 === 0) {
                playNoise(ctx, dest, t, 0.05, 0.03);
            }
            beat++;
        };

        loop();
        return setInterval(loop, beatDur * 1000);
    },

    world1(ctx, dest) {
        const melody = [
            NOTE.C4, NOTE.E4, NOTE.G4, NOTE.E4, NOTE.F4, NOTE.A4, NOTE.G4, NOTE.E4,
            NOTE.D4, NOTE.F4, NOTE.A4, NOTE.G4, NOTE.E4, NOTE.D4, NOTE.C4, NOTE.E4
        ];
        const bass = [
            NOTE.C3, NOTE.C3, NOTE.E3, NOTE.E3, NOTE.F3, NOTE.F3, NOTE.G3, NOTE.G3,
            NOTE.A3, NOTE.A3, NOTE.F3, NOTE.F3, NOTE.G3, NOTE.G3, NOTE.C3, NOTE.C3
        ];
        let beat = 0;
        const bpm = 140;
        const beatDur = 60 / bpm;

        const loop = () => {
            if (!ctx || ctx.state === 'closed') return;
            const t = ctx.currentTime + 0.05;
            const idx = beat % melody.length;
            playNote(ctx, dest, melody[idx], t, beatDur * 0.7, 'square', 0.04);
            playNote(ctx, dest, bass[idx], t, beatDur * 0.9, 'triangle', 0.04);
            if (beat % 4 === 0) playNoise(ctx, dest, t, 0.04, 0.04);
            if (beat % 2 === 1) playNoise(ctx, dest, t, 0.02, 0.02);
            beat++;
        };

        loop();
        return setInterval(loop, beatDur * 1000);
    },

    world2(ctx, dest) {
        const melody = [
            NOTE.A4, NOTE.C5, NOTE.E5, NOTE.D5, NOTE.C5, NOTE.A4, NOTE.G4, NOTE.A4,
            NOTE.B4, NOTE.D5, NOTE.C5, NOTE.B4, NOTE.A4, NOTE.G4, NOTE.A4, NOTE.C5
        ];
        const bass = [
            NOTE.A3, NOTE.A3, NOTE.E3, NOTE.E3, NOTE.F3, NOTE.F3, NOTE.C3, NOTE.C3,
            NOTE.G3, NOTE.G3, NOTE.D3, NOTE.D3, NOTE.E3, NOTE.E3, NOTE.A3, NOTE.A3
        ];
        let beat = 0;
        const bpm = 110;
        const beatDur = 60 / bpm;

        const loop = () => {
            if (!ctx || ctx.state === 'closed') return;
            const t = ctx.currentTime + 0.05;
            const idx = beat % melody.length;
            playNote(ctx, dest, melody[idx], t, beatDur * 0.6, 'sine', 0.05);
            playNote(ctx, dest, bass[idx], t, beatDur * 0.85, 'triangle', 0.04);
            beat++;
        };

        loop();
        return setInterval(loop, beatDur * 1000);
    }
};
