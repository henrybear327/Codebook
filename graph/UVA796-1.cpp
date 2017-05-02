#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1111;
vector<int> g[MAX_N];

int tt = 0, dfn[MAX_N], low[MAX_N];
typedef pair<int, int> ii;
vector<ii> ans;
void dfs(int u, int p)
{
    dfn[u] = low[u] = tt++;

    for (auto v : g[u]) {
        if (v == p)
            continue;

        if (dfn[v] == -1) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] > dfn[u])
                ans.push_back(ii(min(u, v), max(u, v)));
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++)
            g[i].clear();

        for (int i = 0; i < n; i++) {
            int u, cnt;
            scanf("%d (%d)", &u, &cnt);

            for (int j = 0; j < cnt; j++) {
                int v;
                scanf("%d", &v);

                g[u].push_back(v);
            }
        }

        memset(dfn, -1, sizeof(dfn));
        memset(low, -1, sizeof(low));
        tt = 0;
        ans.clear();
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i, -1);
            }
        }

        sort(ans.begin(), ans.end());
        printf("%d critical links\n", (int)ans.size());
        for (auto i : ans)
            printf("%d - %d\n", i.first, i.second);
        printf("\n");
    }

    return 0;
}
