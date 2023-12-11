#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int i, a[100]{}, t;
    FILE* f, * g;
    if ((f = fopen("fileA.txt", "r")) == NULL)
        printf("Error!");
    else
    {
        g = fopen("fileB.txt", "w");
        for (i = 0; i < 100 && !feof(f);)
        {
            fscanf_s(f, "%d", &a[i]);
            for (int j = t = 0; j < i && t == 0; ++j)
                t = (a[j] == a[i]);
            if (t == 0)
                fprintf(g, "%d ", a[i++]);
        }
        printf("Победа!");
        fclose(f);
        fclose(g);
    }
    return 0;
}