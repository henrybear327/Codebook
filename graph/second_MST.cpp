const int INF = 0x3f3f3f3f;
const int MAX_V = 100;
const int MAX_LOG_V = 7;
int V, E; // 記得初使化

struct Edge {
	int u, v, w;
};
vector<Edge> edges;

// btn[i][u] = u 前往它 2^i parent 的路上經過的最大權重
// par[i][u] = u 的 2^i parent 是誰
int dep[MAX_V]; // should be init to -1
int btn[MAX_LOG_V][MAX_V];
int par[MAX_LOG_V][MAX_V];

// mst
struct AdjE {
	int to, w;
};
vector<AdjE> g[MAX_V];

void dfs(int u, int p, int d) {
	dep[u] = d;
	par[0][u] = p;
	for (auto e : g[u]) {
		if (e.to != p) {
			btn[0][e.to] = e.w;
			dfs(e.to, u, d + 1);
		}
	}
}

void build() {
	for (int u = 0; u < V; u++) {
		if (dep[u] == -1) {
			dfs(u, -1, 0);
		}
	}

	for (int i = 0; i + 1 < MAX_LOG_V; i++) {
		for (int u = 0; u < V; u++) {
			if (par[i][u] == -1 || par[i][par[i][u]] == -1) {
				par[i + 1][u] = -1;
				btn[i + 1][u] = 0;
			}
			else {
				par[i + 1][u] = par[i][par[i][u]];
				btn[i + 1][u] = max(btn[i][u], btn[i][par[i][u]]);
			}
		}
	}
}

int lca(int u, int v) { // 回傳 u, v 之間的最大權重
	int mx = -INF; // u, v 之間的最大權重

	if (dep[u] > dep[v]) swap(u, v);
	int diff = dep[v] - dep[u];
	for (int i = MAX_LOG_V - 1; i >= 0; i--) {
		if (diff & (1 << i)) {
			mx = max(mx, btn[i][v]);
			v = par[i][v];
		}
	}

	if (u == v) return mx;

	for (int i = MAX_LOG_V - 1; i >= 0; i--) {
		if (par[i][u] != par[i][v]) {
			mx = max(mx, btn[i][u]);
			mx = max(mx, btn[i][v]);
			u = par[i][u];
			v = par[i][v];
		}
	}
	// lca = par[0][u] = par[0][v];
	mx = max(mx, max(btn[0][u], btn[0][v]));

	return mx;
}

// second mst
build();
int ans = INF;
for (auto e: non_mst_edges) {
	int mx_w = lca(e.u, e.v);
	ans = min(ans, (total_w + e.w - mx_w));
}

