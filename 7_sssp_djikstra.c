#include <stdio.h>
#include <conio.h>  

#define MAX 10     
#define INF 9999     

int V;              

void dijkstra(int graph[MAX][MAX], int src);

void main() {
    int graph[MAX][MAX];
    int i, j;

    clrscr();  

    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &V);

    printf("Enter the adjacency matrix (%d x %d):\n", V, V);
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    dijkstra(graph, 0);  

    getch();  
}

// Dijkstra's algorithm
void dijkstra(int graph[MAX][MAX], int src) {
    int dist[MAX], visited[MAX];
    int i, v, count, min, min_index;

    for (i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (count = 0; count < V - 1; count++) {
        min = INF;
        min_index = -1;

        for (v = 0; v < V; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }

        if (min_index == -1) {
            break;
        }

        visited[min_index] = 1;

        for (v = 0; v < V; v++) {
            if (!visited[v] && graph[min_index][v] && dist[min_index] != INF &&
                dist[min_index] + graph[min_index][v] < dist[v]) {
                dist[v] = dist[min_index] + graph[min_index][v];
            }
        }
    }

    printf("\nVertex   Distance from Source (0)\n");
    for (i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}
