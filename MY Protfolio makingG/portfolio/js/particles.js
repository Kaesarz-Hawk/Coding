/* ============================================================
   PARTICLES.JS — Canvas 2D Particle System (Fallback)
   Kaesarz Portfolio | Kawsar Hoque
   ============================================================
   NOTE: This file will be fully implemented later as a
   lightweight canvas particle system. It serves as a
   mobile-friendly fallback when Three.js is disabled.
   Currently a skeleton.
   ============================================================ */

const Particles = {
  canvas: null,
  ctx: null,
  particles: [],
  isActive: false,
  animationId: null,

  init() {
    // Will be wired when Three.js scene is disabled on mobile
    // For now, this is inactive
    this.isActive = false;
  },

  start() {
    // Placeholder for future implementation
  },

  stop() {
    if (this.animationId) {
      cancelAnimationFrame(this.animationId);
      this.animationId = null;
    }
    this.isActive = false;
  }
};


/* ----- INIT ----- */
document.addEventListener('DOMContentLoaded', () => {
  Particles.init();
});
