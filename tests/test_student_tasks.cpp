#include <cstdlib>
#include <cstring>
#include <gtest/gtest.h>

extern "C" {
#include "student_tasks.h"
}

// ========== Задание 1: Произведение массива (0.5 балла) ==========
TEST(Task01_ArrayProduct, SingleElement) {
  int arr[] = {7};
  EXPECT_EQ(arrayProduct(arr, 1), 7);
}

TEST(Task01_ArrayProduct, MultiplePositive) {
  int arr[] = {1, 2, 3, 4};
  EXPECT_EQ(arrayProduct(arr, 4), 24);
}

TEST(Task01_ArrayProduct, WithNegatives) {
  int arr[] = {-1, 2, -3};
  EXPECT_EQ(arrayProduct(arr, 3), 6);

  int arr2[] = {2, -3, 4};
  EXPECT_EQ(arrayProduct(arr2, 3), -24);
}

TEST(Task01_ArrayProduct, WithZero) {
  int arr[] = {1, 0, 3};
  EXPECT_EQ(arrayProduct(arr, 3), 0);
}

// ========== Задание 2: Среднее арифметическое (0.5 балла) ==========
TEST(Task02_ArrayAverage, SingleElement) {
  int arr[] = {10};
  EXPECT_DOUBLE_EQ(arrayAverage(arr, 1), 10.0);
}

TEST(Task02_ArrayAverage, MultipleElements) {
  int arr[] = {1, 2, 3, 4, 5};
  EXPECT_DOUBLE_EQ(arrayAverage(arr, 5), 3.0);
}

TEST(Task02_ArrayAverage, NonIntegerResult) {
  int arr[] = {1, 2};
  EXPECT_DOUBLE_EQ(arrayAverage(arr, 2), 1.5);

  int arr2[] = {1, 2, 4};
  EXPECT_NEAR(arrayAverage(arr2, 3), 2.333333, 0.001);
}

TEST(Task02_ArrayAverage, WithNegatives) {
  int arr[] = {-10, 10};
  EXPECT_DOUBLE_EQ(arrayAverage(arr, 2), 0.0);
}

// ========== Задание 3: Подсчёт отрицательных (0.5 балла) ==========
TEST(Task03_CountNegative, NoNegatives) {
  int arr[] = {1, 2, 3, 0};
  EXPECT_EQ(countNegative(arr, 4), 0);
}

TEST(Task03_CountNegative, AllNegative) {
  int arr[] = {-1, -2, -3};
  EXPECT_EQ(countNegative(arr, 3), 3);
}

TEST(Task03_CountNegative, Mixed) {
  int arr[] = {-1, 2, -3, 4, -5};
  EXPECT_EQ(countNegative(arr, 5), 3);

  int arr2[] = {0, -1, 0, -2};
  EXPECT_EQ(countNegative(arr2, 4), 2);
}

// ========== Задание 4: Сумма цифр (0.5 балла) ==========
TEST(Task04_DigitSum, Zero) { EXPECT_EQ(digitSum(0), 0); }

TEST(Task04_DigitSum, SingleDigit) {
  EXPECT_EQ(digitSum(5), 5);
  EXPECT_EQ(digitSum(9), 9);
}

TEST(Task04_DigitSum, MultipleDigits) {
  EXPECT_EQ(digitSum(1234), 10);
  EXPECT_EQ(digitSum(999), 27);
  EXPECT_EQ(digitSum(100), 1);
}

TEST(Task04_DigitSum, Negative) {
  EXPECT_EQ(digitSum(-56), 11);
  EXPECT_EQ(digitSum(-1234), 10);
}

// ========== Задание 5: Факториал (0.5 балла) ==========
TEST(Task05_Factorial, Zero) { EXPECT_EQ(factorial(0), 1); }

TEST(Task05_Factorial, One) { EXPECT_EQ(factorial(1), 1); }

TEST(Task05_Factorial, SmallNumbers) {
  EXPECT_EQ(factorial(5), 120);
  EXPECT_EQ(factorial(6), 720);
  EXPECT_EQ(factorial(10), 3628800);
}

TEST(Task05_Factorial, LargerNumbers) {
  EXPECT_EQ(factorial(12), 479001600LL);
  EXPECT_EQ(factorial(15), 1307674368000LL);
}

