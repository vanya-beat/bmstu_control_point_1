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
    tasks_["Task01_Sub"] = TaskInfo("Задание 1: Разность двух чисел", 0.5);
    tasks_["Task02_Summ"] = TaskInfo("Задание 2: Сумма N чисел", 0.5);
    tasks_["Task03_IsPerfect"] =
        TaskInfo("Задание 3: Проверка на совершенное число", 0.5);
    tasks_["Task04_FindMin"] = TaskInfo("Задание 4: Минимальный элемент", 0.5);
    tasks_["Task05_ToUpperString"] =
        TaskInfo("Задание 5: Преобразование в заглавные", 0.5);
    tasks_["Task06_IsPalindrome"] =
        TaskInfo("Задание 6: Проверка на палиндром", 0.5);
    tasks_["Task07_BubbleSort"] =
        TaskInfo("Задание 7: Сортировка пузырьком", 0.5);
    tasks_["Task08_HCF"] = TaskInfo("Задание 8: НОК двух чисел", 0.5);
    tasks_["Task09_Catalan"] = TaskInfo("Задание 9: Число Каталана", 0.5);
    tasks_["Task10_IntToOctalString"] =
        TaskInfo("Задание 10: Восьмеричная строка", 0.5);
    tasks_["Task11_ValidHtml"] =
        TaskInfo("Задание 11: Проверка HTML тегов", 5.0);
    tasks_["Task12_NormalizeWindowsPath"] =
        TaskInfo("Задание 12: Нормализация Windows пути", 5.0);
    tasks_["Task13_ReversePolishNotation"] =
        TaskInfo("Задание 13: Обратная польская нотация", 10.0);
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
    if (totalScore >= 20.0)
      grade = "ОТЛИЧНО (5)";
    else if (totalScore >= 15.0)
      grade = "ХОРОШО (4)";
    else if (totalScore >= 10.0)
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
