// SCC缩点 http://www.cnblogs.com/qscqesze/p/4291922.html
int V;                 //顶点数量
vector<int> G[max_v];  //图的邻接表表示方法
vector<int> rG[max_v]; //把边反向建的图
vector<int> vs;        //后序遍历顺序的顶点列表
bool used[max_v];      //访问标记
int cmp[max_v];        //所属强连通分量的拓扑顺序
void add_edge(int from, int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        if(!used[[G[v][i])
                      dfs(G[v][i]);
         }
        vs.push_back(v);
}
void rdfs(int v, int k)
{
    used[v] = true;
    cmp[v] = k;
    for (int i = 0; i < rG[v].size(); i++) {
        if(!used[rG[v][i])
           rdfs(rG[v][i], k);
    }
}
int scc()
{
    memset(used, 0, sizeof(used));
    vs.clear();
    for (int v = 0; v < V; v++) {
        if (!used[v])
            dfs(v);
    }
    memset(used, 0, sizeof(used));
    int k = 0;
    for (int i = vs.size(); i >= 0; i--) {
        if (!used[vs[i]])
            rdfs(vs[i], k++);
    }
    return k;
}
