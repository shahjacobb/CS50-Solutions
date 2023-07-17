#include <stdio.h>
#include <cs50.h>

int getPyramidHeight()
{

    int height;

    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 20);

    return height;
}
void printPyramids(int height)
{
    for (int i = 1; i <= height; i++)
    {
        // right aligned, spaces first, then hashes
        // left aligned, hashes first, then spaces
        int spaces = height - i;
        int hashes = i;

        // left aligned tower
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < hashes; j++)
        {
            printf("#");
        }

        // space between towers
        printf("  ");

        // okay, now the right aligned  tower
        for (int j = 0; j < hashes; j++)
        {
            printf("#");
        }
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        // don't forget the new line for each row!
        printf("\n");
    }
}

int main()
{
    int pyramidHeight = getPyramidHeight();
    printPyramids(pyramidHeight);
}