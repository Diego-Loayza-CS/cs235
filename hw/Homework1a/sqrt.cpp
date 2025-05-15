#include <iostream>
using std::cout, std::endl, std::cerr;
#include <cstdlib>
using std::abs, std::atof;

int main(int argc, char* argv[]) {
    const double start = atof(argv[1]);

    if (start < 0) {
        cerr << "Input must be greater than 0" << endl;
        return 1;
    }

    double lower = 0;
    double upper = start;
    double approx = 0;

    while (abs(start - approx) >= 0.0001) {
        double middle = lower + ((upper - lower) / 2);
        approx = middle * middle;

        cout << middle << " (" << approx << ")" << endl;

        if (approx > start) {
            upper = middle;
        }
        else if (approx < start) {
            lower = middle;
        }
    }
    return 0;
}