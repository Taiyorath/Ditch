#include <stdio.h>

int q[10];
int r = -1, f = 0; // Rear and front for the queue
int adj[10][10];
int vis[10] = {0};

void bfs(int s, int n) {
    q[++r] = s; // Enqueue the source vertex
    vis[s] = 1; // Mark the source vertex as visited
    printf("BFS: %d", s);

    while (f <= r) {
        int u = q[f++]; // Dequeue the front vertex

        // Traverse all vertices
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && vis[v] == 0) {
                printf(" -> %d", v);
                vis[v] = 1;    // Mark it as visited
                q[++r] = v;    // Enqueue the vertex
            }
        }
    }
}

int main() {
    int n, s;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    
    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &s);

    bfs(s, n);
    
    return 0;
}
