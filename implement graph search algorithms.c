#include <stdio.h>

int adj[10][10], visited[10], queue[10];
int n, front = 0, rear = -1;

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

void BFS(int start) {
    front = 0;
    rear = -1;
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("BFS starting from vertex %d: ", start);
    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS starting from vertex %d: ", start);
    DFS(start);
    printf("\n");

    BFS(start);

    return 0;
}
