#ifndef SCORE_CALCULATOR_H
#define SCORE_CALCULATOR_H

#include <algorithm>
#include <gtest/gtest.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

struct TaskInfo {
  std::string name;
  double maxScore;
  int totalTests;
  int passedTests;

  TaskInfo() : maxScore(0.0), totalTests(0), passedTests(0) {}
  TaskInfo(const std::string &n, double score)
      : name(n), maxScore(score), totalTests(0), passedTests(0) {}

  double getScore() const {
    if (totalTests == 0)
      return 0.0;
    return (static_cast<double>(passedTests) / totalTests) * maxScore;
  }

  bool isPerfect() const { return totalTests > 0 && passedTests == totalTests; }
};

class ScoreCalculatorListener : public ::testing::TestEventListener {
private:
  std::map<std::string, TaskInfo> tasks_;
  TestEventListener *defaultListener_;

  void initializeTasks() {
    // Простые задания (15 заданий)
    tasks_["Task01_ArrayProduct"] =
        TaskInfo("Задание 1: Произведение массива", 0.5);
    tasks_["Task02_ArrayAverage"] =
        TaskInfo("Задание 2: Среднее арифметическое", 0.5);
    tasks_["Task03_CountNegative"] =
        TaskInfo("Задание 3: Подсчёт отрицательных", 0.5);
    tasks_["Task04_DigitSum"] = TaskInfo("Задание 4: Сумма цифр числа", 0.5);
    tasks_["Task05_Factorial"] = TaskInfo("Задание 5: Факториал", 0.5);
    tasks_["Task06_GCD"] = TaskInfo("Задание 6: НОД (Евклид)", 0.5);
    tasks_["Task07_IsPrime"] = TaskInfo("Задание 7: Проверка на простоту", 0.5);
    tasks_["Task08_FillFibonacci"] =
        TaskInfo("Задание 8: Числа Фибоначчи", 0.5);
    tasks_["Task09_DotProduct"] =
        TaskInfo("Задание 9: Скалярное произведение", 0.5);
    tasks_["Task10_CountInRange"] =
        TaskInfo("Задание 10: Подсчёт в диапазоне", 0.5);
    tasks_["Task11_RotateRight"] =
        TaskInfo("Задание 11: Циклический сдвиг вправо", 0.5);
    tasks_["Task12_ArrayMedian"] = TaskInfo("Задание 12: Медиана массива", 1.0);
    tasks_["Task13_AllUnique"] = TaskInfo("Задание 13: Все уникальны", 1.0);
    tasks_["Task14_ArrayIntersection"] =
        TaskInfo("Задание 14: Пересечение массивов (malloc)", 1.0);
    tasks_["Task15_SetDifference"] =
        TaskInfo("Задание 15: Разность множеств (malloc)", 1.5);

    // Сложные задания (5 заданий)
    tasks_["Task16_MatrixMultiply"] =
        TaskInfo("Задание 16: Умножение матриц (malloc)", 3.0);
    tasks_["Task17_SieveOfEratosthenes"] =
        TaskInfo("Задание 17: Решето Эратосфена (malloc)", 3.0);
    tasks_["Task18_MaxSubarraySum"] =
        TaskInfo("Задание 18: Макс. подмассив — Кадане (malloc)", 4.0);
    tasks_["Task19_IntToBase"] =
        TaskInfo("Задание 19: Число в систему счисления (malloc)", 5.0);
    tasks_["Task20_SortStrings"] =
        TaskInfo("Задание 20: Сортировка строк", 5.0);
  }

  std::string getTaskPrefix(const std::string &testSuiteName) const {
    return testSuiteName;
  }

public:
  explicit ScoreCalculatorListener(TestEventListener *listener)
      : defaultListener_(listener) {
    initializeTasks();
  }

  ~ScoreCalculatorListener() override { delete defaultListener_; }

  void OnTestProgramStart(const ::testing::UnitTest &unit_test) override {
    defaultListener_->OnTestProgramStart(unit_test);
  }

  void OnTestIterationStart(const ::testing::UnitTest &unit_test,
                            int iteration) override {
    defaultListener_->OnTestIterationStart(unit_test, iteration);
  }

  void OnEnvironmentsSetUpStart(const ::testing::UnitTest &unit_test) override {
    defaultListener_->OnEnvironmentsSetUpStart(unit_test);
  }

  void OnEnvironmentsSetUpEnd(const ::testing::UnitTest &unit_test) override {
    defaultListener_->OnEnvironmentsSetUpEnd(unit_test);
  }

  void OnTestSuiteStart(const ::testing::TestSuite &test_suite) override {
    defaultListener_->OnTestSuiteStart(test_suite);
  }

