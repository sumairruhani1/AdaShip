#include "./include/index.hpp"

// Boat class
class Boat {
public:
  int length;
  std::string name;
  bool isPlaced;

  Boat(int length, const std::string &name, bool isPlaced)
      : length(length), name(name), isPlaced(isPlaced) {}
};

// Board class
class Board {
public:
  static int boardHeight; // height of the game board
  static int boardWidth;  // width of the game board

  // represent a cell on the game board
  class Cell {
  public:
    Cell() : isShip(false) {}
    bool isShip; // whether there is a ship at this cell
  };

  // initialize the game board
  Board() {
    gameBoard.resize(boardHeight);
    for (int i = 0; i < boardHeight; i++) {
      gameBoard[i].resize(boardWidth);
      for (int j = 0; j < boardWidth; j++) {
        gameBoard[i][j].isShip = false;
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
    row--;                // adjust for zero-based indexing
    int x = column - 'A'; // convert column to integer
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

private:
  std::vector<std::vector<Cell>> gameBoard;
};

int Board::boardHeight = 10; // initialize the board height
int Board::boardWidth = 10;  // initialize the board width

// import boat configuration data from a file
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

int main() {
  std::vector<Boat> boats;
  importBoatConfigData("adaship_config.ini", boats);

  Board board;

  // list the boats and allow the user to select a boat to place on the board
  int n = 0; // counter of the number of boats that have been placed
  while (!boats.empty()) {
    board.printBoard();
    int index = 0;
    std::cout << std::endl << "Available boats:" << std::endl << std::endl;
    for (const Boat &boat : boats) {
      if (!boat.isPlaced) {
        std::cout << ++index << ". " << boat.name << " [Length: " << boat.length
                  << "]" << std::endl;
      }
    }

    std::cout << std::endl << "Enter the number of the boat to place: ";
    int number;
    if (!(std::cin >> number)) {
      std::cout << std::endl
                << std::endl
                << "Error: Please enter a valid boat number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    if (position.empty() || (orientation != 'V' && orientation != 'v' &&
                             orientation != 'H' && orientation != 'h')) {
      std::cout << std::endl << "Error: Invalid input" << std::endl;
      continue;
    }

    board.plotShip(position, boat, isVertical);
  }

  return 0;
}