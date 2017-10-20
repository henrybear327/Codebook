const int INF = 0x3f3f3f3f;
int lsis(const vector<int>& v) {
    vector<int> dp(sz(v), INF);
    for (auto x : v) {
        *lower_bound(dp.begin(), dp.end(), x) = x;
    }
    return find(dp.begin(), dp.end(), INF) - dp.begin();
}
int lsds(const vector<int>& v) {
    vector<int> rv = v;
    reverse(rv.begin(), rv.end());
    return lsis(rv);
}