#include "BST.h"
#include <algorithm>
#include <iostream>

Node::Node(int v) {
    value = v;
    left = nullptr;
    right = nullptr;
    height = 0;
}

BST::BST(int v) : root(new Node(v)) {
    ++size;
}

void BST::Insert(Node *n, int v) {
    if (n->value < v) {
        if (n->right != nullptr) {
            Insert(n->right, v);
        } else {
            Node *n_new = new Node(v);
            n->right = n_new;
            ++size;
        }
    } else if (n->value > v) {
        if (n->left != nullptr) {
            Insert(n->left, v);
        } else {
            Node *n_new = new Node(v);
            n->left = n_new;
            ++size;
        }
    }
}

int BST::GetHeight(Node *n) {
    if (n != nullptr) {
        return std::max(GetHeight(n->left), GetHeight(n->right)) + 1;
    }
    return 0;
}

void BST::GetMax(Node *n, int oldmax, int &answer) {
    if (n->value != oldmax) {
        answer = std::max(n->value, answer);
    }
    if (n->right != nullptr) {
        GetMax(n->right, oldmax, answer);
    }
    if (n->left != nullptr) {
        GetMax(n->left, oldmax, answer);
    }
}

std::vector<int> BST::GetObhod(Node *n) {
    if (size == obhod.size())
        return obhod;
    obhod.clear();
    Tour(n);
    return obhod;
}

void BST::Tour(Node *n) {
    obhod.push_back(n->value);
    if (n->right != nullptr) {
        Tour(n->right);
    }
    if (n->left != nullptr) {
        Tour(n->left);
    }
}

Node *BST::GetRoot() {
    return root;
}

void BST::PrintLeaves(Node *n) {
    if (n->right == nullptr and n->left == nullptr) {
        std::cout << n->value << " ";
    } else {
        if (n->right != nullptr) {
            PrintLeaves(n->right);
        }
        if (n->left != nullptr) {
            PrintLeaves(n->left);
        }
    }
}

void BST::PrintForks(Node *n) {
    if (n->right != nullptr and n->left != nullptr) {
        std::cout << n->value << " ";
    }
    if (n->right != nullptr) {
        PrintForks(n->right);
    }
    if (n->left != nullptr) {
        PrintForks(n->left);
    }
}

void BST::PrintBranches(Node *n) {
    if ((n->right != nullptr and n->left == nullptr) or (n->right == nullptr and n->left != nullptr)) {
        std::cout << n->value << " ";
    }
    if (n->right != nullptr) {
        PrintBranches(n->right);
    }
    if (n->left != nullptr) {
        PrintBranches(n->left);
    }
}

bool BST::Is_AVL_Balanced(Node *n) {
    int r, l;
    if (n->right == nullptr) {
        r = 0;
    } else {
        r = GetHeight(n->right);
    }
    if (n->left == nullptr) {
        l = 0;
    } else {
        l = GetHeight(n->left);
    }
    if (std::abs(r - l) > 1) {
        return false;
    } else {
        bool status = true;
        if (n->right != nullptr) {
            status = std::min(status, Is_AVL_Balanced(n->right));
        }
        if (n->left != nullptr) {
            status = std::min(status, Is_AVL_Balanced(n->left));
        }
        return status;
    }
}
