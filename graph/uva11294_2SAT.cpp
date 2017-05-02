#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
int N, M;

const int MAX_V = 4 * MAX_N;
const int INF = 0x3f3f3f3f;
int dfn_idx = 0;
int scc_cnt = 0;
int dfn[MAX_V];
int low[MAX_V];
int belong[MAX_V];
bool in_st[MAX_V];
vector<int> g[MAX_V];
vector<int> st;

void scc(int v)
{
    dfn[v] = low[v] = dfn_idx++;
    st.push_back(v);
    in_st[v] = true;

    for (int i = 0; i < int(g[v].size()); i++) {
        const int u = g[v][i];
        if (dfn[u] == -1) {
            scc(u);
            low[v] = min(low[v], low[u]);
        } else if (in_st[u]) {
            low[v] = min(low[v], dfn[u]);
        }
    }

    if (dfn[v] == low[v]) {
        int k;
        do {
            k = st.back();
            st.pop_back();
            in_st[k] = false;
            belong[k] = scc_cnt;
        } while (k != v);
        scc_cnt++;
    }
}

void tarjan(int V) // scc 建立的順序即為反向的拓璞排序
{
    st.clear();
    fill(dfn, dfn + V, -1);
    fill(low, low + V, INF);
    dfn_idx = 0;
    scc_cnt = 0;
    for (int v = 0; v < V; v++) {
        if (dfn[v] == -1) {
            scc(v);
        }
    }
}

int get_inp()
{
    int id;
    char gender[3];
    scanf("%d%s", &id, gender);
    id *= 2;
    if (gender[0] == 'w')
        id += 2 * N;
    return id;
}

int main()
{
    // [0, 2 * N) : h
    // [2 * N, 4 * N) : w

    // T : at same side as bride
    // F : at the other side of bride

    // h xor w
    // = ~( (h and w) or (~h and ~w) )
    // = (~h or ~w) and (h or w)

    while (scanf("%d %d", &N, &M)) {
        if (N == 0 && M == 0)
            break;

        // init
        for (int i = 0; i < 4 * N; i++)
            g[i].clear();

        // w[0] should be T
        g[(2 * N) ^ 1].push_back(2 * N);

        // h[i] 與 w[i] 不同邊
        for (int h = 0; h < 2 * N; h += 2) {
            int w = h + 2 * N;
            // h xor w
            g[h].push_back(w ^ 1);
            g[w].push_back(h ^ 1);
            g[h ^ 1].push_back(w);
            g[w ^ 1].push_back(h);
        }

        while (M--) {
            int u = get_inp();
            int v = get_inp();
            // u or v
            g[u ^ 1].push_back(v);
            g[v ^ 1].push_back(u);
        }

        tarjan(4 * N);

        bool ok = true;
        for (int i = 0; i < 4 * N; i += 2) {
            if (belong[i] == belong[i ^ 1]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            puts("bad luck");
            continue;
        }

        bool is_first = true;
        for (int h = 2; h < 2 * N; h += 2) {
            if (belong[h] < belong[h ^ 1]) {
                if (is_first)
                    is_first = false;
                else {
                    printf(" ");
                }
                printf("%dh", h / 2);
            }
        }
        for (int w = 2 * N + 2; w < 4 * N; w += 2) {
            if (belong[w] < belong[w ^ 1]) {
                if (is_first)
                    is_first = false;
                else {
                    printf(" ");
                }
                printf("%dw", (w - 2 * N) / 2);
            }
        }
        puts("");
    }

    return 0;
}
