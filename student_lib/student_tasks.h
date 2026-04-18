#ifndef STUDENT_TASKS_H
#define STUDENT_TASKS_H
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// ============== ПРОСТЫЕ ЗАДАНИЯ (15 заданий, 0.5-1.5 балла) ==============

/* Задание 1: Произведение элементов массива (0.5 балла)
 * Пример: arrayProduct([1,2,3,4], 4) -> 24
 */
long long arrayProduct(const int *arr, int size);

/* Задание 2: Среднее арифметическое массива (0.5 балла)
 * Пример: arrayAverage([1,2,3,4,5], 5) -> 3.0
 */
double arrayAverage(const int *arr, int size);

/* Задание 3: Подсчитать отрицательные числа (0.5 балла)
 * Пример: countNegative([-1,2,-3,4], 4) -> 2
 */
int countNegative(const int *arr, int size);

/* Задание 4: Сумма цифр числа (0.5 балла)
 * Для отрицательных чисел — сумма цифр модуля
 * Пример: digitSum(1234) -> 10, digitSum(-56) -> 11
 */
int digitSum(int number);

/* Задание 5: Факториал числа (0.5 балла)
 * factorial(0) = 1, factorial(n) = n * factorial(n-1)
 * Пример: factorial(5) -> 120
 */
long long factorial(int n);

/* Задание 6: НОД двух чисел — алгоритм Евклида (0.5 балла)
 * Работает с положительными числами
 * Пример: gcd(12, 8) -> 4, gcd(7, 13) -> 1
 */
int gcd(int a, int b);

/* Задание 7: Проверка числа на простоту (0.5 балла)
 * Пример: isPrime(7) -> true, isPrime(4) -> false, isPrime(1) -> false
 */
bool isPrime(int n);

/* Задание 8: Заполнить массив числами Фибоначчи (0.5 балла)
 * F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)
 * Пример: fillFibonacci(arr, 6) -> arr = [0,1,1,2,3,5]
 */
void fillFibonacci(int *arr, int size);

/* Задание 9: Скалярное произведение двух векторов (0.5 балла)
 * Пример: dotProduct([1,2,3], [4,5,6], 3) -> 32  (1*4+2*5+3*6)
 */
long long dotProduct(const int *a, const int *b, int size);

/* Задание 10: Подсчитать элементы в диапазоне [min, max] включительно (0.5
 * балла) Пример: countInRange([1,5,3,8,2], 5, 2, 5) -> 3  (5,3,2)
 */
int countInRange(const int *arr, int size, int min, int max);

/* Задание 11: Циклический сдвиг вправо на k позиций (0.5 балла)
 * Пример: rotateRight([1,2,3,4,5], 5, 2) -> [4,5,1,2,3]
 */
void rotateRight(int *arr, int size, int k);

/* Задание 12: Медиана массива (1 балл)
 * Для нечётного размера — средний элемент отсортированного массива
 * Для чётного — среднее двух средних
 * Исходный массив НЕ модифицировать
 * Пример: arrayMedian([3,1,2], 3) -> 2.0
 *         arrayMedian([4,1,3,2], 4) -> 2.5
 */
double arrayMedian(const int *arr, int size);

/* Задание 13: Проверить, все ли элементы уникальны (1 балл)
 * Пример: allUnique([1,2,3,4], 4) -> true
 *         allUnique([1,2,3,2], 4) -> false
 */
bool allUnique(const int *arr, int size);

/* Задание 14: Пересечение двух массивов (1 балл)
 * Вернуть динамически выделенный массив (malloc) с общими элементами
 * Каждый элемент включается столько раз, сколько он есть в обоих массивах (min)
 * Записать размер в *resultSize. Если пересечение пусто — NULL, *resultSize=0
 * Пример: arrayIntersection([1,2,2,3], 4, [2,2,4], 3, &sz) -> [2,2], sz=2
 */
int *arrayIntersection(const int *a, int sizeA, const int *b, int sizeB,
                       int *resultSize);

/* Задание 15: Разность множеств A \ B (1.5 балла)
 * Вернуть элементы из A, которых нет в B (malloc)
 * Каждый элемент — не более одного раза (множество)
 * Записать размер в *resultSize. Если пусто — NULL, *resultSize=0
 * Пример: setDifference([1,2,3,4], 4, [3,4,5], 3, &sz) -> [1,2], sz=2
 */
int *setDifference(const int *a, int sizeA, const int *b, int sizeB,
                   int *resultSize);

// ============== СЛОЖНЫЕ ЗАДАНИЯ (5 заданий, 3-5 баллов) ==============

/* Задание 16: Умножение матриц (3 балла)
 * Матрицы хранятся построчно (row-major). Вернуть новую матрицу (malloc)
 * Размер результата: rowsA x colsB
 * result[i*colsB+j] = sum(a[i*colsA+k] * b[k*colsB+j]) для k=0..colsA-1
 * Пример: A=[1,2,3,4](2x2), B=[5,6,7,8](2x2) -> [19,22,43,50](2x2)
 */
int *matrixMultiply(const int *a, int rowsA, int colsA, const int *b, int rowsB,
                    int colsB);

/* Задание 17: Решето Эратосфена (3 балла)
 * Вернуть массив (malloc) всех простых чисел от 2 до n включительно
 * Записать количество в *resultSize
 * Пример: sieveOfEratosthenes(10, &sz) -> [2,3,5,7], sz=4
 */
int *sieveOfEratosthenes(int n, int *resultSize);

/* Задание 18: Подмассив с максимальной суммой — алгоритм Кадане (4 балла)
 * Найти непрерывный подмассив с максимальной суммой
 * Вернуть массив из 3 элементов (malloc): [startIndex, endIndex, maxSum]
 * Пример: maxSubarraySum([-2,1,-3,4,-1,2,1,-5,4], 9)
 *         -> [3, 6, 6]  (подмассив [4,-1,2,1], сумма=6)
 */
int *maxSubarraySum(const int *arr, int size);

/* Задание 19: Конвертация числа в строку в заданной системе счисления (5
 * баллов) Основание от 2 до 36. Цифры > 9 обозначаются строчными буквами a-z
 * Для отрицательных чисел добавить '-' в начало
 * Строка выделяется через malloc
 * Пример: intToBase(255, 16) -> "ff"
 *         intToBase(-10, 2) -> "-1010"
 *         intToBase(0, 8) -> "0"
 */
char *intToBase(int number, int base);

/* Задание 20: Сортировка массива строк лексикографически (5 баллов)
 * Отсортировать массив строк по возрастанию (как strcmp)
 * Сортировка на месте (менять указатели)
 * Пример: sortStrings(["banana","apple","cherry"], 3)
 *         -> ["apple","banana","cherry"]
 */
void sortStrings(char **strings, int count);

#ifdef __cplusplus
}
#endif

#endif // STUDENT_TASKS_H
