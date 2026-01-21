#include <truth_table.hpp>
#include <fstream>
#include <iostream>
#include <stdexcept>

TruthTable::TruthTable() : n(0), f() {};

TruthTable::TruthTable(int n_value, const std::vector<uint8_t>& f_values) : n(n_value), f(f_values) {
    int rows = 1 << n;
    if (n < 1 || n > 6) {
        throw std::runtime_error("Number of inputs n must be between 1 and 6.");
    }
    if (static_cast<int>(f.size()) != rows) {
        throw std::runtime_error("Truth table size does not match 2^n.");
    }
}

void TruthTable::load(const std::string& filename) {
    // open file
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    // read n
    infile >> n;
    if (n < 1 || n > 6) {
        throw std::runtime_error("Number of inputs n must be between 1 and 6.");
    }
    int rows = 1 << n; // 2^n

    f.clear();
    f.reserve(rows);

    std::string line;
    infile.ignore(); // get rid of the newline after n

    int count = 0;
    while (std::getline(infile, line) && count < rows) {
        if (line.empty()) continue;

        if (line.length() != 1 || (line[0] != '0' && line[0] != '1')) {
            throw std::runtime_error("Invalid output value at row: " + std::to_string(count));
        }
        f.push_back(line[0] - '0');
        count++;
    }

    if (count != rows) {
        throw std::runtime_error("Expected " + std::to_string(rows) + " values, got " + std::to_string(count));
    }
    infile.close();
}

void TruthTable::print() const {
    std::cout << "n = " << n << std::endl;
    std::cout << "rows = " << getRows() << std::endl;
    std::cout << "f = ";
    for (size_t i = 0; i < f.size(); i++) {
        if (i > 0) std::cout << " ";
        std::cout << (int)f[i];
    }
    std::cout << std::endl;
}
