/* ============================================================
   MAIN.JS — App Orchestrator
   Kaesarz Portfolio | Kawsar Hoque
   ============================================================ */

const App = {
  init() {
    this.splitText();
    this.loader();
    this.navigation();
    this.scrollProgress();
    this.currentYear();
    this.scrollIndicator();
    this.backToTop();
    this.smoothScroll();
    this.contactForm();
    this.copyEmail();
    this.initAnimate();
  },

  /* ----- LOADER ----- */
  loader() {
    const loader = document.getElementById('loader');
    if (!loader) return;
    let completed = false;

    const complete = () => {
      if (completed) return;
      completed = true;
      loader.classList.add('loader--hidden');
      window.dispatchEvent(new Event('loader:complete'));
    };

    const barFill = loader.querySelector('.loader__bar-fill');
    if (barFill) {
      barFill.addEventListener('animationend', () => {
        setTimeout(complete, 500);
      });
    }

    // Fallback: force complete after 4s
    setTimeout(() => {
      if (!completed) complete();
    }, 4500);
  },

  /* ----- NAVIGATION ----- */
  navigation() {
    const hamburger = document.getElementById('navHamburger');
    const navLinks = document.getElementById('navLinks');
    const links = navLinks?.querySelectorAll('.nav__link');
    const nav = document.getElementById('nav');

    if (!hamburger || !navLinks) return;

    // Toggle mobile menu
    hamburger.addEventListener('click', () => {
      const isOpen = hamburger.getAttribute('aria-expanded') === 'true';
      hamburger.setAttribute('aria-expanded', !isOpen);
      navLinks.classList.toggle('nav__links--open');
      document.body.style.overflow = isOpen ? '' : 'hidden';

      // Animate links stagger
      if (!isOpen && links) {
        links.forEach((link, i) => {
          link.style.transition = `opacity 0.4s ease, transform 0.4s ease`;
          link.style.transitionDelay = `${i * 0.08}s`;
          link.style.opacity = '1';
          link.style.transform = 'translateY(0)';
        });
      } else if (links) {
        links.forEach((link) => {
          link.style.transition = 'opacity 0.2s ease, transform 0.2s ease';
          link.style.transitionDelay = '0s';
          link.style.opacity = '';
          link.style.transform = '';
        });
      }
    });

    // Close menu on link click
    links?.forEach((link) => {
      link.addEventListener('click', () => {
        hamburger.setAttribute('aria-expanded', 'false');
        navLinks.classList.remove('nav__links--open');
        document.body.style.overflow = '';
        links.forEach((l) => {
          l.style.transition = 'opacity 0.2s ease, transform 0.2s ease';
          l.style.transitionDelay = '0s';
          l.style.opacity = '';
          l.style.transform = '';
        });
      });
    });

    // Nav hide/show on scroll
    let lastScroll = 0;

    window.addEventListener('scroll', () => {
      const currentScroll = window.scrollY;
      if (currentScroll > lastScroll && currentScroll > 100) {
        nav.classList.add('nav--hidden');
      } else {
        nav.classList.remove('nav--hidden');
      }
      lastScroll = currentScroll;
    }, { passive: true });

    // Active section indicator
    const sections = document.querySelectorAll('section[id]');
    const observer = new IntersectionObserver(
      (entries) => {
        entries.forEach((entry) => {
          if (entry.isIntersecting) {
            links?.forEach((link) => {
              link.classList.remove('nav__link--active');
              const href = link.getAttribute('href');
              if (href === `#${entry.target.id}`) {
                link.classList.add('nav__link--active');
              }
            });
          }
        });
      },
      { threshold: 0.3, rootMargin: '-80px 0px 0px 0px' }
    );

    sections.forEach((section) => observer.observe(section));
  },

  /* ----- SCROLL PROGRESS BAR ----- */
  scrollProgress() {
    const fill = document.getElementById('scrollProgressFill');
    const progressBar = document.querySelector('.scroll-progress');
    if (!fill) return;

    let ticking = false;

    const updateProgress = () => {
      const scrollTop = document.documentElement.scrollTop || document.body.scrollTop;
      const scrollHeight = Math.max(document.documentElement.scrollHeight - window.innerHeight, 1);
      const progress = Math.min(Math.max((scrollTop / scrollHeight) * 100, 0), 100);
      fill.style.width = `${progress}%`;
      if (progressBar) progressBar.setAttribute('aria-valuenow', String(Math.round(progress)));
      ticking = false;
    };

    window.addEventListener('scroll', () => {
      if (ticking) return;
      ticking = true;
      requestAnimationFrame(updateProgress);
    }, { passive: true });

    updateProgress();
  },

  /* ----- TYPING EFFECT ----- */
  typingEffect() {
    const el = document.getElementById('typingText');
    if (!el) return;

    const roles = [
      'Software Engineer',
      'Competitive Programmer',
      'AI Powered Developer',
      'Creative Problem Solver'
    ];

    let roleIndex = 0;
    let charIndex = 0;
    let isDeleting = false;
    let isPaused = false;

    function type() {
      if (isPaused) return;

      const currentRole = roles[roleIndex];

      if (isDeleting) {
        el.textContent = currentRole.substring(0, charIndex - 1);
        charIndex--;
      } else {
        el.textContent = currentRole.substring(0, charIndex + 1);
        charIndex++;
      }

      let delay = isDeleting ? 30 : 80;

      if (!isDeleting && charIndex === currentRole.length) {
        delay = 2000;
        isPaused = true;
        setTimeout(() => {
          isDeleting = true;
          isPaused = false;
          type();
        }, delay);
        return;
      }

      if (isDeleting && charIndex === 0) {
        isDeleting = false;
        roleIndex = (roleIndex + 1) % roles.length;
        delay = 500;
      }

      setTimeout(type, delay);
    }

    type();
  },

  /* ----- SPLIT TEXT (vanilla JS — no GSAP SplitText plugin) ----- */
  splitText() {
    const el = document.getElementById('heroNameText');
    if (!el) return;

    if (el.dataset.splitReady === 'true' && el.querySelector('.char')) {
      return el.querySelectorAll('.char');
    }

    const text = el.textContent;
    el.dataset.originalText = text;
    el.dataset.splitReady = 'true';
    const chars = text.split('');
    el.replaceChildren();
    el.setAttribute('aria-label', text);

    chars.forEach((char) => {
      const span = document.createElement('span');
      span.className = 'char';
      span.setAttribute('aria-hidden', 'true');
      span.textContent = char === ' ' ? '\u00A0' : char;
      el.appendChild(span);
    });

    return el.querySelectorAll('.char');
  },

  /* ----- CURRENT YEAR (footer) ----- */
  currentYear() {
    const yearEl = document.getElementById('currentYear');
    if (yearEl) {
      yearEl.textContent = new Date().getFullYear().toString();
    }
  },

  /* ----- SCROLL INDICATOR FADE ----- */
  scrollIndicator() {
    const indicator = document.getElementById('scrollIndicator');
    if (!indicator) return;

    let ticking = false;
    window.addEventListener('scroll', () => {
      if (!ticking) {
        requestAnimationFrame(() => {
          if (window.scrollY > 100) {
            indicator.style.opacity = '0';
            indicator.style.pointerEvents = 'none';
          } else {
            indicator.style.opacity = '1';
            indicator.style.pointerEvents = '';
          }
          ticking = false;
        });
        ticking = true;
      }
    }, { passive: true });
  },

  /* ----- BACK TO TOP ----- */
  backToTop() {
    const btn = document.getElementById('backToTop');
    if (!btn) return;

    btn.addEventListener('click', () => {
      window.scrollTo({ top: 0, behavior: 'smooth' });
    });
  },

  /* ----- SMOOTH SCROLL (anchor links) ----- */
  smoothScroll() {
    document.querySelectorAll('a[href^="#"]').forEach((anchor) => {
      anchor.addEventListener('click', (e) => {
        const targetId = anchor.getAttribute('href');
        if (targetId === '#') return;
        const target = document.querySelector(targetId);
        if (target) {
          e.preventDefault();
          const offset = 80;
          const top = target.getBoundingClientRect().top + window.scrollY - offset;
          window.scrollTo({ top, behavior: 'smooth' });
        }
      });
    });
  },

  /* ----- CONTACT FORM ----- */
  contactForm() {
    const form = document.getElementById('contactForm');
    if (!form) return;

    const nameInput = document.getElementById('formName');
    const emailInput = document.getElementById('formEmail');
    const messageInput = document.getElementById('formMessage');
    const nameError = document.getElementById('formNameError');
    const emailError = document.getElementById('formEmailError');
    const messageError = document.getElementById('formMessageError');
    const submitBtn = form.querySelector('.contact__submit');
    const successMsg = document.getElementById('contactSuccess');

    function showError(input, errorEl, message) {
      errorEl.textContent = message;
      errorEl.classList.add('contact__error--visible');
      input.style.borderColor = '#ef4444';
      input.setAttribute('aria-invalid', 'true');
    }

    function clearError(input, errorEl) {
      errorEl.textContent = '';
      errorEl.classList.remove('contact__error--visible');
      input.style.borderColor = '';
      input.removeAttribute('aria-invalid');
    }

    function validate() {
      let isValid = true;

      if (!nameInput.value.trim()) {
        showError(nameInput, nameError, 'Please enter your name');
        isValid = false;
      } else {
        clearError(nameInput, nameError);
      }

      if (!emailInput.value.trim()) {
        showError(emailInput, emailError, 'Please enter your email');
        isValid = false;
      } else if (!/^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(emailInput.value)) {
        showError(emailInput, emailError, 'Please enter a valid email');
        isValid = false;
      } else {
        clearError(emailInput, emailError);
      }

      if (!messageInput.value.trim()) {
        showError(messageInput, messageError, 'Please enter your message');
        isValid = false;
      } else if (messageInput.value.trim().length < 10) {
        showError(messageInput, messageError, 'Message must be at least 10 characters');
        isValid = false;
      } else {
        clearError(messageInput, messageError);
      }

      return isValid;
    }

    form.addEventListener('submit', (e) => {
      e.preventDefault();

      if (!validate()) return;

      // Loading state
      submitBtn.classList.add('contact__submit--loading');
      submitBtn.disabled = true;

      // Simulate send (no backend — just demo)
      setTimeout(() => {
        submitBtn.classList.remove('contact__submit--loading');
        submitBtn.classList.add('contact__submit--success');

        setTimeout(() => {
          submitBtn.classList.remove('contact__submit--success');
          submitBtn.disabled = false;
          form.reset();
          successMsg.hidden = false;
          successMsg.focus();
        }, 1500);
      }, 2000);
    });

    // Real-time validation on blur
    nameInput.addEventListener('blur', () => {
      if (nameInput.value.trim()) clearError(nameInput, nameError);
    });
    emailInput.addEventListener('blur', () => {
      if (emailInput.value.trim() && /^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(emailInput.value)) {
        clearError(emailInput, emailError);
      }
    });
    messageInput.addEventListener('blur', () => {
      if (messageInput.value.trim().length >= 10) clearError(messageInput, messageError);
    });
  },

  /* ----- COPY EMAIL ----- */
  copyEmail() {
    const btn = document.getElementById('copyEmailBtn');
    const tooltip = document.getElementById('copyTooltip');
    if (!btn || !tooltip) return;

    const email = 'hello@kaesarz.dev';

    btn.addEventListener('click', async () => {
      try {
        await navigator.clipboard.writeText(email);
        tooltip.classList.add('contact__copy-tooltip--visible');
        setTimeout(() => {
          tooltip.classList.remove('contact__copy-tooltip--visible');
        }, 2000);
      } catch {
        // Fallback
        const textarea = document.createElement('textarea');
        textarea.value = email;
        document.body.appendChild(textarea);
        textarea.select();
        document.execCommand('copy');
        document.body.removeChild(textarea);
        tooltip.classList.add('contact__copy-tooltip--visible');
        setTimeout(() => {
          tooltip.classList.remove('contact__copy-tooltip--visible');
        }, 2000);
      }
    });
  },

  /* ----- INIT ANIMATE (data-animate observer) ----- */
  initAnimate() {
    const els = document.querySelectorAll('[data-animate]');

    if (!els.length) return;

    const observer = new IntersectionObserver(
      (entries) => {
        entries.forEach((entry) => {
          if (entry.isIntersecting) {
            entry.target.classList.add('animated');
            observer.unobserve(entry.target);
          }
        });
      },
      { threshold: 0.15, rootMargin: '0px 0px -50px 0px' }
    );

    els.forEach((el) => observer.observe(el));
  }
};


/* ----- INIT ON DOM READY ----- */
document.addEventListener('DOMContentLoaded', () => {
  App.init();
});
