#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// BST'ye ekleme
Node* insert(Node* root, int key) {
    if(!root) return new Node(key);
    if(key < root->key) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

// BST arama
bool search(Node* root, int key) {
    if(!root) return false;
    if(root->key == key) return true;
    else if(key < root->key) return search(root->left, key);
    else return search(root->right, key);
}