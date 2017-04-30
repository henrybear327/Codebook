typedef long long ll;

ll fast_pow(ll a, ll b, ll p) {
    ll ans = 1;
    ll base = a % p;
    b = b % (p - 1); // Fermat's little theorem
    while (b) {
        if (b & 1) {
            ans = (ans * base) % p;
        }
        base = (base * base) % p;
        b >>= 1;
    }
    return ans;
}

ll inv(ll a, ll p) {
    return fast_pow(a, p - 2, p);
}

ll C(ll n, ll m, ll p) {
    if (n < m) return 0;
    m = min(m, n - m);
    ll nom = 1, den = 1;
    for (ll i = 1; i <= m; i++) {
        nom = (nom * (n - i + 1)) % p;
        den = (den * i) % p;
    }
    return (nom * inv(den, p)) % p;
}

// To make C(n, m) % p computed in O(log(p, n) * p) instead of O(m)
// https://en.wikipedia.org/wiki/Lucas's_theorem
ll lucas(ll n, ll m, ll p) {
    if (m == 0) return 1;
    return C(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}
