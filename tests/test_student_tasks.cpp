#include <cstring>
#include <gtest/gtest.h>

extern "C" {
#include "student_tasks.h"
}

// ========== Задание 1: Сумма двух чисел (0.5 балл) ==========
TEST(Task01_Add, PositiveNumbers) {
  EXPECT_EQ(add(2, 3), 5);
  EXPECT_EQ(add(10, 20), 30);
  EXPECT_EQ(add(100, 200), 300);
}

TEST(Task01_Add, NegativeNumbers) {
  EXPECT_EQ(add(-5, -3), -8);
  EXPECT_EQ(add(-10, 5), -5);
  EXPECT_EQ(add(10, -5), 5);
}

TEST(Task01_Add, WithZero) {
  EXPECT_EQ(add(0, 0), 0);
  EXPECT_EQ(add(5, 0), 5);
  EXPECT_EQ(add(0, -5), -5);
}

// ========== Задание 2: Факториал числа (0.5 балл) ==========
TEST(Task02_Factorial, BaseCase) {
  EXPECT_EQ(factorial(0), 1);
  EXPECT_EQ(factorial(1), 1);
}

TEST(Task02_Factorial, SmallNumbers) {
  EXPECT_EQ(factorial(2), 2);
  EXPECT_EQ(factorial(3), 6);
  EXPECT_EQ(factorial(4), 24);
  EXPECT_EQ(factorial(5), 120);
}

TEST(Task02_Factorial, LargerNumbers) {
  EXPECT_EQ(factorial(6), 720);
  EXPECT_EQ(factorial(7), 5040);
  EXPECT_EQ(factorial(10), 3628800);
}

// ========== Задание 3: Проверка на простое число (0.5 балла) ==========
TEST(Task03_IsPrime, PrimeNumbers) {
  EXPECT_TRUE(isPrime(2));
  EXPECT_TRUE(isPrime(3));
  EXPECT_TRUE(isPrime(5));
  EXPECT_TRUE(isPrime(7));
  EXPECT_TRUE(isPrime(11));
  EXPECT_TRUE(isPrime(13));
  EXPECT_TRUE(isPrime(17));
  EXPECT_TRUE(isPrime(23));
  EXPECT_TRUE(isPrime(97));
}

TEST(Task03_IsPrime, NonPrimeNumbers) {
  EXPECT_FALSE(isPrime(1));
  EXPECT_FALSE(isPrime(4));
  EXPECT_FALSE(isPrime(6));
  EXPECT_FALSE(isPrime(8));
  EXPECT_FALSE(isPrime(9));
  EXPECT_FALSE(isPrime(15));
  EXPECT_FALSE(isPrime(100));
}

TEST(Task03_IsPrime, EdgeCases) {
  EXPECT_FALSE(isPrime(0));
  EXPECT_FALSE(isPrime(-5));
  EXPECT_FALSE(isPrime(-7));
}

// ========== Задание 4: Найти максимальный элемент в массиве (0.5 балл)
// ==========
TEST(Task04_FindMax, BasicArrays) {
  int arr1[] = {1, 2, 3, 4, 5};
  EXPECT_EQ(findMax(arr1, 5), 5);

  int arr2[] = {-5, -2, -10, -1};
  EXPECT_EQ(findMax(arr2, 4), -1);

  int arr3[] = {42};
  EXPECT_EQ(findMax(arr3, 1), 42);
}

TEST(Task04_FindMax, UnorderedArrays) {
  int arr1[] = {3, 7, 2, 9, 1};
  EXPECT_EQ(findMax(arr1, 5), 9);

  int arr2[] = {100, 50, 200, 75};
  EXPECT_EQ(findMax(arr2, 4), 200);

  int arr3[] = {5, 5, 5, 5};
  EXPECT_EQ(findMax(arr3, 4), 5);
}

TEST(Task04_FindMax, MaxAtStart) {
  int arr[] = {10, 9, 8, 7, 6};
  EXPECT_EQ(findMax(arr, 5), 10);
}

// ========== Задание 5: Перевернуть строку (0.5 балл) ==========
TEST(Task05_ReverseString, BasicStrings) {
  char reversed[100];

  reverseString("hello", reversed);
  EXPECT_STREQ(reversed, "olleh");

  reverseString("world", reversed);
  EXPECT_STREQ(reversed, "dlrow");

  reverseString("12345", reversed);
  EXPECT_STREQ(reversed, "54321");
}

