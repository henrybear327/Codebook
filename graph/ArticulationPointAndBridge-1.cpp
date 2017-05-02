const int MAX_N = 1111;
vector<int> g[MAX_N];

// for bridge
typedef pair<int, int> ii;
vector<ii> ans;

// for articulation point
int root;                // set it before dfs() call
bool isCutVertex[MAX_N]; // init to false

int tt = 0, dfn[MAX_N], low[MAX_N]; // init array to -1
void dfs(int u, int p)
{
    dfn[u] = low[u] = tt++;

    // for articulation point, root needs to have >= 2 childrens
    int child = 0;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        child++;

        if (dfn[v] == -1) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] > dfn[u]) // bridge
                ans.push_back(ii(min(u, v), max(u, v)));

            if (u != root && low[v] >= dfn[u]) { // articulation point
                isCutVertex[u] = true;
            } else if (u == root && child >= 2) { // articulation point
                isCutVertex[u] = true;
            }
        } else {
            // u -> v, u has direct access to v -> back edge
            low[u] = min(low[u], dfn[v]);
        }
    }
}
