#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

class ZeroMatrix
{
    int **matrix;
    int dimensionRow, dimensionColumn;

    public:
    ZeroMatrix(int dimensionRow, int dimensionColumn);
    void makeZero();
    int **getMatrix();
    ~ZeroMatrix();
};

ZeroMatrix::ZeroMatrix(int dimensionRow, int dimensionColumn)
{
    this->dimensionRow = dimensionRow;
    this->dimensionColumn = dimensionColumn;

    matrix = new int*[this->dimensionRow];
    for(int indexRow = 0; indexRow < this->dimensionColumn; indexRow++)
    {
        matrix[indexRow] = new int[this->dimensionColumn];
    }

    srand(time(NULL));
    for(int indexRow = 0; indexRow < dimensionRow; indexRow++)
    {
        for(int indexColumn = 0; indexColumn < dimensionColumn; indexColumn++)
        {
             matrix[indexRow][indexColumn] = rand() % 10;
        }
    }
}

void ZeroMatrix::makeZero()
{
    set<int> rowSet, columnSet;

    for(int indexRow = 0; indexRow < dimensionRow; indexRow++)
    {
        for(int indexColumn = 0; indexColumn < dimensionColumn; indexColumn++)
        {
            if(matrix[indexRow][indexColumn] == 0)
            {
                rowSet.insert(indexRow);
                columnSet.insert(indexColumn);
            }
        }
    }
    
    for(set<int>::iterator it = rowSet.begin(); it != rowSet.end(); it++)
    {
        for(int column = 0; column < dimensionColumn; column++)
        {
            matrix[*it][column] = 0;
        }
    }
    
    for(set<int>::iterator it = columnSet.begin(); it != columnSet.end(); it++)
    {
        for(int row = 0; row < dimensionColumn; row++)
        {
            matrix[row][*it] = 0;
        }
    }

}

int** ZeroMatrix::getMatrix()
{
    return matrix;
}

ZeroMatrix::~ZeroMatrix()
{
    for(int index=0; index < dimensionRow; index++)
    {
        delete matrix[index];
    }
    
    delete matrix;
}

int main()
{
    ZeroMatrix matrix(5, 6);
    
    int **beforeZeroMatrix = matrix.getMatrix();
    for(int indexRow = 0; indexRow < 5; indexRow++)
    {
        for(int indexColumn = 0; indexColumn < 6; indexColumn++)
        {
            printf("%d ", beforeZeroMatrix[indexRow][indexColumn]);
        }
        printf("\n");
    }
    
    printf("\n");
        
    matrix.makeZero();

    int **zeroMatrix = matrix.getMatrix();
    for(int indexRow = 0; indexRow < 5; indexRow++)
    {
        for(int indexColumn = 0; indexColumn < 6; indexColumn++)
        {
            printf("%d ", zeroMatrix[indexRow][indexColumn]);
        }
        printf("\n");
    }

    return 0;
}
