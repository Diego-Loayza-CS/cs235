#pragma once

struct Node {
    Node *left;
    Node *right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {
    }
};

void update_height(Node *&node) {
    if (node == nullptr) {
        return;
    }
    if (node->left == nullptr && node->right == nullptr) {
        node->height = 1;
    } else if (node->left == nullptr) {
        node->height = 1 + node->right->height;
    } else if (node->right == nullptr) {
        node->height = 1 + node->left->height;
    } else {
        if (node->left->height > node->right->height) {
            node->height = 1 + node->left->height;
        } else {
            node->height = 1 + node->right->height;
        }
    }
}

void get_children_data(Node *&node, int &left_value, int &right_value, int &balance) {
    int left_height = 0;
    int right_height = 0;
    if (node->left != nullptr) {
        update_height(node->left);
        left_height = node->left->height;
    }
    if (node->right != nullptr) {
        update_height(node->right);
        right_height = node->right->height;
    }
    int difference = right_height - left_height;

    left_value = left_height;
    right_value = right_height;
    balance = difference;
}

void promote_left(Node *&root) {
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;

    update_height(root);
    update_height(temp);

    root = temp;
}

void promote_right(Node *&root) {
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;

    update_height(root);
    update_height(temp);

    root = temp;
}

void rebalance(Node *&root) {
    int left_h = 0;
    int right_h = 0;
    int balance = 0;
    get_children_data(root, left_h, right_h, balance);

    int c_left_h = 0;
    int c_right_h = 0;
    int c_balance = 0;

    if (balance > 1) {
        get_children_data(root->right, c_left_h, c_right_h, c_balance);

        if (c_balance < 0) {
            promote_left(root->right);
        }
        promote_right(root);
    }

    else if (balance < -1) {
        get_children_data(root->left, c_left_h, c_right_h, c_balance);

        if (c_balance > 0) {
            promote_right(root->left);
        }
        promote_left(root);
    }

    update_height(root);
}