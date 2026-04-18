#include "student_tasks.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// ============== ПРОСТЫЕ ЗАДАНИЯ (15 заданий, 0.5-1.5 балла) ==============

// Задание 1: Произведение элементов массива (0.5 балла)
long long arrayProduct(const int *arr, int size) {
  // TODO: Вычислить произведение всех элементов массива
  return 0;
}

// Задание 2: Среднее арифметическое массива (0.5 балла)
double arrayAverage(const int *arr, int size) {
  // TODO: Вычислить среднее арифметическое элементов массива
  return 0.0;
}

// Задание 3: Подсчитать отрицательные числа (0.5 балла)
int countNegative(const int *arr, int size) {
  // TODO: Подсчитать количество отрицательных чисел в массиве
  return 0;
}

// Задание 4: Сумма цифр числа (0.5 балла)
int digitSum(int number) {
  // TODO: Вернуть сумму цифр числа (для отрицательных — сумму цифр модуля)
  return 0;
}

// Задание 5: Факториал числа (0.5 балла)
long long factorial(int n) {
  // TODO: Вычислить n! (0! = 1)
  return 0;
}

// Задание 6: НОД двух чисел — алгоритм Евклида (0.5 балла)
int gcd(int a, int b) {
  // TODO: Найти наибольший общий делитель двух чисел
  return 0;
}

// Задание 7: Проверка числа на простоту (0.5 балла)
bool isPrime(int n) {
  // TODO: Вернуть true, если n — простое число
  // 0 и 1 не являются простыми
  return false;
}

// Задание 8: Заполнить массив числами Фибоначчи (0.5 балла)
void fillFibonacci(int *arr, int size) {
  // TODO: Заполнить массив: F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)
}

// Задание 9: Скалярное произведение двух векторов (0.5 балла)
long long dotProduct(const int *a, const int *b, int size) {
  // TODO: Вычислить сумму a[i]*b[i] для всех i
  return 0;
}

// Задание 10: Подсчитать элементы в диапазоне [min, max] включительно (0.5
// балла)
int countInRange(const int *arr, int size, int min, int max) {
  // TODO: Подсчитать элементы arr[i], для которых min <= arr[i] <= max
  return 0;
}

// Задание 11: Циклический сдвиг вправо на k позиций (0.5 балла)
void rotateRight(int *arr, int size, int k) {
  // TODO: Сдвинуть элементы массива вправо на k позиций
  // Пример: [1,2,3,4,5], k=2 -> [4,5,1,2,3]
}

// Задание 12: Медиана массива (1 балл)
double arrayMedian(const int *arr, int size) {
  // TODO: Найти медиану массива (не модифицируя исходный массив)
  // Для нечётного размера — средний элемент отсортированного массива
  // Для чётного — среднее двух средних
  return 0.0;
}

// Задание 13: Проверить, все ли элементы уникальны (1 балл)
bool allUnique(const int *arr, int size) {
  // TODO: Вернуть true, если все элементы различны
  return false;
}

// Задание 14: Пересечение двух массивов (1 балл)
int *arrayIntersection(const int *a, int sizeA, const int *b, int sizeB,
                       int *resultSize) {
  // TODO: Вернуть массив (malloc) с общими элементами
  // Каждый элемент включается min(countA, countB) раз
  // Если пересечение пусто — вернуть NULL и *resultSize = 0
  *resultSize = 0;
  return NULL;
}

// Задание 15: Разность множеств A \ B (1.5 балла)
int *setDifference(const int *a, int sizeA, const int *b, int sizeB,
                   int *resultSize) {
  // TODO: Вернуть элементы из A, которых нет в B (каждый не более одного раза)
  // Выделить результат через malloc
  // Если пусто — вернуть NULL и *resultSize = 0
  *resultSize = 0;
  return NULL;
}

// ============== СЛОЖНЫЕ ЗАДАНИЯ (5 заданий, 3-5 баллов) ==============

// Задание 16: Умножение матриц (3 балла)
int *matrixMultiply(const int *a, int rowsA, int colsA, const int *b, int rowsB,
                    int colsB) {
  // TODO: Перемножить матрицы A (rowsA x colsA) и B (rowsB x colsB)
  // Результат: матрица rowsA x colsB, выделенная через malloc
  // result[i*colsB+j] = sum(a[i*colsA+k] * b[k*colsB+j])
  return NULL;
}

// Задание 17: Решето Эратосфена (3 балла)
int *sieveOfEratosthenes(int n, int *resultSize) {
  // TODO: Вернуть массив (malloc) всех простых чисел от 2 до n включительно
  // Записать количество в *resultSize
  *resultSize = 0;
  return NULL;
}

// Задание 18: Подмассив с максимальной суммой — алгоритм Кадане (4 балла)
int *maxSubarraySum(const int *arr, int size) {
  // TODO: Найти непрерывный подмассив с максимальной суммой
  // Вернуть массив из 3 элементов (malloc): [startIndex, endIndex, maxSum]
  return NULL;
}

// Задание 19: Конвертация числа в строку в заданной системе счисления (5
// баллов)
char *intToBase(int number, int base) {
  // TODO: Перевести число в строку в системе счисления base (2..36)
  // Цифры > 9 обозначаются строчными буквами: a=10, b=11, ..., z=35
  // Для отрицательных чисел — добавить '-' в начало
  // Строку выделить через malloc
  return NULL;
}

// Задание 20: Сортировка массива строк лексикографически (5 баллов)
void sortStrings(char **strings, int count) {
  // TODO: Отсортировать массив строк по возрастанию (как strcmp)
  // Сортировка на месте — менять указатели
}