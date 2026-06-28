/* ============================================================
   CURSOR.JS — Custom Cursor with Magnetic & Spotlight Effects
   Kaesarz Portfolio | Kawsar Hoque
   ============================================================ */

const Cursor = {
  el: null,
  glow: null,
  isTouch: false,
  isVisible: true,

  mouse: { x: 0, y: 0 },
  current: { x: 0, y: 0 },

  init() {
    this.isTouch = window.matchMedia('(hover: none)').matches;
    if (this.isTouch) return;

    this.el = document.getElementById('cursor');
    this.glow = document.getElementById('cursorGlow');
    if (!this.el) return;

    this.bindEvents();
    this.animate();
  },

  bindEvents() {
    document.addEventListener('mousemove', (e) => {
      this.mouse.x = e.clientX;
      this.mouse.y = e.clientY;
    }, { passive: true });

    // Hover effects for interactive elements
    this.initMagnetic();
    this.initSpotlight();
    this.initHoverEffects();
    this.initWindowBoundary();
  },

  /* ----- MAIN ANIMATION LOOP (smooth lerp) ----- */
  animate() {
    const lerp = (a, b, n) => a + (b - a) * n;

    this.current.x = lerp(this.current.x, this.mouse.x, 0.12);
    this.current.y = lerp(this.current.y, this.mouse.y, 0.12);

    if (this.el) {
      this.el.style.transform = `translate(${this.current.x - 4}px, ${this.current.y - 4}px)`;
    }
    if (this.glow) {
      this.glow.style.transform = `translate(${this.mouse.x - 100}px, ${this.mouse.y - 100}px)`;
    }

    requestAnimationFrame(() => this.animate());
  },

  /* ----- MAGNETIC BUTTONS ----- */
  initMagnetic() {
    const magnets = document.querySelectorAll('[data-cursor="magnetic"]');

    magnets.forEach((el) => {
      el.addEventListener('mousemove', (e) => {
        const rect = el.getBoundingClientRect();
        const x = e.clientX - rect.left - rect.width / 2;
        const y = e.clientY - rect.top - rect.height / 2;

        const strength = 0.3;
        el.style.transform = `translate(${x * strength}px, ${y * strength}px)`;
      });

      el.addEventListener('mouseleave', () => {
        el.style.transform = 'translate(0, 0)';
      });
    });
  },

  /* ----- SPOTLIGHT ON CARDS ----- */
  initSpotlight() {
    const cards = document.querySelectorAll('.project-card, .skill-card, .cp-card, .github__repo-card, .github__profile');

    cards.forEach((card) => {
      card.addEventListener('mousemove', (e) => {
        const rect = card.getBoundingClientRect();
        const x = ((e.clientX - rect.left) / rect.width) * 100;
        const y = ((e.clientY - rect.top) / rect.height) * 100;
        card.style.setProperty('--x', `${x}%`);
        card.style.setProperty('--y', `${y}%`);
      });
    });
  },

  /* ----- HOVER EFFECTS (cursor morph) ----- */
  initHoverEffects() {
    const targets = document.querySelectorAll(
      'a, button, .btn, .skill-card, .project-card, .cp-card, .contact__social, .nav__link, .github__repo-card'
    );

    targets.forEach((el) => {
      el.addEventListener('mouseenter', () => {
        if (this.el) {
          this.el.style.width = '40px';
          this.el.style.height = '40px';
          this.el.style.background = 'rgba(0, 102, 255, 0.15)';
          this.el.style.border = '1px solid rgba(0, 102, 255, 0.3)';
          this.el.style.mixBlendMode = 'normal';
        }
        if (this.glow) {
          this.glow.style.opacity = '0.8';
          this.glow.style.width = '300px';
          this.glow.style.height = '300px';
        }
      });

      el.addEventListener('mouseleave', () => {
        if (this.el) {
          this.el.style.width = '8px';
          this.el.style.height = '8px';
          this.el.style.background = '#ffffff';
          this.el.style.border = 'none';
          this.el.style.mixBlendMode = 'difference';
        }
        if (this.glow) {
          this.glow.style.opacity = '0.4';
          this.glow.style.width = '200px';
          this.glow.style.height = '200px';
        }
      });
    });
  },

  /* ----- HIDE ON WINDOW LEAVE ----- */
  initWindowBoundary() {
    document.addEventListener('mouseleave', () => {
      if (this.el) this.el.style.opacity = '0';
      if (this.glow) this.glow.style.opacity = '0';
    });

    document.addEventListener('mouseenter', () => {
      if (this.el) this.el.style.opacity = '1';
      if (this.glow) this.glow.style.opacity = '0.4';
    });
  },
};


/* ----- INIT ----- */
document.addEventListener('DOMContentLoaded', () => {
  Cursor.init();
});
