#pragma once
#include <functional>

template<class T>
class AVL {
public:
    struct Node {
        Node *left;
        Node *right;
        size_t height;
        T value;

        Node(T v): left(nullptr), right(nullptr), height(0), value(v) {
        }
    };

    AVL() {
        m_root = nullptr;
        m_size = 0;
    }

    ~AVL() {
        clear();
    }

    bool insert(T item) {
        return m_insert(m_root, item);
    }

    bool remove(T item) {
        return m_remove(m_root, item);
    }

    bool contains(T item) const {
        return m_contains(m_root, item);
    }

    void clear() {
        return m_clear(m_root);
    }

    int size() const {
        return m_size;
    }

    void inorder_traversal(std::function<void(T)> visit) const {
        return m_inorder(m_root, visit);
    }

    void preorder_traversal(std::function<void(T)> visit) const {
        return m_preorder(m_root, visit);
    }

    void postorder_traversal(std::function<void(T)> visit) const {
        return m_postorder(m_root, visit);
    }

private:
    Node *m_root;
    int m_size;

    void updateHeight(Node *&node) {
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
        int left_h = 0;
        int right_h = 0;
        if (node == nullptr) {
            return;
        }
        if (node->left != nullptr) {
            updateHeight(node->left);
            left_h = node->left->height;
        }
        if (node->right != nullptr) {
            updateHeight(node->right);
            right_h = node->right->height;
        }
        int difference = right_h - left_h;

        left_value = left_h;
        right_value = right_h;
        balance = difference;
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
        } else if (balance < -1) {
            get_children_data(root->left, c_left_h, c_right_h, c_balance);

            if (c_balance > 0) {
                promote_right(root->left);
            }
            promote_left(root);
        }

        updateHeight(root);
    }

    void promote_left(Node *&root) {
        Node *temp = root->left;
        root->left = temp->right;
        temp->right = root;
        updateHeight(root);
        updateHeight(temp);
        root = temp;
    }

    void promote_right(Node *&root) {
        Node *temp = root->right;
        root->right = temp->left;
        temp->left = root;
        updateHeight(root);
        updateHeight(temp);
        root = temp;
    }

    bool m_insert(Node * &node, T item) {
        if (node == nullptr) {
            node = new Node(item);
            m_size++;
            return true;
        }
        if (node->value == item) {
            return false;
        }
        bool result = m_insert(item < node->value ? node->left : node->right, item);
        rebalance(node);
        return result;
    }

    Node *m_get_iop(Node *const&node) {
        Node *iop = node->left;
        while (iop->right != nullptr) {
            iop = iop->right;
        }
        return iop;
    }

    bool m_remove(Node *&node, T item) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == item) {
            if (node->left == nullptr) {
                Node *tmp = node;
                node = node->right;
                m_size--;
                delete tmp;
            } else if (node->right == nullptr) {
                Node *tmp = node;
                node = node->left;
                m_size--;
                delete tmp;
            } else {
                Node *iop = m_get_iop(node);
                node->value = iop->value;
                m_remove(node->left, iop->value);
            }
            rebalance(node);
            return true;
        }
        bool result = m_remove(item < node->value ? node->left : node->right, item);
        rebalance(node);
        return result;
    }

    bool m_contains(const Node *node, T value) const {
        if (node == nullptr) {
            return false;
        } else if (value < node->value) {
            return m_contains(node->left, value);
        } else if (value > node->value) {
            return m_contains(node->right, value);
        }
        return true;
    }

    void m_inorder(Node *node, std::function<void(T)> visit) const {
        if (node == nullptr) {
            return;
        }
        m_inorder(node->left, visit);
        visit(node->value);
        m_inorder(node->right, visit);
    }

    void m_preorder(Node *node, std::function<void(T)> visit) const {
        if (node == nullptr) {
            return;
        }
        visit(node->value);
        m_preorder(node->left, visit);
        m_preorder(node->right, visit);
    }

    void m_postorder(Node *node, std::function<void(T)> visit) const {
        if (node == nullptr) {
            return;
        }
        m_postorder(node->left, visit);
        m_postorder(node->right, visit);
        visit(node->value);
    }

    void m_clear(Node *&node) {
        if (node == nullptr) {
            return;
        }
        m_clear(node->left);
        m_clear(node->right);
        delete node;
        node = nullptr;
        m_size = 0;
    }
};