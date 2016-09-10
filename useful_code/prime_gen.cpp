const ll MAX_NUM = 1e6; // 要是合數
bool is_prime[MAX_NUM];
vector<ll> primes;

void init_primes() {
	fill(is_prime, is_prime + MAX_NUM, true);
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i < MAX_NUM; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (ll j = i * i; j < MAX_NUM; j += i)
				is_prime[j] = false;
		}
	}
}
