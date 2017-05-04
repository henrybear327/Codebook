#define sz(x) (int(x.size()))
const int MAX_V = ...;
const int INF = 0x3f3f3f3f;

struct Edge {
    int to, w;
};
vector<Edge> g[MAX_V];
int d[MAX_V];

bool spfa(int V, int S) {
    fill(d, d + V, INF);
    queue<int> q;
    vector<bool> inq(V, false);
    vector<int> cnt(V, 0);

    d[S] = 0;
    cnt[S]++;
    inq[S] = true;
    q.push(S);

    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        for (int i = 0; i < sz(g[u]); i++) {
            const Edge& e = g[u][i];
            if (d[e.to] > d[u] + e.w) {
                d[e.to] = d[u] + e.w;
                if (++cnt[e.to] >= V) {
                    return true;
                }
                if (!inq[e.to]) {
                    inq[e.to] = true;
                    q.push(e.to);
                }
            }
        }
    }

    return false;
}
