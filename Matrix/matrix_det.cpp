typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll determinant(mat m) { // square matrix
    const int n = m.size();
    ll det = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = i, b = j;
            while (m[b][i]) {
                ll q = m[a][i] / m[b][i];
                for (int k = 0; k < n; k++)
                    m[a][k] = m[a][k] - m[b][k] * q;
                swap(a, b);
            }

            if (a != i) {
                swap(m[i], m[j]);
                det = -det;
            }
        }

        if (m[i][i] == 0)
            return 0;
        else
            det *= m[i][i];
    }
    return det;
}
