#include "student_tasks.h"
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

// ============== ПРОСТЫЕ ЗАДАНИЯ (15 заданий, 0.5-1.5 балла) ==============

// Задание 1: Вычислить длину строки (0.5 балла)
size_t stringLength(const char *str) {
  size_t length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}

// Задание 2: Скопировать строку (0.5 балла)
void stringCopy(char *dest, const char *src) {
  size_t i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
}

// Задание 3: Конкатенация строк (0.5 балла)
void stringConcat(char *dest, const char *src) {
  dest += stringLength(dest);
  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
}

// Задание 4: Сравнение строк (0.5 балла)
int stringCompare(const char *str1, const char *str2) {
  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }
  if (*str1 < *str2) {
    return -1;
  } else if (*str1 > *str2) {
    return 1;
  }
  return 0;
}

// Задание 5: Подсчитать количество вхождений символа (0.5 балла)
int countChar(const char *str, char ch) {
  int count = 0;
  while (*str != '\0') {
    if (*str == ch) {
      count++;
    }
    str++;
  }
  return count;
}

// Задание 6: Подсчитать количество гласных букв (0.5 балла)
int countVowels(const char *str) {
  int count = 0;
  while (*str != '\0') {
    char ch = tolower(*str);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
      count++;
    }
    str++;
  }
  return count;
}

// Задание 7: Удалить все пробелы из строки (0.5 балла)
void removeSpaces(const char *str, char *result) {
  size_t j = 0;
  for (size_t i = 0; str[i] != '\0'; i++) {
    if (str[i] != ' ') {
      result[j++] = str[i];
    }
  }
  result[j] = '\0';
}

// Задание 10: Заменить все вхождения символа (0.5 балла)
void replaceChar(const char *str, char oldChar, char newChar, char *result) {
  size_t i = 0;
  while (str[i] != '\0') {
    if (str[i] == oldChar) {
      result[i] = newChar;
    } else {
      result[i] = str[i];
    }
    i++;
  }
  result[i] = '\0';
}

// Задание 8: Найти длину первого слова (0.5 балла)
int firstWordLength(const char *str) {
  int length = 0;
bool inword = false;

  while ((*str != '\0' && *str != ' ') || !inword) {
      if (*str == '\0') {
          break;
      }
      if (inword) {
          length++;
      } else if (*str != '\0' && *str != ' ') {
          inword = true;
          length++;
      }
    str++;
  }
  return length;
}

// Задание 9: Найти подстроку в строке (0.5 балла)
int findSubstring(const char *str, const char *substr) {
  if (*substr == '\0') {
    return 0;
  }
  for (size_t i = 0; str[i] != '\0'; i++) {
    size_t j = 0;
    while (str[i + j] != '\0' && substr[j] != '\0' && str[i + j] == substr[j]) {
      j++;
    }
    if (substr[j] == '\0') {
      return i;
    }
  }
  return -1;
}


// Задание 11: Удалить начальные и конечные пробелы (trim) (0.5 балла)
void trimString(const char *str, char *result) {
  size_t start = 0;
  size_t end = stringLength(str) - 1;
  while (str[start] == ' ') {
    start++;
  }
  while (end > start && str[end] == ' ') {
    end--;
  }
  size_t i = 0;
  for (size_t j = start; j <= end; j++) {
    result[i++] = str[j];
  }
  result[i] = '\0';
}

// Задание 12: Перевернуть слова в строке (1 балл)
void reverseWords(const char *str, char *result) {

      const char* wordStart;
    const char* wordEnd;
    char* out = result;

 while (*str)
    {
        // Copy spaces directly
        if (*str == ' ')
        {
            *out = *str;
            out++;
            str++;
        }
        else
        {
            wordStart = str;

            while (*str && *str != ' ')
            {
                str++;
            }

            wordEnd = str - 1;

            while (wordEnd >= wordStart)
            {
                *out = *wordEnd;
                out++;
                wordEnd--;
            }
        }
    }

    *out = '\0';
}

