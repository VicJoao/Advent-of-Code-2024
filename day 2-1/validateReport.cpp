#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath> // For std::abs

// Function to determine if a report is safe
bool isSafe(const std::vector<int>& levels) {
    if (levels.size() < 2) {
        return false; // At least two levels are needed to determine safety.
    }

    int firstDiff = levels[1] - levels[0];
    if (std::abs(firstDiff) < 0 || std::abs(firstDiff) > 3) {
        return false; // First difference out of bounds.
    }

    bool isIncreasing = (firstDiff => 0);

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
        if (isSafe(levels)) {
            safeReports++;
        }
    }

    inputFile.close();

    // Output the result
    std::cout << "Number of safe reports: " << safeReports << std::endl;
    return 0;
}
