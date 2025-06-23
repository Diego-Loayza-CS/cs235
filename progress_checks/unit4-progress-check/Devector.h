#pragma once

size_t INITIAL_CAPACITY = 5;

template<class T>
class Devector {
public:
    Devector() {
        m_size = 0;
        m_capacity = INITIAL_CAPACITY;
        m_data = new T[m_capacity];
        m_front = 0;
    }

    ~Devector() {
        clear();
        delete [] m_data;
    }

    void push_back(T const &item) {
        if (m_size == m_capacity) {
            grow();
        }
        m_data[(m_front + m_size) % m_capacity] = item;
        m_size++;
    }

    void pop_back() {
        m_size--;
    }

    void push_front(T const &item) {
        if (m_size == m_capacity) {
            grow();
        }
        if (m_front == 0) {
            m_front = m_capacity - 1;
        } else {
            m_front--;
        }
        m_data[m_front] = item;
        m_size++;
    }

    void pop_front() {
        if (m_front == m_capacity - 1) {
            m_front = 0;
        } else {
            m_front++;
        }
        m_size--;
    }

    T &operator[](size_t index) {
        size_t newIndex = (m_front + index) % m_capacity;
        return m_data[newIndex];
    }

    T &at(size_t index) {
        if (index < m_size) {
            size_t newIndex = (m_front + index) % m_capacity;
            return m_data[newIndex];
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
    size_t m_front;

    void grow() {
        T *newArray = new T[m_capacity * 2];

        for (size_t i = 0; i < m_size; i++) {
            newArray[i] = m_data[(m_front + i) % m_capacity];
        }
        delete [] m_data;
        m_data = newArray;
        m_front = 0;
        m_capacity *= 2;
    }
};
