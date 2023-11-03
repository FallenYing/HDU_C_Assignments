#include <stdio.h>
#include <stdlib.h>

void test(int **pp)
{
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            printf("%3d,", pp[i][j]);
        }
        puts("");
    }
}

int main()
{
    int **pp = (int **)malloc(10 * sizeof(int *));
    for (size_t i = 0; i < 10; i++)
        *(pp + i) = (int *)malloc(20 * sizeof(int));
    for (size_t i = 0; i < 10; i++)
        for (size_t j = 0; j < 20; j++)
            *(*(pp + i) + j) = 20 * i + j;
    test(pp);
    for (size_t i = 0; i < 10; i++)
        free(pp[i]);
    free(pp);
    return EXIT_SUCCESS;
}