TEST(Task05_ReverseString, EdgeCases) {
  char reversed[100];

  reverseString("", reversed);
  EXPECT_STREQ(reversed, "");

  reverseString("a", reversed);
  EXPECT_STREQ(reversed, "a");
}

TEST(Task05_ReverseString, LongerStrings) {
  char reversed[100];

  reverseString("Programming", reversed);
  EXPECT_STREQ(reversed, "gnimmargorP");
}

// ========== Задание 6: Проверка на палиндром (0.5 балл) ==========
TEST(Task06_IsPalindrome, Palindromes) {
  EXPECT_TRUE(isPalindrome(""));
  EXPECT_TRUE(isPalindrome("a"));
  EXPECT_TRUE(isPalindrome("aa"));
  EXPECT_TRUE(isPalindrome("aba"));
  EXPECT_TRUE(isPalindrome("abba"));
  EXPECT_TRUE(isPalindrome("racecar"));
  EXPECT_TRUE(isPalindrome("madam"));
}

TEST(Task06_IsPalindrome, NonPalindromes) {
  EXPECT_FALSE(isPalindrome("ab"));
  EXPECT_FALSE(isPalindrome("hello"));
  EXPECT_FALSE(isPalindrome("world"));
  EXPECT_FALSE(isPalindrome("abcd"));
}

TEST(Task06_IsPalindrome, Numbers) {
  EXPECT_TRUE(isPalindrome("12321"));
  EXPECT_TRUE(isPalindrome("1001"));
  EXPECT_FALSE(isPalindrome("12345"));
}

// ========== Задание 7: Сортировка массива пузырьком (0.5 балла) ==========
TEST(Task07_BubbleSort, BasicArrays) {
  int arr1[] = {5, 2, 8, 1, 9};
  bubbleSort(arr1, 5);
  int expected1[] = {1, 2, 5, 8, 9};
  EXPECT_TRUE(memcmp(arr1, expected1, sizeof(expected1)) == 0);
}

TEST(Task07_BubbleSort, AlreadySorted) {
  int arr[] = {1, 2, 3, 4, 5};
  bubbleSort(arr, 5);
  int expected[] = {1, 2, 3, 4, 5};
  EXPECT_TRUE(memcmp(arr, expected, sizeof(expected)) == 0);
}

TEST(Task07_BubbleSort, ReverseSorted) {
  int arr[] = {5, 4, 3, 2, 1};
  bubbleSort(arr, 5);
  int expected[] = {1, 2, 3, 4, 5};
  EXPECT_TRUE(memcmp(arr, expected, sizeof(expected)) == 0);
}

TEST(Task07_BubbleSort, WithNegatives) {
  int arr[] = {3, -1, 4, -5, 2};
  bubbleSort(arr, 5);
  int expected[] = {-5, -1, 2, 3, 4};
  EXPECT_TRUE(memcmp(arr, expected, sizeof(expected)) == 0);
}

TEST(Task07_BubbleSort, SingleElement) {
  int arr[] = {42};
  bubbleSort(arr, 1);
  EXPECT_EQ(arr[0], 42);
}

// ========== Задание 8: Вычисление НОД двух чисел (0.5 балла) ==========
TEST(Task08_GCD, BasicCases) {
  EXPECT_EQ(gcd(12, 8), 4);
  EXPECT_EQ(gcd(48, 18), 6);
  EXPECT_EQ(gcd(100, 50), 50);
}

TEST(Task08_GCD, CoprimeNumbers) {
  EXPECT_EQ(gcd(17, 19), 1);
  EXPECT_EQ(gcd(7, 13), 1);
}

TEST(Task08_GCD, WithOne) {
  EXPECT_EQ(gcd(1, 5), 1);
  EXPECT_EQ(gcd(10, 1), 1);
}

TEST(Task08_GCD, SameNumbers) {
  EXPECT_EQ(gcd(5, 5), 5);
  EXPECT_EQ(gcd(100, 100), 100);
}

TEST(Task08_GCD, OrderDoesNotMatter) {
  EXPECT_EQ(gcd(24, 36), gcd(36, 24));
  EXPECT_EQ(gcd(15, 25), gcd(25, 15));
}

