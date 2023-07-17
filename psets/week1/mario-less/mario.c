#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int pyramidHeight;

    do
    {
        pyramidHeight = get_int("Height: ");

    } while (pyramidHeight < 1 || pyramidHeight > 8);

    const int ROWLENGTH = 8;
    int bricks;
    int whiteSpace;

    // this one needs to be less than pyramid height, the rows being 8 characters long is independent of the pyramid ehight
    // loop needs to start at 1 because otherwise 8 spaces are printed out
    for (int i = 0; i < pyramidHeight; i++)
    {
        whiteSpace = pyramidHeight - i - 1;
        bricks = i + 1;
        // two variables for eac loop

        // we need two loops
        for (int j = 0; j < whiteSpace; j++)
        {
            printf(" ");

        }

        for (int j = 0; j < bricks; j++)
        {
            printf("#");
        }

        // adds a newline character per row
        printf("\n");
    }
}