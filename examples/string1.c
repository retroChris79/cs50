#include <cs50.h>
#include <stdio.h>
#include <string.h>



int main (void)
{
    string one ="My first String";
    string two ="My Second String";
    string three="My 3rd String";
    char four[] = "4";
    char five[] ="4";

    char one_character[1] = " ";
    one_character[0] = five[0];

    int length_of_stringone = strlen(one);
    int result = strcmp(four, five);

    printf("This are my strings:\n %s\n %s\n %s\n %s\n", one, two, three, four);

    printf("This is the length of my string %i\n", length_of_stringone);

    printf("Result of stringcompare %i\n", result);

    //string part = strtok(test, "-");


    //printf("the parts of the test string: %s\n", part);


}