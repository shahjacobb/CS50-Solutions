#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // initialize variables
    int initialSize, currentSize, endingSize, years = 0;

    do
    {

        initialSize = get_int("Start size: ");

    }

    while (initialSize < 9);

    do
    {
        endingSize = get_int("End size: ");
    } while (endingSize < initialSize);

    // population growth logic

    // feels bizarre to keep track of state using the initial start variable, so i'll just track state in this variable called currentSize
    currentSize = initialSize;

    while (currentSize < endingSize) // it needs to be less than and not less than or equal to. if it's less than or equal to, it'll try to calculating years. however, a starting and ending state of 9 would be 0 years.
    {
        int llamaGain = currentSize / 3;
        int llamaLoss = currentSize / 4;

        currentSize += (llamaGain - llamaLoss);

        years++;
    }

    // TODO: Print number of years

    printf("Years: %d\n", years);
}
