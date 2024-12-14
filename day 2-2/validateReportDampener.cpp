#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath> // For std::abs
#include <iterator>

// Function to determine if a report is safe
bool isSafe(const std::vector<int>& levels) {
    if (levels.size() < 2) {
        return false; // At least two levels are needed to determine safety.
    }

    int firstDiff = levels[1] - levels[0];
    if (std::abs(firstDiff) < 0 || std::abs(firstDiff) > 3) {
        return false; // First difference out of bounds.
    }

    bool isIncreasing = (firstDiff > 0);

    // Validate all subsequent differences
    for (size_t i = 1; i < levels.size(); i++) {
        int diff = levels[i] - levels[i - 1];

        // Check if difference is within bounds
        if (std::abs(diff) < 1 || std::abs(diff) > 3) {
            return false;
        }

        // Check if the trend remains consistent
        if ((isIncreasing && diff < 0) || (!isIncreasing && diff > 0)) {
            return false;
        }
    }

    return true;
}

std::vector<int> damperList(const std::vector<int>& levels, int post) {
    // Crie uma cópia de 'levels' para permitir a modificação
    std::vector<int> out = levels;

    // Certifique-se de que o índice 'post' está dentro do intervalo válido
    if (post >= 0 && post < static_cast<int>(out.size())) {
        // Remova o elemento na posição 'post'
        out.erase(out.begin() + post);
    }

    return out;
}


bool levelSafeDampener (const std::vector<int>& levels){
    if( isSafe(levels)){
        return true;
    }
    else{
        std::vector<int> dumper = levels;
        for(size_t i = 0; i < levels.size(); i++){
            dumper = damperList(levels, i);
            std::cout << '\n';
            for (int i: dumper){
                std::cout << i << ',';
            }
            if(isSafe(dumper)){
                return true;
            }
        }
        return false;
    }
    }

int main() {
    int safeReports = 0;
    std::ifstream inputFile("input.txt");
    std::string line;

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file!" << std::endl;
        return 1;
    }

    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::vector<int> levels;
        int level;

        // Read levels from the line
        while (ss >> level) {
            levels.push_back(level);
        }

        // Check if the report is safe
        if (levelSafeDampener(levels)) {
            safeReports++;
        }
    }

    inputFile.close();

    // Output the result
    std::cout << "Number of safe reports: " << safeReports << std::endl;
    return 0;
}
