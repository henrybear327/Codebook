typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

vec gauss_jordan(mat A) {
    int n = A.size(), m = A[0].size(); // 增廣矩陣
    for (int i = 0; i < n; i++) {
        // float: find j s.t. A[j][i] is max
        // mod: find min j s.t. A[j][i] is not 0
        int pivot = i;
        for (int j = i; j < n; j++) {
            // if (fabs(A[j][i]) > fabs(A[pivot])) {
            //     pivot = j;
            // }
            if (A[pivot][i] != 0) {
                pivot = j;
                break;
            }
        }

        swap(A[i], A[pivot]);
        if (A[i][i] == 0) { // if (fabs(A[i][i]) < eps)
            // 無解或無限多組解
            // 可改成 continue，全部做完後再判
            return vec();
        }

        ll divi = inv(A[i][i]);
        for (int j = i; j < m; j++) {
            // A[i][j] /= A[i][i];
            A[i][j] = (A[i][j] * divi) % MOD;
        }

        for (int j = 0; j < n; j++) {
            if (j != i) {
                for (int k = i + 1; k < m; k++) {
                    // A[j][k] -= A[j][i] * A[i][k];
                    ll p = (A[j][i] * A[i][k]) % MOD;
                    A[j][k] = (A[j][k] - p + MOD) % MOD;
                }
            }
        }
    }

    vec x(n);
    for (int i = 0; i < n; i++)
        x[i] = A[i][m - 1];
    return x;
}
