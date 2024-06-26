//
// Created by mkartv on 26.06.2024.
//
#include "matrix.h"

/**
 * @brief Структура для хранения матрицы
 */
struct Matrix{
    short **data; /**<-Двумерный массив для хранения значений матрицы*/
    int size; /**<-Размер матрицы (N*N)*/
};

Matrix* allocateMatrix (int size){
    Matrix *matrix = (Matrix*)malloc(size*sizeof(Matrix));
    if(!matrix){
        perror ("Не удалось выделить память для структуры матрицы");
        exit(EXIT_FAILURE);
    }

    matrix->data = (short**)malloc(size*sizeof(short*));
    if(!matrix->data){
        perror ("Не удалось выделить память для данных матрицы");
        free(matrix);
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < size; ++i){
        matrix->data[i] = (short*)malloc(size*sizeof(short));
        if(!matrix->data[i]){
            perror("Не удалось выделить память для стркои матрицы");
            for(int j = 0; j < i; ++j){
                free(matrix->data[j]);
            }
            free(matrix->data);
            free(matrix);
            exit(EXIT_FAILURE);
        }
    }
    matrix->size = size;
    return matrix;
}

void freeMatrix(Matrix* matrix){
    for(int i = 0; i < matrix->size; ++i){
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void generateMatrix(Matrix* matrix){
    for(int i = 0; i < matrix->size; ++i)
        for(int j = 0; j < matrix->size; ++j){
            matrix->data[i][j] = (rand()%(MAXVALUE-MINVALUE+1)) + MINVALUE;
        }
}

void printMatrix(Matrix* matrix){
    for(int i = 0; i < matrix->size; ++i) {
        for (int j = 0; j < matrix->size; ++j) {
            printf("%i\t", matrix->data[i][j]);
        }
        printf("\n");
    }
}

int sumOfDiagonals(Matrix* matrix){
    int sumDiag = 0;
    for(int i = 0; i < matrix->size; ++i){
        sumDiag += matrix->data[i][i];
        sumDiag += matrix->data[i][matrix->size-i-1];
    }
    return sumDiag;
}

int minValueOfMainDiagonal(Matrix* matrix){
    int minValue = MAXVALUE+1;
    for(int i = 0; i<matrix->size; ++i){
        for(int j = i + 1; j < matrix->size; j++){
            if(matrix->data[i][j] < minValue){
                minValue = matrix->data[i][j];
            }
        }
    }
    return minValue;
}

int maxValueOfSubDiagonal(Matrix* matrix){
    int maxValue = MINVALUE-1;
    for(int i = 0; i<matrix->size; ++i){
        for(int j = 4; j >= matrix->size-i-1; --j){
            if(matrix->data[i][j] > maxValue){
                maxValue = matrix->data[i][j];
            }
        }
    }
    return maxValue;
}

double averageMatrixValue(Matrix* matrix){
    int sumMatrix = 0;
    for(int i = 0; i < matrix->size; ++i) {
        for (int j = 0; j < matrix->size; ++j) {
            sumMatrix += matrix->data[i][j];
        }
    }
    int matrixValue;
    matrixValue = (matrix->size)^2;

    return ((double)sumMatrix / matrixValue);
}

void checkElementsGreaterThanAverage(Matrix* matrix){
    double average = averageMatrixValue(matrix);
    printf("\nЭлементы больше среднего значения матрицы(%f): \n", average);
    for(int i = 0; i< matrix->size; ++i){
        for(int j = 0; j < matrix->size; ++j){
            if(matrix->data[i][j] > average){
                printf("%d\t", matrix->data[i][j]);
            }
        }
    }
    printf("\n");
}

void changeMatrixNegative(Matrix* matrix){
    for(int i = 0; i < matrix->size; ++i){
        for(int j = 0; j < matrix->size; ++j){
            if(matrix->data[i][j] < 0){
                matrix->data[i][j] = -matrix->data[i][j];
            }
        }
    }
}

void changeMatrixDivisibleFive(Matrix* matrix){
    for(int i = 0; i < matrix->size; ++i){
        for(int j = 0; j < matrix->size; ++j){
            if(matrix->data[i][j]%5==0){
                matrix->data[i][j] = 0;
            }
        }
    }
}