#include <vector>
using std::vector;
#include <iostream>
using std::cout, std::endl;

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

int main(int argc, char* argv[]) {
    vector<int> list = {3, 7, -5, 10, 1};
    sort(list);
    for (const auto&elem : list) {
        cout << elem << " ";
    }
    return 0;
}