#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main (int argc, string argv[])
{
    if (argc != 2) return 0;

    string somestring = argv[1];

    char tokenizer[] = "-";

    string word = strtok(somestring, tokenizer);

    while (word != NULL)
    {
        printf("%s\n", word );
        word = strtok(NULL, tokenizer);

    }


}