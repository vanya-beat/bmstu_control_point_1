#ifndef STUDENT_TASKS_H
#define STUDENT_TASKS_H
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Задание 1: Сумма двух чисел (0.5 балл) */
int add(int a, int b);

/* Задание 2: Факториал числа (0.5 балл) */
int factorial(int n);

/* Задание 3: Проверка на простое число (0.5 балла) */
bool isPrime(int n);

/* Задание 4: Найти максимальный элемент в массиве (0.5 балл) */
int findMax(const int *arr, int size);

/* Задание 5: Перевернуть строку (0.5 балл) */
void reverseString(const char *str, char *reversed);

/* Задание 6: Проверка на палиндром (0.5 балл) */
bool isPalindrome(const char *str);

/* Задание 7: Сортировка массива пузырьком (0.5 балла) */
void bubbleSort(int *arr, int size);

/* Задание 8: Вычисление НОД двух чисел (0.5 балла) */
int gcd(int a, int b);

/* Задание 9: Вычисление числа Фибоначчи (0.5 балла) */
unsigned int fibonacci(unsigned int n);

/* Задание 10: Перевод числа в шестнадцатеричную строку (0.5 балла) */
void intToHexString(unsigned int number, char *hexString);

/* Задание 11: Определить правильность скобочной последовательности (5 баллов)
 * Использует variadic arguments, завершается NULL
 * Пример: isValidParentheses('(', ')', NULL) -> true
 *         isValidParentheses('(', '(', ')', NULL) -> false
 */
bool isValidParentheses(char symbol, ...);

/* Задание 12: Реализовать функцию нормализации Unix пути (5 баллов)
 * Пример: "/a/b/../c/./d//" -> "/a/c/d"
 * Путь всегда корректен и начинается с '/'
 */
void normalizeUnixPath(const char *path, char *normalizedPath);

/* Задание 13: Реализовать функцию вычисления значения выражения в постфиксной
 * нотации (10 баллов) Пример: "23 34 + 5 *" -> (23 + 34) * 5 = 285
 * Поддерживаемые операции: +, -, *, /
 */
int reversePolishNotation(const char *expression);

#ifdef __cplusplus
}
#endif

#endif // STUDENT_TASKS_H