// ========== Задание 9: Вычисление числа Фибоначчи (0.5 балла) ==========
TEST(Task09_Fibonacci, BaseCase) {
  EXPECT_EQ(fibonacci(0), 0);
  EXPECT_EQ(fibonacci(1), 1);
}

TEST(Task09_Fibonacci, SmallNumbers) {
  EXPECT_EQ(fibonacci(2), 1);
  EXPECT_EQ(fibonacci(3), 2);
  EXPECT_EQ(fibonacci(4), 3);
  EXPECT_EQ(fibonacci(5), 5);
  EXPECT_EQ(fibonacci(6), 8);
}

TEST(Task09_Fibonacci, LargerNumbers) {
  EXPECT_EQ(fibonacci(7), 13);
  EXPECT_EQ(fibonacci(8), 21);
  EXPECT_EQ(fibonacci(10), 55);
  EXPECT_EQ(fibonacci(15), 610);
}

// ========== Задание 10: Перевод числа в шестнадцатеричную строку (0.5 балла)
// ==========
TEST(Task10_IntToHexString, BasicNumbers) {
  char hex[20];

  intToHexString(0, hex);
  EXPECT_STREQ(hex, "0");

  intToHexString(1, hex);
  EXPECT_STREQ(hex, "1");

  intToHexString(10, hex);
  EXPECT_STREQ(hex, "A");

  intToHexString(15, hex);
  EXPECT_STREQ(hex, "F");
}

TEST(Task10_IntToHexString, TwoDigitNumbers) {
  char hex[20];

  intToHexString(16, hex);
  EXPECT_STREQ(hex, "10");

  intToHexString(255, hex);
  EXPECT_STREQ(hex, "FF");

  intToHexString(256, hex);
  EXPECT_STREQ(hex, "100");
}

TEST(Task10_IntToHexString, LargerNumbers) {
  char hex[20];

  intToHexString(4095, hex);
  EXPECT_STREQ(hex, "FFF");

  intToHexString(65535, hex);
  EXPECT_STREQ(hex, "FFFF");

  intToHexString(1000000, hex);
  EXPECT_STREQ(hex, "F4240");
}

// ========== Задание 11: Правильность скобочной последовательности (5 баллов)
// ==========
TEST(Task11_ValidParentheses, ValidSequences) {
  EXPECT_TRUE(isValidParentheses('(', ')', '\0'));
  EXPECT_TRUE(isValidParentheses('[', ']', '\0'));
  EXPECT_TRUE(isValidParentheses('{', '}', '\0'));
  EXPECT_TRUE(isValidParentheses('(', '(', ')', ')', '\0'));
  EXPECT_TRUE(isValidParentheses('(', '[', ']', ')', '\0'));
  EXPECT_TRUE(isValidParentheses('{', '[', '(', ')', ']', '}', '\0'));
}

TEST(Task11_ValidParentheses, InvalidSequences) {
  EXPECT_FALSE(isValidParentheses('(', '(', ')', '\0'));
  EXPECT_FALSE(isValidParentheses('(', ']', '\0'));
  EXPECT_FALSE(isValidParentheses('(', '\0'));
  EXPECT_FALSE(isValidParentheses(')', '\0'));
  EXPECT_FALSE(isValidParentheses('(', ')', ')', '\0'));
  EXPECT_FALSE(isValidParentheses('[', '(', ']', ')', '\0'));
}

TEST(Task11_ValidParentheses, EmptySequence) {
  EXPECT_TRUE(isValidParentheses('\0'));
}

TEST(Task11_ValidParentheses, ComplexSequences) {
  EXPECT_TRUE(isValidParentheses('(', '{', '[', ']', '}', ')', '\0'));
  EXPECT_TRUE(isValidParentheses('(', ')', '{', '}', '[', ']', '\0'));
  EXPECT_FALSE(isValidParentheses('(', '{', '[', '}', ']', ')', '\0'));
  EXPECT_FALSE(isValidParentheses('(', '(', '(', ')', ')', '\0'));
}

// ========== Задание 12: Нормализация Unix пути (5 баллов) ==========
TEST(Task12_NormalizeUnixPath, BasicPaths) {
  char normalized[256];

  normalizeUnixPath("/home/user", normalized);
  EXPECT_STREQ(normalized, "/home/user");

  normalizeUnixPath("/", normalized);
  EXPECT_STREQ(normalized, "/");
}

