#include "./include/index.hpp"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

// Boat class
class Boat {
public:
  int length;
  std::string name;
  bool isPlaced;

  Boat(int length, const std::string &name, bool isPlaced)
      : length(length), name(name), isPlaced(isPlaced) {}

  // reset all boats by setting their isPlaced member variable to false
  static void resetShips(std::vector<Boat> &boats) {
    for (Boat &boat : boats) {
      boat.isPlaced = false;
    }
  }
};

// Board class
class Board {
public:
  static int boardHeight; // height of the game board
  static int boardWidth;  // width of the game board

  // represent a cell on the game board
  class Cell {
  public:
    Cell() : isShip(false), isHit(false) {}
    bool isShip; // whether there is a ship at this cell
    bool isHit;  // whether this cell has been hit by a shot
  };

  // initialize the game board
  Board() {
    gameBoard.resize(boardHeight);
    for (int i = 0; i < boardHeight; i++) {
      gameBoard[i].resize(boardWidth);
      for (int j = 0; j < boardWidth; j++) {
        gameBoard[i][j].isShip = false;
        gameBoard[i][j].isHit = false;
      }
    }
  }

  // check if a cell is within the bounds of the game board
  bool isValidCell(int x, int y) {
    return x >= 0 && x < boardWidth && y >= 0 && y < boardHeight;
  }

  bool canPlaceShip(int x, int y, int length, bool isVertical) {
    // check if the ship is within the bounds of the game board
    if (isVertical) {
      if (!isValidCell(x, y) || !isValidCell(x, y + length - 1)) {
        return false;
      }
    } else {
      if (!isValidCell(x, y) || !isValidCell(x + length - 1, y)) {
        return false;
      }
    }

    // check if there is a ship at any of the cells occupied by the ship
    if (isVertical) {
      for (int i = y; i < y + length; i++) {
        if (gameBoard[i][x]
                .isShip) { // check if the cell is already occupied by a ship
          return false;
        }
      }
    } else {
      for (int i = x; i < x + length; i++) {
        if (gameBoard[y][i]
                .isShip) { // check if the cell is already occupied by a ship
          return false;
        }
      }
    }
    return true;
  }

  // place a ship on the game table
  void placeShip(int x, int y, int length, bool isVertical) {
    for (int k = 0; k < length; k++) {
      if (isVertical) {
        gameBoard[y + k][x].isShip = true;

      } else {
        gameBoard[y][x + k].isShip = true;
      }
    }
  }

  // plot a ship on the game table
  void plotShip(const std::string &position, Boat &boat, bool isVertical) {

    // parse the position string
    std::stringstream stream(
        position); // create a stringstream from the position string
    char column;
    int row;
    if (!(stream >> column >> row)) {
      std::cout << "Invalid position" << std::endl;
      return;
    }
    row--; // adjust for zero-based indexing
    int x =
        column - 'A'; // convert column to integer (assuming uppercase input)
    int y = row;
    int length = boat.length;

    // check if the ship can be placed at the specified location
    if (!canPlaceShip(x, y, length, isVertical)) {
      std::cout << "Cannot place ship at specified location" << std::endl;
      return;
    }

    // place the ship on the board
    placeShip(x, y, length, isVertical);
    boat.isPlaced = true; // mark the boat as placed
    std::cout << boat.name << " placed at " << position << std::endl;
  }

  // function to automatically plot the remaining ships that haven't been
  // plotted just yet
  void autoPlotShips(std::vector<Boat> &boats) {
    // initialize a random number generator
    std::srand(std::time(nullptr));

    // find the remaining boats that have not been placed
    std::vector<Boat *> remainingBoats;
    for (auto &boat : boats) {
      if (!boat.isPlaced) {
        remainingBoats.push_back(&boat);
      }
    }

    // continue until all remaining boats have been placed
    while (!remainingBoats.empty()) {
      // choose a random remaining boat
      int index = std::rand() % remainingBoats.size();
      Boat *boat = remainingBoats[index];

      // choose a random orientation for the boat (vertical or horizontal)
      bool isVertical = std::rand() % 2 == 0;

      // choose a random starting position for the boat
      int x = std::rand() % boardWidth;
      int y = std::rand() % boardHeight;

      // try to place the boat at the chosen location
      if (canPlaceShip(x, y, boat->length, isVertical)) {
        placeShip(x, y, boat->length, isVertical);
        boat->isPlaced = true;

        // remove the boat from the remaining boats list
        remainingBoats.erase(remainingBoats.begin() + index);
      }
    }
  }

  // remove all ships from the board
  void resetBoard() {
    for (int i = 0; i < boardHeight; i++) {
      for (int j = 0; j < boardWidth; j++) {
        gameBoard[i][j].isShip = false;
      }
    }
  }

