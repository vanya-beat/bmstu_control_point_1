#include "student_tasks.h"
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

// ============== ПРОСТЫЕ ЗАДАНИЯ (15 заданий, 0.5-1.5 балла) ==============

// Задание 1: Вычислить длину строки (0.5 балла)
size_t stringLength(const char *str) {
  // TODO: Реализовать аналог strlen
  return 0;
}

// Задание 2: Скопировать строку (0.5 балла)
void stringCopy(char *dest, const char *src) {
  // TODO: Реализовать аналог strcpy
}

// Задание 3: Конкатенация строк (0.5 балла)
void stringConcat(char *dest, const char *src) {
  // TODO: Реализовать аналог strcat - добавить src в конец dest
}

// Задание 4: Сравнение строк (0.5 балла)
int stringCompare(const char *str1, const char *str2) {
  // TODO: Реализовать аналог strcmp
  // Возвращает: 0 если равны, <0 если str1<str2, >0 если str1>str2
  return 0;
}

// Задание 5: Подсчитать количество вхождений символа (0.5 балла)
int countChar(const char *str, char ch) {
  // TODO: Подсчитать вхождения символа ch в строке str
  return 0;
}

// Задание 6: Подсчитать количество гласных букв (0.5 балла)
int countVowels(const char *str) {
  // TODO: Подсчитать гласные: a, e, i, o, u (регистр не важен)
  return 0;
}

// Задание 7: Удалить все пробелы из строки (0.5 балла)
void removeSpaces(const char *str, char *result) {
  // TODO: Скопировать str в result, пропуская все пробелы
}

// Задание 8: Найти длину первого слова (0.5 балла)
int firstWordLength(const char *str) {
  // TODO: Найти длину первого слова (последовательность непробельных символов)
  return 0;
}

// Задание 9: Найти подстроку в строке (0.5 балла)
int findSubstring(const char *str, const char *substr) {
  // TODO: Вернуть индекс первого вхождения substr в str или -1
  return -1;
}

// Задание 10: Заменить все вхождения символа (0.5 балла)
void replaceChar(const char *str, char oldChar, char newChar, char *result) {
  // TODO: Скопировать str в result, заменив все oldChar на newChar
}

// Задание 11: Удалить начальные и конечные пробелы (trim) (0.5 балла)
void trimString(const char *str, char *result) {
  // TODO: Скопировать str в result без начальных и конечных пробелов
}

// Задание 12: Перевернуть слова в строке (1 балл)
void reverseWords(const char *str, char *result) {
  // TODO: Перевернуть символы внутри каждого слова
  // Пример: "hello world" -> "olleh dlrow"
}

// Задание 13: Палиндром без учета регистра и пробелов (1 балл)
bool isPalindromeIgnoreCase(const char *str) {
  // TODO: Проверить палиндром, игнорируя регистр и пробелы
  return false;
}

// Задание 14: Подсчитать количество слов в строке (1 балл)
int countWords(const char *str) {
  // TODO: Подсчитать количество слов (разделенных пробелами)
  return 0;
}

// Задание 15: Проверка на анаграммы (1.5 балла)
bool isAnagram(const char *str1, const char *str2) {
  // TODO: Проверить, являются ли строки анаграммами
  // Игнорировать регистр и пробелы
  return false;
}

// ============== СЛОЖНЫЕ ЗАДАНИЯ (5 заданий, 3-5 баллов) ==============

// Задание 16: Найти самый длинный общий префикс (3 балла)
void longestCommonPrefix(char *result, const char *first, ...) {
  // TODO: Найти общий префикс всех строк (variadic arguments, завершается
  // NULL) Пример: longestCommonPrefix(result, "flower", "flow", "flight", NULL)
  // -> "fl"
  result[0] = '\0';
}

// Задание 17: RLE-сжатие строки (3 балла)
void compressString(const char *str, char *result) {
  // TODO: Run-Length Encoding
  // Пример: "aaabbcccc" -> "a3b2c4"
  // Если символ один раз, просто символ: "abc" -> "abc"
  result[0] = '\0';
}

// Задание 18: Простой калькулятор (4 балла)
int calculateExpression(const char *expression) {
  // TODO: Вычислить выражение с +, -, *, / и скобками
  // Пример: "2 + 3 * 4" -> 14
  //         "(2 + 3) * 4" -> 20
  return 0;
}

// Задание 19: Валидация email адреса (5 баллов)
bool validateEmail(const char *email) {
  // TODO: Проверить корректность email
  // Правила:
  //   - ровно один @
  //   - до @ минимум 1 символ (буквы, цифры, точка, дефис, подчеркивание)
  //   - после @ домен с точкой
  //   - доменная зона минимум 2 символа
  return false;
}

// Задание 20: Найти самую длинную палиндромную подстроку (5 баллов)
int longestPalindromicSubstring(const char *str) {
  // TODO: Вернуть длину самой длинной палиндромной подстроки
  // Пример: "babad" -> 3 ("bab" или "aba")
  return 0;
}