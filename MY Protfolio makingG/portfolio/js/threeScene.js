/* ============================================================
   THREESCENE.JS — Production Three.js Background
   Kaesarz Portfolio | Kawsar Hoque
   ============================================================
   Starfield | Floating Particles | Volumetric Lighting
   Floating Geometries | Mouse-Reactive Camera | Bloom
   Graceful degradation on mobile / low-end devices.
   ============================================================ */

const ThreeScene = {
  scene: null,
  camera: null,
  renderer: null,
  composer: null,
  clock: null,

  stars: null,
  particleField: null,
  geometries: [],
  lights: [],

  isActive: false,
  isLowEnd: false,
  container: null,
  animationId: null,

  mouse: { x: 0, y: 0 },
  target: { x: 0, y: 0 },
  current: { x: 0, y: 0 },
  handleMouseMove: null,
  handleResize: null,
  handleComposerResize: null,

  /* ----- INIT ----- */
  init() {
    this.container = document.getElementById('three-container');
    if (!this.container) return;

    if (typeof THREE === 'undefined') {
      console.warn('[ThreeScene] THREE not loaded.');
      return;
    }

    this.detectPerformance();

    // Disable entirely on small mobile
    if (window.innerWidth < 480) return;

    this.isActive = true;
    this.clock = new THREE.Clock();

    this.createScene();
    this.createCamera();
    this.createRenderer();
    this.createLights();
    this.createStarfield();
    this.createParticleField();
    this.createGeometries();
    if (!this.isLowEnd) this.createBloom();
    this.bindEvents();
    this.animate();
  },

  /* ----- DETECT LOW-END DEVICES ----- */
  detectPerformance() {
    const cores = navigator.hardwareConcurrency || 4;
    const memory = navigator.deviceMemory || 4;
    const isMobile = /Mobi|Android|iPhone/i.test(navigator.userAgent);

    this.isLowEnd = cores <= 4 || memory <= 2 || isMobile;
  },

  /* ----- SCENE ----- */
  createScene() {
    this.scene = new THREE.Scene();
    this.scene.background = new THREE.Color(0x050505);
    this.scene.fog = new THREE.FogExp2(0x050505, this.isLowEnd ? 0.003 : 0.0018);
  },

  /* ----- CAMERA ----- */
  createCamera() {
    this.camera = new THREE.PerspectiveCamera(
      75,
      window.innerWidth / window.innerHeight,
      0.1,
      100
    );
    this.camera.position.set(0, 0, 6);
  },

  /* ----- RENDERER ----- */
  createRenderer() {
    this.renderer = new THREE.WebGLRenderer({
      alpha: false,
      antialias: !this.isLowEnd,
      powerPreference: 'high-performance',
    });
    this.renderer.setSize(window.innerWidth, window.innerHeight);
    this.renderer.setPixelRatio(Math.min(window.devicePixelRatio, this.isLowEnd ? 1 : 2));
    this.renderer.toneMapping = THREE.ACESFilmicToneMapping;
    this.renderer.toneMappingExposure = 1.0;
    this.renderer.outputEncoding = THREE.sRGBEncoding;
    this.container.appendChild(this.renderer.domElement);
  },

  /* ----- LIGHTS (volumetric feel) ----- */
  createLights() {
    const ambient = new THREE.AmbientLight(0x111122, 0.3);
    this.scene.add(ambient);

    // Blue key light
    const keyLight = new THREE.PointLight(0x0066ff, 2, 15);
    keyLight.position.set(-4, 3, 4);
    this.scene.add(keyLight);

    // Cyan fill light
    const fillLight = new THREE.PointLight(0x00d4ff, 1, 15);
    fillLight.position.set(4, -2, 3);
    this.scene.add(fillLight);

    // Silver accent
    const rimLight = new THREE.PointLight(0x8888ff, 0.5, 10);
    rimLight.position.set(0, -5, -5);
    this.scene.add(rimLight);

    this.lights = [keyLight, fillLight, rimLight];
  },

  /* ----- STARFIELD (procedural) ----- */
  createStarfield() {
    const count = this.isLowEnd ? 4000 : 12000;
    const geometry = new THREE.BufferGeometry();
    const positions = new Float32Array(count * 3);
    const sizes = new Float32Array(count);
    const colors = new Float32Array(count * 3);

    const colorBlue = new THREE.Color(0x0066ff);
    const colorCyan = new THREE.Color(0x00d4ff);
    const colorWhite = new THREE.Color(0xffffff);
    const colorSilver = new THREE.Color(0xc0c0c0);

    for (let i = 0; i < count; i++) {
      const radius = 10 + Math.random() * 30;
      const theta = Math.random() * Math.PI * 2;
      const phi = Math.acos(2 * Math.random() - 1);

      positions[i * 3] = radius * Math.sin(phi) * Math.cos(theta);
      positions[i * 3 + 1] = radius * Math.sin(phi) * Math.sin(theta);
      positions[i * 3 + 2] = radius * Math.cos(phi);

      sizes[i] = 0.1 + Math.random() * 0.4;

      const colorChoice = Math.random();
      const color = colorChoice < 0.15 ? colorBlue
        : colorChoice < 0.25 ? colorCyan
        : colorChoice < 0.4 ? colorSilver
        : colorWhite;
      colors[i * 3] = color.r;
      colors[i * 3 + 1] = color.g;
      colors[i * 3 + 2] = color.b;
    }

    geometry.setAttribute('position', new THREE.BufferAttribute(positions, 3));
    geometry.setAttribute('size', new THREE.BufferAttribute(sizes, 1));
    geometry.setAttribute('color', new THREE.BufferAttribute(colors, 3));

    // Twinkle via custom ShaderMaterial
    const material = new THREE.ShaderMaterial({
      uniforms: {
        uTime: { value: 0 },
        uPixelRatio: { value: this.renderer.getPixelRatio() },
      },
      vertexShader: `
        attribute float size;
        attribute vec3 color;
        varying vec3 vColor;
        uniform float uTime;
        uniform float uPixelRatio;

        void main() {
          vColor = color;
          vec4 mvPosition = modelViewMatrix * vec4(position, 1.0);
          float twinkle = 0.6 + 0.4 * sin(uTime * 0.5 + position.x * 2.0 + position.y * 3.0 + position.z * 1.5);
          gl_PointSize = size * uPixelRatio * (200.0 / -mvPosition.z) * twinkle;
          gl_Position = projectionMatrix * mvPosition;
        }
      `,
      fragmentShader: `
        varying vec3 vColor;

        void main() {
          float d = distance(gl_PointCoord, vec2(0.5));
          if (d > 0.5) discard;
          float alpha = 1.0 - smoothstep(0.0, 0.5, d);
          alpha *= alpha;
          gl_FragColor = vec4(vColor, alpha);
        }
      `,
      transparent: true,
      blending: THREE.AdditiveBlending,
      depthWrite: false,
    });

    this.stars = new THREE.Points(geometry, material);
    this.scene.add(this.stars);
  },

  /* ----- PARTICLE FIELD (floating dust) ----- */
  createParticleField() {
    const count = this.isLowEnd ? 200 : 600;
    const geometry = new THREE.BufferGeometry();
    const positions = new Float32Array(count * 3);
    const velocities = [];

    for (let i = 0; i < count; i++) {
      positions[i * 3] = (Math.random() - 0.5) * 12;
      positions[i * 3 + 1] = (Math.random() - 0.5) * 8;
      positions[i * 3 + 2] = (Math.random() - 0.5) * 6 - 2;

      velocities.push({
        x: (Math.random() - 0.5) * 0.002,
        y: (Math.random() - 0.5) * 0.002,
        z: (Math.random() - 0.5) * 0.002,
      });
    }

    geometry.setAttribute('position', new THREE.BufferAttribute(positions, 3));

    const material = new THREE.PointsMaterial({
      color: 0x0066ff,
      size: 0.015,
      transparent: true,
      opacity: 0.4,
      blending: THREE.AdditiveBlending,
      depthWrite: false,
      sizeAttenuation: true,
    });

    this.particleField = new THREE.Points(geometry, material);
    this.particleField.userData.velocities = velocities;
    this.scene.add(this.particleField);
  },

  /* ----- FLOATING GEOMETRIES ----- */
  createGeometries() {
    const geoConfigs = this.isLowEnd
      ? [
          { type: 'octahedron', size: 0.4, color: 0x0066ff, pos: [0, 0.5, -1.5], rotSpeed: 0.003 },
        ]
      : [
          { type: 'octahedron', size: 0.6, color: 0x0066ff, pos: [-2.5, 1.2, -2], rotSpeed: 0.005 },
          { type: 'torusKnot', size: 0.5, color: 0x00d4ff, pos: [2.8, -0.8, -3], rotSpeed: 0.008 },
          { type: 'icosahedron', size: 0.5, color: 0x4488ff, pos: [0, -1.5, -4], rotSpeed: 0.004 },
          { type: 'octahedron', size: 0.35, color: 0x6666ff, pos: [-3, -1, -1.5], rotSpeed: 0.006 },
          { type: 'icosahedron', size: 0.3, color: 0x44ddff, pos: [3.5, 1.5, -1], rotSpeed: 0.007 },
        ];

    geoConfigs.forEach((cfg) => {
      let geometry;
      switch (cfg.type) {
        case 'octahedron':
          geometry = new THREE.OctahedronGeometry(cfg.size);
          break;
        case 'torusKnot':
          geometry = new THREE.TorusKnotGeometry(cfg.size * 0.8, cfg.size * 0.3, 64, 8);
          break;
        case 'icosahedron':
          geometry = new THREE.IcosahedronGeometry(cfg.size);
          break;
        default:
          geometry = new THREE.OctahedronGeometry(cfg.size);
      }

      const material = new THREE.MeshPhysicalMaterial({
        color: cfg.color,
        emissive: cfg.color,
        emissiveIntensity: 0.08,
        metalness: 0.3,
        roughness: 0.2,
        transparent: true,
        opacity: 0.35,
        wireframe: cfg.type === 'icosahedron',
        envMapIntensity: 0.5,
      });

      const mesh = new THREE.Mesh(geometry, material);
      mesh.position.set(cfg.pos[0], cfg.pos[1], cfg.pos[2]);
      mesh.userData = {
        rotSpeed: cfg.rotSpeed,
        floatAmplitude: 0.15 + Math.random() * 0.1,
        floatSpeed: 0.3 + Math.random() * 0.2,
        initialY: cfg.pos[1],
        phase: Math.random() * Math.PI * 2,
      };

      this.scene.add(mesh);
      this.geometries.push(mesh);
    });
  },

  /* ----- BLOOM POST-PROCESSING ----- */
  createBloom() {
    const deps = [
      THREE.EffectComposer,
      THREE.RenderPass,
      THREE.UnrealBloomPass,
      THREE.CopyShader,
      THREE.ShaderPass,
    ];

    const missing = deps.filter((d) => typeof d === 'undefined');
    if (missing.length) {
      console.warn('[ThreeScene] Bloom deps missing — skipping.');
      return;
    }

    try {
      this.composer = new THREE.EffectComposer(this.renderer);
      this.composer.addPass(new THREE.RenderPass(this.scene, this.camera));

      const bloomPass = new THREE.UnrealBloomPass(
        new THREE.Vector2(window.innerWidth, window.innerHeight),
        0.3,
        0.5,
        0.1
      );
      this.composer.addPass(bloomPass);

      this.handleComposerResize = () => {
        this.composer.setSize(window.innerWidth, window.innerHeight);
      };
      window.addEventListener('resize', this.handleComposerResize);
    } catch (e) {
      console.warn('[ThreeScene] Bloom init failed:', e.message);
      this.composer = null;
    }
  },

  /* ----- MOUSE + EVENTS ----- */
  bindEvents() {
    this.handleMouseMove = (e) => {
      this.mouse.x = (e.clientX / window.innerWidth) * 2 - 1;
      this.mouse.y = -(e.clientY / window.innerHeight) * 2 + 1;
    };
    document.addEventListener('mousemove', this.handleMouseMove, { passive: true });

    this.handleResize = () => this.onResize();
    window.addEventListener('resize', this.handleResize, { passive: true });
  },

  onResize() {
    if (!this.camera || !this.renderer) return;

    const w = window.innerWidth;
    const h = window.innerHeight;

    this.camera.aspect = w / h;
    this.camera.updateProjectionMatrix();
    this.renderer.setSize(w, h);

    if (this.composer && this.handleComposerResize) {
      try { this.composer.setSize(w, h); } catch (e) { /* ignore */ }
    }
  },

  /* ----- ANIMATION LOOP ----- */
  animate() {
    if (!this.isActive) return;

    this.animationId = requestAnimationFrame(() => this.animate());

    const elapsed = this.clock.getElapsedTime();
    this.clock.getDelta();

    // Smooth mouse lerp
    this.target.x += (this.mouse.x - this.target.x) * 0.05;
    this.target.y += (this.mouse.y - this.target.y) * 0.05;

    // Camera follows mouse subtly
    this.camera.position.x += (this.target.x * 0.3 - this.camera.position.x) * 0.02;
    this.camera.position.y += (this.target.y * 0.2 - this.camera.position.y) * 0.02;
    this.camera.lookAt(0, 0, 0);

    // Update starfield twinkle
    if (this.stars) {
      this.stars.material.uniforms.uTime.value = elapsed;
    }

    // Animate particle field drift
    if (this.particleField) {
      const pos = this.particleField.geometry.attributes.position;
      const vel = this.particleField.userData.velocities;
      for (let i = 0; i < pos.count; i++) {
        pos.array[i * 3] += vel[i].x;
        pos.array[i * 3 + 1] += vel[i].y;
        pos.array[i * 3 + 2] += vel[i].z;

        // Wrap around
        if (Math.abs(pos.array[i * 3]) > 6) vel[i].x *= -1;
        if (Math.abs(pos.array[i * 3 + 1]) > 4) vel[i].y *= -1;
        if (pos.array[i * 3 + 2] > 4 || pos.array[i * 3 + 2] < -6) vel[i].z *= -1;
      }
      pos.needsUpdate = true;
    }

    // Animate floating geometries
    this.geometries.forEach((mesh) => {
      const ud = mesh.userData;
      mesh.rotation.x += ud.rotSpeed * 0.6;
      mesh.rotation.y += ud.rotSpeed;
      mesh.rotation.z += ud.rotSpeed * 0.3;
      mesh.position.y = ud.initialY + Math.sin(elapsed * ud.floatSpeed + ud.phase) * ud.floatAmplitude;
    });

    // Animate lights subtly with mouse
    if (this.lights.length >= 2) {
      this.lights[0].position.x = -4 + this.target.x * 1.5;
      this.lights[0].position.y = 3 + this.target.y * 1;
      this.lights[1].position.x = 4 - this.target.x * 1;
      this.lights[1].position.y = -2 - this.target.y * 0.8;
    }

    // Render
    if (this.composer) {
      this.composer.render();
    } else if (this.renderer && this.scene && this.camera) {
      this.renderer.render(this.scene, this.camera);
    }
  },

  /* ----- DESTROY (cleanup) ----- */
  destroy() {
    this.isActive = false;
    if (this.animationId) {
      cancelAnimationFrame(this.animationId);
      this.animationId = null;
    }

    this.geometries.forEach((mesh) => {
      if (mesh.geometry) mesh.geometry.dispose();
      if (mesh.material) mesh.material.dispose();
    });
    this.geometries = [];

    if (this.stars) {
      this.stars.geometry.dispose();
      this.stars.material.dispose();
    }
    if (this.particleField) {
      this.particleField.geometry.dispose();
      this.particleField.material.dispose();
    }
    if (this.renderer) {
      this.renderer.dispose();
      if (this.renderer.domElement.parentNode) {
        this.renderer.domElement.parentNode.removeChild(this.renderer.domElement);
      }
    }
    if (this.handleMouseMove) {
      document.removeEventListener('mousemove', this.handleMouseMove);
      this.handleMouseMove = null;
    }
    if (this.handleResize) {
      window.removeEventListener('resize', this.handleResize);
      this.handleResize = null;
    }
    if (this.handleComposerResize) {
      window.removeEventListener('resize', this.handleComposerResize);
      this.handleComposerResize = null;
    }
  },
};


/* ----- INIT ----- */
document.addEventListener('DOMContentLoaded', () => {
  ThreeScene.init();
});
