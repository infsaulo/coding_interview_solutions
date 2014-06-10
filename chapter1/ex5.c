#include <stdlib.h>
#include <stdio.h>

void replaceSpaces(char *string, int length)
{
    int amountSpaces = 0;
    char *ptr, *shiftPtr;

    ptr = string;
    while(*ptr)
    {
        if(*ptr == ' ')
	{
	    amountSpaces++;
	}

	ptr++;
    }

    amountSpaces /= 3;
    ptr--;
    shiftPtr = ptr;
    ptr = string + length - 1;

    int index;
    for(index=length-1; index >= 0; index--, ptr--)
    {
        if(*ptr != ' ')
	{
            *shiftPtr = *ptr;
	    shiftPtr--;
	}
	else
	{
	    *shiftPtr = '0';
            shiftPtr--;
	    *shiftPtr = '2';
	    shiftPtr--;
	    *shiftPtr = '%';
	    shiftPtr--;

	}
    }
}

int main()
{
    char string[13];
    sprintf(string, "saulo marq  ");
    replaceSpaces(string, 10);
    printf("%s\n", string);

    return 0;
}
