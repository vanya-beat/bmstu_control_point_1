#include "student_tasks.hpp"
#include <algorithm>
#include <chrono>
#include <gtest/gtest.h>
#include <random>
#include <set>

// Вспомогательная функция для измерения времени выполнения
template <typename Func> long long measureTime(Func func) {
  auto start = std::chrono::high_resolution_clock::now();
  func();
  auto end = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
      .count();
}

// ========== Задание 1: Удаление дубликатов (1 балл) ==========

TEST(Task01_RemoveDuplicates, BasicTest) {
  std::vector<int> input = {4, 2, 1, 2, 3, 4, 1};
  std::vector<int> expected = {4, 2, 1, 3};
  EXPECT_EQ(removeDuplicates(input), expected);
}

TEST(Task01_RemoveDuplicates, NoDuplicates) {
  std::vector<int> input = {1, 2, 3, 4};
  std::vector<int> expected = {1, 2, 3, 4};
  EXPECT_EQ(removeDuplicates(input), expected);
}

TEST(Task01_RemoveDuplicates, AllDuplicates) {
  std::vector<int> input = {5, 5, 5, 5};
  std::vector<int> expected = {5};
  EXPECT_EQ(removeDuplicates(input), expected);
}

TEST(Task01_RemoveDuplicates, PerformanceTest) {
  // Тест производительности: 100k элементов
  // Правильная реализация (unordered_set): O(n)
  // Неправильная (например, каждый раз проверка всего вектора): O(n²) - НЕ
  // ПРОЙДЁТ
  std::vector<int> input(100000);
  for (int i = 0; i < 100000; i++) {
    input[i] = i % 50000; // Много дубликатов
  }

  auto time = measureTime([&]() { auto result = removeDuplicates(input); });

  EXPECT_LE(time, 100) << "Слишком медленная реализация! Используйте "
                          "правильный контейнер для O(n)";
}

// ========== Задание 2: Поиск пары с заданной суммой (1.5 балла) ==========

TEST(Task02_TwoSum, BasicTest) {
  std::vector<int> nums = {2, 7, 11, 15};
  auto result = twoSum(nums, 9);
  EXPECT_TRUE((result.first == 0 && result.second == 1) ||
              (result.first == 1 && result.second == 0));
}

TEST(Task02_TwoSum, DifferentPair) {
  std::vector<int> nums = {3, 2, 4};
  auto result = twoSum(nums, 6);
  EXPECT_TRUE((result.first == 1 && result.second == 2) ||
              (result.first == 2 && result.second == 1));
}

TEST(Task02_TwoSum, NegativeNumbers) {
  std::vector<int> nums = {-1, -2, -3, -4, -5};
  auto result = twoSum(nums, -8);
  EXPECT_TRUE((result.first == 2 && result.second == 4) ||
              (result.first == 4 && result.second == 2) ||
              (result.first == 3 && result.second == 2) ||
              (result.first == 2 && result.second == 3));
}

TEST(Task02_TwoSum, PerformanceTest) {
  // Тест производительности: 100k элементов
  // Правильная реализация (unordered_map): O(n)
  // Неправильная (два цикла): O(n²) - НЕ ПРОЙДЁТ
  std::vector<int> nums(100000);
  for (int i = 0; i < 100000; i++) {
    nums[i] = i;
  }
  int target = 100000 + 100001; // последние два элемента

  auto time = measureTime([&]() { auto result = twoSum(nums, target); });

  EXPECT_LE(time, 50) << "Слишком медленная реализация! O(n²) не пройдёт. "
                         "Используйте hash map!";
}

// ========== Задание 3: Группировка анаграмм (2 балла) ==========

