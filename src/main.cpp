#include <canonical.hpp>
#include <truth_table.hpp>

#include <iostream>
#include <sstream>

static std::string join_indices(const std::vector<int>& indices) {
    std::ostringstream out;
    for (size_t i = 0; i < indices.size(); ++i) {
        if (i > 0) {
            out << ",";
        }
        out << indices[i];
    }
    return out.str();
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "usage: logicopt <truth_table_file>" << std::endl;
        return 1;
    }

    TruthTable t;
    t.load(argv[1]);
    t.print();

    std::vector<int> mins = minterm_indices(t);
    std::vector<int> maxs = maxterm_indices(t);

    std::cout << "sop = Σm(" << join_indices(mins) << ")" << std::endl;
    std::cout << "pos = ΠM(" << join_indices(maxs) << ")" << std::endl;

    TruthTable sop_recon = reconstruct_from_minterms(t.getN(), mins);
    TruthTable pos_recon = reconstruct_from_maxterms(t.getN(), maxs);

    bool sop_ok = (sop_recon.getF() == t.getF());
    bool pos_ok = (pos_recon.getF() == t.getF());

    std::cout << "check_sop = " << (sop_ok ? "OK" : "FAIL") << std::endl;
    std::cout << "check_pos = " << (pos_ok ? "OK" : "FAIL") << std::endl;

    if (!sop_ok || !pos_ok) {
        std::cerr << "error: canonical reconstruction failed" << std::endl;
        return 1;
    }

    return 0;
}
