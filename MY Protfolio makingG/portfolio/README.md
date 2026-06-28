# Kaesarz — Kawsar Hoque | Portfolio

> An award-winning cinematic portfolio built with pure HTML, CSS, JavaScript, Three.js, GSAP, and Lenis.

## Tech Stack

| Technology | Purpose |
|---|---|
| **HTML5** | Semantic structure, accessibility |
| **CSS3** | Design system, glassmorphism, animations, responsive |
| **JavaScript ES6+** | App logic, cursor, typing, form validation |
| **Three.js** | 3D particle star field, floating geometries, bloom |
| **GSAP** | Scroll-triggered animations, stagger reveals, smooth transitions |
| **Lenis** | Premium smooth scrolling with easing |

## Features

- Interactive 3D particle background with mouse-reactive lighting
- Custom cursor with magnetic hover effects
- Glassmorphism design system
- Typing animation with role rotation
- Animated skill cards with 3D tilt
- Project cards with spotlight and gradient borders
- Dynamic GitHub profile and repository fetching
- Codeforces rating integration via API
- Fully responsive (mobile-first)
- Dark theme with blue/cyan accent palette
- 60 FPS performance with mobile fallbacks
- WCAG accessible

## Sections

1. **Hero** — Animated introduction with typing effect, profile image, CTA
2. **About** — Biography with badges and visual orb
3. **Skills** — Categorized skill grid with glass cards
4. **Projects** — 3 interactive project cards with hover effects
5. **GitHub** — Live profile data and repository cards from GitHub API
6. **Competitive Programming** — Codeforces + CodeChef profile cards
7. **Contact** — Validated form with social links and copy-email
8. **Footer** — Brand, navigation, back to top

## Setup

### 1. Clone or download

```bash
git clone https://github.com/Kaesarz-Hawk/portfolio.git
cd portfolio
```

### 2. Serve locally

Use any static file server:

```bash
# Python
python -m http.server 3000

# Node (npx)
npx serve .

# VS Code Live Server extension
```

### 3. Open in browser

Navigate to `http://localhost:3000`

## Project Structure

```
portfolio/
├── index.html              # Main HTML
├── css/
│   ├── style.css           # Design system & components
│   ├── animations.css      # Keyframes & transitions
│   └── responsive.css      # Breakpoints & fallbacks
├── js/
│   ├── main.js             # App orchestrator
│   ├── animations.js       # GSAP + Lenis config
│   ├── cursor.js           # Custom cursor logic
│   ├── particles.js        # Canvas 2D particles (fallback)
│   ├── threeScene.js       # Three.js 3D scene
│   └── api.js              # GitHub & Codeforces API
├── assets/
│   ├── images/
│   ├── icons/
│   └── fonts/
└── README.md
```

## Configuration

Edit `js/api.js` to update:

- `githubUser` — Your GitHub username
- `cfHandle` — Your Codeforces handle
- `ccUser` — Your CodeChef username

Edit `index.html` to update:

- Social media links in the Contact section
- Email address (current: `hello@kaesarz.dev`)
- Profile image

## Performance

- Three.js particle count reduces on tablet (8k), disabled on mobile
- GSAP animations simplify on mobile
- Custom cursor hidden on touch devices
- Reduced motion media query supported
- Lazy loading ready for images

## Browser Support

- Chrome 90+
- Firefox 90+
- Safari 15+
- Edge 90+

## Build Notes

- No frameworks (no React, no Vue, no Angular)
- No templates
- No paid GSAP plugins (all effects recreated with vanilla JS + free GSAP)
- Zero fake data — all API-fetched content
