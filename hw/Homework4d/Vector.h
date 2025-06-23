#pragma once

#include <iostream>
#include <string>

const size_t INITIAL_CAPACITY = 5;

template<class T>
class Vector {
public:
    class iterator {
        T *current;

    public:
        iterator(T* const& index) : current(index) {}

        T &operator*() {
            return *current;
        }

        iterator &operator++() {
            current++;
            return *this;
        }

        bool operator==(const iterator &other) const {
            return current == other.current;
        }

        bool operator!=(const iterator &other) const {
            return !(*this == other);
        }
    };

    iterator begin() {
        return iterator(m_data);
    }

    iterator end() {
        return iterator(m_data + m_size);
    };


    Vector() {
        m_size = 0;
        m_capacity = INITIAL_CAPACITY;
        m_data = new T[m_capacity];
    }

    ~Vector() {
        clear();
        delete [] m_data;
    }

    void push_back(T const &item) {
        if (m_size == m_capacity) {
            grow();
        }
        m_data[m_size++] = item;
    }

    void pop_back() {
        m_size--;
    }

    void insert(T const &item, size_t position) {
        if (m_size == m_capacity) {
            grow();
        }
        for (size_t i = m_size; i > position; i--) {
            m_data[i] = m_data[i - 1];
        }
        m_data[position] = item;
        m_size++;
    }

    void remove(size_t position) {
        while (position < m_size - 1) {
            m_data[position] = m_data[position + 1];
            position++;
        }
        pop_back();
    }

    T &operator[](size_t index) {
        return m_data[index];
    }

    T &at(size_t index) {
        if (index < m_size) {
            return m_data[index];
        } else {
            throw std::out_of_range("Supplied index is too large");
        }
    }

    size_t size() const {
        return m_size;
    }

    void clear() {
        m_size = 0;
    }

private:
    T *m_data;
    size_t m_size;
    size_t m_capacity;

    void grow() {
        m_capacity *= 2;
        T *newArray = new T[m_capacity];
        for (size_t i = 0; i < m_size; i++) {
            newArray[i] = m_data[i];
        }
        delete [] m_data;
        m_data = newArray;
    }
};