// ========== Задание 6: НОД (0.5 балла) ==========
TEST(Task06_GCD, SameNumbers) {
  EXPECT_EQ(gcd(5, 5), 5);
  EXPECT_EQ(gcd(12, 12), 12);
}

TEST(Task06_GCD, OneIsMultiple) {
  EXPECT_EQ(gcd(6, 3), 3);
  EXPECT_EQ(gcd(15, 5), 5);
}

TEST(Task06_GCD, Coprime) {
  EXPECT_EQ(gcd(7, 13), 1);
  EXPECT_EQ(gcd(17, 19), 1);
}

TEST(Task06_GCD, General) {
  EXPECT_EQ(gcd(12, 8), 4);
  EXPECT_EQ(gcd(54, 24), 6);
  EXPECT_EQ(gcd(48, 18), 6);
}

// ========== Задание 7: Простое число (0.5 балла) ==========
TEST(Task07_IsPrime, NotPrime) {
  EXPECT_FALSE(isPrime(0));
  EXPECT_FALSE(isPrime(1));
  EXPECT_FALSE(isPrime(4));
  EXPECT_FALSE(isPrime(9));
  EXPECT_FALSE(isPrime(100));
}

TEST(Task07_IsPrime, Prime) {
  EXPECT_TRUE(isPrime(2));
  EXPECT_TRUE(isPrime(3));
  EXPECT_TRUE(isPrime(7));
  EXPECT_TRUE(isPrime(13));
  EXPECT_TRUE(isPrime(97));
}

TEST(Task07_IsPrime, Negative) { EXPECT_FALSE(isPrime(-5)); }

// ========== Задание 8: Фибоначчи (0.5 балла) ==========
TEST(Task08_FillFibonacci, SingleElement) {
  int arr[1];
  fillFibonacci(arr, 1);
  EXPECT_EQ(arr[0], 0);
}

TEST(Task08_FillFibonacci, TwoElements) {
  int arr[2];
  fillFibonacci(arr, 2);
  EXPECT_EQ(arr[0], 0);
  EXPECT_EQ(arr[1], 1);
}

TEST(Task08_FillFibonacci, SixElements) {
  int arr[6];
  fillFibonacci(arr, 6);
  int expected[] = {0, 1, 1, 2, 3, 5};
  for (int i = 0; i < 6; i++)
    EXPECT_EQ(arr[i], expected[i]);
}

