struct Edge {
    int to, cost;
};

typedef pair<int, int> P; // <d, v>
const int INF = 0x3f3f3f3f;

int N, R;
vector<Edge> g[5000];

int d[5000];
int sd[5000];

int solve()
{
    fill(d, d + N, INF);
    fill(sd, sd + N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;

    d[0] = 0;
    pq.push(P(0, 0));

    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;

        if (sd[v] < p.first) // 比次短距離還大，沒用，跳過
            continue;

        for (size_t i = 0; i < g[v].size(); i++) {
            Edge &e = g[v][i];
            int nd = p.first + e.cost;
            if (nd < d[e.to]) { // 更新最短距離
                swap(d[e.to], nd);
                pq.push(P(d[e.to], e.to));
            }
            if (d[e.to] < nd && nd < sd[e.to]) { // 更新次短距離
                sd[e.to] = nd;
                pq.push(P(sd[e.to], e.to));
            }
        }
    }

    return sd[N - 1];
}
