#include <cstdio>
#include <vector>

using namespace std;

#define N 10010
int is_prime[N];
vector<int> prime;
void init()
{
    fill(is_prime, is_prime + N, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < N; i++) {
	if(is_prime[i] == true) {
	    for(int j = i * i; j < N; j += i)
		is_prime[j] = false;
	}
    }

    for(int i = 0; i < N; i++)
	if(is_prime[i] == true)
	    prime.push_back(i);
}

int main()
{
    init();

    int n;
    while(scanf("%d", &n) == 1 && n) {
	int ans = 0;
	for(int i = 0; i < (int)prime.size(); i++) {
	    if(prime[i] > n)
		break;
	    int sum = 0;
	    for(int j = i; j < (int)prime.size(); j++) {
		sum += prime[j];
		if(sum == n) {
		    ans++;
		    break;
		} else if (sum > n){
		    break;
		}
	    }
	}
	printf("%d\n", ans);
    }
    return 0;
}
