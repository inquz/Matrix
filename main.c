#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINVALUE -100
#define MAXVALUE 100

void generateMatrix(short **matrix, int N){
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j){
            matrix[i][j] = (rand()%(MAXVALUE-MINVALUE+1)) + MINVALUE;
        }
}

void printMatrix(short **matrix, int N){
    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%i\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int sumOfDiagonals(short **matrix, int N){
    int sumDiag = 0;
    for(int i = 0; i < N; ++i){
         sumDiag += matrix[i][i];
         sumDiag += matrix[i][N-i-1];
    }
    return sumDiag;
}

int minValueOfMainDiagonal(short **matrix, int N){
    int minValue = MAXVALUE+1;
    for(int i = 0; i<N; ++i){
        for(int j = i + 1; j < N; j++){
            if(matrix[i][j] < minValue){
                minValue = matrix[i][j];
            }
        }
    }
    return minValue;
}

int maxValueOfSubDiagonal(short **matrix, int N){
    int maxValue = MINVALUE-1;
    for(int i = 0; i<N; ++i){
        for(int j = 4; j >= N-i-1; --j){
            if(matrix[i][j] > maxValue){
                maxValue = matrix[i][j];
            }
        }
    }
    return maxValue;
}

double averageMatrixValue(short **matrix, int N){
    int sumMatrix = 0;
    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            sumMatrix += matrix[i][j];
        }
    }
    int matrixValue;
    matrixValue = N * N;

    return ((double)sumMatrix / matrixValue);
}

void checkElementsGreaterThanAverage(short **matrix, int N){
    double average = averageMatrixValue(matrix, N);
    printf("\nElements greater than average(%f): \n", average);
    for(int i = 0; i<N;++i){
        for(int j = 0; j < N; ++j){
            if(matrix[i][j] > average){
                printf("%d\t", matrix[i][j]);
            }
        }
    }
    printf("\n");
}

void changeMatrixNegative(short **matrix, int N){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(matrix[i][j] < 0){
                matrix[i][j] = -matrix[i][j];
            }
        }
    }
}

void changeMatrixDivisibleFive(short **matrix, int N){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(matrix[i][j]%5==0){
                matrix[i][j] = 0;
            }
        }
    }
}

int main(){

    int N;
    printf( "Enter matrix size: \n" );
    scanf("%i", &N);

    while(N < 5){
        printf("Error\n:");
        scanf("%i", &N);
    }

    short **matrix = (short**)malloc(N*sizeof(short*));
    for(int i = 0; i < N; ++i){
        matrix[i] = (short*)malloc(N*sizeof(short));
    }

    srand(time(NULL));
    generateMatrix(matrix, N);
    printf("Original matrix: \n");
    printMatrix(matrix, N);

    printf("\nSum of diags: %i\n", sumOfDiagonals(matrix, N));
    printf("\nMinValue: %i\n", minValueOfMainDiagonal(matrix, N));
    printf("\nMaxValue: %i\n", maxValueOfSubDiagonal(matrix, N));

    checkElementsGreaterThanAverage(matrix, N);

    changeMatrixNegative(matrix, N);
    printf("\nNew matrix after replacing negative numbers: \n");
    printMatrix(matrix, N);

    changeMatrixDivisibleFive(matrix, N);
    printf("\nNew matrix after replacing numbers, which are divisible by 5 with zeros: \n");
    printMatrix(matrix, N);


    free(matrix);
    return 0;
}
