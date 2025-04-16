#include <stdio.h>
#include <string.h>
#include <conio.h>

char* multiplyLargeNumbers(char num1[], char num2[]) {
    static char result[1000] = {0};
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int resultSize = len1 + len2;
    int res[1000];
    int i, j, index = 0;

    for (i = 0; i < 1000; i++)
        res[i] = 0;

    for (i = len1 - 1; i >= 0; i--) {
        for (j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + res[i + j + 1];
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }

    i = 0;
    while (i < resultSize && res[i] == 0)
        i++;

    while (i < resultSize)
        result[index++] = res[i++] + '0';

    if (index == 0)
        return "0";

    result[index] = '\0';
    return result;
}

void main() {
    char num1[500], num2[500];
    clrscr();  

    printf("Enter first large number: ");
    scanf("%s", num1);

    printf("Enter second large number: ");
    scanf("%s", num2);

    printf("Product: %s\n", multiplyLargeNumbers(num1, num2));

    getch();  
}
