#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "main.h"

void writeStringToLine(const std::string& filename, const std::string& str, int lineNumber) {
    std::ifstream inputFile(filename);
    std::ofstream outputFile("temp.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }

    std::string line;
    int currentLineNumber = 1;

    // Read each line from the input file
    while (currentLineNumber <= lineNumber) {
        if (currentLineNumber == lineNumber) {
            // If this is the line where you want to write the string, write it
            outputFile << str << std::endl;
        } else if (std::getline(inputFile, line)) {
            // If it's not the line you want to modify, write the original line
            outputFile << line << std::endl;
        } else {
            // If we reached the end of the file and there are not enough lines, add blank lines
            while (currentLineNumber < lineNumber) {
                outputFile << std::endl;
                currentLineNumber++;
            }
            // Write the string to the specified line
            outputFile << str << std::endl;
            break;
        }
        currentLineNumber++;
    }

    // Write the rest of the lines if any
    while (std::getline(inputFile, line)) {
        outputFile << line << std::endl;
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    // Rename the temp file to the original file
    std::remove(filename.c_str());
    std::rename("temp.txt", filename.c_str());
}
