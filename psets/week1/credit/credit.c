#include <cs50.h>
#include <stdio.h>

/*
TODO
- add last step of logic for adding every other digit multiplied by two
- print out AMEX\n, VISA\n, or MASTERCARD\n for card entered (if valid)
- print out INVALID\n if not valid
*/
// might need to rename type

string LuhnsAlgorithm(long ccNumber);
int main(void)
{

    long number;
    do
    {
        number = get_long("Enter a valid credit card number\n");
    } while (number < 0);
    printf("%s", LuhnsAlgorithm(number));
}

string LuhnsAlgorithm(long ccNumber)
{

    long workingCC = ccNumber;
    int ccLength = 0, lastSum = 0, everyOtherSum = 0, totalSum;

    while (workingCC > 0)
    {
        lastSum += workingCC % 10;
        workingCC /= 10;
        ccLength++;
        int everyOtherDigit = workingCC % 10 * 2;
        // if the product is greater than 10...
        if (everyOtherDigit >= 10)
            everyOtherSum += (everyOtherDigit % 10) + (everyOtherDigit / 10);
        // we need to use an else block (i think), otherwise it'll repeat it
        else
        {
            everyOtherSum += everyOtherDigit;
        }
        workingCC /= 10;
        ccLength++;
    }

    // at the end here, if last sum + everOther isn't congruent to 0, return INVALID
    totalSum = lastSum + everyOtherSum;

    if (totalSum % 10 != 0)
        return "INVALID\n";

    /*
    okay, if it IS valid, we need to determine the card network
    remember how we used a copy of the ccnumber argument passed in to 'trim' down the cc number and do the check sum logic? we're going to use the original to determine the card network
*/

    // checking if it's greater than 100 works because the moment it's just 3 digits long, it passes the condition of the while loop divides and reassigns the cc number to two digits
    while (ccNumber > 100)
    {
        ccNumber /= 10;
    }

    // now we use if statements to check what it belongs to

    // these numbers are numbers relevant to the card networks
    /*
    AMEX: starts with 34 or 37. Must be 15 digits
    MASTERCARD: starts with 51, 52, 53, 54, 55. Must be 16 digits
    VISA: starts with 4. Must be 13 or 16 digits

    */

    if ((ccNumber == 34 || ccNumber == 37) && ccLength == 15)
    {
        return "AMEX\n";
    }
    if ((ccNumber > 50 && ccNumber < 55) && ccLength == 16)
    {

        return "MASTERCARD\n";
    }
    if ((ccNumber == 4) && (ccLength == 13 || ccLength == 16))
    {

        return "VISA\n";
    }

    return "INVALID\n";
}