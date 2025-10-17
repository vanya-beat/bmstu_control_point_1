#include "score_calculator.h"
#include <gtest/gtest.h>

int main(int argc, char **argv) {
  std::cout << "╔══════════════════════════════════════════════════════════════"
               "══════════╗\n";
  std::cout << "║           СИСТЕМА АВТОМАТИЧЕСКОЙ ПРОВЕРКИ СТУДЕНЧЕСКИХ РАБОТ "
               "          ║\n";
  std::cout << "╚══════════════════════════════════════════════════════════════"
               "══════════╝\n";
  std::cout << "\n";

  ::testing::InitGoogleTest(&argc, argv);

  ::testing::TestEventListeners &listeners =
      ::testing::UnitTest::GetInstance()->listeners();

  ::testing::TestEventListener *default_printer =
      listeners.Release(listeners.default_result_printer());

  listeners.Append(new ScoreCalculatorListener(default_printer));

  return RUN_ALL_TESTS();
}