TEST(Task03_GroupAnagrams, BasicTest) {
  std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
  auto result = groupAnagrams(input);

  EXPECT_EQ(result.size(), 3);

  // Проверяем, что каждая группа содержит правильные анаграммы
  for (const auto &group : result) {
    if (group.size() == 3) {
      std::set<std::string> s(group.begin(), group.end());
      EXPECT_TRUE(s.count("eat") && s.count("tea") && s.count("ate"));
    } else if (group.size() == 2) {
      std::set<std::string> s(group.begin(), group.end());
      EXPECT_TRUE((s.count("tan") && s.count("nat")) ||
                  (s.count("eat") && s.count("tea")));
    } else if (group.size() == 1) {
      EXPECT_TRUE(group[0] == "bat" || group[0] == "nat" || group[0] == "tan");
    }
  }
}

TEST(Task03_GroupAnagrams, SingleGroup) {
  std::vector<std::string> input = {"abc", "bca", "cab"};
  auto result = groupAnagrams(input);
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0].size(), 3);
}

TEST(Task03_GroupAnagrams, PerformanceTest) {
  // Генерируем 10000 строк с анаграммами
  std::vector<std::string> input(10000);
  std::string base = "abcdefgh";
  std::mt19937 gen(42);

  for (int i = 0; i < 10000; i++) {
    std::string s = base;
    std::shuffle(s.begin(), s.end(), gen);
    input[i] = s;
  }

  auto time = measureTime([&]() { auto result = groupAnagrams(input); });

  EXPECT_LE(time, 200) << "Слишком медленная реализация!";
}

// ========== Задание 4: Топ K частых элементов (2 балла) ==========

TEST(Task04_TopKFrequent, BasicTest) {
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};
  auto result = topKFrequent(nums, 2);
  std::sort(result.begin(), result.end());
  EXPECT_EQ(result.size(), 2);
  EXPECT_TRUE(std::find(result.begin(), result.end(), 1) != result.end());
  EXPECT_TRUE(std::find(result.begin(), result.end(), 2) != result.end());
}

TEST(Task04_TopKFrequent, SingleElement) {
  std::vector<int> nums = {1};
  auto result = topKFrequent(nums, 1);
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], 1);
}

TEST(Task04_TopKFrequent, AllSameFrequency) {
  std::vector<int> nums = {1, 2, 3, 4};
  auto result = topKFrequent(nums, 2);
  EXPECT_EQ(result.size(), 2);
}

TEST(Task04_TopKFrequent, PerformanceTest) {
  // 100k элементов
  std::vector<int> nums(100000);
  for (int i = 0; i < 100000; i++) {
    nums[i] = i % 1000; // 1000 уникальных чисел с разными частотами
  }

  auto time = measureTime([&]() { auto result = topKFrequent(nums, 10); });

  EXPECT_LE(time, 100) << "Слишком медленная реализация!";
}

// ========== Задание 5: Следующий больший элемент (1.5 балла) ==========

TEST(Task05_NextGreaterElement, BasicTest) {
  std::vector<int> nums1 = {4, 1, 2};
  std::vector<int> nums2 = {1, 3, 4, 2};
  std::vector<int> expected = {-1, 3, -1};
  EXPECT_EQ(nextGreaterElement(nums1, nums2), expected);
}

TEST(Task05_NextGreaterElement, AllGreater) {
  std::vector<int> nums1 = {1, 2};
  std::vector<int> nums2 = {1, 2, 3, 4};
  std::vector<int> expected = {2, 3};
  EXPECT_EQ(nextGreaterElement(nums1, nums2), expected);
}

TEST(Task05_NextGreaterElement, NoGreater) {
  std::vector<int> nums1 = {2};
  std::vector<int> nums2 = {2, 1};
  std::vector<int> expected = {-1};
  EXPECT_EQ(nextGreaterElement(nums1, nums2), expected);
}

TEST(Task05_NextGreaterElement, PerformanceTest) {
  // 10k элементов
  std::vector<int> nums2(10000);
  for (int i = 0; i < 10000; i++) {
    nums2[i] = i;
  }
  std::vector<int> nums1(5000);
  for (int i = 0; i < 5000; i++) {
    nums1[i] = i * 2;
  }

  auto time =
      measureTime([&]() { auto result = nextGreaterElement(nums1, nums2); });

  EXPECT_LE(time, 100) << "Слишком медленная реализация!";
}

