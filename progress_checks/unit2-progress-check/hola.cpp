#include <cstddef>
#include <queue>
using std::priority_queue;

template <class T>
class PQ {

public:

    void push(T const& item) {
        pqu.push(item);
    }

    void pop() {
        pqu.pop();
    }

    size_t size() const {
        return pqu.size();
    }

    T top() const {
        return pqu.top();
    }

    bool empty() const {
        return pqu.empty();
    }

private:
    priority_queue<T> pqu;
};

int main() {
    return 0;
}