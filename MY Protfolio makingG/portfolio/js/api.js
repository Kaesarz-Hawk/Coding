/* ============================================================
   API.JS — GitHub & Codeforces API Fetching
   Kaesarz Portfolio | Kawsar Hoque
   ============================================================
   NOTE: This file will be fully implemented in Phase 11 & 12.
   Currently a skeleton that fetches GitHub profile data
   and populates the GitHub section.
   ============================================================ */

const API = {
  githubUser: 'Kaesarz-Hawk',
  cfHandle: 'Kaesarz.exe',

  elements: {},
  githubRequestId: 0,

  async init() {
    this.cacheElements();
    this.bindEvents();
    await this.fetchGitHub();
    await this.fetchCodeforces();
  },

  cacheElements() {
    this.elements = {
      githubLoadingState: document.getElementById('githubLoadingState'),
      githubErrorState: document.getElementById('githubErrorState'),
      githubRetryBtn: document.getElementById('githubRetryBtn'),
      githubProfile: document.getElementById('githubProfile'),
      githubProfileLink: document.getElementById('githubProfileLink'),
      githubLastFetched: document.getElementById('githubLastFetched'),
      githubAvatar: document.getElementById('githubAvatar'),
      githubName: document.getElementById('githubName'),
      githubBio: document.getElementById('githubBio'),
      githubRepos: document.getElementById('githubRepos'),
      githubFollowers: document.getElementById('githubFollowers'),
      githubFollowing: document.getElementById('githubFollowing'),
      githubLanguageBadges: document.getElementById('githubLanguageBadges'),
      githubReposGrid: document.getElementById('githubReposGrid'),
      githubLangBar: document.getElementById('githubLangBar'),
      githubReposContainer: document.getElementById('githubReposContainer'),
      githubLanguages: document.getElementById('githubLanguages'),
      cfRating: document.getElementById('cfRating'),
      cfMaxRating: document.getElementById('cfMaxRating'),
      cfRank: document.getElementById('cfRank'),
      cfPending: document.getElementById('cfPending'),
      cfArcFill: document.getElementById('cfArcFill'),
      cfStats: document.getElementById('cfStats'),
    };
  },

  bindEvents() {
    if (this.elements.githubRetryBtn) {
      this.elements.githubRetryBtn.addEventListener('click', () => {
        this.fetchGitHub();
      });
    }
  },

  setGitHubLoading() {
    const {
      githubLoadingState,
      githubErrorState,
      githubProfile,
      githubReposContainer,
      githubLanguages,
      githubReposGrid,
      githubLangBar,
      githubLanguageBadges,
      githubName,
      githubBio,
      githubRepos,
      githubFollowers,
      githubFollowing,
      githubLastFetched,
    } = this.elements;

    if (githubLoadingState) githubLoadingState.hidden = false;
    if (githubErrorState) githubErrorState.hidden = true;
    if (githubProfile) githubProfile.hidden = true;
    if (githubReposContainer) githubReposContainer.hidden = true;
    if (githubLanguages) githubLanguages.hidden = true;

    if (githubName) githubName.textContent = 'Kaesarz-Hawk';
    if (githubBio) githubBio.textContent = 'Loading GitHub data...';
    if (githubRepos) githubRepos.textContent = '—';
    if (githubFollowers) githubFollowers.textContent = '—';
    if (githubFollowing) githubFollowing.textContent = '—';
    if (githubLastFetched) githubLastFetched.textContent = 'Waiting for live data';

    if (githubReposGrid) {
      githubReposGrid.innerHTML = this.buildRepoSkeletons();
    }

    if (githubLangBar) {
      githubLangBar.innerHTML = '<p class="github__loading">Loading language badges...</p>';
    }

    if (githubLanguageBadges) {
      githubLanguageBadges.innerHTML = '<span class="github__badge github__badge--loading">Loading badges...</span>';
    }
  },

  showGitHubError(message) {
    const {
      githubLoadingState,
      githubErrorState,
      githubProfile,
      githubReposContainer,
      githubLanguages,
      githubBio,
      githubLastFetched,
    } = this.elements;

    if (githubLoadingState) githubLoadingState.hidden = true;
    if (githubErrorState) githubErrorState.hidden = false;
    if (githubProfile) githubProfile.hidden = true;
    if (githubReposContainer) githubReposContainer.hidden = true;
    if (githubLanguages) githubLanguages.hidden = true;

    if (githubErrorState) {
      const errorText = githubErrorState.querySelector('.github__state-text');
      if (errorText) errorText.textContent = message;
    }
    if (githubBio) githubBio.textContent = 'GitHub data temporarily unavailable.';
    if (githubLastFetched) githubLastFetched.textContent = 'Live data unavailable right now.';
  },

  showGitHubContent() {
    const { githubLoadingState, githubErrorState, githubProfile, githubReposContainer, githubLanguages } = this.elements;

    if (githubLoadingState) githubLoadingState.hidden = true;
    if (githubErrorState) githubErrorState.hidden = true;
    if (githubProfile) githubProfile.hidden = false;
    if (githubReposContainer) githubReposContainer.hidden = false;
    if (githubLanguages) githubLanguages.hidden = false;
  },

  async fetchGitHub() {
    const requestId = ++this.githubRequestId;
    this.setGitHubLoading();

    try {
      const [userRes, reposRes] = await Promise.all([
        fetch(`https://api.github.com/users/${this.githubUser}`, {
          headers: {
            Accept: 'application/vnd.github+json',
            'X-GitHub-Api-Version': '2022-11-28',
          },
        }),
        fetch(`https://api.github.com/users/${this.githubUser}/repos?type=public&sort=updated&per_page=100`, {
          headers: {
            Accept: 'application/vnd.github+json',
            'X-GitHub-Api-Version': '2022-11-28',
          },
        }),
      ]);

      if (!userRes.ok) throw new Error(`GitHub profile request failed with ${userRes.status}`);
      if (!reposRes.ok) throw new Error(`GitHub repository request failed with ${reposRes.status}`);

      const [userData, reposData] = await Promise.all([userRes.json(), reposRes.json()]);
      if (requestId !== this.githubRequestId) return;

      const repos = Array.isArray(reposData)
        ? reposData.filter((repo) => !repo.fork).sort((a, b) => new Date(b.updated_at) - new Date(a.updated_at))
        : [];

      this.renderGitHubProfile(userData);
      this.renderGitHubRepos(repos.slice(0, 6));
      this.renderGitHubLanguageBadges(repos);
      this.showGitHubContent();
      this.updateGitHubSummary(userData, repos);
    } catch (error) {
      console.warn('[API] GitHub fetch failed:', error.message);
      if (requestId !== this.githubRequestId) return;
      this.showGitHubError('The GitHub API could not be reached. Retry to load the live profile again.');
    }
  },

  renderGitHubProfile(userData) {
    const {
      githubProfileLink,
      githubAvatar,
      githubName,
      githubBio,
      githubRepos,
      githubFollowers,
      githubFollowing,
    } = this.elements;

    if (githubProfileLink) githubProfileLink.href = userData.html_url || `https://github.com/${this.githubUser}`;
    if (githubAvatar && userData.avatar_url) githubAvatar.src = userData.avatar_url;
    if (githubAvatar && userData.name) githubAvatar.alt = `${userData.name} avatar`;
    if (githubName) githubName.textContent = userData.name || userData.login || this.githubUser;
    if (githubBio) githubBio.textContent = userData.bio || 'No public bio available.';
    if (githubRepos) githubRepos.textContent = String(userData.public_repos ?? '—');
    if (githubFollowers) githubFollowers.textContent = String(userData.followers ?? '—');
    if (githubFollowing) githubFollowing.textContent = String(userData.following ?? '—');
  },

  renderGitHubRepos(repos) {
    const { githubReposGrid } = this.elements;
    if (!githubReposGrid) return;

    githubReposGrid.innerHTML = '';

    if (!repos.length) {
      githubReposGrid.innerHTML = '<p class="github__loading">No public repositories found.</p>';
      return;
    }

    repos.forEach((repo) => {
      githubReposGrid.appendChild(this.createRepoCard(repo));
    });
  },

  createRepoCard(repo) {
    const card = document.createElement('a');
    card.href = repo.html_url;
    card.target = '_blank';
    card.rel = 'noopener noreferrer';
    card.className = 'github__repo-card';
    card.setAttribute('data-cursor', 'magnetic');

    const header = document.createElement('div');
    header.className = 'github__repo-header';

    const title = document.createElement('h4');
    title.className = 'github__repo-name';
    title.textContent = repo.name;

    const stars = document.createElement('span');
    stars.className = 'github__repo-stars';
    stars.textContent = `★ ${repo.stargazers_count ?? 0}`;

    header.append(title, stars);

    const description = document.createElement('p');
    description.className = 'github__repo-desc';
    description.textContent = repo.description || 'No description available.';

    const footer = document.createElement('div');
    footer.className = 'github__repo-footer';

    const language = document.createElement('span');
    language.className = 'github__repo-lang';

    const dot = document.createElement('span');
    dot.className = 'github__repo-lang-dot';
    dot.style.background = this.getLanguageColor(repo.language);

    const languageName = document.createElement('span');
    languageName.textContent = repo.language || 'N/A';

    language.append(dot, languageName);

    const updated = document.createElement('span');
    updated.className = 'github__repo-updated';
    updated.textContent = `Updated ${this.formatDate(repo.updated_at)}`;

    const forkCount = document.createElement('span');
    forkCount.className = 'github__repo-forks';
    forkCount.textContent = `⑂ ${repo.forks_count ?? 0}`;

    footer.append(language, updated, forkCount);

    card.append(header, description, footer);
    return card;
  },

  renderGitHubLanguageBadges(repos) {
    const counts = new Map();

    repos.forEach((repo) => {
      if (!repo.language) return;
      counts.set(repo.language, (counts.get(repo.language) || 0) + 1);
    });

    const topLanguages = Array.from(counts.entries())
      .sort((a, b) => b[1] - a[1])
      .slice(0, 6);

    const containers = [this.elements.githubLanguageBadges, this.elements.githubLangBar];

    containers.forEach((container) => {
      if (!container) return;
      container.innerHTML = '';

      if (!topLanguages.length) {
        container.innerHTML = '<p class="github__loading">No language data available.</p>';
        return;
      }

      topLanguages.forEach(([language, count]) => {
        const badge = document.createElement('span');
        badge.className = 'github__badge';

        const dot = document.createElement('span');
        dot.className = 'github__badge-dot';
        dot.style.background = this.getLanguageColor(language);

        const label = document.createElement('span');
        label.textContent = `${language} · ${count}`;

        badge.append(dot, label);
        container.appendChild(badge);
      });
    });
  },

  updateGitHubSummary(userData, repos) {
    const { githubLastFetched } = this.elements;
    if (!githubLastFetched) return;

    const latestRepo = repos[0];
    const updatedLabel = latestRepo ? `Latest repo updated ${this.formatDate(latestRepo.updated_at)}` : 'No public repositories found';
    githubLastFetched.textContent = `${updatedLabel} · Live from GitHub REST API`;
  },

  buildRepoSkeletons() {
    return Array.from({ length: 3 }, (_, index) => `
      <div class="github__repo-card github__repo-card--skeleton" aria-hidden="true">
        <div class="github__skeleton github__skeleton--title"></div>
        <div class="github__skeleton github__skeleton--line"></div>
        <div class="github__skeleton github__skeleton--line github__skeleton--short"></div>
        <div class="github__skeleton-row">
          <div class="github__skeleton github__skeleton--pill"></div>
          <div class="github__skeleton github__skeleton--pill"></div>
        </div>
      </div>
    `).join('');
  },

  formatDate(dateValue) {
    if (!dateValue) return 'recently';

    return new Intl.DateTimeFormat('en', {
      month: 'short',
      day: 'numeric',
      year: 'numeric',
    }).format(new Date(dateValue));
  },

  /* ----- GITHUB LANGUAGE COLORS ----- */
  getLanguageColor(lang) {
    const colors = {
      JavaScript: '#f1e05a',
      Python: '#3572A5',
      HTML: '#e34c26',
      CSS: '#563d7c',
      Java: '#b07219',
      'C++': '#f34b7d',
      C: '#555555',
      TypeScript: '#3178c6',
      Shell: '#89e051',
      PHP: '#4F5D95',
      Ruby: '#701516',
      Swift: '#ffac45',
      Kotlin: '#F18E33',
      Go: '#00ADD8',
      Rust: '#dea584',
    };

    return colors[lang] || 'var(--text-tertiary)';
  },

  /* ----- CODEFORCES ----- */
  async fetchCodeforces() {
    const ratingEl = this.elements.cfRating;
    const maxRatingEl = this.elements.cfMaxRating;
    const rankEl = this.elements.cfRank;
    const pendingEl = this.elements.cfPending;
    const arcFill = this.elements.cfArcFill;
    const stats = this.elements.cfStats;

    if (pendingEl) pendingEl.textContent = 'Fetching data from the official Codeforces API...';
    if (stats) stats.hidden = false;

    try {
      const res = await fetch(
        `https://codeforces.com/api/user.info?handles=${encodeURIComponent(this.cfHandle)}`
      );

      if (!res.ok) throw new Error(`Codeforces API returned ${res.status}`);

      const data = await res.json();

      if (data.status !== 'OK' || !data.result?.length) {
        throw new Error('Codeforces API returned no data');
      }

      const user = data.result[0];

      if (ratingEl) ratingEl.textContent = user.rating || 'Unrated';
      if (maxRatingEl) maxRatingEl.textContent = user.maxRating || 'Unrated';
      if (rankEl) rankEl.textContent = user.rank || 'Unrated';

      const maxCf = 4000;
      const rating = user.rating || 0;
      const pct = Math.min(rating / maxCf, 1);
      const circumference = 314;
      const offset = circumference - pct * circumference;

      if (arcFill) {
        arcFill.style.strokeDasharray = circumference.toString();
        arcFill.style.strokeDashoffset = circumference.toString();

        setTimeout(() => {
          arcFill.style.transition = 'stroke-dashoffset 1.5s cubic-bezier(0.4, 0, 0.2, 1)';
          arcFill.style.strokeDashoffset = offset.toString();
        }, 250);
      }

      if (pendingEl) pendingEl.textContent = 'Live data fetched from the official Codeforces API.';
      if (stats) stats.hidden = false;
    } catch (error) {
      console.warn('[API] Codeforces fetch failed:', error.message);

      if (ratingEl) ratingEl.textContent = '—';
      if (maxRatingEl) maxRatingEl.textContent = '—';
      if (rankEl) rankEl.textContent = '—';
      if (pendingEl) pendingEl.textContent = 'Live stats unavailable. Open the official profile above.';
      if (stats) stats.hidden = true;
      if (arcFill) arcFill.style.strokeDashoffset = '314';
    }
  },
};

document.addEventListener('DOMContentLoaded', () => {
  API.init();
});
