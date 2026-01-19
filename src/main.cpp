#include <iostream>
#include <truth_table.hpp>

int main() {
    TruthTable t = TruthTable();
    t.load("input/xor2.txt");
    t.print();
}
