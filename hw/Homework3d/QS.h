#pragma once

#include <utility>
using std::swap;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;

template<class T>
int bubble_sort_bounds(vector<T> &vec, int left, int right) {
    int middle = (left + right) / 2;
    if (vec[left] > vec[middle]) {
        swap(vec[left], vec[middle]);
    }
    if (vec[middle] > vec[right]) {
        swap(vec[middle], vec[right]);
    }
    if (vec[left] > vec[middle]) {
        swap(vec[left], vec[middle]);
    }
    return middle;
}

template<class T>
void quicksort(vector<T> &vec, int left, int right) {
    if (right - left > 0) {
        int middle = bubble_sort_bounds(vec, left, right);
        swap(vec[left], vec[middle]);
        int up = left + 1;
        int down = right;
        while (up <= down) {
            while (up <= right && vec[up] <= vec[left] ) {
                up++;
            }
            while (down >= left && vec[down] > vec[left]) {
                down--;
            }
            if (up < down) {
                T temp = vec[up];
                vec[up] = vec[down];
                vec[down] = temp;
            }
        }

        swap(vec[left], vec[down]);

        quicksort(vec, left, down - 1);
        quicksort(vec, down + 1, right);
    }
}

template<class T>
void sort(vector<T> &vec) {
    int left = 0;
    int right = vec.size() - 1;
    quicksort(vec, left, right);
}