#pragma once

#include <vector>
using std::vector;

template <class T>
void sort(vector<T> &array)
{
    for (int i = 1; i <= array.size() - 1; i++) {
        T item = array[i];
        int j = i;
        while (j > 0 && array[j - 1] > item) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = item;
    }
}