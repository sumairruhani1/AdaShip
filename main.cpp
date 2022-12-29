#include "./include/index.hpp"

class Boat {
 public:
  int length;
  std::string name;
  bool isPlaced;

  Boat(int length, const std::string& name, bool isPlaced)
      : length(length), name(name), isPlaced(isPlaced) {}
};

void importBoatConfigData(std::string filename, std::vector<Boat>& boats) {
  // file handling for adaship_config.ini file
  std::ifstream file;
  file.open(filename); // open file
  std::string line;
  if (file) {
    while (std::getline(file, line)) {
      line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

      if (line.find("Boat") != -1) {
        int startPointer = line.find(":") + 1;           // Initial pointer
        int endPointer = line.find(",") + 1; // Secondary pointer
        int diff = endPointer - startPointer;            // string difference
        std::string name = line.substr(startPointer, diff - 1);
        int length = std::stoi(line.substr(endPointer));
        boats.emplace_back(length, name, false);
      }
    }
  }
  else {
    std::cout << "Could not find or open adaship_config.ini" << std::endl;
  }
};



class Board {
 public:
  static int boardHeight; // height of the game board
  static int boardWidth; // width of the game board


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
      if (gameBoard[i][x].isShip) {  // check if the cell is already occupied by a ship
        return false;
      }
    }
  } else {
    for (int i = x; i < x + length; i++) {
      if (gameBoard[y][i].isShip) {  // check if the cell is already occupied by a ship
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
  void plotShip(const std::string& position, int length, bool isVertical) {
    // parse the position string
    std::stringstream stream(position);  // create a stringstream from the position string
    char col;
    int row;
    stream >> col >> row;  // read the column and row from the stringstream
    int x, y;
    if (isalpha(col)) {
      x = col - 'A';
      y = row - 1;
    } else {
      x = row - 1;
      stream >> col;  // read the column character from the stringstream
      y = col - 'A';
    }
  
    // check if the ship can be placed at the given position and orientation
    if (canPlaceShip(x, y, length, isVertical)) {
      placeShip(x, y, length, isVertical);
    } else {
      std::cout << std::endl << "Error: Cannot place ship at position " << position
                << " in the given orientation" << std::endl << std::endl;
    }
  }

  // plot some ships on the game table
  void plotShips() {
    while (true) {
      std::string position;
      int length;
      bool isVertical;
      printBoard();
    
      // read the position, length, and orientation of the ship
      std::cout << std::endl << "Enter position, length, and orientation for ship (e.g. A1 2 V): ";
      std::cin >> position >> length >> std::ws;  // read the position and length, and skip any leading whitespace
      if (position.empty()) {  // check if the position string is empty
        return;  // exit the function
      }
      if (std::cin.fail()) {  // check if there was an error reading the input
        std::cin.clear();  // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore the rest of the line
        continue;  // go back to the beginning of the loop
      }
      char orientation;
      std::cin >> orientation;  // read the orientation character
      if (std::cin.fail()) {  // check if there was an error reading the input
        std::cin.clear();  // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore the rest of the line
        continue;  // go back to the beginning of the loop
      }
      while (orientation != 'V' && orientation != 'v' && orientation != 'H' && orientation != 'h') {  // validate the orientation input
        std::cout << "Error: Invalid orientation. Please enter either V or H: ";
        std::cin >> orientation;
      }
      isVertical = (orientation == 'V' || orientation == 'v');
      plotShip(position, length, isVertical);
    }
  }

    // print the game board
  void printBoard() {
    // print the alphabet along the top row
    std::cout << std::endl << "   ";  // add an extra space to align the letters with the board cells
    for (int i = 0; i < boardWidth; i++) {
      std::cout << std::setw(2) << static_cast<char>('A' + i) << " ";  // use setw to align the letters
    }
    std::cout << std::endl;

    // print the numbers along the left column and the contents of the board cells
    for (int i = 0; i < boardHeight; i++) {
      std::cout << std::setw(2) << i + 1 << "  ";  // use setw to align the numbers and add an extra space to align with the board cells
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

int Board::boardHeight;  // initialize the boardHeight and boardWidth variables
int Board::boardWidth;


void importBoardConfigData(std::string filename) {
  // file handling for adaship_config.ini file
  std::ifstream file;
  file.open(filename); // open file
  std::string line;
  if (file) {
    while (std::getline(file, line)) {
      line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

      if (line.find("Board") != -1) {
        int startPointer = line.find(":") + 1;           // Initial pointer
        int endPointer = line.find("x") + 1; // Secondary pointer
        int diff = endPointer - startPointer;            // string difference
        std::string height = line.substr(startPointer, diff - 1);
        std::string width = line.substr(endPointer);
        std::cout << "Board Height is " << height << " and width is " << width
                  << std::endl;
        Board::boardHeight = atoi(height.c_str());
        Board::boardWidth = atoi(width.c_str());
      }
    }
  }
  else {
    std::cout << "Could not find or open adaship_config.ini" << std::endl;
  }
};

void tutorialInstructions() {
  std::cout << "Welcome to AdaShip!" << std::endl <<std::endl;
  std::cout 
    << "AdaShip is a spinoff version of the classic battleships game and the rules are simple. \n"
    << "Firstly, you and your opponent will tactically place ships on your boards. Following this you \n"
    << "take turns firing torpedoes at your opponents ships with the intent of hitting all of theirs, \n"
    << "while not getting hit yourself. \n\n"
    << "If you destroy all your opponents ships before they can destroy yours then you have won." << std::endl << std::endl;
}

void menuOptions() {
  int option;
  std::cout << "Menu:" << std::endl;
  std::cout << "1. One Player vs Computer" << std::endl;
  std::cout << "2. Quit Game" << std::endl << std::endl;
  std::cout << "Enter option: ";
  std::cin >> option;

  if (option == 1) {
    importBoardConfigData("adaship_config.ini");
    Board board;
    board.plotShips();
    board.printBoard();
  } else if (option == 2) {
    std::exit;
  } else {
    std::cout << ("You haven't entered a valid option");
  }
}

int main() {
  tutorialInstructions();
  menuOptions();
  return 0;
}