  void OnTestStart(const ::testing::TestInfo &test_info) override {
    defaultListener_->OnTestStart(test_info);

    std::string taskPrefix = getTaskPrefix(test_info.test_suite_name());
    if (tasks_.find(taskPrefix) != tasks_.end()) {
      tasks_[taskPrefix].totalTests++;
    }
  }

  void
  OnTestPartResult(const ::testing::TestPartResult &test_part_result) override {
    defaultListener_->OnTestPartResult(test_part_result);
  }

  void OnTestEnd(const ::testing::TestInfo &test_info) override {
    defaultListener_->OnTestEnd(test_info);

    std::string taskPrefix = getTaskPrefix(test_info.test_suite_name());
    if (tasks_.find(taskPrefix) != tasks_.end()) {
      if (test_info.result()->Passed()) {
        tasks_[taskPrefix].passedTests++;
      }
    }
  }

  void OnTestSuiteEnd(const ::testing::TestSuite &test_suite) override {
    defaultListener_->OnTestSuiteEnd(test_suite);
  }

  void
  OnEnvironmentsTearDownStart(const ::testing::UnitTest &unit_test) override {
    defaultListener_->OnEnvironmentsTearDownStart(unit_test);
  }

  void
  OnEnvironmentsTearDownEnd(const ::testing::UnitTest &unit_test) override {
    defaultListener_->OnEnvironmentsTearDownEnd(unit_test);
  }

  void OnTestIterationEnd(const ::testing::UnitTest &unit_test,
                          int iteration) override {
    defaultListener_->OnTestIterationEnd(unit_test, iteration);
  }

  void OnTestProgramEnd(const ::testing::UnitTest &unit_test) override {
    defaultListener_->OnTestProgramEnd(unit_test);
    printScoreReport();
  }

private:
  void printScoreReport() const {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════"
                 "════════════╗\n";
    std::cout << "║                    РЕЗУЛЬТАТЫ ПРОВЕРОЧНОЙ РАБОТЫ           "
                 "            ║\n";
    std::cout << "╠════════════════════════════════════════════════════════════"
                 "════════════╣\n";

    double totalScore = 0.0;
    double maxTotalScore = 0.0;

    // Сортируем задания по номеру
    std::vector<std::pair<std::string, TaskInfo>> sortedTasks(tasks_.begin(),
                                                              tasks_.end());
    std::sort(sortedTasks.begin(), sortedTasks.end(),
              [](const auto &a, const auto &b) { return a.first < b.first; });

    for (const auto &[key, task] : sortedTasks) {
      double score = task.getScore();
      totalScore += score;
      maxTotalScore += task.maxScore;

      std::string status = task.isPerfect()       ? "✓"
                           : task.passedTests > 0 ? "~"
                                                  : "✗";

      std::cout << "║ " << std::left << std::setw(50) << task.name << " │ "
                << status << " │ " << std::right << std::setw(4) << std::fixed
                << std::setprecision(2) << score << "/" << std::setw(4)
                << task.maxScore << " ║\n";

      if (!task.isPerfect() && task.totalTests > 0) {
        std::cout << "║   └─ Пройдено тестов: " << task.passedTests << "/"
                  << task.totalTests
                  << std::string(48 -
                                     std::to_string(task.passedTests).length() -
                                     std::to_string(task.totalTests).length(),
                                 ' ')
                  << "║\n";
      }
    }

    std::cout << "╠════════════════════════════════════════════════════════════"
                 "════════════╣\n";
    std::cout << "║ " << std::left << std::setw(50) << "ИТОГО:" << " │   │ "
              << std::right << std::setw(4) << std::fixed
              << std::setprecision(2) << totalScore << "/" << std::setw(4)
              << maxTotalScore << " ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════"
                 "════════════╝\n";

    // Оценка
    std::string grade;
    if (totalScore >= 25.0)
      grade = "ОТЛИЧНО (5)";
    else if (totalScore >= 20.0)
      grade = "ХОРОШО (4)";
    else if (totalScore >= 15.0)
      grade = "УДОВЛЕТВОРИТЕЛЬНО (3)";
    else
      grade = "НЕУДОВЛЕТВОРИТЕЛЬНО (2)";

    double percentage = (totalScore / maxTotalScore) * 100.0;

    std::cout << "\n";
    std::cout << "  Набрано баллов: " << totalScore << " из " << maxTotalScore
              << " (" << std::fixed << std::setprecision(1) << percentage
              << "%)\n";
    std::cout << "  Оценка: " << grade << "\n";
    std::cout << "\n";

    // Легенда
    std::cout << "  Обозначения: ✓ - выполнено полностью  ~ - выполнено "
                 "частично  ✗ - не выполнено\n";
    std::cout << "\n";
  }
};

#endif // SCORE_CALCULATOR_H
