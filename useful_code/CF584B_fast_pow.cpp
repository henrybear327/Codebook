#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;
typedef long long ll;

ll fast_pow(ll base, ll exp, ll mod)
{
    if(exp == 0)
	return 1LL;
    ll res = 1;
    while(exp > 0) {
	if(exp & 1) {
	    res = ((res % mod) * (base % mod)) % mod;
	}
	exp >>= 1;
	base = (base * base) % mod;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    int mod = (int)1e9 + 7;
    ll ans = (fast_pow(3, 3 * n, mod) - fast_pow(7, n, mod) + mod) % mod;
    printf("%lld\n", ans);

    return 0;
}
