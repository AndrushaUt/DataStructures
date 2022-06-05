#include <iostream>
#include <vector>

class SparseTable {
public:
    explicit SparseTable(const std::vector<long long> &vec);

    long long GetMin(long long left, long long right);

    void Print();

private:
    long long Fast_pow(long long num, long long st);

private:
    std::vector<std::vector<long long>> table;
    std::vector<long long> degrees_of_2;
};

