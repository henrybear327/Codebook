typedef pair<int, int> ii;
vector<ii> g[N];

bool SPFA()
{
    vector<ll> d(n, INT_MAX);
    d[0] = 0; // origin

    queue<int> q;
    vector<bool> inqueue(n, false);
    vector<int> cnt(n, 0);
    q.push(0);
    inqueue[0] = true;
    cnt[0]++;

    while (q.empty() == false) {
        int u = q.front();
        q.pop();
        inqueue[u] = false;

        for (auto i : g[u]) {
            int v = i.first, w = i.second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (inqueue[v] == false) {
                    q.push(v);
                    inqueue[v] = true;
                    cnt[v]++;

                    if (cnt[v] == n) { // loop!
                        return true;
                    }
                }
            }
        }
    }

    return false;
}
