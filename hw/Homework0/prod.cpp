#include <iostream>
using std::cout , std::cerr, std::endl;
#include <cstdlib>
using std::atof;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "prod requires 2 arguments" << endl;
        return 1;
    }
    float a = atof(argv[1]);
    float b = atof(argv[2]);
    cout << a << " * " << b << " = " << a * b << endl;
    return 0;
}
