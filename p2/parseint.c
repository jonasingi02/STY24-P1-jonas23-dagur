#include "parseint.h"
#include <math.h>

/*
 * Returns the value of c or -1 on error
 */
int convertDecimalDigit(char c)
{
    (void)c;
    if (isdigit(c)){
        return c-48;
    }

    return -1;
}

/*
 * Parses a non-negative integer, interpreted as octal when starting with 0,
 * decimal otherwise. Returns -1 on error.
 */
int parseInt(char *string)
{
    (void)string;

    int base = 10, power = 0, retval = 0;

    int len = strlen(string);

    if (len == 0){
        return -1;
    }

    if(string[0] == '0'){
        base = 8;
    }

    string += 1;
    len -= 1;

    for (int i = len-1; i >= 0 ; i--) {
        int digit = convertDecimalDigit(string[i]);

        if (digit == -1){
            return -1;
        }

        retval += digit * (pow(base, power));

        power ++;

    }

    return retval;
}
