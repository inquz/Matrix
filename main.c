#include "src/matrix.h"

int main(){
    #ifdef _WIN32
        system("chcp 65001");
    #endif

    int N;
    printf( "Введите размер матрицы: \n" );
    scanf("%i", &N);

    if(5 > N){
        fprintf(stderr, "Размер матрциы должен быть больше или равен 5\n");
        return EXIT_FAILURE;
    }

    Matrix* matrix = allocateMatrix(N);

    srand(time(NULL));
    generateMatrix(matrix);
    printf("Изначальная матрица: \n");
    printMatrix(matrix);

    printf("\nСумма диагоналей: %i\n", sumOfDiagonals(matrix));
    printf("\nМинимальное значение элементов над основой диагональю: %i\n", minValueOfMainDiagonal(matrix));
    printf("\nМаксимальное значение элементов под побочной диагональю : %i\n", maxValueOfSubDiagonal(matrix));

    checkElementsGreaterThanAverage(matrix);

    changeMatrixNegative(matrix);
    printf("\nОбновленная матрица после замены отрицательных элементов на положительные: \n");
    printMatrix(matrix);

    changeMatrixDivisibleFive(matrix);
    printf("\nОбновленная матрица после обнуления элементов, делимых на пять: \n");
    printMatrix(matrix);


    freeMatrix(matrix);
    return 0;
}