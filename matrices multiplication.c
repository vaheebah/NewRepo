#include <stdio.h>


void getmatrixelements(int matrix[][10], int rows, int cols)
{
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; ++i)
        {
        for (int j = 0; j < cols; ++j)
            {
                printf("Enter element for row %d and column %d: ", i + 1, j + 1);
                scanf("%d", &matrix[i][j]);
            }
        }
}

//multiplying matrices
void multiplymatrices(int firstMatrix[][10], int secondMatrix[][10], int result[][10], int rows1, int cols1, int rows2, int cols2)
{

    if (cols1 != rows2)
        {
            printf("Error: Number of columns in the first matrix should be equal to the number of rows in the second matrix.\n");
            return;
        }


    for (int i = 0; i < rows1; ++i)
        {
        for (int j = 0; j < cols2; ++j)
            {
                result[i][j] = 0;
            }
        }


    for (int i = 0; i < rows1; ++i)
        {
            for (int j = 0; j < cols2; ++j)
            {
                for (int k = 0; k < cols1; ++k)
                    {
                        result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
                    }
            }
        }
}


void display(int matrix[][10], int rows, int cols)
{
    printf("Resultant matrix:\n");
    for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
                {
                    printf("%d\t", matrix[i][j]);
                }
            printf("\n");
        }
}

int main()
{
    int rows1, cols1, rows2, cols2;


    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);


    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);


    while (cols1 != rows2)
        {
            printf("Error: Number of columns in the first matrix should be equal to the number of rows in the second matrix.\n");


            printf("Enter the number of rows and columns for the first matrix: ");
            scanf("%d %d", &rows1, &cols1);

            printf("Enter the number of rows and columns for the second matrix: ");
            scanf("%d %d", &rows2, &cols2);
        }

    int firstMatrix[10][10], secondMatrix[10][10], result[10][10];


    printf("\nFor the first matrix:\n");
    getmatrixelements(firstMatrix, rows1, cols1);

    printf("\nFor the second matrix:\n");
    getmatrixelements(secondMatrix, rows2, cols2);


    multiplymatrices(firstMatrix, secondMatrix, result, rows1, cols1, rows2, cols2);


    display(result, rows1, cols2);

    return 0;
}
