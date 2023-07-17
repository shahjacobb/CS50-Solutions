#include <stdio.h>
#include <ctype.h>
#include <cs50.h>

int main()
{
    char val = 'A';
    printf("%i\n", (val + 5) % 26 );
    printf("%c\n", (val + 5) % 26 );

;}