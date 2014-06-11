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
            int column1, column2;
            for(column1 = 0, column2 = dimension -1; column2 >= column1; column1++, column2--)
            {
                int tmp = matrix[row][column1];
                matrix[row][column1] = matrix[row][column2];
                matrix[row][column2] = tmp;
            }
        }
    }
    else // +90
    {
        // Reverse each column
        int column;
        for(column = 0; column < dimension; column++)
        {
            int row1, row2;
            for(row1 = 0, row2 = dimension - 1; row2 >= row1; row1++, row2 --)
            {
                int tmp = matrix[row1][column];
                matrix[row1][column] = matrix[row2][column];
                matrix[row2][column] = tmp;
            }
        }
    }
}

int main()
{
    int **matrix = malloc(sizeof(int*) * 3);
    int index;
    for(index=0; index < 3; index++)
    {
	    matrix[index] = malloc(sizeof(int) * 3);
    }

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

    for(index=0; index < 3; index++)
    {
	    free(matrix[index]);
    }

    free(matrix);

    return 0;
}
