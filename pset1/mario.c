//mario.c

#include <stdio.h>
#include <cs50.h>

//our main method
int main (void)
{
    //store a valid length here
    int n = 0;

    do
    {
        printf("Height: ");
        n = get_int();

        // validate height here
    }
    while (n < 0 || n > 23);

    int max_hashes = n + 1;

    for (int i = 0; i < n; n--)
    {
        int spaces = (n + 1) - 2;

        //print spaces
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        int hashes = max_hashes - spaces;

        //print hashes
        for (int k = 0; k < hashes; k++)
        {
            printf("#");
        }

        //print new line
        printf("\n");
    }
}