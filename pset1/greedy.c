//greedy.c

#include <cs50.h>
#include <stdio.h>
#include <math.h>

//our main function, everything starts here
int main (void)
{
    //dont forget to convert to cents and round to the nearest cent before that

    //get user input
    float n = 0;
    printf("oh hai! ");
    do
    {
        printf("How much change is owed?\n");
        n = get_float();

    }
    while (n < 0);

    printf("%f\n", n);
    //dont forget to convert to cents and round to the nearest cent before that 4.985 should be 498.5
    //float conversion = n *100.0f;

    float cents = n * 100.0f;

    //lets check wether we should round up or down
    if ((ceil(cents) - cents) <= 0.5f)
    {
        cents = ceil(cents);
    }
    else
    {
        cents = floor(cents);
    }

    //printf ( "%i \n", (int) ceil(cents));
    //printf ( "%f %f\n", ceil(test2), floor(test2));

    //how to convert to integer > typecast

    const int twentyfive = 25;
    const int ten = 10;
    const int five = 5;
    const int one = 1;
    int coin_counter = 0;

    //typcast to integer so division and modulo works as intended
    int newcents = (int)cents;

    //are there 25s to be returend ?
    if (newcents / twentyfive > 0)
    {
        coin_counter = newcents / twentyfive;
        newcents = newcents % twentyfive;
    }
    //are tere 10s to be returned?
    if (newcents / ten > 0)
    {
        coin_counter += newcents / ten;
        newcents = newcents %  ten;
    }
    //are there 5s to be returned ?
    if (newcents / five > 0)
    {
        coin_counter += newcents / five;
        newcents = newcents % five;
    }
    //are there 1s to be returned?
    if (newcents / one > 0)
    {
        coin_counter += newcents / one;

    }

    printf("%i\n", coin_counter);




}