#include <iostream>
#include <string>
#include <utility>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    bool isThreaded;

    Node(int key) : data(key), left(nullptr), right(nullptr), isThreaded(false) {}
};

Node* newNode(int key) {
    return new Node(key);
}

Node *leftMostNode(Node* root) {
    Node* node = root;
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

void populateNext(Node* curr, Node* &prev) {
    if (curr == nullptr) {
        return;
    }

    populateNext(curr->left, prev);

    if (prev && !prev->right) {
        prev->right = curr; // Update the 'right' pointer to make it threaded
        prev->isThreaded = true;
    }
    
    prev = curr;

    populateNext(curr->right, prev);
}

void convertToThreaded(Node* root) {
    Node* prev = nullptr;
    populateNext(root, prev);
}

void traverse(Node* root) {
    Node* curr = leftMostNode(root);
    while (curr) {
        cout << curr->data << " ";

        if (curr->isThreaded) {
            curr = curr->right;
        } else {
            curr = leftMostNode(curr->right);
        }
    }
}

int main() {
    /* Construct the following tree
       5
      / \
     /   \
    2     7
   / \   / \
  1   4 6   9
       \     \
        3     10
    */
    Node* root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(7); 
    root->left->left = newNode(1); 
    root->left->right = newNode(4); 
    root->right->left = newNode(6); 
    root->right->right = newNode(9); 
    root->left->right->right = newNode(3); 
    root->right->right->right = newNode(10); 

    convertToThreaded(root); 
    traverse(root);

    return 0;
}
