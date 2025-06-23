#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#include "display.h"

template<class T>
struct Node {
    T value;
    Node<T>* left;
    Node<T>* right;
    explicit Node(T value) : value(value), left(nullptr), right(nullptr) {}
};

template<class T>
void _inorder_to_string(Node<T>* const& node, string const& prefix, vector<string>& lines) {
    if (node == nullptr) {
        return;
    }
    
    // Because this will print out top-to-bottom
    //  and we will be reading it out sideways
    //  we print right before left
    //  so the sideways text will read left-to-right
    
    // Print right
    _inorder_to_string(node->left, prefix + "  ", lines);
    
    // Print node
    stringstream ss;
    ss << prefix << node->value;
    lines.push_back(ss.str());
    
    // Print left
    _inorder_to_string(node->right, prefix + "  ", lines);
}


template<class T>
string inorder_to_string(Node<T>* const& node) {
    vector<string> lines;
    _inorder_to_string(node, "", lines);
    // for (auto l: lines){
    //     cout << l << endl;
    // }
    
    
    // Transpose!
    int max_len = 0;
    for (auto line : lines) {
        max_len = (max_len < line.length()) ? line.length() : max_len;
    }
    
    char** out = new char*[max_len];
    for (int i = 0; i < max_len; i++) {
        out[i] = new char[lines.size()];
    }
    
    stringstream ss;
    for (int i = 0; i < max_len; i++) {
        for (int j = 0; j < lines.size(); j++) {
            if (i < lines[j].length()) {
                ss << lines[j][i];
            } else {
                ss << ' ';
            }
        }
        ss << endl;
    }
    
    return ss.str();
}

template<class T>
void print_inorder(Node<T>* const& node) {
    cout << inorder_to_string(node) << endl;
}

template<class T>
bool add(Node<T>*& node, T item) {
    if (node == nullptr) {
        node = new Node<T>(item);
        return true;
    }
    if (node->value == item) {
        return false;
    }
    if (item < node->value) {
        return add(node->left, item);
    } else {
        return add(node->right, item);
    }
}

template<class T>
Node<T>* get_inorder_predecessor(Node<T>* const& node) {
    // Pass in the node, not the left child
    Node<T>* iop = node->left;
    while (iop->right != nullptr) {
        iop = iop->right;
    }
    return iop;

}


template<class T>
bool remove(Node<T>*& node, T value) {
    if (node == nullptr) {
//        cout << "value not found" << endl;
        return false;
    }
    if (node->value == value) {
        if (node->left == nullptr) {
            auto tmp = node;
            node = node->right;
            delete tmp;
        } else if (node->right == nullptr) {
            auto tmp = node;
            node = node->left;
            delete tmp;
        } else {
            auto iop = get_inorder_predecessor(node);
            node->value = iop->value;
            remove(node->left, iop->value);
        }
        return true;
    } else if (value < node->value) {
        return remove(node->left, value);
    } else {
        return remove(node->right, value);
    }

}

template<class T>
void clear(Node<T>*& node){
}

int main(){
    Node<string>* M = new Node<string>("M");

    M->left = new Node<string>("G");
    M->left->left = new Node<string>("A");
    M->left->right = new Node<string>("J");

    M->right = new Node<string>("T");
    M->right->left = new Node<string>("Q");    
    M->right->right = new Node<string>("V");

    print_inorder(M);

    cout << boolalpha << "BST add()\n";
    PRINT(add(M, (string)"Z"));
    PRINT(add(M, (string)"Z"));
    PRINT(add(M, (string)"a"));
    add(M,(string)"H");
    print_inorder(M);


    cout << "Inorder Predecessor\n";
    auto node = get_inorder_predecessor(M);
    cout << node->value << endl;

    cout << "Remove a node\n";
    PRINT(remove(M,(string)"M"));
    PRINT(remove(M,(string)"S"));
    remove(M,(string)"T");
    print_inorder(M);

    return 0;
}