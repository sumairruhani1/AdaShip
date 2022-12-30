// #include "../include/index.hpp"

// int Board::boardHeight = 10;
// int Board::boardWidth = 10;

// Board::Cell::Cell() : isShip(false), isHit(false) {}

// Board::Board() {
//   gameBoard.resize(boardHeight);
//   for (int i = 0; i < boardHeight; i++) {
//     gameBoard[i].resize(boardWidth);
//     for (int j = 0; j < boardWidth; j++) {
//       gameBoard[i][j].isShip = false;
//       gameBoard[i][j].isHit = false;
//     }
//   }
// }

// bool Board::isValidCell(int x, int y) {
//   return x >= 0 && x < boardWidth && y >= 0 && y < boardHeight;
// }

// bool Board::canPlaceShip(int x, int y, int length, bool isVertical) {
//   // check if the ship is within the bounds of the game board
//   if (isVertical) {
//     if (!isValidCell(x, y) || !isValidCell(x, y + length - 1)) {
//       return false;
//     }
//   } else {
//     if (!isValidCell(x, y) || !isValidCell(x + length - 1, y)) {
//       return false;
//   }

//   // check if there is a ship at any of the cells occupied by the ship
//   if (isVertical) {
//     for (int i = y; i < y + length; i++) {
//       if (gameBoard[i][x].isShip) { // check if the cell is already occupied by a ship
//         return false;
//       }
//     }
//   } else {
//     for (int i = x; i < x + length; i++) {
//       if (gameBoard[y][i].isShip) { // check if the cell is already occupied by a ship
//         return false;
//       }
//     }
//   }
//   return true;
// }

// void Board::placeShip(int x, int y, int length, bool isVertical) {
//   for (int k = 0; k < length; k++) {
//     if (isVertical) {
//       gameBoard[y + k][x].isShip = true;
//     } else {
//       gameBoard[y][x + k].isShip = true;
//     }
//   }
// }

// void Board::plotShip(const std::string &position, Boat &boat, bool isVertical) {
//   // parse the position string
//   std::stringstream stream(position); // create a stringstream from the position string
//   char column;
//   int row;
//   if (!(stream >> column >> row)) {
//     std::cout << "Invalid position" << std::endl;
//     return;
//   }
//   row--; // adjust for zero-based indexing
//   int x = column - 'A'; // convert column to integer (assuming uppercase input)
//   int y = row;
//   int length = boat.length;

//   if (!canPlaceShip(x, y, length, isVertical)) {
//     std::cout << "Cannot place ship at position " << position << std::endl;
//     return;
//   }
//   placeShip(x, y, length, isVertical);
//   boat.isPlaced = true;
// }

// void Board::printBoard() {
//   std::cout << "  "
//   // print column labels
//   for (int i = 0; i < boardWidth; i++) {
//     std::cout << static_cast<char>('A' + i) << " ";
//   }
//   std::cout << std::endl;

//   for (int i = 0; i < boardHeight; i++) {
//     // print row label
//     std::cout << i + 1 << " ";
//     for (int j = 0; j < boardWidth; j++) {
//       if (gameBoard[i][j].isHit) {
//         if (gameBoard[i][j].isShip) {
//           std::cout << "X ";
//         } else {
//           std::cout << "- ";
//         }
//       } else {
//         std::cout << "* ";
//       }
//     }
//     std::cout << std::endl;
//   }
// }

// bool Board::shoot(const std::string &position) {
//   // parse the position string
//   std::stringstream stream(position); // create a stringstream from the position string
//   char column;
//   int row;
//   if (!(stream >> column >> row)) {
//     std::cout << "Invalid position" << std::endl;
//     return false;
//   }
//   row--; // adjust for zero-based indexing
//   int x = column - 'A'; // convert column to integer (assuming uppercase input)
//   int y = row;

//   if (!isValidCell(x, y)) {
//     std::cout << "Invalid position" << std::endl;
//     return false;
//   }

//   if (gameBoard[y][x].isHit) {
//     std::cout << "You have already shot at this position" << std::endl;
//     return false;
//   }

//   gameBoard[y][x].isHit = true;
//   if (gameBoard[y][x].isShip) {
//     std::cout << "Hit!" << std::endl;
//     return true;
//   } else {
//     std::cout << "Miss!" << std::endl;
//     return false;
//   }
// }

// bool Board::allShipsSunk() {
//   for (int i = 0; i < boardHeight; i++) {
//     for (int j = 0; j < boardWidth; j++) {
//       if (gameBoard[i][j].isShip && !gameBoard[i][j].is
//         return false;
//       }
//     return true;
//     }
// }

// void Board::autoPlotShips(std::vector<Boat> &boats) {
//   std::random_device rd;
//   std::mt19937 gen(rd());
//   std::uniform_int_distribution<> disX(0, boardWidth - 1);
//   std::uniform_int_distribution<> disY(0, boardHeight - 1);
//   std::uniform_int_distribution<> disO(0, 1); // 0 for horizontal, 1 for vertical

//   for (Boat &boat : boats) {
//     bool isPlaced = false;
//     while (!isPlaced) {
//       int x = disX(gen);
//       int y = disY(gen);
//       bool isVertical = disO(gen);
//       if (canPlaceShip(x, y, boat.length, isVertical)) {
//         placeShip(x, y, boat.length, isVertical);
//         boat.isPlaced = true;
//         isPlaced = true;
//       }
//     }
//   }
// }

//   Board::Board() {
//   gameBoard.resize(boardHeight);
//   for (int i = 0; i < boardHeight; i++) {
//     gameBoard[i].resize(boardWidth);
//     for (int j = 0; j < boardWidth; j++) {
//       gameBoard[i][j].isShip = false;
//       gameBoard[i][j].isHit = false;
//     }
//   }
// }

