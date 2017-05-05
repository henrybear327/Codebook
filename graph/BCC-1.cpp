const int MAX_N = 5555;
vector<int> g[MAX_N];
int tt, dfn[MAX_N], low[MAX_N];
int bcc;
int belong[MAX_N]; // 縮點用
stack<int> s;
void dfs(int u, int p)
{
    dfn[u] = low[u] = tt++;
    s.push(u);
    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (v == p)
            continue;
        if (dfn[v] == -1) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        bcc++;
        while (1) {
            int v = s.top();
            s.pop();
            belong[v] = bcc;
            if (v == u)
                break;
        }
    }
}
