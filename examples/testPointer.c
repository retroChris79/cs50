//test strings and pointers

#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>


int** allocate_please (int size);

void please_fill_me(int** to_be_filled);

void please_print_me(int** to_be_printed);

int main ()
{
    int *x[4] = {malloc(sizeof(int)),malloc(sizeof(int)),malloc(sizeof(int)),malloc(sizeof(int))};
    int *x2[4][4] =
    {
        {malloc(sizeof(int)),malloc(sizeof(int))},
        {malloc(sizeof(int)),malloc(sizeof(int))}

    };
    int **y = malloc(sizeof(int));


    printf("%i\n", *x2[0][0]);

    for (int i =0; i < 4; i++)
    {
      y[i] = calloc(4, sizeof(int));

    }


    for (int i=0; i < 4; i++)
    {
        for (int j =0; j <4; j++)
        {
            printf("%i", y[i][j]);
        }
        printf("\n");
    }


   printf("size of x %lu and size of y %lu\n", sizeof(x), sizeof(y));

   int **iam_going_tobeallocated = allocate_please(4);

   please_fill_me(iam_going_tobeallocated);
   please_print_me(iam_going_tobeallocated);

   iam_going_tobeallocated = allocate_please(4);
   please_print_me(iam_going_tobeallocated);


}

int** allocate_please(int size)
{
    int** tobeallocated = malloc(sizeof(int));

    for (int i =0; i < size; i++)
    {
       tobeallocated[i] = calloc(size, sizeof(int));

    }
    return tobeallocated;
}

void please_fill_me(int** to_be_filled)
{
    int x = 1;
    for (int i=0; i < 4; i++)
    {
        for (int j =0; j <4; j++)
        {
            to_be_filled[i][j] = x;
            x++;
        }
    }
}

void please_print_me(int** to_be_printed)
{
    for (int i=0; i < 4; i++)
    {
        for (int j =0; j <4; j++)
        {
            printf("%i ", to_be_printed[i][j]);
        }
        printf("\n");
    }
}



