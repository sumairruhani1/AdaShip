#include "./include/index.hpp"

int main() {
  importConfigData("./adaship_config.ini", "x");
  importConfigData("./adaship_config.ini", ",");

  Boat Carrier = Boat(5, "Carrier");
  return 0;
}
