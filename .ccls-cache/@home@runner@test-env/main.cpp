#include "./include/index.hpp"

int main() {
  importConfigData("./adaship_config.ini", "x");
  importConfigData("./adaship_config.ini", ",");
  return 0;
}
