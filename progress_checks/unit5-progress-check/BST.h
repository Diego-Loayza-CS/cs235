#pragma once
#include <cstdlib>
#include <functional>


template<typename T>
class BST {
public:
    struct Node {
        Node *left;
        Node *right;
        T value;

        Node(T v): left(nullptr), right(nullptr), value(v) {
        }
    };

    BST(): m_root(nullptr), m_size(0) {
    }

    ~BST() {
        clear();
    }

    bool insert(T const &value) {
        return m_insert(m_root, value);
    }

    bool contains(T const &value) {
        return m_contains(m_root, value);
    }

    bool remove(T const &value) {
        return m_remove(m_root, value);
    }

    void inorder_traversal(std::function<void(T)> visit) const {
        m_inorder(m_root, visit);
    }

    void preorder_traversal(std::function<void(T)> visit) const {
        m_preorder(m_root, visit);
    }

    void postorder_traversal(std::function<void(T)> visit) const {
        m_postorder(m_root, visit);
    }

    size_t size() const {
        return m_size;
    }

    void clear() {
        m_clear(m_root);
    }

private:
    Node *m_root;
    size_t m_size;

    bool m_insert(Node *&node, T item) {
        if (node == nullptr) {
            node = new Node(item);
            m_size++;
            return true;
        }
        if (item == node->value) {
            return false;
        }
        return m_insert(item < node->value ? node->left : node->right, item);
    }

    bool m_contains(Node *&node, T item) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == item) {
            return true;
        }
        return m_contains(item < node->value ? node->left : node->right, item);
    }

    Node *m_get_iop(Node *&node) {
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
                Node *temp = node;
                node = node->right;
                delete temp;
                m_size--;
                return true;
            }
            if (node->right == nullptr) {
                Node *temp = node;
                node = node->left;
                delete temp;
                m_size--;
                return true;
            }
            Node *iop = m_get_iop(node);
            node->value = iop->value;
            return m_remove(node->left, iop->value);
        }
        return m_remove(item < node->value ? node->left : node->right, item);
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
};
