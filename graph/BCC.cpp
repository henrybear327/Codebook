int cnt, root, dfsTime[N], dfsLow[N], timer, group[N]; // max N nodes
stack<int> s;
bool in[N];
void dfs(int u, int p)
{
    s.push(u);
    in[u] = true;

    dfsTime[u] = dfsLow[u] = timer++;

    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];

        if (v == p)
            continue;

        if (dfsTime[v] == 0) {
            dfs(v, u);
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        } else {
            if (in[u]) // gain speed
                dfsLow[u] = min(dfsLow[u], dfsTime[v]);
        }
    }

    if (dfsTime[u] == dfsLow[u]) { //dfsLow[u]== dfsTime[u] -> SCC found
        cnt++;
        while (true) {
            int v = s.top();
            s.pop();
            in[v] = false;

            group[v] = cnt;
            if (v == u)
                break;
        }
    }
}

// get SCC degree
int deg[n + 1];
memset(deg, 0, sizeof(deg));
for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)g[i].size(); j++) {
        int v = g[i][j];
        if (group[i] != group[v])
            deg[group[i]]++;
    }
}

