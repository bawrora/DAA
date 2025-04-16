#include <stdio.h>
#define MAX_ITEMS 20
#define MAX_WEIGHT 100

int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[MAX_ITEMS + 1][MAX_WEIGHT + 1];

    for(i = 0; i <= n; i++) {
        for(w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if(wt[i-1] <= w) {
                K[i][w] = max(val[i-1] + K[i-1][w - wt[i-1]], K[i-1][w]);
            } else {
                K[i][w] = K[i-1][w];
            }
        }
    }

    return K[n][W];
}

int main() {
    int i, n, W;
    int val[MAX_ITEMS], wt[MAX_ITEMS];

    printf("Enter number of items (max %d): ", MAX_ITEMS);
    scanf("%d", &n);

    printf("Enter value and weight of items:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &val[i]);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &wt[i]);
    }
    printf("Enter capacity of knapsack (max %d): ", MAX_WEIGHT);
    scanf("%d", &W);
    printf("Maximum value in Knapsack = %d\n", knapsack(W, wt, val, n));
    return 0;
}
