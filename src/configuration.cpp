// #include "../include/index.hpp"
// #include "Boat.hpp"

// // import board data from config file
// void importBoardConfigData(std::string filename, int &height, int &width) {
//   // file handling for adaship_config.ini file
//   std::ifstream file;
//   file.open(filename); // open file
//   std::string line;
//   if (file) {
//     while (std::getline(file, line)) {
//       line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

//       if (line.find("Board") != -1) {
//         int startPointer = line.find(":") + 1; // Initial pointer
//         int endPointer = line.find("x") + 1;   // Secondary pointer
//         int diff = endPointer - startPointer;  // string difference
//         std::string heightStr = line.substr(startPointer, diff - 1);
//         std::string widthStr = line.substr(endPointer);
//         height = std::stoi(heightStr);
//         width = std::stoi(widthStr);
//       }
//     }
//   } else {
//     std::cout << "Could not find or open adaship_config.ini" << std::endl;
//   }
// };

// // import boat data from config file
// void importBoatConfigData(const std::string &filename,
//                           std::vector<Boat> &boats) {
//   // file handling for adaship_config.ini file
//   std::ifstream file;
//   file.open(filename); // open file
//   std::string line;
//   if (file) {
//     while (std::getline(file, line)) {
//       line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

//       if (line.find("Boat") != -1) {
//         int startPointer = line.find(":") + 1; // Initial pointer
//         int endPointer = line.find(",") + 1;   // Secondary pointer
//         int diff = endPointer - startPointer;  // string difference
//         std::string name = line.substr(startPointer, diff - 1);
//         int length = std::stoi(line.substr(endPointer));
//         boats.emplace_back(length, name, false);
//       }
//     }
//   } else {
//     std::cout << "Could not find or open adaship_config.ini" << std::endl;
//   }
// }