TEST(Task08_FillFibonacci, TenElements) {
  int arr[10];
  fillFibonacci(arr, 10);
  int expected[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
  for (int i = 0; i < 10; i++)
    EXPECT_EQ(arr[i], expected[i]);
}

// ========== Задание 9: Скалярное произведение (0.5 балла) ==========
TEST(Task09_DotProduct, SingleElement) {
  int a[] = {3};
  int b[] = {4};
  EXPECT_EQ(dotProduct(a, b, 1), 12);
}

TEST(Task09_DotProduct, MultipleElements) {
  int a[] = {1, 2, 3};
  int b[] = {4, 5, 6};
  EXPECT_EQ(dotProduct(a, b, 3), 32); // 1*4+2*5+3*6
}

TEST(Task09_DotProduct, WithNegatives) {
  int a[] = {1, -1, 2};
  int b[] = {-3, 4, 5};
  EXPECT_EQ(dotProduct(a, b, 3), 3); // -3+(-4)+10
}

TEST(Task09_DotProduct, Orthogonal) {
  int a[] = {1, 0};
  int b[] = {0, 1};
  EXPECT_EQ(dotProduct(a, b, 2), 0);
}

// ========== Задание 10: Подсчёт в диапазоне (0.5 балла) ==========
TEST(Task10_CountInRange, AllInRange) {
  int arr[] = {1, 2, 3, 4, 5};
  EXPECT_EQ(countInRange(arr, 5, 1, 5), 5);
}

TEST(Task10_CountInRange, NoneInRange) {
  int arr[] = {1, 2, 3};
  EXPECT_EQ(countInRange(arr, 3, 10, 20), 0);
}

TEST(Task10_CountInRange, SomeInRange) {
  int arr[] = {1, 5, 3, 8, 2, 7};
  EXPECT_EQ(countInRange(arr, 6, 2, 5), 3); // 5, 3, 2

  int arr2[] = {-5, -1, 0, 3, 7};
  EXPECT_EQ(countInRange(arr2, 5, -1, 3), 3); // -1, 0, 3
}

TEST(Task10_CountInRange, BoundaryValues) {
  int arr[] = {10, 20, 30};
  EXPECT_EQ(countInRange(arr, 3, 10, 30), 3);
  EXPECT_EQ(countInRange(arr, 3, 10, 10), 1);
}

// ========== Задание 11: Циклический сдвиг вправо (0.5 балла) ==========
TEST(Task11_RotateRight, RotateByZero) {
  int arr[] = {1, 2, 3, 4, 5};
  rotateRight(arr, 5, 0);
  int expected[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++)
    EXPECT_EQ(arr[i], expected[i]);
}

TEST(Task11_RotateRight, RotateByTwo) {
  int arr[] = {1, 2, 3, 4, 5};
  rotateRight(arr, 5, 2);
  int expected[] = {4, 5, 1, 2, 3};
  for (int i = 0; i < 5; i++)
    EXPECT_EQ(arr[i], expected[i]);
}

TEST(Task11_RotateRight, RotateBySize) {
  int arr[] = {1, 2, 3, 4, 5};
  rotateRight(arr, 5, 5);
  int expected[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++)
    EXPECT_EQ(arr[i], expected[i]);
}

TEST(Task11_RotateRight, RotateMoreThanSize) {
  int arr[] = {1, 2, 3, 4, 5};
  rotateRight(arr, 5, 7); // 7 % 5 = 2
  int expected[] = {4, 5, 1, 2, 3};
  for (int i = 0; i < 5; i++)
    EXPECT_EQ(arr[i], expected[i]);
}

// ========== Задание 12: Медиана массива (1 балл) ==========
TEST(Task12_ArrayMedian, SingleElement) {
  int arr[] = {42};
  EXPECT_DOUBLE_EQ(arrayMedian(arr, 1), 42.0);
}

TEST(Task12_ArrayMedian, OddSize) {
  int arr[] = {3, 1, 2};
  EXPECT_DOUBLE_EQ(arrayMedian(arr, 3), 2.0);

  int arr2[] = {5, 1, 3, 2, 4};
  EXPECT_DOUBLE_EQ(arrayMedian(arr2, 5), 3.0);
}

TEST(Task12_ArrayMedian, EvenSize) {
  int arr[] = {4, 1, 3, 2};
  EXPECT_DOUBLE_EQ(arrayMedian(arr, 4), 2.5);

  int arr2[] = {1, 2};
  EXPECT_DOUBLE_EQ(arrayMedian(arr2, 2), 1.5);
}

TEST(Task12_ArrayMedian, DoesNotModifyOriginal) {
  int arr[] = {3, 1, 2};
  arrayMedian(arr, 3);
  EXPECT_EQ(arr[0], 3);
  EXPECT_EQ(arr[1], 1);
  EXPECT_EQ(arr[2], 2);
}

// ========== Задание 13: Все уникальны (1 балл) ==========
TEST(Task13_AllUnique, SingleElement) {
  int arr[] = {1};
  EXPECT_TRUE(allUnique(arr, 1));
}

TEST(Task13_AllUnique, AllDifferent) {
  int arr[] = {1, 2, 3, 4, 5};
  EXPECT_TRUE(allUnique(arr, 5));
}

TEST(Task13_AllUnique, HasDuplicates) {
  int arr[] = {1, 2, 3, 2, 5};
  EXPECT_FALSE(allUnique(arr, 5));

  int arr2[] = {5, 5};
  EXPECT_FALSE(allUnique(arr2, 2));
}

TEST(Task13_AllUnique, WithNegatives) {
  int arr[] = {-1, 0, 1};
  EXPECT_TRUE(allUnique(arr, 3));

  int arr2[] = {-1, 2, -1};
  EXPECT_FALSE(allUnique(arr2, 3));
}

// ========== Задание 14: Пересечение массивов (1 балл) ==========
TEST(Task14_ArrayIntersection, NoCommon) {
  int a[] = {1, 2, 3};
  int b[] = {4, 5, 6};
  int resultSize;
  int *result = arrayIntersection(a, 3, b, 3, &resultSize);
  EXPECT_EQ(result, nullptr);
  EXPECT_EQ(resultSize, 0);
}

TEST(Task14_ArrayIntersection, SomeCommon) {
  int a[] = {1, 2, 3, 4};
  int b[] = {3, 4, 5, 6};
  int resultSize;
  int *result = arrayIntersection(a, 4, b, 4, &resultSize);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(resultSize, 2);
  // Результат должен содержать 3 и 4
  int found3 = 0, found4 = 0;
  for (int i = 0; i < resultSize; i++) {
    if (result[i] == 3)
      found3++;
    if (result[i] == 4)
      found4++;
  }
  EXPECT_EQ(found3, 1);
  EXPECT_EQ(found4, 1);
  free(result);
}

TEST(Task14_ArrayIntersection, WithDuplicates) {
  int a[] = {1, 2, 2, 3};
  int b[] = {2, 2, 4};
  int resultSize;
  int *result = arrayIntersection(a, 4, b, 3, &resultSize);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(resultSize, 2); // два двойки
  EXPECT_EQ(result[0], 2);
  EXPECT_EQ(result[1], 2);
  free(result);
}

TEST(Task14_ArrayIntersection, FullOverlap) {
  int a[] = {1, 2, 3};
  int b[] = {1, 2, 3};
  int resultSize;
  int *result = arrayIntersection(a, 3, b, 3, &resultSize);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(resultSize, 3);
  free(result);
}

// ========== Задание 15: Разность множеств (1.5 балла) ==========
TEST(Task15_SetDifference, NoOverlap) {
  int a[] = {1, 2, 3};
  int b[] = {4, 5, 6};
  int resultSize;
  int *result = setDifference(a, 3, b, 3, &resultSize);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(resultSize, 3);
  free(result);
}

TEST(Task15_SetDifference, FullOverlap) {
  int a[] = {1, 2, 3};
  int b[] = {1, 2, 3};
  int resultSize;
  int *result = setDifference(a, 3, b, 3, &resultSize);
  EXPECT_EQ(result, nullptr);
  EXPECT_EQ(resultSize, 0);
}

TEST(Task15_SetDifference, PartialOverlap) {
  int a[] = {1, 2, 3, 4};
  int b[] = {3, 4, 5};
  int resultSize;
  int *result = setDifference(a, 4, b, 3, &resultSize);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(resultSize, 2);
  // Результат должен содержать 1 и 2
  int found1 = 0, found2 = 0;
  for (int i = 0; i < resultSize; i++) {
    if (result[i] == 1)
      found1++;
    if (result[i] == 2)
      found2++;
  }
  EXPECT_EQ(found1, 1);
  EXPECT_EQ(found2, 1);
  free(result);
}

TEST(Task15_SetDifference, DuplicatesInA) {
  int a[] = {1, 1, 2, 2, 3};
  int b[] = {2};
  int resultSize;
  int *result = setDifference(a, 5, b, 1, &resultSize);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(resultSize, 2); // {1, 3} — каждый по одному разу
  free(result);
}

// ========== Задание 16: Умножение матриц (3 балла) ==========
TEST(Task16_MatrixMultiply, Square2x2) {
  int a[] = {1, 2, 3, 4};
  int b[] = {5, 6, 7, 8};
  int *result = matrixMultiply(a, 2, 2, b, 2, 2);
  ASSERT_NE(result, nullptr);
  // [1*5+2*7, 1*6+2*8, 3*5+4*7, 3*6+4*8] = [19,22,43,50]
  EXPECT_EQ(result[0], 19);
  EXPECT_EQ(result[1], 22);
  EXPECT_EQ(result[2], 43);
  EXPECT_EQ(result[3], 50);
  free(result);
}

TEST(Task16_MatrixMultiply, Rectangular) {
  // A(2x3) * B(3x2) = C(2x2)
  int a[] = {1, 2, 3, 4, 5, 6};
  int b[] = {7, 8, 9, 10, 11, 12};
  int *result = matrixMultiply(a, 2, 3, b, 3, 2);
  ASSERT_NE(result, nullptr);
  // [1*7+2*9+3*11, 1*8+2*10+3*12, 4*7+5*9+6*11, 4*8+5*10+6*12]
  // = [58, 64, 139, 154]
  EXPECT_EQ(result[0], 58);
  EXPECT_EQ(result[1], 64);
  EXPECT_EQ(result[2], 139);
  EXPECT_EQ(result[3], 154);
  free(result);
}

TEST(Task16_MatrixMultiply, Identity) {
  int a[] = {1, 0, 0, 1};
  int b[] = {5, 6, 7, 8};
  int *result = matrixMultiply(a, 2, 2, b, 2, 2);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(result[0], 5);
  EXPECT_EQ(result[1], 6);
  EXPECT_EQ(result[2], 7);
  EXPECT_EQ(result[3], 8);
  free(result);
}

TEST(Task16_MatrixMultiply, VectorTimesVector) {
  // Row vector (1x3) * Column vector (3x1) = scalar (1x1)
  int a[] = {1, 2, 3};
  int b[] = {4, 5, 6};
  int *result = matrixMultiply(a, 1, 3, b, 3, 1);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(result[0], 32); // 1*4+2*5+3*6
  free(result);
}

// ========== Задание 17: Решето Эратосфена (3 балла) ==========
TEST(Task17_SieveOfEratosthenes, UpTo10) {
  int resultSize;
  int *result = sieveOfEratosthenes(10, &resultSize);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(resultSize, 4);
  int expected[] = {2, 3, 5, 7};
  for (int i = 0; i < 4; i++)
    EXPECT_EQ(result[i], expected[i]);
  free(result);
}

TEST(Task17_SieveOfEratosthenes, UpTo2) {
  int resultSize;
  int *result = sieveOfEratosthenes(2, &resultSize);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(resultSize, 1);
  EXPECT_EQ(result[0], 2);
  free(result);
}

TEST(Task17_SieveOfEratosthenes, UpTo1) {
  int resultSize;
  int *result = sieveOfEratosthenes(1, &resultSize);
  EXPECT_EQ(result, nullptr);
  EXPECT_EQ(resultSize, 0);
}

TEST(Task17_SieveOfEratosthenes, UpTo30) {
  int resultSize;
  int *result = sieveOfEratosthenes(30, &resultSize);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(resultSize, 10);
  int expected[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  for (int i = 0; i < 10; i++)
    EXPECT_EQ(result[i], expected[i]);
  free(result);
}

// ========== Задание 18: Подмассив с макс. суммой — Кадане (4 балла) ==========
TEST(Task18_MaxSubarraySum, AllPositive) {
  int arr[] = {1, 2, 3, 4};
  int *result = maxSubarraySum(arr, 4);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(result[0], 0);  // start
  EXPECT_EQ(result[1], 3);  // end
  EXPECT_EQ(result[2], 10); // sum
  free(result);
}

TEST(Task18_MaxSubarraySum, Classic) {
  int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int *result = maxSubarraySum(arr, 9);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(result[0], 3); // start
  EXPECT_EQ(result[1], 6); // end
  EXPECT_EQ(result[2], 6); // sum = 4+(-1)+2+1
  free(result);
}

TEST(Task18_MaxSubarraySum, AllNegative) {
  int arr[] = {-3, -5, -1, -4};
  int *result = maxSubarraySum(arr, 4);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(result[0], 2);  // start (index of -1)
  EXPECT_EQ(result[1], 2);  // end
  EXPECT_EQ(result[2], -1); // max single element
  free(result);
}

TEST(Task18_MaxSubarraySum, SingleElement) {
  int arr[] = {42};
  int *result = maxSubarraySum(arr, 1);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(result[0], 0);
  EXPECT_EQ(result[1], 0);
  EXPECT_EQ(result[2], 42);
  free(result);
}

TEST(Task18_MaxSubarraySum, MixedWithMaxAtEnd) {
  int arr[] = {-1, -2, 5, 6};
  int *result = maxSubarraySum(arr, 4);
  ASSERT_NE(result, nullptr);
  EXPECT_EQ(result[0], 2);
  EXPECT_EQ(result[1], 3);
  EXPECT_EQ(result[2], 11);
  free(result);
}

// ========== Задание 19: Конвертация в систему счисления (5 баллов) ==========
TEST(Task19_IntToBase, Zero) {
  char *result = intToBase(0, 10);
  ASSERT_NE(result, nullptr);
  EXPECT_STREQ(result, "0");
  free(result);
}

TEST(Task19_IntToBase, Decimal) {
  char *result = intToBase(255, 10);
  ASSERT_NE(result, nullptr);
  EXPECT_STREQ(result, "255");
  free(result);
}

TEST(Task19_IntToBase, Binary) {
  char *result = intToBase(10, 2);
  ASSERT_NE(result, nullptr);
  EXPECT_STREQ(result, "1010");
  free(result);
}

TEST(Task19_IntToBase, Hexadecimal) {
  char *result = intToBase(255, 16);
  ASSERT_NE(result, nullptr);
  EXPECT_STREQ(result, "ff");
  free(result);

  char *result2 = intToBase(26, 16);
  ASSERT_NE(result2, nullptr);
  EXPECT_STREQ(result2, "1a");
  free(result2);
}

TEST(Task19_IntToBase, Octal) {
  char *result = intToBase(8, 8);
  ASSERT_NE(result, nullptr);
  EXPECT_STREQ(result, "10");
  free(result);
}

TEST(Task19_IntToBase, Negative) {
  char *result = intToBase(-10, 2);
  ASSERT_NE(result, nullptr);
  EXPECT_STREQ(result, "-1010");
  free(result);

  char *result2 = intToBase(-255, 16);
  ASSERT_NE(result2, nullptr);
  EXPECT_STREQ(result2, "-ff");
  free(result2);
}

TEST(Task19_IntToBase, Base36) {
  char *result = intToBase(35, 36);
  ASSERT_NE(result, nullptr);
  EXPECT_STREQ(result, "z");
  free(result);

  char *result2 = intToBase(36, 36);
  ASSERT_NE(result2, nullptr);
  EXPECT_STREQ(result2, "10");
  free(result2);
}

// ========== Задание 20: Сортировка строк (5 баллов) ==========
TEST(Task20_SortStrings, AlreadySorted) {
  char s1[] = "apple";
  char s2[] = "banana";
  char s3[] = "cherry";
  char *arr[] = {s1, s2, s3};
  sortStrings(arr, 3);
  EXPECT_STREQ(arr[0], "apple");
  EXPECT_STREQ(arr[1], "banana");
  EXPECT_STREQ(arr[2], "cherry");
}

TEST(Task20_SortStrings, ReverseSorted) {
  char s1[] = "cherry";
  char s2[] = "banana";
  char s3[] = "apple";
  char *arr[] = {s1, s2, s3};
  sortStrings(arr, 3);
  EXPECT_STREQ(arr[0], "apple");
  EXPECT_STREQ(arr[1], "banana");
  EXPECT_STREQ(arr[2], "cherry");
}

TEST(Task20_SortStrings, Unsorted) {
  char s1[] = "delta";
  char s2[] = "alpha";
  char s3[] = "charlie";
  char s4[] = "bravo";
  char *arr[] = {s1, s2, s3, s4};
  sortStrings(arr, 4);
  EXPECT_STREQ(arr[0], "alpha");
  EXPECT_STREQ(arr[1], "bravo");
  EXPECT_STREQ(arr[2], "charlie");
  EXPECT_STREQ(arr[3], "delta");
}

TEST(Task20_SortStrings, WithPrefixes) {
  char s1[] = "test";
  char s2[] = "testing";
  char s3[] = "tester";
  char *arr[] = {s1, s2, s3};
  sortStrings(arr, 3);
  EXPECT_STREQ(arr[0], "test");
  EXPECT_STREQ(arr[1], "tester");
  EXPECT_STREQ(arr[2], "testing");
}

TEST(Task20_SortStrings, SingleElement) {
  char s1[] = "only";
  char *arr[] = {s1};
  sortStrings(arr, 1);
  EXPECT_STREQ(arr[0], "only");
}

TEST(Task20_SortStrings, WithDuplicates) {
  char s1[] = "banana";
  char s2[] = "apple";
  char s3[] = "banana";
  char s4[] = "apple";
  char *arr[] = {s1, s2, s3, s4};
  sortStrings(arr, 4);
  EXPECT_STREQ(arr[0], "apple");
  EXPECT_STREQ(arr[1], "apple");
  EXPECT_STREQ(arr[2], "banana");
  EXPECT_STREQ(arr[3], "banana");
}
