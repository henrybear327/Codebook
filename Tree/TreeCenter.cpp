int diameter = 0, radius[N], deg[N]; // deg = in + out degree
int findRadius() 
{
    queue<int> q; // add all leaves in this group
    for (auto i : group)
        if (deg[i] == 1)
            q.push(i);

    int mx = 0;
    while (q.empty() == false) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            deg[v]--;
            if (deg[v] == 1) {
                q.push(v);
                radius[v] = radius[u] + 1;
                mx = max(mx, radius[v]);
            }
        }
    }

    int cnt = 0; // crucial for knowing if there are 2 centers or not
    for (auto j : group)
        if (radius[j] == mx)
            cnt++;

    // add 1 if there are 2 centers (radius, diameter)
    diameter = max(diameter, mx * 2 + (cnt == 2)); 
    return mx + (cnt == 2); 
}
