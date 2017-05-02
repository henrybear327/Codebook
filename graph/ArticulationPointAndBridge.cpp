// timer = 1, dfs arrays init to 0, set root carefully!
int timer, dfsTime[N], dfsLow[N], root;
bool articulationPoint[N]; // set<ii> bridge;
void findArticulationPoint(int u, int p)
{
    dfsTime[u] = dfsLow[u] = timer++;

    int child = 0;        // root child counter for articulation point
    for (auto v : g[u]) { // vector<int> g[N]; // undirected graph
        if (v == p)         // don't go back to parent
            continue;

        if (dfsTime[v] == 0) {
            child++; // root child counter for articulation point
            findArticulationPoint(v, u);
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);

            // <= for articulation point, < for bridge
            if (dfsTime[u] <= dfsLow[v] && root != u)
                articulationPoint[u] = true;
            // special case for articulation point root only
            if (u == root && child >= 2)
                articulationPoint[u] = true;
        } else { // visited before (back edge)
            dfsLow[u] = min(dfsLow[u], dfsTime[v]);
        }
    }
}
