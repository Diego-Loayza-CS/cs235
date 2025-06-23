#pragma once
#include <list>
#include <utility>
#include <functional>
#include <iostream>
#include <sstream>
using namespace std;

const size_t INITIAL_CAP = 3;

template<class K, class V>
class Hashmap {
public:
    Hashmap(): m_size(0), m_capacity(INITIAL_CAP) {
        m_data = new list<pair<K, V> >[INITIAL_CAP];
    }

    ~Hashmap() {
        delete [] m_data;
    }

    bool insert(K key, V item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the set
        auto hashcode = hash<K>{}(key);
        size_t index = hashcode % m_capacity;
        auto itr = m_data[index].begin();
        for (; itr != m_data[index].end(); itr++) {
            if (itr->first == key) {
                break;
            }
        }
        if (itr == m_data[index].end()) {
            m_data[index].push_back(key, item);
            m_size++;
            return true;
        } else {
            itr->second = item;
            return true;
        }
    }

    bool remove(K key, V item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the set
    }

    bool contains(K item) const {
        // implement contains here
        // return true if item is in the set, false otherwise
    }

    V& operator[](K const &key) {
        auto hashcode = hash<K>{}(key);
        size_t index = hashcode % m_capacity;
        auto itr = m_data[index].begin();
        for (; itr != m_data[index].end(); itr++) {
            if (itr->first == key) {
                return itr->second;;
            }
        }
        V item;
        m_data[index].push_back(pair(key, item));
        m_size++;
        return item;
    }

    void clear() {
        // implement clear here
        // remove all elements from the set
    }

    size_t size() const {
        return m_size;
    }

    string toString() {
        ostringstream os;
        for (size_t i = 0; i < m_capacity; i++) {
            if (!m_data[i].empty()) {
                os << "bucket: " << i << ": ";
                for (auto item: m_data[i]) {
                    cout << item.first << "=>" << item.second << " ";
                }
                os << endl;
            }
        }
    }

private:
    size_t m_size;
    size_t m_capacity;
    list<pair<K, V> > *m_data;
};