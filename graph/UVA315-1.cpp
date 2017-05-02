#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 111;
vector<int> g[MAX_N];

int tt = 0, root;
int dfn[MAX_N], low[MAX_N]; // init to -1
bool isCutVertex[MAX_N];
void dfs(int u, int p)
{
    dfn[u] = low[u] = tt++;

    int child = 0;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        child++;

        if (dfn[v] == -1) {
            dfs(v, u);

            low[u] = min(low[u], low[v]);

            if (u != root && low[v] >= dfn[u]) {
                isCutVertex[u] = true;
            } else if (u == root && child >= 2) {
                isCutVertex[u] = true;
            }
        } else {
            // u -> v, u has direct access to v -> back edge
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main()
{
    char inp[10000];
    while (fgets(inp, 10000, stdin) != NULL) {
        int n;
        sscanf(inp, "%d", &n);
        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
            g[i].clear();
        while (fgets(inp, 10000, stdin) != NULL) {
            char *u = strtok(inp, " ");

            if (atoi(u) == 0)
                break;
            int uu = atoi(u) - 1;

            char *v = strtok(NULL, " ");
            while (v != NULL) {
                int vv = atoi(v) - 1;
                g[uu].push_back(vv);
                g[vv].push_back(uu);
                v = strtok(NULL, " ");
            }
        }

        /*
        for(int i = 0; i < n; i++) {
                printf("u = %d: ", i + 1);
                for(auto j : g[i])
                        printf("%d ", j + 1);
                printf("\n");
        }
        */

        memset(dfn, -1, sizeof(dfn));
        memset(low, -1, sizeof(low));
        memset(isCutVertex, false, sizeof(isCutVertex));
        tt = 0;
        for (int i = 0; i < n; i++)
            if (dfn[i] == -1) {
                root = i;
                dfs(i, -1);
            }

        int ans = 0;
        for (int i = 0; i < n; i++)
            if (isCutVertex[i]) {
                // printf("%d\n", i + 1);
                ans++;
            }

        printf("%d\n", ans);
    }
    return 0;
}