TEST(Task12_NormalizeUnixPath, WithCurrentDirectory) {
  char normalized[256];

  normalizeUnixPath("/./", normalized);
  EXPECT_STREQ(normalized, "/");

  normalizeUnixPath("/a/./b", normalized);
  EXPECT_STREQ(normalized, "/a/b");

  normalizeUnixPath("/a/./b/./c", normalized);
  EXPECT_STREQ(normalized, "/a/b/c");
}

TEST(Task12_NormalizeUnixPath, WithParentDirectory) {
  char normalized[256];

  normalizeUnixPath("/a/b/../c", normalized);
  EXPECT_STREQ(normalized, "/a/c");

  normalizeUnixPath("/a/../b", normalized);
  EXPECT_STREQ(normalized, "/b");

  normalizeUnixPath("/a/b/c/../../d", normalized);
  EXPECT_STREQ(normalized, "/a/d");
}

TEST(Task12_NormalizeUnixPath, WithTrailingSlashes) {
  char normalized[256];

  normalizeUnixPath("/a/b//", normalized);
  EXPECT_STREQ(normalized, "/a/b");

  normalizeUnixPath("/a///b", normalized);
  EXPECT_STREQ(normalized, "/a/b");
}

TEST(Task12_NormalizeUnixPath, ComplexCases) {
  char normalized[256];

  normalizeUnixPath("/a/b/../c/./d//", normalized);
  EXPECT_STREQ(normalized, "/a/c/d");

  normalizeUnixPath("/home/./user/../admin/./docs", normalized);
  EXPECT_STREQ(normalized, "/home/admin/docs");

  normalizeUnixPath("/../", normalized);
  EXPECT_STREQ(normalized, "/");

  normalizeUnixPath("/a/b/../../", normalized);
  EXPECT_STREQ(normalized, "/");
}

TEST(Task12_NormalizeUnixPath, MultipleParentDirectories) {
  char normalized[256];

  normalizeUnixPath("/a/b/c/../../../d", normalized);
  EXPECT_STREQ(normalized, "/d");

  normalizeUnixPath("/a/b/../c/../d", normalized);
  EXPECT_STREQ(normalized, "/a/d");
}

TEST(Task13_ReversePolishNotation, BasicExpressions) {
  EXPECT_EQ(reversePolishNotation("3 4 +"), 7);
  EXPECT_EQ(reversePolishNotation("10 2 -"), 8);
  EXPECT_EQ(reversePolishNotation("5 6 *"), 30);
  EXPECT_EQ(reversePolishNotation("8 4 /"), 2);
}

TEST(Task13_ReversePolishNotation, ComplexExpressions) {

  EXPECT_EQ(reversePolishNotation("3 4 + 2 * 7 /"), 2);

  EXPECT_EQ(reversePolishNotation("5 1 2 + 4 * + 3 -"), 14);

  EXPECT_EQ(reversePolishNotation("10 2 8 * + 3 -"), 23);
}

TEST(Task13_ReversePolishNotation, SingleNumber) {
  EXPECT_EQ(reversePolishNotation("42"), 42);
}

TEST(Task13_ReversePolishNotation, DivisionByZero) {
  EXPECT_EQ(reversePolishNotation("8 0 /"), 0);
}

TEST(Task13_ReversePolishNotation, NegativeNumbers) {
  EXPECT_EQ(reversePolishNotation("-3 -4 +"), -7);
  EXPECT_EQ(reversePolishNotation("10 -2 -"), 12);
  EXPECT_EQ(reversePolishNotation("-5 6 *"), -30);
  EXPECT_EQ(reversePolishNotation("8 -4 /"), -2);
}

TEST(Task13_ReversePolishNotation, MixedOperations) {
  EXPECT_EQ(reversePolishNotation("2 3 + 5 * 6 -"), 19);
  EXPECT_EQ(reversePolishNotation("4 2 / 3 + 7 *"), 35);
}

TEST(Task13_ReversePolishNotation, MultipleDigitNumbers) {
  EXPECT_EQ(reversePolishNotation("12 34 +"), 46);
  EXPECT_EQ(reversePolishNotation("100 25 -"), 75);
  EXPECT_EQ(reversePolishNotation("15 3 *"), 45);
  EXPECT_EQ(reversePolishNotation("144 12 /"), 12);
}