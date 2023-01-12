#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void matrix_A ( int ** A, int row, int col);
void matrix_B ( int ** B, int row, int col);
void max_min ( int ** A, int row, int col);
void matrix_print(int **, int, int);
void transposition ( int ** B, int row, int col);
void multiply ( int ** A, int row, int col, int ** B );
void sort(int** A, int row);
void summ (int **A, int **B, int row, int col, int sumA, int sumB);
int main()

{
    int **A;
    int **B;
    int row, col;
    int choice;
    int e = 0;
    int sumA = 0, sumB = 0;

    srand(time(NULL));
    printf("\nEnter number of rows\n>");
    scanf (" %d", &row);
    printf("\nEnter number of columns\n>");
    scanf (" %d", &col);

    A = (int **) calloc (row, sizeof (int *));
    if( A == NULL )
    {
        printf("Memory has not been allocated");
        exit(0);
    }
    for(int i = 0; i < row; i++)
    {
        A[i] = (int *) calloc (row, sizeof (int));
        if(A[i]==NULL)
        {
            printf("Memory has not been allocated");
            exit(0);
        }
    }

    B = (int **) calloc (row, sizeof (int *));
    if( B == NULL )
    {
        printf("Memory has not been allocated");
        exit(0);
    }
    for(int i = 0; i < row; i++)
    {
        B[i] = (int *) calloc (col, sizeof (int));
        if(B[i]==NULL)
        {
            printf("Memory has not been allocated");
            exit(0);
        }
    }
    matrix_A(A,row,row);
    matrix_B(B,row,col);

    do
    {
        system("cls");
        printf("Matrix A:\n");
        matrix_print(A,row,row);
        printf("Matrix B:\n");
        matrix_print(B,row,col);
        printf("Select operations on matrices:\n");
        printf("1: Maximum value matrix A\n");
        printf("2: Transpose the matrix B\n");
        printf("3: Find the matrix product A*B\n");
        printf("4: Sort the elements of array A\n");
        printf("5: Sum of the elements\n");
        printf("6: Exit\n>");
        scanf("%d", &choice);
        if (choice == 1)
        {
            max_min (A, row, row);
            system("pause");
        }
        else if(choice == 2)
        {
            transposition (B, row, col);
            system("pause");
        }
        else if(choice == 3)
        {
            multiply (A, row, col,B);
            system("pause");
        }
        else if(choice == 4)
        {
            sort (A, row);
            system("pause");
        }
        else if(choice == 5)
        {
            summ (A, B, row, col, sumA, sumB);
            system("pause");
        }
        else if(choice == 6)
        {
            e = 1;
        }
    }
    while(e == 0);

    for (int i = 0; i < row; i++)
    {
        free(A[i]);
    }
    free(A);
    for (int i = 0; i < row; i++)
    {
        free(B[i]);
    }
    free(B);
    return 0;
}

//---------------------------------------------------------------------------------------

void matrix_A ( int ** A, int row, int col)
{
    const int min_r = 0;
    const int max_r = 23;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            A[i][j] = min_r + rand() % (max_r - min_r + 1);
        }
    }
}

//---------------------------------------------------------------------------------------

void matrix_B ( int ** B, int row, int col)
{
    const int min_r = 0;
    const int max_r = 23;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            B[i][j] = min_r + rand() % (max_r - min_r + 1);
        }
    }
}

//---------------------------------------------------------------------------------------


void matrix_print(int ** M, int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("  %d  ",M[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

//---------------------------------------------------------------------------------------

void max_min ( int ** A, int row, int col)
{
    int max_element;
    int min_element;
    max_element = A[0][0];
    min_element = A[0][0];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<row; j++)
        {
            if (A[i][j] > max_element)
            {
                max_element = A[i][j];
            }
        }
    }
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<row; j++)
        {
            if (A[i][j] < min_element)
            {
                min_element = A[i][j];
            }
        }
    }
    printf("\n Max_element = %d  ",max_element);
    printf("\n Min_element = %d  \n",min_element);
}

//---------------------------------------------------------------------------------------

void transposition ( int ** B, int row, int col )
{
    int **T;
    int row_T;
    int col_T;
    row_T = col;
    col_T = row;
    T = (int **) calloc (row_T, sizeof (int *));
    if( T == NULL )
    {
        printf("Memory has not been allocated");
        exit(0);
    }
    for(int i = 0; i < row_T; i++)
    {
        T[i] = (int *) calloc (col_T, sizeof (int));
        if(T[i]==NULL)
        {
            printf("Memory has not been allocated");
            exit(0);
        }
    }
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            T[j][i]=B[i][j];
        }
    }
    matrix_print(T,row_T,col_T);
}

//---------------------------------------------------------------------------------------

void multiply ( int ** A, int row, int col, int ** B )
{
    int **D;
    int rows_C;
    int colums_S;
    int x;
    int y;
    rows_C = row;
    colums_S = col;
    D = (int **) calloc (rows_C, sizeof (int *));
    if( D == NULL )
    {
        printf("Memory has not been allocated");
        exit(0);
    }
    for(int i = 0; i < rows_C; i++)
    {
        D[i] = (int *) calloc (colums_S, sizeof (int));
        if(D[i]==NULL)
        {
            printf("Memory has not been allocated");
            exit(0);
        }
    }
    for(int i=0; i<rows_C; i++)
    {
        for(int j=0; j<colums_S; j++)
        {
            x = 0;
            for(int p=0; p<rows_C; p++)
            {
                y = (A[i][p])*(B[p][j]);
                x = x+y;
            }
            D[i][j]=x;
        }
    }
    matrix_print(D,rows_C,colums_S);

}

//---------------------------------------------------------------------------------------

void sort (int **A, int row)
{
    int** C = (int **) calloc (row, sizeof (int *));
    if( C == NULL )
    {
        printf("Memory has not been allocated");
        exit(0);
    }
    for(int i = 0; i < row; i++)
    {
        C[i] = (int *) calloc (row, sizeof (int));
        if(C[i]==NULL)
        {
            printf("Memory has not been allocated");
            exit(0);
        }
    }
    for (int i=0; i<row; i++)
        for (int j=0; j<row; j++)
            C[i][j] = A[i][j];
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<row; j++)
        {
            int mini = C[i][j];

            int x = i;
            int y = j;

            int w = j;

            for (int k = i; k < row; k++)
            {
                for (w; w < row; w++)
                {
                    if (C[k][w] < mini)
                    {
                        mini = C[k][w];
                        x = k;
                        y = w;
                    }
                }
                w = 0;
            }
            int temp = C[i][j];
            C[i][j] = C[x][y];
            C[x][y] = temp;
        }
    }

    printf("\nSorted A: \n");
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<row; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++)
    {
        free(C[i]);
    }
    free(C);
}
//---------------------------------------------------------------------------------------

void summ (int **A, int **B, int row, int col, int sumA, int sumB)
{

    for(int i=0; i<row; i++)
    {
        sumA=0;
        for(int j=0; j<row; j++)
        {
            sumA += A[i][j];
        }
        printf("\n Sum of a rows %d of the matrix A = %d",(i+1),sumA);
    }

    for(int j=0; j<col; j++)
    {
        sumB=0;
        for(int i=0; i<row; i++)
        {
            sumB += B[i][j];
        }
        printf("\n Sum of a column %d of the matrix B = %d",(j+1),sumB);
    }
    printf("\n");
}
