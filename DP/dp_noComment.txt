# 零一背包 (poj 1276)
fill(dp, dp + W + 1, 0);
for (int i = 0; i < N; i++)
    for (int j = W; j >= items[i].w; j--)
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
return dp[W];

# 多重背包二進位拆解 (poj 1276)
for_each(ll v, w, num) {
    for (ll k = 1; k <= num; k *= 2) {
        items.push_back((Item) {k * v, k * w});
        num -= k;
    }
    if (num > 0)
        items.push_back((Item) {num * v, num * w});
}

# 完全背包
dp[i][j] = 前 i + 1 個物品，在重量 j 下所能組出的最大價值
第 i 個物品，不放或至少放一個
dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i])
fill(dp, dp + W + 1, 0);
for (int i = 0; i < N; i++)
    for (int j = w[i]; j <= W; j++)
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
return dp[W];

# Coin Change (2015 桂冠賽 E)
dp[i][j] = 前 i + 1 個物品，組出 j 元的方法數
第 i 個物品，不用或用至少一個
dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i]]

# Cutting Sticks (2015 桂冠賽 F)
補上二個切點在最左與最右
dp[i][j] = 使 (i, j) 區間中的所有切點都被切的最小成本
dp[i][j] = min(dp[i][c] + dp[c][j] + (p[j] - p[i]) for i < c < j)
dp[i][i + 1] = 0
ans = dp[0][N + 1]

# Throwing a Party (itsa dp 06)
給定一棵有根樹，代表公司職位層級圖，每個人有其權重，現從中選一個點集合出來，
且一個人不能與其上司一都在集合中，並最大化集合的權重和，輸出該總和。
dp[u][0/1] = u 在或不在集合中，以 u 為根的子樹最大權重和
dp[u][0] = max(max(dp[c][0], dp[c][1]) for children c of u) + val[u]
dp[u][1] = max(dp[c][0] for children c of u)
bottom up dp

# LIS (O(N^2))
dp[i] = 以 i 為結尾的 LIS 的長度
dp[i] = max(dp[j] for 0 <= j < i) + 1
ans = max(dp)

# LIS (O(nlgn)), poj 1631
dp[i] = 長度為 i + 1 的 LIS 的最後一項的最小值，不存在時為 INF
fill(dp, dp + N, INF);
for (int i = 0; i < N; i++)
    *lower_bound(dp, dp + N, A[i]) = A[i];
ans = lower_bound(dp, dp + N, INF) - dp;

# Maximum Subarray

# Not equal on a Segment (cf edu7 C)
給定長度為 n 的陣列 a[] 與 m 個詢問。
針對每個詢問 l, r, x 請輸出 a[l, r] 中不等於 x 的任一位置。
不存在時輸出 -1
dp[i] = max j such that j < i and a[j] != a[i]
dp[0] = -1
dp[i] = dp[i - 1] if a[i] == a[i - 1] else i - 1
針對每筆詢問 l, r, x
1. a[r] != x                -> 輸出 r
2. a[r] = x && dp[r] >= l   -> 輸出 dp[r]
3. a[r] = x && dp[r] < l    -> 輸出 -1

# bitmask dp, poj 2686
給定一個無向帶權圖，代表 M 個城市之間的路，與 N 張車票，
每張車票有一個數值 t[i]，若欲使用車票 t[i] 從城市 u 經由路徑 d[u][v] 走到城市 v，
所花的時間為 d[u][v] / t[i]。請問，從城市 A 走到城市 B 最快要多久？
dp[S][v] = 從城市 A 到城市 v 的最少時間，其中 S 為用過的車票的集合
考慮前一個城市 u 是誰，使用哪個車票 t[i] 而來，可以得到轉移方程式:
dp[S][v] = min([
    dp[S - {v}][u] + d[u][v] / t[i]
    for all city u has edge to v, for all ticket in S
])

