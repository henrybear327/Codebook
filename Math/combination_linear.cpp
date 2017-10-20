ll binomialCoeff(ll n, ll k)
{
    ll res = 1;
    
    if ( k > n - k ) // Since C(n, k) = C(n, n-k)
    k = n - k;
    
    for (int i = 0; i < k; ++i) // n...n-k / 1...k
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}