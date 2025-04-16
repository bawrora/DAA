#include <stdio.h>
#include <conio.h>

#define INF 9999
#define MAX 10  

void printMatrix(int matrix[MAX][MAX], int nV) {
    int i, j;
    printf("\nShortest distance matrix:\n");
    for(i = 0; i < nV; i++) {
        for(j = 0; j < nV; j++) {
            if(matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}
void floydWarshall(int graph[MAX][MAX], int nV) {
    int matrix[MAX][MAX];
    int i, j, k;
    for(i = 0; i < nV; i++) {
        for(j = 0; j < nV; j++) {
            matrix[i][j] = graph[i][j];
        }
    }
    for(k = 0; k < nV; k++) {
        for(i = 0; i < nV; i++) {
            for(j = 0; j < nV; j++) {
                if(matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    printMatrix(matrix, nV);
}

void main(void) {
    int graph[MAX][MAX];
    int nV, i, j;
    clrscr();  

    printf("Enter the number of vertices (max %d): ", MAX);
    scanf("%d", &nV);

    printf("Enter the adjacency matrix (use %d for INF):\n", INF);
    for(i = 0; i < nV; i++) {
        for(j = 0; j < nV; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    floydWarshall(graph, nV);

    getch();  
}
