#pragma once
#include <vector>
#include <string>

std::vector<std::vector<double>> read_csv(const std::string& filename);
void test_csv_reader();