#include <bits/stdc++.h>
#define rank rk
using namespace std;
const int MXN = 1e5 + 5;
int n, k;
int rank[MXN], tmp[MXN];
bool cmp_sa(int i, int j)
{
    if (rank[i] != rank[j])
        return rank[i] < rank[j];
    int _i = i + k <= n ? rank[i + k] : -1;
    int _j = j + k <= n ? rank[j + k] : -1;
    return _i < _j;
}

void build_sa(string s, int *sa)   // O(nlg2n)
{
    n = s.length();
    for (int i = 0; i <= n; i++) {
        sa[i] = i;                   // 先填入sa
        rank[i] = i < n ? s[i] : -1; // ascii當排名用
    }
    for (k = 1; k <= n; k <<= 1) {
        sort(sa, sa + n + 1, cmp_sa); // 依照排名sort sa
        tmp[sa[0]] = 0;               // 初始化第0名
        for (int i = 1; i <= n; i++)  // 依照sa重新排名
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp_sa(sa[i - 1], sa[i]) ? 1 : 0);
        for (int i = 0; i <= n; i++) // 儲存排名結果
            rank[i] = tmp[i];
    }
}

void build_lcp(string s, int *sa, int *lcp)
{
    int n = s.length(), h = 0;
    /* 自行製造rank數列
    for(int i=0;i<=n;i++) rank[sa[i]] = i;
    */
    lcp[0] = 0;
    for (int i = 0; i < n; i++) {
        int j = sa[rank[i] - 1]; // 存下排名在i之前
        if (h > 0)
            h--;
        for (; j + h < n && i + h < n; h++)
            if (s[j + h] != s[i + h])
                break;
        lcp[rank[i] - 1] = h;
    }
}
int main()
{
    string str = "abracadabra";
    int suffix[10000], lcp[10000];
    build_sa(str, suffix);
    build_lcp(str, suffix, lcp);
}
