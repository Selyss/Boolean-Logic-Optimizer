#ifndef CANONICAL_HPP
#define CANONICAL_HPP

#include <vector>

#include <truth_table.hpp>

std::vector<int> minterm_indices(const TruthTable& tt);
std::vector<int> maxterm_indices(const TruthTable& tt);

TruthTable reconstruct_from_minterms(int n, const std::vector<int>& mins);
TruthTable reconstruct_from_maxterms(int n, const std::vector<int>& maxs);

#endif // CANONICAL_HPP