  // print the game board
  void printBoard() {
    // print the alphabet along the top row
    std::cout << std::endl
              << "   "; // add an extra space to align the letters with the
                        // board cells
    for (int i = 0; i < boardWidth; i++) {
      std::cout << std::setw(2) << static_cast<char>('A' + i)
                << " "; // use setw to align the letters
    }
    std::cout << std::endl;

    // print the numbers along the left column and the contents of the board
    // cells
    for (int i = 0; i < boardHeight; i++) {
      std::cout << std::setw(2) << i + 1
                << "  "; // use setw to align the numbers and add an extra space
                         // to align with the board cells
      for (int j = 0; j < boardWidth; j++) {
        if (gameBoard[i][j].isShip) {
          std::cout << "X  ";
        } else {
          std::cout << ".  ";
        }
      }
      std::cout << std::endl;
    }
  }

  // fire a shot at a given location on the game board
  bool fireShot(int x, int y) {
    if (!isValidCell(x, y)) {
      return false; // invalid cell
    }
    if (gameBoard[y][x].isHit) {
      return false; // cell has already been hit
    }
    gameBoard[y][x].isHit = true;
    return gameBoard[y][x].isShip;
  }

  // generate a random position for a shot
  std::pair<int, int> generateRandomPosition(int numAttempts, bool ignoreHits) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, boardWidth - 1);
    while (numAttempts--) {
      int x = dis(gen);
      int y = dis(gen);
      if (ignoreHits || !gameBoard[y][x].isHit) {
        return std::make_pair(x, y);
      }
    }
    return std::make_pair(-1, -1);
  }

private:
  std::vector<std::vector<Cell>> gameBoard;
};

int Board::boardHeight; // initialize the board height
int Board::boardWidth;  // initialize the board width

void importBoardConfigData(std::string filename, int &height, int &width) {
  // file handling for adaship_config.ini file
  std::ifstream file;
  file.open(filename); // open file
  std::string line;
  if (file) {
    while (std::getline(file, line)) {
      line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

      if (line.find("Board") != -1) {
        int startPointer = line.find(":") + 1; // Initial pointer
        int endPointer = line.find("x") + 1;   // Secondary pointer
        int diff = endPointer - startPointer;  // string difference
        std::string heightStr = line.substr(startPointer, diff - 1);
        std::string widthStr = line.substr(endPointer);
        height = std::stoi(heightStr);
        width = std::stoi(widthStr);
      }
    }
  } else {
    std::cout << "Could not find or open adaship_config.ini" << std::endl;
  }
};

// import boat data from config file
void importBoatConfigData(const std::string &filename,
                          std::vector<Boat> &boats) {
  // file handling for adaship_config.ini file
  std::ifstream file;
  file.open(filename); // open file
  std::string line;
  if (file) {
    while (std::getline(file, line)) {
      line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

      if (line.find("Boat") != -1) {
        int startPointer = line.find(":") + 1; // Initial pointer
        int endPointer = line.find(",") + 1;   // Secondary pointer
        int diff = endPointer - startPointer;  // string difference
        std::string name = line.substr(startPointer, diff - 1);
        int length = std::stoi(line.substr(endPointer));
        boats.emplace_back(length, name, false);
      }
    }
  } else {
    std::cout << "Could not find or open adaship_config.ini" << std::endl;
  }
}

// function prototypes
void setupBoards(Board &playerBoard, Board &computerBoard,
                 std::vector<Boat> &playerShips,
                 std::vector<Boat> &computerShips);
void playGame(Board &playerBoard, Board &computerBoard,
              std::vector<Boat> &playerShips, std::vector<Boat> &computerShips);

void listAvailableShips(std::vector<Boat> &boats, Board &board) {
  // list the boats and allow the user to select a boat to place on the board
  board.printBoard();
  int index = 0;
  std::cout << std::endl << "Available boats:" << std::endl << std::endl;
  for (const Boat &boat : boats) {
    if (!boat.isPlaced) {
      std::cout << ++index << ". " << boat.name << " [Length: " << boat.length
                << "]" << std::endl;
    }
  }
  std::cout << std::endl
            << "9"
            << ". Automatically place all or remaining ships" << std::endl;
  std::cout << std::endl
            << "0"
            << ". Reset the board" << std::endl;
}

