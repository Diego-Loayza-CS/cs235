#include "QS.h"

int main() {

    vector<size_t> items;
    vector<size_t> expected;
    for (size_t i = 0; i < 1000000; i++) {
        items.push_back(i);
        expected.push_back(i);
    }

    sort(items);

    for (const auto& item : items) {
        std::cout << item << " ";
    }

    return 0;
}