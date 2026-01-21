#ifndef TRUTH_TABLE_HPP
#define TRUTH_TABLE_HPP

#include <vector>
#include <string>
#include <cstdint>

class TruthTable {
    private:
        int n; // number of inputs
        std::vector<uint8_t> f; // output values, from 0 to 2^n - 1
    public:
        TruthTable();
        TruthTable(int n, const std::vector<uint8_t>& f_values);
        void load(const std::string& filename);

        int getN() const {return n;}
        int getRows() const { return 1 << n; } // 2^n
        const std::vector<uint8_t>& getF() const { return f; }

        void print() const;
};


#endif // TRUTH_TABLE_HPP
