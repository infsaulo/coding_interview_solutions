#include <stdio.h>
#include <stdlib.h>

void rotate90(int clockwise, int **matrix, int dimension)
{

    // Calculate the transpose matrix
    int row;
    for(row=0; row < dimension; row++)
    {
        int column;
        for(column = 0; column < row; column++)
        {
            int tmp = matrix[row][column];
            matrix[row][column] = matrix[column][row];
            matrix[column][row] = tmp;
        }
    }

    // Now decides with invert line ou column according to how rotation direction is desired - -90 or +90
    if(clockwise) // -90
    {
        // Reverse each row
        int row;
        for(row = 0; row < dimension; row++)
        {
            int *ptr1, *ptr2;
            for(ptr1 = &matrix[row][0], ptr2 = &matrix[row][dimension - 1]; ptr2 >= ptr1; ptr1++, ptr2--)
            {
                int tmp = *ptr1;
                *ptr1 = *ptr2;
                *ptr2 = tmp;
            }
        }
    }
    else // +90
    {
        // Reverse each column
        int column;
        for(column = 0; column < dimension; column++)
        {
            int *ptr1, *ptr2;
            for(ptr1 = &matrix[0][column], ptr2 = &matrix[dimension - 1][column]; ptr2 >= ptr1; ptr1+=dimension, ptr2 -=dimension)
            {
                int tmp = *ptr1;
                *ptr1 = *ptr2;
                *ptr2 = tmp;
            }
        }
    }
}

int main()
{
    int matrix[3][3];
    int row, column;
    for(row = 0; row < 3; row++)
    {
        for(column=0; column < 3; column++)
        {
            matrix[row][column] = row + column;
        }
    }

    for(row = 0; row < 3; row++)
    {
        for(column=0; column < 3; column++)
        {
            printf("%d ", matrix[row][column]);
        }
        printf("\n");
    }

    // Rotate -90
    rotate90(1, matrix, 3);

    for(row = 0; row < 3; row++)
    {
        for(column=0; column < 3; column++)
        {
            printf("%d ", matrix[row][column]);
        }
        printf("\n");
    }
   
    // Rotate +90
    rotate90(0, matrix, 3);
    for(row = 0; row < 3; row++)
    {
        for(column=0; column < 3; column++)
        {
            printf("%d ", matrix[row][column]);
        }
        printf("\n");
    }

    return 0;
}
