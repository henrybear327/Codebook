int ans = 0;
bool used[n];
memset(used, false, sizeof(used));

priority_queue<ii, vector<ii>, greater<ii>> pq;
pq.push(ii(0, 0)); // push (0, origin)
while (!pq.empty())
{
    ii cur = pq.top();
    pq.pop();

    int u = cur.second;
    if (used[u])
        continue;
    ans += cur.first;
    used[u] = true;

    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i].first, w = g[u][i].second;
        if (used[v] == false)
            pq.push(ii(w, v));
    }
}