#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> readFileToArray(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> lines;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return lines; // Return empty vector if file cannot be opened
    }

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

    return lines;
}
