#pragma once

#include <stdexcept>

template<class T>
class DLList {
public:
    struct Node {
        Node *prev;
        Node *next;
        T value;

        Node(T v, Node *next = nullptr, Node *prev = nullptr): prev(prev), next(next), value(v) {
        }
    };

private:
    size_t m_size;
    Node *m_head;
    Node *m_tail;

    void m_clear(Node* &node) {
        if (node == nullptr) {
            return;
        }
        m_clear(node->next);
        delete node;
        node = nullptr;
        m_size--;
    }

public:
    DLList(): m_size(0), m_head(nullptr), m_tail(nullptr) {
    }

    ~DLList() {
        clear();
    }

    const Node *get_head() const {
        return m_head;
    }

    void push_front(T item) {
        m_head = new Node(item, m_head);
        if (m_size != 0) {
            m_head->next->prev = m_head;
        } else {
            m_tail = m_head;
        }
        m_size++;
    }

    void push_back(T item) {
        Node* newNode = new Node(item, nullptr, m_tail);
        if (m_size == 0) {
            m_head = newNode;
            m_tail = newNode;
        } else {
            m_tail->next = newNode;
            m_tail = newNode;
        }
        m_size++;
    }

    void insert(T item, int position) {
        if (position < 0 || position > m_size) {
            throw std::out_of_range("Invalid index");
        }
        if (position == m_size) {
            push_back(item);
        } else if (position == 0) {
            push_front(item);
        } else {
            Node *ptr = m_head;
            for (int i = 0; i < position; i++) {
                ptr = ptr->next;
            }
            Node *newItem = new Node(item, ptr, ptr->prev);
            ptr->prev = newItem;
            newItem->prev->next = newItem;
            m_size++;
        }
    }

    void pop_front() {
        Node *temp = m_head;
        if (m_size == 1) {
            m_head = nullptr;
            m_tail = nullptr;
        } else {
            m_head = m_head->next;
            m_head->prev = nullptr;
        }
        m_size--;
        delete temp;
    }

    void pop_back() {
        Node *temp = m_tail;
        if (m_size == 1) {
            m_head = nullptr;
            m_tail = nullptr;
        } else {
            m_tail = m_tail->prev;
            m_tail->next = nullptr;
        }
        m_size--;
        delete temp;
    }

    void remove(int position) {
        if (position < 0 || position >= m_size) {
            throw std::out_of_range("Invalid index");
        }
        if (position == m_size - 1) {
            pop_back();
        } else if (position == 0) {
            pop_front();
        } else {
            Node *ptr = m_head;
            for (int i = 0; i < position; i++) {
                ptr = ptr->next;
            }
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            m_size--;
            delete ptr;
        }
    }

    const T &front() const {
        return m_head->value;
    }

    const T &back() const {
        return m_tail->value;
    }

    const T &at(int index) const {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Invalid index");
        }
        Node *ptr = m_head;
        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        return ptr->value;
    }

    bool contains(const T &item) const {
        Node *ptr = m_head;
        while (ptr != nullptr) {
            if (ptr->value == item) {
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }

    int size() const {
        return m_size;
    }

    void clear() {
        m_clear(m_head);
    }
};
