#include "../include/index.hpp"

void importConfigData(std::string filename, std::string stringDelimiter) {
  // file handling for adaship_config.ini file, storing details
  std::ifstream file;
  file.open(filename); // open file
  std::string line;

  // if (stringDelimiter != "x" || stringDelimiter != ",") {
  //   std::cout << "Error: An invalid value was passed as the string "
  //                "delimiter. The delimiter needs to be either an x or , to "
  //                "parse adaship_config.ini correctly. "
  //             << std::endl;
  // }

  // loop through file lines if file is opened successfuly
  if (file) {
    while (std::getline(file, line)) {
      line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

      if (line.find("Board") != -1 && stringDelimiter == "x") {
        int startPointer = line.find(":") + 1;           // Initial pointer
        int endPointer = line.find(stringDelimiter) + 1; // Secondary pointer
        int diff = endPointer - startPointer;            // string difference
        std::string height = line.substr(startPointer, diff - 1);
        std::string width = line.substr(endPointer);
        std::cout << "Board Height is " << height << " and width is " << width
                  << std::endl;
      }
      if (line.find("Boat") != -1 && stringDelimiter == ",") {
        int startPointer = line.find(":") + 1;           // Initial pointer
        int endPointer = line.find(stringDelimiter) + 1; // Secondary pointer
        int diff = endPointer - startPointer;            // string difference
        std::string boatType = line.substr(startPointer, diff - 1);
        std::string boatName = line.substr(endPointer);
        std::cout << boatType << " Health: " << boatName << std::endl;
      }
    }
  } else {
    std::cout << "Could not find or open adaship_config.ini" << std::endl;
  }
};
