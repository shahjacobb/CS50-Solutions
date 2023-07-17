#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*
TODO
- parse the string that was inputted as plaintest by get_string at run time. make sure it's valid. the hardest part of the logic by far
- only rotate alphabetical characters (uppercase and lower case). which means two cases of logic for both letters
    - our previous logic wasn't working because we forgot that upper case and lower case letters each have different ASCII values
      doing (p + k) % 26 was outputting some gibberish value since when you do the arithmethic,  then it gets mapped to whatever corresponding ascii value
-
*/

bool caesarArgumentVerifier(int argc, string argv[]);
string caesar_cipher(string plaintext, int shift);

int main(int argc, string argv[])
{
    string plaintext, ciphertext;
    int shift;
    // we'll need to pass in the shfit as an argument to the caesar function. atoi is necessary, because remember, command line args are strings

    if (argc != 2)
    {
    printf("Usage: ./caesar key\n");
    return 1;
    }


    shift = atoi(argv[1]);



    if (caesarArgumentVerifier(argc, argv))
    {

        plaintext = get_string("plaintext:  ");
        ciphertext = caesar_cipher(plaintext, shift);
        printf("ciphertext:   %s\n", ciphertext);
    }

    else
    {
        return 1;
    }
}

bool caesarArgumentVerifier(int argc, string argv[])
{
    string commandLineArg = argv[1];
    // check if every digit in the arg is a valid digit or not
    // wasn't specified in the pset description, but you need to run a check for a non negative input
    if (commandLineArg[0] == '-')
        printf("Usage: ./caesar key");

    for (int i = 0; i < strlen(commandLineArg); i++)
    {

        if (!isdigit(commandLineArg[i]))
        {
            printf("Usage: ./caesar key");
            return false;
        }


    }
    return true;


}

string caesar_cipher(string plaintext, int shift)
{

    string ciphertext = plaintext;

    for (int i = 0; i < strlen(ciphertext); i++)
    {
        // for upper case letters, we need to first 'normalize' them since A starts at 65, NOT 0 as we mistakenly thought
        if (isupper(ciphertext[i]))
            ciphertext[i] = (ciphertext[i] - 'A' + shift) % 26 + 'A';
        // similarly, for lower case letters, we need to 'normalize' them', since a starts at 97 and not 0
        // however, we need to use an else if since it's also possible that non letter valid characters are present. it's not binary. ex: '!', '100'
        else if (islower(ciphertext[i]))
            ciphertext[i] = (ciphertext[i] - 'a' + shift) % 26 + 'a';
    }
    return ciphertext;
}
