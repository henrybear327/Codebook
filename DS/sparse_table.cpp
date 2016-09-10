struct {
    int sp[MAX_LOG_N][MAX_N]; // MAX_LOG_N = ceil(lg(MAX_N))

    void build(int inp[], int n)
    {
        for (int j = 0; j < n; j++)
            sp[0][j] = inp[j];

        for (int i = 1; (1 << i) <= n; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                sp[i][j] = min(sp[i-1][j],sp[i-1][j+(1 << (i - 1))]);
    }

    int query(int l, int r) // [l, r)
    {
        int k = floor(log2(r - l));
        return min(sp[k][l], sp[k][r - (1 << k)]);
    }
} sptb;
