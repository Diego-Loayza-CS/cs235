#pragma once

#include <functional>

template<class T>
class BST {
public:
    struct Node {
        Node *left;
        Node *right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {
        }
    };

    BST(): m_root(nullptr), m_nodeCount(0) {
    }

    ~BST() {
        clear();
    }

    const Node *getRootNode() const {
        return m_root;
    }

    bool insert(T item) {
        Node *newNode = new Node(item);
        if (m_root == nullptr) {
            m_root = newNode;
            m_nodeCount++;
            return true;
        }
        bool isAdded = m_insert(m_root, newNode);
        if (isAdded) {
            m_nodeCount++;
            return true;
        } else {
            delete newNode;
            return false;
        }
    }

    bool remove(T item) {
        if (m_remove(m_root, item)) {
            m_nodeCount--;
            return true;
        }
        return false;
    }

    bool contains(T item) const {
        return m_contains(m_root, item);
    }

    void clear() {
        m_clear(m_root);
    }

    int size() const {
        return m_nodeCount;
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
    int m_nodeCount;

    bool m_insert(Node *node, Node *newNode) {
        if (newNode->value == node->value) {
            return false;
        }
        if (newNode->value < node->value) {
            if (node->left == nullptr) {
                node->left = newNode;
                return true;
            } else {
                return m_insert(node->left, newNode);
            }
        }
        if (newNode->value > node->value) {
            if (node->right == nullptr) {
                node->right = newNode;
                return true;
            } else {
                return m_insert(node->right, newNode);
            }
        }
    }

    bool m_contains(const Node* node, T value) const {
        if (node == nullptr) {
            return false;
        } else if (value < node->value) {
            return m_contains(node->left, value);
        } else if (value > node->value) {
            return m_contains(node->right, value);
        }
        return true;
    }

    bool m_remove(Node *&node, T value) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            if (node->left == nullptr) {
                Node *tmp = node;
                node = node->right;
                delete tmp;
            } else if (node->right == nullptr) {
                Node *tmp = node;
                node = node->left;
                delete tmp;
            } else {
                auto iop = m_get_iop(node);
                node->value = iop->value;
                m_remove(node->left, iop->value);
            }
            return true;
        } else if (value < node->value) {
            return m_remove(node->left, value);
        } else {
            return m_remove(node->right, value);
        }
    }

    Node* m_get_iop(Node*const& node) {
        Node *iop = node->left;
        while (iop->right != nullptr) {
            iop = iop->right;
        }
        return iop;
    }

    void m_clear(Node *&node) {
        if (node == nullptr) {
            return;
        }
        m_clear(node->left);
        m_clear(node->right);
        delete node;
        node = nullptr;
        m_nodeCount = 0;
    }

    void m_inorder(Node* node, std::function<void(T)> visit) const {
        if (node == nullptr) {
            return;
        }
        m_inorder(node->left, visit);
        visit(node->value);
        m_inorder(node->right, visit);
    }

    void m_preorder(Node* node, std::function<void(T)> visit) const {
        if (node == nullptr) {
            return;
        }
        visit(node->value);
        m_preorder(node->left, visit);
        m_preorder(node->right, visit);
    }

    void m_postorder(Node* node, std::function<void(T)> visit) const {
        if (node == nullptr) {
            return;
        }
        m_postorder(node->left, visit);
        m_postorder(node->right, visit);
        visit(node->value);
    }
};
