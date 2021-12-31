#include <stdio.h>

#define max_yr 9999
#define min_yr 1800

int leap_year(int a);
int valid_date(int x, int y, int z);
int main(void)
{
    // Ask user for the date.
    int d, m, yr;
    printf("Please input the day: ");
    scanf("%d", &d);
    printf("Please input the month: ");
    scanf("%d", &m);
    printf("Please input the year: ");
    scanf("%d", &yr);

    // Validate the date.
    // I declared a variable leap to be able to apply the leap year function.
    int leap = leap_year(yr);
    if (valid_date(d, m, yr))
    {
        if (leap)
        {
            printf("This is a leap year!\n");
        }
        printf("This is a valid date!");
    }
    else
        printf("This is an invalid date!");
    return 0;
}

int leap_year(int a)
{
    // A leap year is divisible by 4.
    if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// This function is meant to check whether the date entered is valid.
// It validates every distinct unit of a year.
int valid_date(int x, int y, int z)
{
    // Check if the years and months are valid.
    if (z < min_yr || z > max_yr)
        return 0;
    if (y < 1 || y > 12)
        return 0;
    if (x < 1 || x > 31)
        return 0;
    // This validates the month of Feb on normal and leap years.
    if (y == 2)
    {
        if (leap_year(z))
        {
            if (x <= 29)
                return 1;
        }
        else if (x > 28)
        {
            return 0;
        }
    }
    // This validates those months that have 30 days.
    if (y == 4 || y == 6 || y == 9 || y == 11)
    {
        if (x > 30)
            return 0;
    }
}
