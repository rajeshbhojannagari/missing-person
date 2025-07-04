#ifndef BST_H
#define BST_H
#include <iostream>
#include <fstream>
#include "person.h"
struct TreeNode {
    Person person;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const Person& p) : person(p), left(nullptr), right(nullptr) {}
};
class BST {
private:
    TreeNode* root;
    void insert(TreeNode*& node, const Person& p) {
        if (!node)
            node = new TreeNode(p);
        else if (p.age < node->person.age)
            insert(node->left, p);
        else
            insert(node->right, p);
    }
    void inorder(TreeNode* node, std::ofstream& out) {
        if (!node) return;
        inorder(node->left, out);
        out << node->person.name << " (" << node->person.age << ") - " 
            << node->person.location << "\n";
        inorder(node->right, out);
    }
public:
    BST() : root(nullptr) {}
    void insert(const Person& p) {
        insert(root, p);
    }
    void writeInOrder(std::ofstream& out) {
        inorder(root, out);
    }
};
#endif