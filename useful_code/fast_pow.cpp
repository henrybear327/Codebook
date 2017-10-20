ll fast_pow(ll a, ll b, ll P) {
	// b %= (P - 1)
	ll ans = 1;
	ll base = a % P;
	while (b) {
		if (b & 1)
			ans = ans * base % P;
		base = base * base % P;
		b >>= 1;
	}
	return ans;
}
