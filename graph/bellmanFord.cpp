vector<pair<ii, int>> edge; // store graph by edge: ((u, v), w)

void BellmanFord()
{
    ll d[n]; // n: total nodes
    fill(d, d + n, INT_MAX);
    d[0] = 0; // src is 0
    bool loop = false;
    for (int i = 0; i < n; i++) {
        // Do n - 1 times. If the n-th time still has relaxation, loop exists
        bool hasChange = false;
        for (int j = 0; j < (int)edge.size(); j++) {
            int u = edge[j].first.first, v = edge[j].first.second, w = edge[j].second;
            if (d[u] != INT_MAX && d[u] + w < d[v]) {
                hasChange = true;
                d[v] = d[u] + w;
            }
        }

        if (i == n - 1 && hasChange == true)
            loop = true;
        else if (hasChange == false)
            break;
    }
}
