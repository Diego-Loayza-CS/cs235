#pragma once
#include <vector>
using std::vector;

template<class T>
class VectorSet {
public:
    bool contains(T item) const {
        for (T elem : vec) {
            if (elem == item) {
                return true;
            }
        }
        return false;
        // return true if item is in the set and false if not
    }

    bool insert(T item) {
        if (contains(item)) {
            return false;
        }
        vec.push_back(item);
        return true;
        // return true if item is inserted and false if item is already in the
        // set
    }

    bool remove(T item) {
        for (auto it = vec.begin(); it != vec.end(); it++) {
            if (*it == item) {
                vec.erase(it);
                return true;
            }
        }
        return false;
        // return true if item is removed and false if item wasn't in the set
    }

    size_t size() const {
        return vec.size();
        // return the number of items in the set
    }

    bool empty() const {
        return (vec.empty());
    }

    void clear() {
        vec.clear();
    }

private:
    vector<T> vec;
};
