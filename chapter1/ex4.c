#include <stdlib.h>
#include <stdio.h>

char* compressString(char *array)
{
    int size, sizeCompressed;
    char *ptr, *setPtr;

    for(size=0; array[size]; size++)
    {
        continue;
    }

    sizeCompressed = 0;
    char *compressedArray = malloc(sizeof(char) * (size*2 + 1));
    char *compressedPtr = compressedArray;
    ptr = array;
    setPtr = ptr;
    while(ptr && *ptr != '\n')
    {
        int count = 0;
        char buffer[128];
	while(*setPtr == *ptr)
        {
	    count++;
	    setPtr++;
        }
	*compressedPtr = *ptr;
	compressedPtr++;
	sizeCompressed++;
        sprintf(buffer, "%d", count);
	char *bufferPtr = buffer;
	while(*bufferPtr)
	{
	    *compressedPtr = *bufferPtr;
	    bufferPtr++;
	    compressedPtr++;
	    sizeCompressed++;
	}
	ptr = setPtr;
    }
    *compressedPtr = '\0';
    compressedPtr++;
    if(sizeCompressed <= size)
    {
        return compressedArray;
    }

    else
    {
        return array;
    }
}

int main()
{
    char *string;
    size_t maxLenght = 128;
    getline(&string, &maxLenght, stdin);
    
    char *compressedString = compressString(string);
    
    printf("%s\n", compressedString);

    return 0;
}
