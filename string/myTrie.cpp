#define N 600010
struct node {
    int child[26]; 
    bool ending;
} trie[N];

/*
root is 0
memset(trie, 0, sizeof(trie));
freeNode = 1;
*/
int freeNode;
void insert(string &str, int pos, int node)
{
    if (pos == (int)str.length()) {
        trie[node].ending = true;
    } else { // find which way to go
        int c = str[pos] - 'a';
        if (trie[node].child[c] == 0) // give a new node
            trie[node].child[c] = freeNode++;
        insert(str, pos + 1, trie[node].child[c]);
    }
}