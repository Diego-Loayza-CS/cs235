#pragma once
#include <list>
#include <functional>
using namespace std;

const size_t INITIAL_CAPACITY = 5;
const double MAX_FILL = 0.8;


template<class T>
class HashSet {
public:
    HashSet() {
        m_size = 0;
        m_capacity = INITIAL_CAPACITY;
        m_data = new list<T>[INITIAL_CAPACITY];
    }

    ~HashSet() {
        clear();
        delete [] m_data;
    }

    bool insert(T item) {
        if (fillFactor() >= MAX_FILL) {
            grow();
        }
        size_t index = get_index(item);
        if (m_data[index].size() != 0) {
            for (auto entry: m_data[index]) {
                if (entry == item) {
                    return false;
                }
            }
        }
        m_data[index].push_front(item);
        m_size++;
        return true;
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the set
        size_t index = get_index(item);
        for (auto itr = m_data[index].begin(); itr != m_data[index].end(); itr++) {
            if (*itr == item) {
                m_data[index].erase(itr);
                m_size--;
                return true;
            }
        }
        return false;
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the set, false otherwise
        size_t index = get_index(item);
        if (m_data[index].size() != 0) {
            for (auto entry: m_data[index]) {
                if (entry == item) {
                    return true;
                }
            }
        }
        return false;
    }

    void clear() {
        // implement clear here
        // remove all elements from the set
        for (size_t i = 0; i < m_capacity; i++) {
            m_data[i].clear();
        }
        m_size = 0;
    }

    int size() const {
        return m_size;
    }

private:
    int m_size;
    size_t m_capacity;
    list<T> *m_data;

    double fillFactor() {
        return static_cast<double>(m_size) / m_capacity;
    }

    size_t get_index(T item) const {
        const size_t hashCode = hash<T>{}(item);
        const size_t index = hashCode % m_capacity;
        return index;
    }

    void grow() {
        size_t oldCapacity = m_capacity;
        list<T>* oldData = m_data;
        m_size = 0;
        m_capacity = 2 * m_capacity + 1;
        m_data = new list<T>[m_capacity];
        for (size_t i = 0; i < oldCapacity; i++) {
            for (auto item : oldData[i]) {
                insert(item);
            }
        }
        delete [] oldData;
    }
};