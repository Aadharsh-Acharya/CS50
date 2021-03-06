#include <cs50.h>
#include <stdio.h>

int main(void){

    long card = get_long("Number: ");
    int j = 0;
    long sum = 0;

    for(long copy = card; copy >= 1; copy /= 10)
    {
        long digit = copy % 10;
        copy -= digit;
        
        if ((j % 2) == 0){
            sum += digit;
        }
        else if (digit >= 5)
        {
            sum += (((2 * digit) % 10) + 1);
        }
        else
        {
            sum += (2 * digit);
        }
        j++;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        int length = 0;
        while(card >= 100)
        {
            card /= 10;
            length++;
        }
        int first = card;

        if ((first == 34 || first == 37) && (length == 13))
        {
            printf("AMEX\n");
        }
        else if ((first == 51 || first == 52 || first == 53 || first == 54 || first == 55) && (length == 14);
        {
            printf("MASTERCARD\n");
        }
        else if ((first % 40 < 10) && ((length == 11) || (length == 14))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
