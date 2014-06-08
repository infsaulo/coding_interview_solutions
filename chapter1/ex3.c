#include <stdio.h>

#define AMOUT_ASCII 128

int isPermutation(char *str1, char *str2)
{
    int counterCharStr1List[128];
    int counterCharStr2List[128];
    int index;
    for(index=0; index < AMOUT_ASCII; index++)
    {
        counterCharStr1List[index] = 0;
        counterCharStr2List[index] = 0;
    }

    char *chPtr = str1;
    while(*chPtr)
    {
        counterCharStr1List[(int)*chPtr] += 1;
        chPtr++;
    }
    chPtr = str2;
    while(*chPtr)
    {
        counterCharStr2List[(int)*chPtr] += 1;
        chPtr++;
    }

    for(index=0; index < AMOUT_ASCII; index++)
    {
        if(counterCharStr1List[index] != counterCharStr2List[index])
        {
            return 0;
        }
    }

    return 1;

}

int main()
{
    char *str1, *str2;
    size_t len = 128;

    getline(&str1, &len, stdin);
    getline(&str2, &len, stdin);

    if(isPermutation(str1, str2))
    {
        printf("Both strings are a permutation of each other\n");
    }

    else
    {
        printf("The strings aren\'t a permutation of each other\n");
    }

    return 0;
}
