#include <vector>

struct Node {
    int value, height;
    Node *left, *right, *parent;

    Node(int v);
};

class BST {
public:
    explicit BST(int v);

    void Insert(Node *n, int v);

    void GetMax(Node *n, int oldmax, int &answer);

    void PrintLeaves(Node *n);

    void PrintForks(Node *n);

    void PrintBranches(Node *n);

    int GetHeight(Node *n);

    std::vector<int> GetObhod(Node *n);

    Node *GetRoot();

    bool Is_AVL_Balanced(Node *n);

private:
    void Tour(Node *n);

private:
    size_t size = 0;
    std::vector<int> obhod;
    Node *root = nullptr;
};


