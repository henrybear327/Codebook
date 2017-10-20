const int INF = 0x3f3f3f3f;
int lmis(const vector<int>& v) {
    vector<int> dp(sz(v), INF);
    for (auto x : v) {
        *upper_bound(dp.begin(), dp.end(), x) = x;
    }
    return find(dp.begin(), dp.end(), INF) - dp.begin();
}
int lmds(const vector<int>& v) {
    vector<int> rv = v;
    reverse(rv.begin(), rv.end());
    return lmis(rv);
}