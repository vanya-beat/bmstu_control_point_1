#include <cstring>
#include <gtest/gtest.h>

extern "C" {
#include "student_tasks.h"
}

// ========== Задание 1: Длина строки (0.5 балла) ==========
TEST(Task01_StringLength, EmptyString) { EXPECT_EQ(stringLength(""), 0); }

TEST(Task01_StringLength, SingleChar) { EXPECT_EQ(stringLength("a"), 1); }

TEST(Task01_StringLength, NormalStrings) {
  EXPECT_EQ(stringLength("hello"), 5);
  EXPECT_EQ(stringLength("world"), 5);
  EXPECT_EQ(stringLength("test"), 4);
  EXPECT_EQ(stringLength("programming"), 11);
}

// ========== Задание 2: Копирование строки (0.5 балла) ==========
TEST(Task02_StringCopy, EmptyString) {
  char dest[100];
  stringCopy(dest, "");
  EXPECT_STREQ(dest, "");
}

TEST(Task02_StringCopy, SingleChar) {
  char dest[100];
  stringCopy(dest, "a");
  EXPECT_STREQ(dest, "a");
}

TEST(Task02_StringCopy, NormalStrings) {
  char dest[100];
  stringCopy(dest, "hello");
  EXPECT_STREQ(dest, "hello");

  stringCopy(dest, "world");
  EXPECT_STREQ(dest, "world");

  stringCopy(dest, "test123");
  EXPECT_STREQ(dest, "test123");
}

// ========== Задание 3: Конкатенация строк (0.5 балла) ==========
TEST(Task03_StringConcat, EmptyStrings) {
  char dest[100] = "";
  stringConcat(dest, "");
  EXPECT_STREQ(dest, "");
}

TEST(Task03_StringConcat, AddToEmpty) {
  char dest[100] = "";
  stringConcat(dest, "hello");
  EXPECT_STREQ(dest, "hello");
}

TEST(Task03_StringConcat, NormalConcat) {
  char dest[100] = "Hello";
  stringConcat(dest, " World");
  EXPECT_STREQ(dest, "Hello World");

  char dest2[100] = "test";
  stringConcat(dest2, "123");
  EXPECT_STREQ(dest2, "test123");
}

// ========== Задание 4: Сравнение строк (0.5 балла) ==========
TEST(Task04_StringCompare, EqualStrings) {
  EXPECT_EQ(stringCompare("hello", "hello"), 0);
  EXPECT_EQ(stringCompare("", ""), 0);
  EXPECT_EQ(stringCompare("test", "test"), 0);
}

TEST(Task04_StringCompare, DifferentStrings) {
  EXPECT_LT(stringCompare("abc", "abd"), 0);
  EXPECT_GT(stringCompare("abd", "abc"), 0);
  EXPECT_LT(stringCompare("hello", "world"), 0);
  EXPECT_GT(stringCompare("world", "hello"), 0);
}

TEST(Task04_StringCompare, DifferentLengths) {
  EXPECT_LT(stringCompare("abc", "abcd"), 0);
  EXPECT_GT(stringCompare("abcd", "abc"), 0);
}

// ========== Задание 5: Подсчет символа (0.5 балла) ==========
TEST(Task05_CountChar, NoOccurrences) {
  EXPECT_EQ(countChar("hello", 'x'), 0);
  EXPECT_EQ(countChar("", 'a'), 0);
}

TEST(Task05_CountChar, SingleOccurrence) {
  EXPECT_EQ(countChar("hello", 'h'), 1);
  EXPECT_EQ(countChar("world", 'w'), 1);
}

TEST(Task05_CountChar, MultipleOccurrences) {
  EXPECT_EQ(countChar("hello", 'l'), 2);
  EXPECT_EQ(countChar("banana", 'a'), 3);
  EXPECT_EQ(countChar("mississippi", 's'), 4);
}

// ========== Задание 6: Подсчет гласных (0.5 балла) ==========
TEST(Task06_CountVowels, NoVowels) {
  EXPECT_EQ(countVowels("bcdfg"), 0);
  EXPECT_EQ(countVowels("xyz"), 0);
  EXPECT_EQ(countVowels(""), 0);
}

