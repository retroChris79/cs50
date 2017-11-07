//water.c

#include <cs50.h>
#include <stdio.h>

//our main function
int main (void)
{
    //the lenght of the shower in minutes stored in n
    int n = 0;
    //check the input for negative values, repeat if necessary
    do
    {
        //print prompt then fetch integer
        printf("Minutes: ");
        n = get_int();

    }
    while (n < 0);

    //calculate the amount of bottles necessary and print the result
    printf("Bottles: %i\n", n * 12);
}