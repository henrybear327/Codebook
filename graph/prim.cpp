priority_queue<ii, vector<ii>, greater<ii>> pq;
pq.push(ii(0, 0)); // push (0, origin)

uf.init(n + 1); // init union find
int ans = 0, earlyTermination = 0;
while (!pq.empty())
{
    ii cur = pq.top();
    pq.pop();

    int u = cur.second;
    if (u != 0 && (uf.root(0) == uf.root(u))) // check loop
        continue;
    uf.merge(0, u);
    ans += cur.first;
    earlyTermination++;
    if (earlyTermination == n) // origin node is dummy node
        break;

    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i].first, w = g[u][i].second;

        if (uf.root(0) != uf.root(v)) {
            pq.push(ii(w, v));
        }
    }
}
