#include "../include/index.hpp"

int Fleet::getBoatCount() { return boatCount; }

Boat::Boat(int Size, std::string BoatType) {
  size = Size;
  boatType = BoatType;
};

std::string Boat::getName() { return boatType; }
void Boat::setName(std::string BoatType) { this->boatType = BoatType; }
void Boat::getDetails() {
  std::cout << boatType << " Size: " << size << std::endl;
}
// sget health
// sget size
// sget coords