TEST(Task06_CountVowels, OnlyVowels) {
  EXPECT_EQ(countVowels("aeiou"), 5);
  EXPECT_EQ(countVowels("AEIOU"), 5);
}

TEST(Task06_CountVowels, MixedStrings) {
  EXPECT_EQ(countVowels("hello"), 2); // e, o
  EXPECT_EQ(countVowels("Hello World"), 3); // e, o, o
  EXPECT_EQ(countVowels("Programming"), 3); // o, a, i
}

// ========== Задание 7: Удаление пробелов (0.5 балла) ==========
TEST(Task07_RemoveSpaces, NoSpaces) {
  char result[100];
  removeSpaces("hello", result);
  EXPECT_STREQ(result, "hello");
}

TEST(Task07_RemoveSpaces, OnlySpaces) {
  char result[100];
  removeSpaces("   ", result);
  EXPECT_STREQ(result, "");
}

TEST(Task07_RemoveSpaces, WithSpaces) {
  char result[100];
  removeSpaces("a b c", result);
  EXPECT_STREQ(result, "abc");

  removeSpaces("  hello  world  ", result);
  EXPECT_STREQ(result, "helloworld");
}

// ========== Задание 8: Длина первого слова (0.5 балла) ==========
TEST(Task08_FirstWordLength, NoLeadingSpaces) {
  EXPECT_EQ(firstWordLength("hello world"), 5);
  EXPECT_EQ(firstWordLength("test"), 4);
}

TEST(Task08_FirstWordLength, WithLeadingSpaces) {
  EXPECT_EQ(firstWordLength("  hello world"), 5);
  EXPECT_EQ(firstWordLength("   test"), 4);
}

TEST(Task08_FirstWordLength, SingleWord) {
  EXPECT_EQ(firstWordLength("hello"), 5);
  EXPECT_EQ(firstWordLength("  word"), 4);
}

TEST(Task08_FirstWordLength, EmptyOrSpacesOnly) {
  EXPECT_EQ(firstWordLength(""), 0);
  EXPECT_EQ(firstWordLength("   "), 0);
}

// ========== Задание 9: Поиск подстроки (0.5 балла) ==========
TEST(Task09_FindSubstring, AtBeginning) {
  EXPECT_EQ(findSubstring("hello world", "hello"), 0);
}

TEST(Task09_FindSubstring, InMiddle) {
  EXPECT_EQ(findSubstring("hello world", "wor"), 6);
  EXPECT_EQ(findSubstring("abcdefgh", "def"), 3);
}

TEST(Task09_FindSubstring, NotFound) {
  EXPECT_EQ(findSubstring("hello world", "xyz"), -1);
  EXPECT_EQ(findSubstring("test", "testing"), -1);
}

TEST(Task09_FindSubstring, EmptySubstring) {
  EXPECT_EQ(findSubstring("hello", ""), 0);
}

// ========== Задание 10: Замена символа (0.5 балла) ==========
TEST(Task10_ReplaceChar, NoOccurrences) {
  char result[100];
  replaceChar("hello", 'x', 'y', result);
  EXPECT_STREQ(result, "hello");
}

TEST(Task10_ReplaceChar, SingleOccurrence) {
  char result[100];
  replaceChar("hello", 'h', 'H', result);
  EXPECT_STREQ(result, "Hello");
}

TEST(Task10_ReplaceChar, MultipleOccurrences) {
  char result[100];
  replaceChar("hello", 'l', 'p', result);
  EXPECT_STREQ(result, "heppo");

  replaceChar("banana", 'a', 'o', result);
  EXPECT_STREQ(result, "bonono");
}

// ========== Задание 11: Trim строки (0.5 балла) ==========
TEST(Task11_TrimString, NoSpaces) {
  char result[100];
  trimString("hello", result);
  EXPECT_STREQ(result, "hello");
}

TEST(Task11_TrimString, OnlyLeadingSpaces) {
  char result[100];
  trimString("  hello", result);
  EXPECT_STREQ(result, "hello");
}

TEST(Task11_TrimString, OnlyTrailingSpaces) {
  char result[100];
  trimString("hello  ", result);
  EXPECT_STREQ(result, "hello");
}

