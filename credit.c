#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");        //long i = get_long("Enter a long: ");
    }
    while (number <= 0 || number > 10000000000000000);

    int l = 0;            // l = ilości cyfr w liczbie
    long n = number;    // dlaczego musi byc n bo zmienia "number" n /= 10;
    while (n > 0)
    {
        n /= 10;
        l++;
    }

    int c1 = number % 10;                   // 16 cyfra         - c1
    int c2 = (number / 10) % 10;  // *2
    int c3 = (number / 100) % 10;
    int c4 = (number / 1000) % 10;  // *2
    int c5 = (number / 10000) % 10;
    int c6 = (number / 100000) % 10;  // *2
    int c7 = (number / 1000000) % 10;
    int c8 = (number / 10000000) % 10;  // *2
    int c9 = (number / 100000000) % 10;
    int c10 = (number / 1000000000) % 10; // *2
    int c11 = (number / 10000000000) % 10;
    int c12 = (number / 100000000000) % 10; // *2
    int c13 = (number / 1000000000000) % 10;
    int c14 = (number / 10000000000000) % 10; // *2
    int c15 = (number / 100000000000000) % 10;
    int c16 = (number / 1000000000000000) % 10;  // *2  // pierwsza cyfra   - c16

    // suma cyfr z iloczynu co 2

    int sum_i_cyfr = ((c2 * 2) % 10 + ((c2 * 2) / 10) % 100)
                     + ((c4 * 2) % 10 + ((c4 * 2) / 10) % 100)
                     + ((c6 * 2) % 10 + ((c6 * 2) / 10) % 100)
                     + ((c8 * 2) % 10 + ((c8 * 2) / 10) % 100)
                     + ((c10 * 2) % 10 + ((c10 * 2) / 10) % 100)
                     + ((c12 * 2) % 10 + ((c12 * 2) / 10) % 100)
                     + ((c14 * 2) % 10 + ((c14 * 2) / 10) % 100)
                     + ((c16 * 2) % 10 + ((c16 * 2) / 10) % 100);

    int sum_p = c1 + c3 + c5 + c7 + c9 + c11 + c13 + c15;   // suma pozostalych
    int test = (sum_p + sum_i_cyfr) % 10;

    int one_n = (number / pow(10, (l - 1)));
    one_n = one_n % 10;

    int two_n = (number / pow(10, (l - 2)));
    two_n = two_n % 10;

    if (test == 0  && one_n == 4 && (l == 16 || l == 13))
    {
        printf("VISA\n");
    }
    else if (test == 0 && l == 15 && (one_n == 3 && (two_n == 4 || two_n == 7)))
    {
        printf("AMERICANEXPRESS\n");
    }
    else if (test == 0 && l == 16) // (one_n == 5 && (two_n > 0 || two_n < 7))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

}
