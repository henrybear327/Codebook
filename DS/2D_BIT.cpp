// BIT is 1-based
const int MAX_N = 20000, MAX_M = 20000; //這個記得改！
ll bit[MAX_N + 1][MAX_M + 1];

ll sum(int a, int b) {
    ll s = 0;
    for (int i = a; i > 0; i -= (i & -i))
        for (int j = b; j > 0; j -= (j & -j))
            s += bit[i][j];
        return s;
}

void add(int a, int b, ll x) {
    // MAX_N, MAX_M 須適時調整！
    for (int i = a; i <= MAX_N; i += (i & -i))
        for (int j = b; j <= MAX_M; j += (j & -j))
            bit[i][j] += x;
}