TEST(Task11_TrimString, BothSides) {
  char result[100];
  trimString("  hello  ", result);
  EXPECT_STREQ(result, "hello");

  trimString("   test   ", result);
  EXPECT_STREQ(result, "test");
}

TEST(Task11_TrimString, MiddleSpacesPreserved) {
  char result[100];
  trimString("  hello world  ", result);
  EXPECT_STREQ(result, "hello world");
}

// ========== Задание 12: Переворот слов (1 балл) ==========
TEST(Task12_ReverseWords, SingleWord) {
  char result[100];
  reverseWords("hello", result);
  EXPECT_STREQ(result, "olleh");
}

TEST(Task12_ReverseWords, MultipleWords) {
  char result[100];
  reverseWords("hello world", result);
  EXPECT_STREQ(result, "olleh dlrow");

  reverseWords("the quick brown", result);
  EXPECT_STREQ(result, "eht kciuq nworb");
}

TEST(Task12_ReverseWords, WithMultipleSpaces) {
  char result[100];
  reverseWords("hello  world", result);
  EXPECT_STREQ(result, "olleh  dlrow");
}

TEST(Task12_ReverseWords, LeadingTrailingSpaces) {
  char result[100];
  reverseWords("  hello  ", result);
  EXPECT_STREQ(result, "  olleh  ");
}

// ========== Задание 13: Палиндром без учета регистра (1 балл) ==========
TEST(Task13_IsPalindromeIgnoreCase, EmptyString) {
  EXPECT_TRUE(isPalindromeIgnoreCase(""));
}

TEST(Task13_IsPalindromeIgnoreCase, SingleChar) {
  EXPECT_TRUE(isPalindromeIgnoreCase("a"));
  EXPECT_TRUE(isPalindromeIgnoreCase("A"));
}

TEST(Task13_IsPalindromeIgnoreCase, SimplePalindromes) {
  EXPECT_TRUE(isPalindromeIgnoreCase("aba"));
  EXPECT_TRUE(isPalindromeIgnoreCase("Aba"));
  EXPECT_TRUE(isPalindromeIgnoreCase("ABA"));
  EXPECT_TRUE(isPalindromeIgnoreCase("racecar"));
  EXPECT_TRUE(isPalindromeIgnoreCase("RaceCar"));
}

TEST(Task13_IsPalindromeIgnoreCase, WithSpaces) {
  EXPECT_TRUE(isPalindromeIgnoreCase("a b a"));
  EXPECT_FALSE(isPalindromeIgnoreCase("A man a Plan"));
  EXPECT_TRUE(isPalindromeIgnoreCase("race car"));
}

TEST(Task13_IsPalindromeIgnoreCase, NotPalindromes) {
  EXPECT_FALSE(isPalindromeIgnoreCase("hello"));
  EXPECT_FALSE(isPalindromeIgnoreCase("world"));
  EXPECT_FALSE(isPalindromeIgnoreCase("test"));
}

// ========== Задание 14: Подсчет слов (1 балл) ==========
TEST(Task14_CountWords, EmptyString) {
  EXPECT_EQ(countWords(""), 0);
  EXPECT_EQ(countWords("   "), 0);
}

TEST(Task14_CountWords, SingleWord) {
  EXPECT_EQ(countWords("hello"), 1);
  EXPECT_EQ(countWords("  hello  "), 1);
}

TEST(Task14_CountWords, MultipleWords) {
  EXPECT_EQ(countWords("hello world"), 2);
  EXPECT_EQ(countWords("the quick brown fox"), 4);
  EXPECT_EQ(countWords("  hello   world  "), 2);
}

TEST(Task14_CountWords, WithTabs) {
  EXPECT_EQ(countWords("hello\tworld"), 2);
  EXPECT_EQ(countWords("\thello\t\tworld\t"), 2);
}

// ========== Задание 15: Анаграммы (1.5 балла) ==========
TEST(Task15_IsAnagram, EmptyStrings) {
  EXPECT_TRUE(isAnagram("", ""));
}