// Задание 13: Палиндром без учета регистра и пробелов (1 балл)
bool isPalindromeIgnoreCase(const char *str) {
  if (*str == '\0') {
    return true;
  }
  size_t left = 0;
  size_t right = stringLength(str) - 1;
  while (left < right) {
    while (left < right && str[left] == ' ') {
      left++;
    }
    while (left < right && str[right] == ' ') {
      right--;
    }
    if (tolower(str[left]) != tolower(str[right])) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

// Задание 14: Подсчитать количество слов в строке (1 балл)
int countWords(const char *str) {
  int count = 0;
  bool inWord = false;
  while (*str != '\0') {
    if (*str != ' ' && *str != '\t' && !inWord) {
      count++;
      inWord = true;
    } else if (*str == ' ' || *str == '\t') {
      inWord = false;
    }
    str++;
  }
  return count;
}

// Задание 15: Проверка на анаграммы (1.5 балла)
bool isAnagram(const char *str1, const char *str2) {
  int count[256] = {0};
  for (size_t i = 0; str1[i] != '\0'; i++) {
    count[(unsigned char)str1[i]]++;
  }
  for (size_t i = 0; str2[i] != '\0'; i++) {
    count[(unsigned char)str2[i]]--;
  }
  for (int i = 0; i < 256; i++) {
    if (count[i] != 0) {
      return false;
    }
  }
  return true;
}

// ============== СЛОЖНЫЕ ЗАДАНИЯ (5 заданий, 3-5 баллов) ==============

// Задание 16: Найти самый длинный общий префикс (3 балла)
void longestCommonPrefix(char *result, const char *first, ...) {
  va_list args;
  va_start(args, first);
  if (first == NULL) {
    result[0] = '\0';
    return;
  }
  size_t prefixLength = stringLength(first);
  const char *current = va_arg(args, const char*);
  while (current != NULL) {
    size_t currentLength = stringLength(current);
    size_t minLength = prefixLength < currentLength ? prefixLength : currentLength;
    size_t i = 0;
    while (i < minLength && first[i] == current[i]) {
      i++;
    }
    prefixLength = i;
    current = va_arg(args, const char*);
  }
  if (prefixLength > 0) {
    for (size_t i = 0; i < prefixLength; i++) {
      result[i] = first[i];
    }
    result[prefixLength] = '\0';
  } else {
    result[0] = '\0';
  }
}

// Задание 17: RLE-сжатие строки (3 балла)
void compressString(const char *str, char *result) {
  size_t j = 0;
  for (size_t i = 0; str[i] != '\0';) {
    char currentChar = str[i];
    size_t count = 1;
    while (str[i + count] == currentChar) {
      count++;
    }
    result[j++] = currentChar;
    if (count > 1) {
      j += sprintf(result + j, "%zu", count);
    }
    i += count;
  }
  result[j] = '\0';
}

// Задание 18: Простой калькулятор (4 балла)
int calculateExpression(const char *expression) {
return 0;
}

// Задание 19: Валидация email адреса (5 баллов)
bool validateEmail(const char *email) {
  // Правила:
  //   - ровно один @
  //   - до @ минимум 1 символ (буквы, цифры, точка, дефис, подчеркивание)
  //   - после @ домен с точкой
  //   - доменная зона минимум 2 символа
  bool hasSymbolBeforeAt = false;
  bool hasAt = false;
  bool hasSymbolAfterAt = false;
  bool hasDotAfterAt = false;
  int domenZoneLength = 0;
  while (*email != '\0') {
    if (isalnum(*email) || *email == '-' || *email == '_' || *email == '.') {
      if (!hasAt) {
        hasSymbolBeforeAt = true;
      }
    }
    if (*email == '@') {
      if (hasAt) {
        return false;
      }
      hasAt = true;
    }
     if (hasAt) {
      if (*email == '.') {
        hasDotAfterAt = true;
      }
      if (hasDotAfterAt && (isalnum(*email) || *email == '-' || *email == '_')) {
        hasSymbolAfterAt = true;
      } else if (hasDotAfterAt && *email != '.') {
        return false; 
      }
        if (hasDotAfterAt && isalnum(*email)) {
          domenZoneLength++;
        }
    } 
    email++;
  }
  return hasSymbolBeforeAt && hasAt && hasSymbolAfterAt && hasDotAfterAt && domenZoneLength >= 2;
}

// Задание 20: Найти самую длинную палиндромную подстроку (5 баллов)
int longestPalindromicSubstring(const char *str) {
  size_t len = stringLength(str);
  if (len == 0) {
    return 0;
  }
  int maxLength = 1;
  for (size_t i = 0; i < len; i++) {
    int left = i, right = i; // Odd 
    while (left >= 0 && right < len && str[left] == str[right]) {
      int currentLength = right - left + 1;
      if (currentLength > maxLength) {
        maxLength = currentLength;
      }
      left--;
      right++;
    }
    left = i, right = i + 1; //Even
    while (left >= 0 && right < len && str[left] == str[right]) {
      int currentLength = right - left + 1;
      if (currentLength > maxLength) {
        maxLength = currentLength;
      }
      left--;
      right++;
    }
  }
  return maxLength;
}