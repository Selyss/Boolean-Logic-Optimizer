#include <canonical.hpp>
#include <stdexcept>

std::vector<int> minterm_indices(const TruthTable& tt) {
    std::vector<int> mins;
    const std::vector<uint8_t>& f = tt.getF();
    mins.reserve(f.size());
    for (size_t i = 0; i < f.size(); ++i) {
        if (f[i] == 1) {
            mins.push_back(static_cast<int>(i));
        }
    }
    return mins;
}

std::vector<int> maxterm_indices(const TruthTable& tt) {
    std::vector<int> maxs;
    const std::vector<uint8_t>& f = tt.getF();
    maxs.reserve(f.size());
    for (size_t i = 0; i < f.size(); ++i) {
        if (f[i] == 0) {
            maxs.push_back(static_cast<int>(i));
        }
    }
    return maxs;
}

TruthTable reconstruct_from_minterms(int n, const std::vector<int>& mins) {
    int rows = 1 << n;
    std::vector<uint8_t> f(rows, 0);
    for (int idx : mins) {
        if (idx < 0 || idx >= rows) {
            throw std::runtime_error("Minterm index out of range.");
        }
        f[static_cast<size_t>(idx)] = 1;
    }
    return TruthTable(n, f);
}

TruthTable reconstruct_from_maxterms(int n, const std::vector<int>& maxs) {
    int rows = 1 << n;
    std::vector<uint8_t> f(rows, 1);
    for (int idx : maxs) {
        if (idx < 0 || idx >= rows) {
            throw std::runtime_error("Maxterm index out of range.");
        }
        f[static_cast<size_t>(idx)] = 0;
    }
    return TruthTable(n, f);
}