# Tug of War
N 個人參加拔河比賽，每個人有其重量 w[i]，欲使二隊的人數最多只差一，雙方的重量和越接近越好
請問二隊的重量和分別是多少？
dp[i][j][k] = 只考慮前 i + 1 個人，可不可以使左堆的重量為 j, 且左堆的人數為 k
dp[i][j][k] = dp[i - 1][j - w[i][k - 1] or dp[i - 1][j][k]
dp[i][j] = (dp[i - 1][j - w[i]] << 1) | (dp[i - 1][j])

# Modulo Sum (cf 319 B)
給定長度為 N 的序列 A 與一正整數 M，請問該序列中有無一個子序列，子序列的總合是 M 的倍數
若 N > M，則根據鴿籠原理，必有至少兩個前綴和的值 mod M 為相同值，解必定存在
dp[i][j] = 前 i + 1 個數可否組出 mod m = j 的數
dp[i][j] = true if
    dp[i - 1][(j - (a[i] mod m)) mod m] or
    dp[i - 1][j] or
    j = a[i] % m

# POJ 2229
給定正整數 N，請問將 N 拆成一堆 2^x 之和的方法數
dp[i] = 拆解 N 的方法數
dp[i] = dp[i / 2] if i is odd
      = dp[i - 1] + dp[i / 2] if i is even

# POJ 3616
給定 N 個區間 [s, t)，每個區間有權重 w[i]，從中選出一些不相交的區間，使權重和最大
dp[i] = 考慮前 i + 1 個區間，且必選第 i 個區間的最大權重和
dp[i] = max(dp[j] | 0 <= j < i) + w[i]
ans = max(dp)

# POJ 2184
N 隻牛每隻牛有權重 <s, f>，從中選出一些牛的集合，
使得 sum(s) + sum(f) 最大，且 sum(s) > 0, sum(f) > 0。
枚舉 sum(s) ，將 sum(s) 視為重量對 f 做零一背包。

# POJ 3666
給定長度為 N 的序列，請問最少要加多少值，使得序列單調遞增
dp[i][j] = 使序列前 i+1 項變為單調，且將 A[i] 變為「第 j 小的數」的最小成本
dp[i][j] = min(dp[i - 1][k] | 0 <= k <= j) + abs(S[j] - A[i])
min(dp[i - 1][k] | 0 <= k <= j) 動態維護
for (int j = 0; j < N; j++)
    dp[0][j] = abs(S[j] - A[0]);
for (int i = 1; i < N; i++) {
    int pre_min_cost = dp[i][0];
    for (int j = 0; j < N; j++) {
        pre_min_cost = min(pre_min_cost, dp[i-1][j]);
        dp[i][j] = pre_min_cost + abs(S[j] - A[i]);
    }
}
ans = min(dp[N - 1])

# POJ 3734
N 個 blocks 上色，R, G, Y, B，上完色後紅色的數量與綠色的數量都要是偶數。請問方法數。
dp[i][0/1/2/3] = 前 i 個 blocks 上完色，紅色數量為奇數/偶數，綠色數量為數/偶數
用遞推，考慮第 i + 1 個 block 的顏色，找出個狀態的轉移，整理可發現
dp[i + 1][0] = dp[i][2] + dp[i][1] + 2 * dp[i][0]
dp[i + 1][1] = dp[i][3] + dp[i][0] + 2 * dp[i][1]
dp[i + 1][2] = dp[i][0] + dp[i][3] + 2 * dp[i][2]
dp[i + 1][3] = dp[i][1] + dp[i][2] + 2 * dp[i][3]
矩陣快速冪加速求 dp[N - 1][0][0]

# POJ 3171
數線上，給定 N 個區間 [s[i], t[i]]，每個區間有其代價，求覆蓋區間 [M, E] 的最小代價。
dp[i][j] = 最多使用前 i + 1 個區間，使 [M, j] 被覆蓋的最小代價
考慮第 i 個區間用或不用，可得:
dp[i][j] =
    1. min(dp[i - 1][k] for k in [s[i] - 1, t[i]]) + cost[i] if j = t[i]
    2. dp[i - 1][j] if j ≠ t[i]
壓空間，使用線段樹加速。
dp[t[i]] = min(dp[t[i]],
    min(dp[i - 1][k] for k in [s[i] - 1, t[i]]) + cost[i]
)
fill(dp, dp + E + 1, INF);
seg.init(E + 1, INF);
int idx = 0;
while (idx < N && A[idx].s == 0) {
    dp[A[idx].t] = min(dp[A[idx].t], A[idx].cost);
    seg.update(A[idx].t, A[idx].cost);
    idx++;
}
for (int i = idx; i < N; i++) {
    ll v = min(dp[A[i].t], seg.query(A[i].s - 1, A[i].t + 1) + A[i].cost);
    dp[A[i].t] = v;
    seg.update(A[i].t, v);
}
