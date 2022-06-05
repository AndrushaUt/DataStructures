#include "SparseTable.h"

SparseTable::SparseTable(const std::vector<long long int> &vec) {
    long long i = 0;
    long long degree = 0;
    while (i <= vec.size()) {
        if (Fast_pow(2, degree) == i) {
            degrees_of_2.push_back(degree);
            ++degree;
            ++i;
        } else if (Fast_pow(2, degree) > i) {
            degrees_of_2.push_back(degree - 1);
            ++i;
        } else {
            ++degree;
        }
    }
    table.resize(degrees_of_2[vec.size()] + 1);
    table[0] = vec;
    for (i = 1; i < table.size(); i++) {
        int j = 0;
        while (true) {
            if (j + Fast_pow(2, i - 1) >= table[i - 1].size()) {
                break;
            }
            table[i].push_back(std::min(table[i - 1][j], table[i - 1][j + Fast_pow(2, i - 1)]));
            ++j;
        }
    }
}

long long SparseTable::GetMin(long long int left, long long int right) {
    return std::min(table[degrees_of_2[right - left + 1]][left], table[degrees_of_2[right - left + 1]][right -
                                                                                                       Fast_pow(2,
                                                                                                                degrees_of_2[
                                                                                                                        right -
                                                                                                                        left +
                                                                                                                        1]) +
                                                                                                       1]);
}

void SparseTable::Print() {
    for (auto &i: table) {
        for (long long j: i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

long long SparseTable::Fast_pow(long long int num, long long int st) {
    if (st == 0) {
        return 1;
    }
    if (st % 2 == 0) {
        return Fast_pow(num * num, st / 2);
    }
    return num * Fast_pow(num, st - 1);
}
