#include <iostream>
using std::cout, std::endl;
#include <cstdlib>
using std::atoi;

int main(int argc, char* argv[]) {
    int num = atoi(argv[1]);
    cout << num << endl;

    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
            cout << num << endl;
        }

        else {
        num = (num * 3) + 1;
        cout << num << endl;
        }
    }

    return 0;
}

