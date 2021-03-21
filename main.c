#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//You have two valid square matrices of order N.
//Find a new matrix by adding to the elements of each row of the first matrix the product of the elements of the corresponding rows of the second matrix.

void fillMatrix(int**, int);
void printMatrix(int**, int);
int ** allocateMemoryForIntMatrix(int);
void freeMemoryFromIntMatrix(int ***, int);

int main() {
    int n;
    printf("declare the size of the square matrices > ");
    scanf("%d",&n);

    int** aMatrix = allocateMemoryForIntMatrix(n);
    int** bMatrix = allocateMemoryForIntMatrix(n);
    int** resultMatrix = allocateMemoryForIntMatrix(n);

    printf("Fill A matrix:\n");
    fillMatrix(aMatrix,n);

    printf("\nFill B matrix:\n");
    fillMatrix(bMatrix, n);

    printf("\nA matrix:\n");
    printMatrix(aMatrix,n);

    printf("\nB matrix:\n");
    printMatrix(bMatrix, n);

    for(int i=0;i<n;i++)
    {
        int multi = 1;
        for(int j=0;j<n;j++)
        {
            multi *= bMatrix[i][j];
        }
        for(int j=0;j<n;j++)
        {
            resultMatrix[i][j] = aMatrix[i][j] + multi;
        }
    }

    printf("\nResult matrix:\n");
    printMatrix(resultMatrix,n);

    freeMemoryFromIntMatrix(&aMatrix, n);
    freeMemoryFromIntMatrix(&bMatrix, n);
    freeMemoryFromIntMatrix(&resultMatrix, n);

    return 0;
}

void fillMatrix(int** matrix,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("[%d][%d] > ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
}

void printMatrix(int** matrix,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%4d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int ** allocateMemoryForIntMatrix(int n) {
    int ** addrInHeap = (int **) malloc(sizeof(int *) * n);
    assert(addrInHeap != NULL);

    for(int i=0; i<n; i++) {
       addrInHeap[i] = (int*)malloc(sizeof(int) * n);
    }
    return addrInHeap;
}

void freeMemoryFromIntMatrix(int *** pointer, int rows) {
    for (int i = 0; i < rows; i++) {
        free((*pointer)[i]);
    }
    free(*pointer);
    *pointer = NULL;
}


