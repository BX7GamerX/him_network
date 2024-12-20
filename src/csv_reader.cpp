#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<std::vector<double>> read_csv(const std::string& filename) {
    std::vector<std::vector<double>> data;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<double> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            // Skip empty cells and the "ai" marker
            if (cell.empty() || cell == "ai") {
                continue;
            }
            // Trim whitespace
            cell.erase(0, cell.find_first_not_of(" "));
            cell.erase(cell.find_last_not_of(" ") + 1);
            
            try {
                row.push_back(std::stod(cell));
            } catch (const std::exception& e) {
                std::cerr << "Error parsing value: " << cell << std::endl;
                continue;
            }
        }
        
        // Only add rows that have data
        if (!row.empty()) {
            data.push_back(row);
        }
    }

    return data;
}

// Test function
void test_csv_reader() {
    auto data = read_csv("table.csv");
    for (const auto& row : data) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}