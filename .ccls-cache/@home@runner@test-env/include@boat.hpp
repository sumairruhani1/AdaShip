#pragma once 

class Fleet {
  static int boatCount; // count the number of boats on the board
public:
  int getBoatCount();
};

//  : public Fleet 
class Boat : public Fleet {
public:
  int size;             // size of boat
  std::string boatType; // type of boat
  int x, y;             // coords for boat
  std::string rotation; // rotation of boat
  Boat(int Size, std::string BoatType);
  std::string getName();
  void setName(std::string BoatType);
  void getDetails();
};