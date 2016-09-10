ll fast_pow(ll a, ll b, ll M) {
	ll ans = 1;
	ll base = a % M;
	while (b) {
		if (b & 1)
			ans = ans * base % M;
		base = base * base % M;
		b >>= 1;
	}
	return ans;
}
