const int MAX_N = 20000; // 記得改
struct UFDS {
    int par[MAX_N];
    
    void init(int n) {
        memset(par, -1, sizeof(int) * n);
    }
    
    int root(int x) {
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }
    
    void merge(int x, int y) {
        x = root(x);
        y = root(y);
        
        if (x != y) {
            if (par[x] > par[y])
            swap(x, y);
            par[x] += par[y];
            par[y] = x;
        }
    }
};