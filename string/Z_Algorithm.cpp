int len = strlen(inp), z[len];
z[0] = 0; // initial

int l = 0, r = 0; // z box bound [l, r]
for (int i = 1; i < len; i++)
{
    if (i > r) { // i not in z box
        l = r = i; // z box contains itself only
        while (r < len && inp[r - l] == inp[r])
            r++;
        z[i] = r - l;
        r--;
    } else { // i in z box
        if (z[i - l] + i < r) // over shoot R bound
            z[i] = z[i - l];
        else {
            l = i;
            while (r < len && inp[r - l] == inp[r])
                r++;
            z[i] = r - l;
            r--;
        }
    }
}
