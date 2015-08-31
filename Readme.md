# Codebook

Algorithms that I have actually implemented in the past.

# Short Code

* GCD

```
long long int gcd(long long int a, long long int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
```

* LCM

```
a * b / gcd(a,b)
```

* Leap year

```
year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)
```

# BFS over a graph

#### (Code simplified and commented from UVa 924)

```
int visited[employee]; // to avoid repeatedly enqueueing elements
memset(visited, 0, sizeof(visited)); //init

queue<int> bfs;
bfs.push(inp); // push the starting element into the queue
visited[inp] = 1;

while (bfs.size()) {
    int curr = bfs.front();
    bfs.pop();

    //using vector
    for (vector<int>::iterator i = graph[curr].begin(); i != graph[curr].end(); i++) {
        if (visited[*i] == 0) {
            bfs.push(*i);
            visited[*i] = visited[curr] + 1; //record level
        }
    }

    //using array
    for (int i = 0; i < (int)graph[curr].size(); i++) {
        if (visited[graph[curr][i]] == 0) {
            bfs.push(graph[curr][i]);
            visited[graph[curr][i]] = visited[curr] + 1;
        }
    }
}
```
# Floyd Warshall (APSP - All-Pairs Shortest Paths)

Using a n * n adjacency matrix to store the graph.

Update the distance between vertices a and b by adding 1 vertex, e.g. c, at a time,
and check if going a->c->b can shorten the distance between a and b or not.

```
for (int k = 1; k < max; k++)
  for (int i = 1; i < max; i++)
    for (int j = 1; j < max; j++)
          graph[i][j] = MIN(graph[i][j], graph[i][k] + graph[k][j]);
```
