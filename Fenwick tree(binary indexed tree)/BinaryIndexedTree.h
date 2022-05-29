#include <vector>


class BinaryIndexedTree {
public:
    BinaryIndexedTree() = default;

    void InitializeTree(size_t n);
    long long GetSum(long long x1, long long y1, long long x2, long long y2);
    long long GetSum(long long x, long long y);
    void Add(long long x, long long y, long long num);
private:
    long long F(long long x);

    long long GetPrefixSum(long long x, long long y);

private:
    size_t size = 0;
    std::vector<std::vector<long long>> tree;
};
