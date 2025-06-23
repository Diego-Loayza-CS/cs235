#pragma once

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;
        Node(T v) : next(nullptr), value(v) {}
    };

    Node *head;
    size_t _size;
    SLList(): head(nullptr), _size(0) {}

    ~SLList() {
        clear();
    }


    const Node* get_head() const {
        return head;
    }


    void _push_back(Node* &node, T const &value) {
        if (node == nullptr) {
            node = new Node(value);
            _size++;
        }
        else {
            _push_back(node->next, value);
        }
    }
    void push_back(T const &item) {
        _push_back(head, item);
    }


    void _pop_back(Node* &node) {
        if (node->next == nullptr) {
            delete node;
            node = nullptr;
            _size--;
        }
        else {
            _pop_back(node->next);
        }
    }
    void pop_back() {
        _pop_back(head);
    }


    void push_front(T item) {
        Node* new_node = new Node(item);
        new_node->next = head;
        head = new_node;
        _size++;
    }

    void pop_front() {
        Node* old_head = head;
        head = head->next;
        delete old_head;
        _size--;
    }

    const T& front() const {
        return head->value;
    }

    int size() const {
        return _size;
    }

    void _clear(Node* &node) {
        if (node == nullptr) {
            return;
        }
        _clear(node->next);
        delete node;
        node = nullptr;
        _size--;
    }

    void clear() {
        _clear(head);
    }
};
