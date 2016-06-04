#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;

#define N 10010

bool is_prime[N];
vector<ll> primes;
void init()
{
    fill(is_prime, is_prime + N, true);
    for (int i = 2; i < N; i++) {
        if (is_prime[i] == true) {
            primes.push_back(i);
            for (int j = i * i; j < N; j += i)
                is_prime[j] = false;
        }
    }
}

int main()
{
    init();

    int n;
    while (scanf("%d", &n) == 1 && n) {
        int ans = 0;
        for (int i = 0; i < (int)primes.size(); i++) {
            if (primes[i] > n)
                break;
            int sum = 0;
            for (int j = i; j < (int)primes.size(); j++) {
                sum += primes[j];
                if (sum == n) {
                    ans++;
                    break;
                } else if (sum > n) {
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