// ========== Задание 6: LRU Cache (3 балла) ==========

TEST(Task06_LRUCache, BasicOperations) {
  LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  EXPECT_EQ(cache.get(1), 1);
  cache.put(3, 3); // Должен вытеснить ключ 2
  EXPECT_EQ(cache.get(2), -1);
  cache.put(4, 4); // Должен вытеснить ключ 1
  EXPECT_EQ(cache.get(1), -1);
  EXPECT_EQ(cache.get(3), 3);
  EXPECT_EQ(cache.get(4), 4);
}

TEST(Task06_LRUCache, UpdateExisting) {
  LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  cache.put(1, 10); // Обновление существующего
  EXPECT_EQ(cache.get(1), 10);
  EXPECT_EQ(cache.get(2), 2);
}

TEST(Task06_LRUCache, GetUpdatesRecency) {
  LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  EXPECT_EQ(cache.get(1), 1); // 1 становится недавно использованным
  cache.put(3, 3);            // Должен вытеснить 2
  EXPECT_EQ(cache.get(2), -1);
  EXPECT_EQ(cache.get(1), 1);
  EXPECT_EQ(cache.get(3), 3);
}

TEST(Task06_LRUCache, PerformanceTest) {
  // Тест O(1) производительности: 50k операций
  // Правильная реализация: O(1) для get и put
  // Неправильная (например, vector): будет O(n) - НЕ ПРОЙДЁТ
  LRUCache cache(10000);

  auto time = measureTime([&]() {
    for (int i = 0; i < 50000; i++) {
      cache.put(i, i);
      if (i % 2 == 0) {
        cache.get(i - 1);
      }
    }
  });

  EXPECT_LE(time, 100)
      << "Операции должны быть O(1)! Используйте комбинацию контейнеров.";
}

// ========== Задание 7: Слияние K отсортированных списков (3 балла) ==========

TEST(Task07_MergeKSorted, BasicTest) {
  std::vector<std::vector<int>> lists = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
  std::vector<int> expected = {1, 1, 2, 3, 4, 4, 5, 6};
  EXPECT_EQ(mergeKSortedLists(lists), expected);
}

TEST(Task07_MergeKSorted, EmptyLists) {
  std::vector<std::vector<int>> lists = {{}, {1}, {}};
  std::vector<int> expected = {1};
  EXPECT_EQ(mergeKSortedLists(lists), expected);
}

TEST(Task07_MergeKSorted, SingleList) {
  std::vector<std::vector<int>> lists = {{1, 2, 3, 4, 5}};
  std::vector<int> expected = {1, 2, 3, 4, 5};
  EXPECT_EQ(mergeKSortedLists(lists), expected);
}

TEST(Task07_MergeKSorted, PerformanceTest) {
  // 500 списков по ~200 элементов = ~100k элементов
  // Правильная реализация с heap: O(N log k)
  // Простая конкатенация + сортировка: O(N log N) - может не пройти
  std::vector<std::vector<int>> lists(500);
  for (int i = 0; i < 500; i++) {
    lists[i].resize(200);
    for (int j = 0; j < 200; j++) {
      lists[i][j] = j * 500 + i; // Отсортированные списки
    }
  }

  auto time = measureTime([&]() { auto result = mergeKSortedLists(lists); });

  EXPECT_LE(time, 500) << "Слишком медленная реализация! Используйте min-heap "
                          "для эффективного слияния.";
  EXPECT_EQ(mergeKSortedLists(lists).size(), 100000);
}

// ========== Задание 8: Первый уникальный символ (1 балл) ==========

TEST(Task08_FirstUniqChar, BasicTest) {
  EXPECT_EQ(firstUniqChar("leetcode"), 0);
  EXPECT_EQ(firstUniqChar("loveleetcode"), 2);
  EXPECT_EQ(firstUniqChar("aabb"), -1);
}

