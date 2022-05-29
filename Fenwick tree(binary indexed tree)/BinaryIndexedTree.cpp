#include "BinaryIndexedTree.h"

void BinaryIndexedTree::InitializeTree(size_t n) {
    tree.assign(n, std::vector<long long>(n, 0));
    size = n;
}

long long BinaryIndexedTree::F(long long x) {
    return (x & (x + 1)) - 1;
}

long long BinaryIndexedTree::GetPrefixSum(long long int x, long long int y) {
    if (x < 0 || y < 0) {
        return 0;
    }
    long long prefix_sum = 0;

    long long i = x;
    while (i >= 0) {
        long long j = y;
        while (j >= 0) {
            prefix_sum += tree[i][j];
            j = F(j);
        }
        i = F(i);
    }

    return prefix_sum;
}

long long BinaryIndexedTree::GetSum(long long x1, long long y1, long long x2, long long y2) {
    return GetPrefixSum(x2, y2) - GetPrefixSum(x1 - 1, y2) - GetPrefixSum(x2, y1 - 1) +
           GetPrefixSum(x1 - 1, y1 - 1);
}

void BinaryIndexedTree::Add(long long x, long long y, long long num) {
    long long i = x;
    while (i < size) {
        long long j = y;
        while (j < size) {
            tree[i][j] += num;
            j |= j + 1;
        }
        i |= i + 1;
    }
}

long long BinaryIndexedTree::GetSum(long long int x, long long int y) {
    return GetPrefixSum(x,y);
}
