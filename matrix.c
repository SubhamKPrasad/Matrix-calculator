#include <stdio.h>

#define MAX 10

void readMatrix(int matrix[MAX][MAX], int rows, int cols);
void printMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int r1, int c1, int r2, int c2);
void transposeMatrix(int mat[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main()
{
    // Declare all variables at the top
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    printf("--- Matrix Operations Menu ---\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Matrix Transpose\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1: // Addition
        printf("Enter rows and columns: ");
        scanf("%d %d", &r1, &c1);

        printf("Enter elements of Matrix 1:\n");
        readMatrix(mat1, r1, c1);

        printf("Enter elements of Matrix 2:\n");
        readMatrix(mat2, r1, c1);

        addMatrices(mat1, mat2, result, r1, c1);

        printf("\nResult of Addition:\n");
        printMatrix(result, r1, c1);
        break;

    case 2: // Multiplication
        printf("Enter rows and columns for Matrix 1: ");
        scanf("%d %d", &r1, &c1);
        printf("Enter rows and columns for Matrix 2: ");
        scanf("%d %d", &r2, &c2);

        // Check if multiplication is mathematically possible
        if (c1 != r2)
        {
            printf("Error: Columns of first matrix must equal rows of second.\n");
            break;
        }

        printf("Enter elements of Matrix 1:\n");
        readMatrix(mat1, r1, c1);

        printf("Enter elements of Matrix 2:\n");
        readMatrix(mat2, r2, c2);

        multiplyMatrices(mat1, mat2, result, r1, c1, r2, c2);

        printf("\nResult of Multiplication:\n");
        printMatrix(result, r1, c2);
        break;

    case 3: // Transpose
        printf("Enter rows and columns: ");
        scanf("%d %d", &r1, &c1);

        printf("Enter elements of the Matrix:\n");
        readMatrix(mat1, r1, c1);

        transposeMatrix(mat1, result, r1, c1);

        printf("\nTransposed Matrix:\n");
        // For transpose, we flip the rows and columns when printing
        printMatrix(result, c1, r1);
        break;

    default:
        printf("Invalid choice!\n");
    }

    return 0;
}

// --- Function Definitions ---

void readMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n"); // Move to the next line after printing a row
    }
}

void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int r1, int c1, int r2, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0; // Start with 0 before adding the multiplied parts
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[MAX][MAX], int result[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = mat[i][j]; // Swap the row and column positions
        }
    }
}