TEST(Task08_FirstUniqChar, SingleChar) { EXPECT_EQ(firstUniqChar("a"), 0); }

TEST(Task08_FirstUniqChar, AllUnique) { EXPECT_EQ(firstUniqChar("abcdef"), 0); }

TEST(Task08_FirstUniqChar, PerformanceTest) {
  // 100k символов
  std::string s(100000, 'a');
  s[99999] = 'b'; // Последний символ уникален

  auto time = measureTime([&]() { auto result = firstUniqChar(s); });

  EXPECT_LE(time, 50) << "Должно работать за O(n)!";
}

// ========== Задание 9: Отсортированная частота (1.5 балла) ==========

TEST(Task09_SortedFrequency, BasicTest) {
  std::vector<int> nums = {4, 5, 4, 5, 4, 6};
  std::vector<std::pair<int, int>> expected = {{4, 3}, {5, 2}, {6, 1}};
  EXPECT_EQ(sortedFrequency(nums), expected);
}

TEST(Task09_SortedFrequency, SingleElement) {
  std::vector<int> nums = {1};
  std::vector<std::pair<int, int>> expected = {{1, 1}};
  EXPECT_EQ(sortedFrequency(nums), expected);
}

TEST(Task09_SortedFrequency, AllUnique) {
  std::vector<int> nums = {5, 1, 3, 2, 4};
  std::vector<std::pair<int, int>> expected = {
      {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}};
  EXPECT_EQ(sortedFrequency(nums), expected);
}

TEST(Task09_SortedFrequency, PerformanceTest) {
  // 100k элементов
  std::vector<int> nums(100000);
  for (int i = 0; i < 100000; i++) {
    nums[i] = i % 10000;
  }

  auto time = measureTime([&]() { auto result = sortedFrequency(nums); });

  EXPECT_LE(time, 150) << "Используйте контейнер с автоматической сортировкой!";
}

// ========== Задание 10: Эффективная вставка в середину (2 балла) ==========

TEST(Task10_MiddleInsertion, BasicOperations) {
  MiddleInsertionList list;
  list.insert(0, 1); // [1]
  list.insert(0, 2); // [2, 1]
  list.insert(1, 3); // [2, 3, 1]

  EXPECT_EQ(list.size(), 3);
  EXPECT_EQ(list.get(0), 2);
  EXPECT_EQ(list.get(1), 3);
  EXPECT_EQ(list.get(2), 1);
}

TEST(Task10_MiddleInsertion, InsertAtEnd) {
  MiddleInsertionList list;
  list.insert(0, 1);
  list.insert(1, 2);
  list.insert(2, 3);

  EXPECT_EQ(list.get(0), 1);
  EXPECT_EQ(list.get(1), 2);
  EXPECT_EQ(list.get(2), 3);
}

TEST(Task10_MiddleInsertion, MixedOperations) {
  MiddleInsertionList list;
  for (int i = 0; i < 10; i++) {
    list.insert(0, i); // Вставка в начало
  }
  EXPECT_EQ(list.size(), 10);
  EXPECT_EQ(list.get(0), 9);
}

TEST(Task10_MiddleInsertion, PerformanceTest) {
  // Много вставок в середину и начало
  // vector: O(n) на вставку = O(n²) общее - НЕ ПРОЙДЁТ
  // deque или другие: лучше, но нужен баланс с get()
  MiddleInsertionList list;

  auto time = measureTime([&]() {
    for (int i = 0; i < 10000; i++) {
      list.insert(i / 2, i); // Вставка преимущественно в середину
    }
    // Проверяем несколько get
    for (int i = 0; i < 100; i++) {
      list.get(i * 50);
    }
  });

  EXPECT_LE(time, 500) << "Вставка в vector в середину - O(n²)! Используйте "
                          "более эффективный контейнер!";
}