TEST(Task15_IsAnagram, SimpleAnagrams) {
  EXPECT_TRUE(isAnagram("listen", "silent"));
  EXPECT_TRUE(isAnagram("evil", "vile"));
  EXPECT_TRUE(isAnagram("abc", "bca"));
}

TEST(Task15_IsAnagram, IgnoreCase) {
  EXPECT_TRUE(isAnagram("Listen", "Silent"));
  EXPECT_TRUE(isAnagram("LISTEN", "silent"));
}

TEST(Task15_IsAnagram, IgnoreSpaces) {
  EXPECT_TRUE(isAnagram("a gentleman", "elegant man"));
  EXPECT_TRUE(isAnagram("conversation", "voices rant on"));
}

TEST(Task15_IsAnagram, NotAnagrams) {
  EXPECT_FALSE(isAnagram("hello", "world"));
  EXPECT_FALSE(isAnagram("test", "testing"));
  EXPECT_FALSE(isAnagram("abc", "abcd"));
}

// ========== Задание 16: Общий префикс (3 балла) ==========
TEST(Task16_LongestCommonPrefix, NullTerminated) {
  char result[100];
  longestCommonPrefix(result, NULL);
  EXPECT_STREQ(result, "");
}

TEST(Task16_LongestCommonPrefix, SingleString) {
  char result[100];
  longestCommonPrefix(result, "hello", NULL);
  EXPECT_STREQ(result, "hello");
}

TEST(Task16_LongestCommonPrefix, CommonPrefix) {
  char result[100];
  longestCommonPrefix(result, "flower", "flow", "flight", NULL);
  EXPECT_STREQ(result, "fl");

  longestCommonPrefix(result, "dog", "racecar", "car", NULL);
  EXPECT_STREQ(result, "");

  longestCommonPrefix(result, "test", "testing", "tester", NULL);
  EXPECT_STREQ(result, "test");
}

TEST(Task16_LongestCommonPrefix, NoCommonPrefix) {
  char result[100];
  longestCommonPrefix(result, "abc", "def", "ghi", NULL);
  EXPECT_STREQ(result, "");
}

TEST(Task16_LongestCommonPrefix, AllIdentical) {
  char result[100];
  longestCommonPrefix(result, "hello", "hello", "hello", NULL);
  EXPECT_STREQ(result, "hello");
}

// ========== Задание 17: RLE сжатие (3 балла) ==========
TEST(Task17_CompressString, EmptyString) {
  char result[100];
  compressString("", result);
  EXPECT_STREQ(result, "");
}

TEST(Task17_CompressString, NoRepeats) {
  char result[100];
  compressString("abc", result);
  EXPECT_STREQ(result, "abc");

  compressString("abcdef", result);
  EXPECT_STREQ(result, "abcdef");
}

TEST(Task17_CompressString, AllSame) {
  char result[100];
  compressString("aaaa", result);
  EXPECT_STREQ(result, "a4");

  compressString("bbbbb", result);
  EXPECT_STREQ(result, "b5");
}

TEST(Task17_CompressString, MixedRepeats) {
  char result[100];
  compressString("aaabbcccc", result);
  EXPECT_STREQ(result, "a3b2c4");

  compressString("aabccc", result);
  EXPECT_STREQ(result, "a2bc3");

  compressString("wwwwaaadexxxxxx", result);
  EXPECT_STREQ(result, "w4a3dex6");
}

// ========== Задание 18: Калькулятор (4 балла) ==========
TEST(Task18_CalculateExpression, SimpleAddition) {
  EXPECT_EQ(calculateExpression("2 + 3"), 5);
  EXPECT_EQ(calculateExpression("10 + 5"), 15);
}

TEST(Task18_CalculateExpression, SimpleSubtraction) {
  EXPECT_EQ(calculateExpression("10 - 3"), 7);
  EXPECT_EQ(calculateExpression("5 - 2"), 3);
}

TEST(Task18_CalculateExpression, SimpleMultiplication) {
  EXPECT_EQ(calculateExpression("3 * 4"), 12);
  EXPECT_EQ(calculateExpression("5 * 6"), 30);
}

TEST(Task18_CalculateExpression, SimpleDivision) {
  EXPECT_EQ(calculateExpression("10 / 2"), 5);
  EXPECT_EQ(calculateExpression("20 / 4"), 5);
}