bool plotPlayerShips(std::vector<Boat> &boats, Board &board) {
  int n = 0; // counter of the number of boats that have been placed

  while (true) {
    // check if all boats have been placed
    if (std::all_of(boats.begin(), boats.end(),
                    [](const Boat &boat) { return boat.isPlaced; })) {
      std::cout << "All ships have been placed. Do you want to continue "
                   "placing ships? (y/n): ";
      char input;
      std::cin >> input;
      if (input == 'n') {
        return true;
      }
    }

    listAvailableShips(boats, board);
    std::cout << std::endl
              << "Enter the number of the boat to place or your option: ";
    int number;
    if (!(std::cin >> number)) {
      std::cout << std::endl
                << std::endl
                << "Error: Please enter a valid boat number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    if (number == 9) {
      board.autoPlotShips(boats);
      board.printBoard();
      continue;
    }
    if (number == 0) {
      board.resetBoard();
      Boat::resetShips(boats);
      continue;
    }

    // find the boat with the given number
    auto it = std::find_if(boats.begin(), boats.end(),
                           [&number, &n](const Boat &boat) {
                             return --number == 0 - n && !boat.isPlaced;
                           });

    if (it == boats.end()) {
      std::cout << "Invalid boat number or boat already placed" << std::endl;
      continue;
    }

    Boat &boat = *it;
    n++; // increment the counter of placed boats

    std::cout << "Enter position and orientation (e.g. A1 V, B5 H etc): ";
    std::string position;
    char orientation;
    if (!(std::cin >> position >> orientation)) {
      std::cout << "Error: Ensure that you have entered acceptable coordinates "
                   "and orientation. Note that a ship cannot be placed over "
                   "other ships. "
                << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    bool isVertical = orientation == 'V';

    // check if both position and orientation are present in the input
    if (position.empty() || (orientation != 'V' && orientation != 'H')) {
      std::cout << std::endl << "Error: Invalid input" << std::endl;
      continue;
    }

    board.plotShip(position, boat, isVertical);
  }
}

// function to setup the game boards and ships
void setupBoards(Board &playerBoard, Board &computerBoard,
                 std::vector<Boat> &playerShips,
                 std::vector<Boat> &computerShips) {
  // initialize the ships
  importBoatConfigData("adaship_config.ini", playerShips);
  computerShips =
      playerShips; // copy the player's ships for the computer's board

  plotPlayerShips(playerShips, playerBoard);
  computerBoard.autoPlotShips(computerShips);
}

// function to play a game of battleships
void playGame(Board &playerBoard, Board &computerBoard,
              std::vector<Boat> &playerShips,
              std::vector<Boat> &computerShips) {
  int playerHits = 0,
      computerHits = 0; // number of hits scored by each player

  // loop until one of the players sinks all of the other player's ships
  while (playerHits < 17 && computerHits < 17) {
    // display the player's board
    std::cout << std::endl << "Your board:" << std::endl;
    playerBoard.printBoard();

    // prompt the player to enter a shot
    std::cout << "Enter a shot: ";
    std::string position;
    std::getline(std::cin, position);

    // parse the position string
    std::stringstream stream(
        position); // create a stringstream from the position string
    char column;
    int row;
    if (!(stream >> column >> row)) {
      std::cout << "Invalid position" << std::endl;
      continue;
    }
    row--; // adjust for zero-based indexing
    int x =
        column - 'A'; // convert column to integer (assuming uppercase input)
    int y = row;
    // fire shot and check if it was a hit
    bool isHit = computerBoard.fireShot(x, y);
    if (isHit) {
      std::cout << "Hit!" << std::endl;
      playerHits++;
    } else {
      std::cout << "Miss." << std::endl;
    }

    // check if the player has won
    if (playerHits == 17) {
      std::cout << "You won!" << std::endl;
      break;
    }

    // have the computer take a shot
    std::pair<int, int> randomPosition = playerBoard.generateRandomPosition(
        100, false); // generate a random position for the shot
    if (randomPosition.first == -1) {
      continue;
    }
    x = randomPosition.first;
    y = randomPosition.second;

    // fire shot and check if it was a hit
    isHit = playerBoard.fireShot(x, y);
    if (isHit) {
      std::cout << "Computer hit your ship at position "
                << static_cast<char>('A' + x) << y + 1 << "!" << std::endl;
      computerHits++;
    } else {
      std::cout << std::endl
                << "Computer missed at position " << static_cast<char>('A' + x)
                << y + 1 << "." << std::endl;
    }

    // check if the computer has won
    if (computerHits == 17) {
      std::cout << "Computer won." << std::endl;
      break;
    }
  }
}

int main() {
  // initialize the boards and ships
  importBoardConfigData("adaship_config.ini", Board::boardHeight,
                        Board::boardWidth);
  Board playerBoard, computerBoard;
  std::vector<Boat> playerShips, computerShips;
  setupBoards(playerBoard, computerBoard, playerShips, computerShips);

  // play the game
  playGame(playerBoard, computerBoard, playerShips, computerShips);

  return 0;
}