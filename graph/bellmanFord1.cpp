struct Edge {
    int from, to, cost;
};

const int MAX_V = ...;
const int MAX_E = ...;
const int INF = 0x3f3f3f3f;
int V, E;
Edge edges[MAX_E];
int d[MAX_V];

bool bellman_ford() {
    fill(d, d + V, INF);

    d[0] = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            Edge& e = edges[j];
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;

                if (i == V-1) // negative cycle
                    return true;
            }
        }
    }

    return false;
}