TEST(Task18_CalculateExpression, OperatorPrecedence) {
  EXPECT_EQ(calculateExpression("2 + 3 * 4"), 14);
  EXPECT_EQ(calculateExpression("10 - 2 * 3"), 4);
  EXPECT_EQ(calculateExpression("20 / 4 + 3"), 8);
}

TEST(Task18_CalculateExpression, WithParentheses) {
  EXPECT_EQ(calculateExpression("(2 + 3) * 4"), 20);
  EXPECT_EQ(calculateExpression("(10 - 2) * 3"), 24);
  EXPECT_EQ(calculateExpression("20 / (4 + 1)"), 4);
}

TEST(Task18_CalculateExpression, ComplexExpressions) {
  EXPECT_EQ(calculateExpression("2 + 3 * 4 - 5"), 9);
  EXPECT_EQ(calculateExpression("(2 + 3) * (4 - 2)"), 10);
  EXPECT_EQ(calculateExpression("10 / 2 + 3 * 4"), 17);
}

// ========== Задание 19: Валидация email (5 баллов) ==========
TEST(Task19_ValidateEmail, ValidEmails) {
  EXPECT_TRUE(validateEmail("user@example.com"));
  EXPECT_TRUE(validateEmail("test@test.org"));
  EXPECT_TRUE(validateEmail("name.surname@domain.com"));
  EXPECT_TRUE(validateEmail("user_name@example.co.uk"));
  EXPECT_TRUE(validateEmail("user-name@test-domain.com"));
}

TEST(Task19_ValidateEmail, InvalidEmails_NoAt) {
  EXPECT_FALSE(validateEmail("invalid.email.com"));
  EXPECT_FALSE(validateEmail("nodomain"));
}

TEST(Task19_ValidateEmail, InvalidEmails_MultipleAt) {
  EXPECT_FALSE(validateEmail("user@@example.com"));
  EXPECT_FALSE(validateEmail("user@test@example.com"));
}

TEST(Task19_ValidateEmail, InvalidEmails_NoDomain) {
  EXPECT_FALSE(validateEmail("user@"));
  EXPECT_FALSE(validateEmail("@example.com"));
}

TEST(Task19_ValidateEmail, InvalidEmails_NoDot) {
  EXPECT_FALSE(validateEmail("user@examplecom"));
  EXPECT_FALSE(validateEmail("user@example"));
}

TEST(Task19_ValidateEmail, InvalidEmails_ShortDomain) {
  EXPECT_FALSE(validateEmail("user@example.c"));
  EXPECT_FALSE(validateEmail("user@test.a"));
}

// ========== Задание 20: Самая длинная палиндромная подстрока (5 баллов) ==========
TEST(Task20_LongestPalindromicSubstring, SingleChar) {
  EXPECT_EQ(longestPalindromicSubstring("a"), 1);
  EXPECT_EQ(longestPalindromicSubstring("b"), 1);
}

TEST(Task20_LongestPalindromicSubstring, EntirePalindrome) {
  EXPECT_EQ(longestPalindromicSubstring("aba"), 3);
  EXPECT_EQ(longestPalindromicSubstring("racecar"), 7);
}

TEST(Task20_LongestPalindromicSubstring, MiddlePalindrome) {
  EXPECT_EQ(longestPalindromicSubstring("babad"), 3); // "bab" or "aba"
  EXPECT_EQ(longestPalindromicSubstring("cbbd"), 2);  // "bb"
}

TEST(Task20_LongestPalindromicSubstring, NoPalindrome) {
  EXPECT_EQ(longestPalindromicSubstring("abc"), 1);
  EXPECT_EQ(longestPalindromicSubstring("abcd"), 1);
}

TEST(Task20_LongestPalindromicSubstring, ComplexCases) {
  EXPECT_EQ(longestPalindromicSubstring("bananas"), 5); // "anana"
  EXPECT_EQ(longestPalindromicSubstring("forgeeksskeegfor"), 10); // "geeksskeeg"
  EXPECT_EQ(longestPalindromicSubstring("abcdefggfedcba"), 14); // entire
}
