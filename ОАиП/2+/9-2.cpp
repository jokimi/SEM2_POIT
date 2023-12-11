#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
int main()
{
    setlocale(LC_CTYPE, "Russian");
    FILE* F1;
    FILE* F2;
    int k;
    char str[255]{};
    printf("k = ");
    scanf_s("%d", &k);
    printf("\n");
    F1 = fopen("f1.txt", "w");
    for (int i = 0; i < 6; i++)
    {
        gets_s(str);
        fputs(str, F1);
        fputs("\n", F1);
    }
    fclose(F1);
    F1 = fopen("f1.txt", "r");
    F2 = fopen("f2.txt", "w");
    while (fgets(str, 255, F1) != NULL)
    {
        if (strlen(str) - 1 > k)
        {
            fputs(str, F2);
        }
    }
    printf("Победа!");
    fclose(F1);
    fclose(F2);
}