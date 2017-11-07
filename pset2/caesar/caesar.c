//caesar less comfy

#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

/*
get key from com line arg
turn key into integer atoi
prompt for plaintext

for each char in plaintext
    preserve case
    shift plaintext char by key: use mod formula but add ascii index to alphabetical index
    ci=(pi+k)md26
print cipher test
*/

int main (int argc, string argv[])
{
    //check for arg count, exit with error with unexpected arg count !=2
    if (argc != 2 )
    {
        printf("Please submit exactly 1 command line argument! Thank you!\n");
        return 1;
    }

    //get key, transform to integer
    int key = atoi(argv[1]);

    printf("plaintext: ");
    //get text which to encrypt
    string plaintext = get_string();

    printf("ciphertext: ");

    int ascii_index;

    for (int i = 0; i < strlen(plaintext); i++)
    {
        //select proper ascii index to add to the alphabetical index
        if (isupper(plaintext[i]))
        {
            ascii_index = 65;
        }
        else if (islower(plaintext[i]))
        {
            ascii_index = 97;
        }
        else //dontconvert
        {
            //just print
            printf("%c", plaintext[i]);
            //skip encryption formula
            continue;
        }

        //use encryption formula and "remove" ascii index
        char encrypted_char = ((plaintext[i] - ascii_index) + (key % 26)) % 26;

        //print and "add" ascii index
        printf("%c", (encrypted_char + ascii_index));
    }
    printf("\n");
    //all is well return 0: no errors
    return 0;

}





