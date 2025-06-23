#pragma once

#include <vector>
using std::vector;

template<typename T>
void split(vector<T> &vec, vector<T> &left, vector<T> &right) {
    int len = vec.size() - 1;
    int mid = len / 2;
    int i = 0;
    while (i <= mid) {
        left.push_back(vec[i]);
        i++;
    }
    while (i <= len) {
        right.push_back(vec[i]);
        i++;
    }
}


template<typename T>
void merge(vector<T> &vec, vector<T> &left, vector<T> &right) {
    int i = 0;
    int j = 0;
    vector<T> data = {};
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            data.push_back(left[i]);
            i++;
        } else {
            data.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size()) {
        data.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        data.push_back(right[j]);
        j++;
    }
    vec = data;
}


template<typename T>
void sort(vector<T> &items) {
    if (int len = items.size(); len > 1) {
        vector<T> left;
        vector<T> right;
        split(items, left, right);
        sort(left);
        sort(right);
        merge(items, left, right);
    }
}
