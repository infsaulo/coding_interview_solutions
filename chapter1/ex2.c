#include <stdio.h>
#include <stdlib.h>

void reverse(char *str)
{
    if(str)
    {
        char *end = str;
        while(*end)
        {
            end++;
        }
        end--;

        while(str < end)
        {
            char tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
}

int main()
{
    char string[128];

    scanf("%s", string);
    
    printf("%s\n", string);
    
    reverse(string);
    
    printf("%s\n", string);
    
    return 0;
}
