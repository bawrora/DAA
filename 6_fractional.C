#include <stdio.h>
#include <conio.h>
#define MAX 20
struct Item {
    int weight, profit;
    float ratio;
};
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}
void sortItems(struct Item items[], int n) {
    int i, j;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}
float fractionalKnapsack(struct Item items[], int n, int capacity, float result[]) {
    int i;
    float totalProfit = 0.0;

    sortItems(items, n);

    for(i = 0; i < n; i++) {
        if(capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
            result[i] = 1.0;
        } else {
            result[i] = (float) capacity / items[i].weight;
            totalProfit += result[i] * items[i].profit;
            break;
        }
    }

    return totalProfit;
}
void main() {
    struct Item items[MAX];
    float result[MAX];
    int n, i, capacity;
    float maxProfit;

    clrscr(); // clear screen

    printf("Enter the number of items (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter weight and profit of each item:\n");
    for(i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Item %d - Profit: ", i + 1);
        scanf("%d", &items[i].profit);
        items[i].ratio = (float) items[i].profit / items[i].weight;
    }
    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);
    maxProfit = fractionalKnapsack(items, n, capacity, result);
    printf("\nItem selection (fraction taken):\n");
    for(i = 0; i < n; i++) {
        printf("Item %d: %.2f\n", i + 1, result[i]);
    }
    printf("\nMaximum Profit: %.2f", maxProfit);

    getch(); 
}
