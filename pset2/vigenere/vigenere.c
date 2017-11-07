//vigenere less comfy

#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

/*
get key from com line arg wich needs to be a aplhabetical
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

    int key_length = strlen(argv[1]);

    //store the key here for later manipulations
    int key[key_length];

    //validate aplhabetical key
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == false)
        {
            printf("The command line argument must be alphabetical! Thanks a lot!\n");
            return 1;
        }
        //ok store the key, use integers
        else
        {
            //convert all to upper then remove ascii index
            key[i] = toupper(argv[1][i]) - 65;
            printf("%i", key[i]);
        }
    }


    printf("plaintext: ");
    //get text which to encrypt
    string plaintext = get_string();

    printf("ciphertext: ");

    //prepare key for usage: wrap around if smaller then plaintext


    int ascii_index;

    for (int i = 0, j = 0; i < strlen(plaintext); i++)
    {
        //select proper ascii index to add to the alphabetical index
        if (isupper(plaintext[i]))
        {
            ascii_index = 65;
            j++;
        }
        else if (islower(plaintext[i]))
        {
            ascii_index = 97;
            j++;
        }
        else //dontconvert, dont move key index
        {
            //just print
            printf("%c", plaintext[i]);
            //skip encryption formula
            continue;
        }


        int current_keyindex = i % key_length;

        //use encryption formula and "remove" ascii index
        char encrypted_char = ((plaintext[i] - ascii_index) + (key[current_keyindex] % 26)) % 26;

        //print and "add" ascii index
        printf("%c", (encrypted_char + ascii_index));
    }
    printf("\n");
    //all is well return 0: no errors
    return 0;

}





