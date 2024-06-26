//
// Created by mkartv on 26.06.2024.
//

#ifndef TRAINING1_MATRIX_H
#define TRAINING1_MATRIX_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINVALUE -100 /**@brief Минимальное значение элемента матрицы*/
#define MAXVALUE 100 /**@brief Максимальное значение элемента матрицы*/

typedef struct Matrix Matrix;
/**
 *
 * @brief Генерация случайных значений матрицы
 * @param matrix Указатель на структуру Matrix
 */
void generateMatrix(Matrix* matrix);

/**
 *
 * @brief Сумма диагоналей матрциы
 * @param matrix Указатель на структуру Matrix
 * @return Сумма значений диагоналей матрицы
 */
int sumOfDiagonals(Matrix* matrix);

/**
 *
 * @brief Выделение памяти для матрицы
 * @param size Размер матрицы
 * @return Указатель на структуру Matrix
 */
Matrix* allocateMatrix (int size);

/**
 *
 * @brief Освобождение памяти матрицы
 * @param matrix Указатель на структуру Matrix
 */
void freeMatrix(Matrix* matrix);

/**
 *
 * @brief Печать матрицы
 * @param matrix Указатель на структуру Matrix
 */
void printMatrix(Matrix* matrix);

/**
 *
 * @brief Минимальное значения на главной диагонали
 * @param matrix Указатель на структуру Matrix
 * @return Минимальное значение
 */
int minValueOfMainDiagonal(Matrix* matrix);

/**
 *
 * @brief Максимальное значение на побочной диагонали
 * @param matrix Указатель на структуру Matrix
 * @return Максимальное значение
 */
int maxValueOfSubDiagonal(Matrix* matrix);

/**
 *
 * @brief Среднее значение элементов матрицы
 * @param matrix Указатель на структуру Matrix
 * @return Среднее значение
 */
double averageMatrixValue(Matrix* matrix);

/**
 *
 * @brief Нахождение элементов, значение которых больше среднего значения матрицы
 * @param matrix Указатель на структуру Matrix
 */
void checkElementsGreaterThanAverage(Matrix* matrix);

/**
 *
 * @brief Замена отрицательных элементов на положительные
 * @param matrix Указатель на структуру Matrix
 */
void changeMatrixNegative(Matrix* matrix);

/**
 *
 * @brief Обнуление элементов матрицы, которые делятся на 5 без остатка
 * @param matrix Указатель на структуру Matrix
 */
void changeMatrixDivisibleFive(Matrix* matrix);
#endif //TRAINING1_MATRIX_H
