//initials less comfy

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>



int main (void)
{
    string user_name = get_string();
    //printf printing a string with %s
    //printf("this is your username, %s\n", user_name);

    //int length = strlen(user_name);
    //printf printing a integer with %i
    //printf("this username is %i long \n", length );


    int initials_counter = 0;
    char initials[10] = " ";
    bool should_be_uppercase = false;

    //testing
    //printf("%c\n", toupper(user_name[1]));

    for (int i = 0; i < strlen(user_name); i++)
    {


        if (i == 0)
        {
            initials[initials_counter] = (char) toupper(user_name[i]);
            initials_counter++;
        }

        if (isspace(user_name[i]))
        {
            should_be_uppercase = true;

        }
        else if (should_be_uppercase)
        {
            should_be_uppercase = false;
            initials[initials_counter] = (char) toupper(user_name[i]);
            initials_counter++;
        }
    }
    printf("%s\n", initials);
}