#include <stdio.h>
#include <conio.h> 
#include <math.h>
int x[100]; 
void printBoard(int n) {
    int i, j;
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (x[i] == j)
                printf(" Q "); 
            else
                printf(" . "); 
        }
        printf("\n");
    }
}
int place(int k, int i) {
    int j;
    for (j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0; 
    }
    return 1;
}
void NQueen(int k, int n) {
    int i;
    for (i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n)
                printBoard(n);
            else
                NQueen(k + 1, n);
        }
    }
}
int main() {
    int n;
    clrscr(); 
    printf("Enter the value of N: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("N should be greater than or equal to 1.\n");
        return 1;
    
    NQueen(1, n);
    getch(); 
    return 0;
}
