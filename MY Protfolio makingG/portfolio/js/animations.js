/* ============================================================
   ANIMATIONS.JS — GSAP ScrollTrigger & Cinematic Timelines
   Kaesarz Portfolio | Kawsar Hoque
   ============================================================
   Handcrafted entrances per section.
   No paid GSAP plugins — all effects vanilla + free GSAP.
   ============================================================ */

const Animations = {
  lenis: null,
  heroTimeline: null,
  isReady: false,

  init() {
    if (typeof gsap === 'undefined') {
      console.warn('[Animations] GSAP not loaded.');
      return;
    }

    this.initLenis();
    this.registerPlugins();
    this.setupInitialStates();

    // Wait for loader to finish before hero animation
    this.heroTimeline = gsap.timeline({ paused: true });
    this.buildHeroTimeline();
    this.buildNavTimeline();

    // Listen for loader complete
    window.addEventListener('loader:complete', () => {
      this.heroTimeline.play();
    });

    // Also start when page fully loads (fallback)
    if (document.readyState === 'complete') {
      setTimeout(() => this.heroTimeline.play(), 2200);
    } else {
      window.addEventListener('load', () => {
        setTimeout(() => this.heroTimeline.play(), 2200);
      });
    }

    // Build section timelines (only if ScrollTrigger is available)
    if (typeof ScrollTrigger !== 'undefined') {
      this.buildAboutTimeline();
      this.buildSkillsTimeline();
      this.buildProjectsTimeline();
      this.buildGitHubTimeline();
      this.buildCPTimeline();
      this.buildContactTimeline();
      this.buildFooterTimeline();
    }

    this.isReady = true;
  },

  /* ----- LENIS SMOOTH SCROLL ----- */
  initLenis() {
    if (typeof Lenis === 'undefined') return;

    this.lenis = new Lenis({
      duration: 1.2,
      easing: (t) => Math.min(1, 1.001 - Math.pow(2, -10 * t)),
      orientation: 'vertical',
      smoothWheel: true,
      touchMultiplier: 1.5,
    });

    if (typeof ScrollTrigger !== 'undefined') {
      this.lenis.on('scroll', ScrollTrigger.update);
    }

    const raf = (time) => {
      this.lenis.raf(time);
      requestAnimationFrame(raf);
    };
    requestAnimationFrame(raf);
  },

  /* ----- REGISTER PLUGINS ----- */
  registerPlugins() {
    if (typeof ScrollTrigger !== 'undefined') {
      gsap.registerPlugin(ScrollTrigger);
    }

    window.addEventListener('resize', () => {
      if (typeof ScrollTrigger !== 'undefined') ScrollTrigger.refresh();
    });
  },

  /* ----- SETUP INITIAL STATES ----- */
  setupInitialStates() {
    // Nav
    gsap.set('.nav', { y: -80, opacity: 0 });

    // Hero greeting
    gsap.set('[data-animate="hero-greeting"]', { opacity: 0, y: 30 });

    // Hero chars
    gsap.set('.char', { opacity: 1, y: 24, rotationX: -12 });

    // Hero typing wrapper
    gsap.set('[data-animate="hero-typing"]', { opacity: 0, y: 20 });

    // Hero tagline
    gsap.set('[data-animate="hero-tagline"]', { opacity: 0, y: 25 });

    // Hero actions
    gsap.set('[data-animate="hero-actions"]', { opacity: 0, y: 30 });

    // Hero visual
    gsap.set('[data-animate="hero-visual"]', { opacity: 0, scale: 0.85 });

    // Scroll indicator
    gsap.set('.hero__scroll-indicator', { opacity: 0, y: 10 });

    // Sections handled by CSS observer — no gsap.set (CSS handles initial state)
    // Sections handled by ScrollTrigger — set initial GSAP state
    gsap.set('[data-animate="about-header"]', { opacity: 0, y: 30 });
    gsap.set('[data-animate="about-content"]', { opacity: 0, y: 40 });
    gsap.set('[data-animate="about-side"]', { opacity: 0, x: 30 });
    gsap.set('[data-animate="about-tag"]', { opacity: 0, y: 15 });
    gsap.set('[data-animate="skills-header"]', { opacity: 0, y: 30 });
    gsap.set('[data-animate="skills-group"]', { opacity: 0, y: 40 });
    gsap.set('[data-skills="card"]', { opacity: 0, y: 30, scale: 0.95 });
    gsap.set('[data-animate="projects-header"]', { opacity: 0, y: 30 });
    gsap.set('[data-projects="card"]', { opacity: 0, y: 40, scale: 0.9 });

    // GitHub
    gsap.set('[data-animate="github-header"]', { opacity: 0, y: 30 });
    gsap.set('[data-animate="github-profile"]', { opacity: 0, y: 40 });
    gsap.set('[data-animate="github-repos"]', { opacity: 0, y: 40 });
    gsap.set('[data-animate="github-langs"]', { opacity: 0, y: 40 });

    // CP
    gsap.set('[data-animate="cp-header"]', { opacity: 0, y: 30 });
    gsap.set('[data-animate="card-stagger"]', { opacity: 0, y: 40, scale: 0.95 });

    // Contact
    gsap.set('[data-animate="contact-header"]', { opacity: 0, y: 30 });
    gsap.set('[data-animate="contact-form"]', { opacity: 0, y: 40 });
    gsap.set('[data-animate="contact-info"]', { opacity: 0, x: 30 });

    // Footer
    gsap.set('[data-animate="footer-inner"]', { opacity: 0, y: 30 });
    gsap.set('[data-animate="footer-bottom"]', { opacity: 0, y: 20 });
  },

  /* ----- HERO TIMELINE ----- */
  buildHeroTimeline() {
    const tl = this.heroTimeline;

    // 1. Nav slides down
    tl.to('.nav', {
      y: 0,
      opacity: 1,
      duration: 0.8,
      ease: 'power3.out',
    });

    // 2. Greeting fades up
    tl.to('[data-animate="hero-greeting"]', {
      opacity: 1,
      y: 0,
      duration: 0.7,
      ease: 'power2.out',
    }, '-=0.4');

    // 3. Name chars stagger reveal (manual split text)
    tl.to('.char', {
      y: 0,
      rotateX: 0,
      duration: 0.5,
      stagger: 0.04,
      ease: 'back.out(1.7)',
    }, '-=0.2');

    // 4. Typing wrapper + start typing effect
    tl.to('[data-animate="hero-typing"]', {
      opacity: 1,
      y: 0,
      duration: 0.6,
      ease: 'power2.out',
      onStart: () => {
        if (typeof App !== 'undefined' && App.typingEffect) {
          App.typingEffect();
        }
      },
    }, '-=0.1');

    // 5. Tagline
    tl.to('[data-animate="hero-tagline"]', {
      opacity: 1,
      y: 0,
      duration: 0.7,
      ease: 'power2.out',
    }, '-=0.2');

    // 6. CTA buttons stagger
    tl.to('[data-animate="hero-actions"] > *', {
      opacity: 1,
      y: 0,
      duration: 0.6,
      stagger: 0.12,
      ease: 'back.out(1.4)',
    }, '-=0.3');

    // 7. Profile visual
    tl.to('[data-animate="hero-visual"]', {
      opacity: 1,
      scale: 1,
      duration: 1,
      ease: 'power3.out',
    }, '-=0.6');

    // 8. Scroll indicator fades in
    tl.to('.hero__scroll-indicator', {
      opacity: 1,
      y: 0,
      duration: 0.8,
      ease: 'power2.out',
    }, '-=0.4');
  },

  /* ----- NAV SCROLL BEHAVIOR ----- */
  buildNavTimeline() {
    if (typeof ScrollTrigger === 'undefined') return;

    gsap.to('.nav', {
      scrollTrigger: {
        trigger: '.hero',
        start: 'bottom top',
        end: 'bottom top+=100',
        scrub: 0.3,
      },
      backdropFilter: 'blur(24px)',
      backgroundColor: 'rgba(5,5,5,0.85)',
    });
  },

  /* ----- ABOUT TIMELINE ----- */
  buildAboutTimeline() {
    if (typeof ScrollTrigger === 'undefined') return;

    // Header fade-up
    gsap.to('[data-animate="about-header"]', {
      scrollTrigger: {
        trigger: '#about',
        start: 'top 85%',
        toggleActions: 'play none none reverse',
      },
      opacity: 1,
      y: 0,
      duration: 0.7,
      ease: 'power2.out',
    });

    // Content — word-reveal style with stagger
    gsap.to('[data-animate="about-content"]', {
      scrollTrigger: {
        trigger: '#about',
        start: 'top 75%',
        toggleActions: 'play none none reverse',
      },
      opacity: 1,
      y: 0,
      duration: 0.8,
      ease: 'power2.out',
    });

    // Side cards — slide in from right
    gsap.to('[data-animate="about-side"]', {
      scrollTrigger: {
        trigger: '#about',
        start: 'top 70%',
        toggleActions: 'play none none reverse',
      },
      opacity: 1,
      x: 0,
      duration: 0.9,
      ease: 'power3.out',
    });

    // Tags stagger
    gsap.to('[data-animate="about-tag"]', {
      scrollTrigger: {
        trigger: '.about__tags',
        start: 'top 85%',
        toggleActions: 'play none none reverse',
      },
      opacity: 1,
      y: 0,
      duration: 0.4,
      stagger: 0.08,
      ease: 'back.out(1.4)',
    });

    // Stats counter animation
    this.animateCounters();
  },

  /* ----- COUNTER ANIMATION ----- */
  animateCounters() {
    const counters = document.querySelectorAll('.about__stat-number');
    if (!counters.length) return;

    counters.forEach((el) => {
      const parent = el.closest('.about__stat');
      const target = parseInt(parent.getAttribute('data-count'), 10);
      if (isNaN(target)) return;

      gsap.from(el, {
        scrollTrigger: {
          trigger: parent,
          start: 'top 85%',
          toggleActions: 'play none none reverse',
        },
        textContent: 0,
        duration: 1.5,
        ease: 'power2.out',
        snap: { textContent: 1 },
        onUpdate: () => {
          const val = Math.round(parseFloat(el.textContent));
          el.textContent = val;
        },
        onComplete: () => {
          el.textContent = target;
        },
      });
    });
  },

  /* ----- SKILLS TIMELINE ----- */
  buildSkillsTimeline() {
    if (typeof ScrollTrigger === 'undefined') return;

    // Header
    gsap.to('[data-animate="skills-header"]', {
      scrollTrigger: {
        trigger: '#skills',
        start: 'top 85%',
        toggleActions: 'play none none reverse',
      },
      opacity: 1,
      y: 0,
      duration: 0.7,
      ease: 'power2.out',
    });

    // Group headers — fade and slide
    gsap.to('[data-animate="skills-group"]', {
      scrollTrigger: {
        trigger: '#skills',
        start: 'top 75%',
        toggleActions: 'play none none reverse',
      },
      opacity: 1,
      y: 0,
      duration: 0.6,
      stagger: 0.15,
      ease: 'power2.out',
    });

    // Skill cards — 3D stagger
    gsap.to('[data-skills="card"]', {
      scrollTrigger: {
        trigger: '#skills',
        start: 'top 70%',
        toggleActions: 'play none none reverse',
      },
      opacity: 1,
      y: 0,
      scale: 1,
      duration: 0.5,
      stagger: 0.04,
      ease: 'back.out(1.4)',
    });
  },

  /* ----- PROJECTS TIMELINE ----- */
  buildProjectsTimeline() {
    if (typeof ScrollTrigger === 'undefined') return;

    // Header
    gsap.to('[data-animate="projects-header"]', {
      scrollTrigger: {
        trigger: '#projects',
        start: 'top 85%',
        toggleActions: 'play none none reverse',
      },
      opacity: 1,
      y: 0,
      duration: 0.7,
      ease: 'power2.out',
    });

    // Project cards — scale + blur + stagger
    gsap.to('[data-projects="card"]', {
      scrollTrigger: {
        trigger: '#projects',
        start: 'top 75%',
        toggleActions: 'play none none reverse',
      },
      opacity: 1,
      y: 0,
      scale: 1,
      duration: 0.7,
      stagger: 0.12,
      ease: 'power3.out',
      filter: 'blur(0px)',
    });
  },

  /* ----- GITHUB TIMELINE ----- */
  buildGitHubTimeline() {
    if (typeof ScrollTrigger === 'undefined') return;

    gsap.to('[data-animate="github-header"]', {
      scrollTrigger: { trigger: '#github', start: 'top 85%', toggleActions: 'play none none reverse' },
      opacity: 1, y: 0, duration: 0.7, ease: 'power2.out',
    });

    gsap.to('[data-animate="github-profile"]', {
      scrollTrigger: { trigger: '#github', start: 'top 75%', toggleActions: 'play none none reverse' },
      opacity: 1, y: 0, duration: 0.8, ease: 'power2.out',
    });

    gsap.to('[data-animate="github-repos"]', {
      scrollTrigger: { trigger: '#github', start: 'top 70%', toggleActions: 'play none none reverse' },
      opacity: 1, y: 0, duration: 0.8, ease: 'power2.out',
    });

    gsap.to('[data-animate="github-langs"]', {
      scrollTrigger: { trigger: '#github', start: 'top 65%', toggleActions: 'play none none reverse' },
      opacity: 1, y: 0, duration: 0.8, ease: 'power2.out',
    });
  },

  /* ----- CP TIMELINE ----- */
  buildCPTimeline() {
    if (typeof ScrollTrigger === 'undefined') return;

    gsap.to('[data-animate="cp-header"]', {
      scrollTrigger: { trigger: '#cp', start: 'top 85%', toggleActions: 'play none none reverse' },
      opacity: 1, y: 0, duration: 0.7, ease: 'power2.out',
    });

    gsap.to('[data-animate="card-stagger"]', {
      scrollTrigger: { trigger: '#cp', start: 'top 75%', toggleActions: 'play none none reverse' },
      opacity: 1, y: 0, scale: 1, duration: 0.6, stagger: 0.15, ease: 'back.out(1.4)',
    });
  },

  /* ----- CONTACT TIMELINE ----- */
  buildContactTimeline() {
    if (typeof ScrollTrigger === 'undefined') return;

    gsap.to('[data-animate="contact-header"]', {
      scrollTrigger: { trigger: '#contact', start: 'top 85%', toggleActions: 'play none none reverse' },
      opacity: 1, y: 0, duration: 0.7, ease: 'power2.out',
    });

    gsap.to('[data-animate="contact-form"]', {
      scrollTrigger: { trigger: '#contact', start: 'top 75%', toggleActions: 'play none none reverse' },
      opacity: 1, y: 0, duration: 0.8, ease: 'power2.out',
    });

    gsap.to('[data-animate="contact-info"]', {
      scrollTrigger: { trigger: '#contact', start: 'top 75%', toggleActions: 'play none none reverse' },
      opacity: 1, x: 0, duration: 0.9, ease: 'power3.out',
    });
  },

  /* ----- FOOTER TIMELINE ----- */
  buildFooterTimeline() {
    if (typeof ScrollTrigger === 'undefined') return;

    gsap.to('[data-animate="footer-inner"]', {
      scrollTrigger: { trigger: '.footer', start: 'top 85%', toggleActions: 'play none none reverse' },
      opacity: 1, y: 0, duration: 0.7, ease: 'power2.out',
    });

    gsap.to('[data-animate="footer-bottom"]', {
      scrollTrigger: { trigger: '.footer', start: 'top 80%', toggleActions: 'play none none reverse' },
      opacity: 1, y: 0, duration: 0.6, ease: 'power2.out',
    });
  },
};


/* ----- INIT ----- */
document.addEventListener('DOMContentLoaded', () => {
  Animations.init();
});
