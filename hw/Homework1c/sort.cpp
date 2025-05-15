#include <iostream>
using std::cout, std:: endl, std::cerr;
#include <string>
using std::string;

void sort(string& a, string& b, string& c) {
    string tmp;

    if (a > b && a > c) {
        tmp = c;
        c = a;
        a = tmp;
    }
    else if (b > a && b > c) {
        tmp = c;
        c = b;
        b = tmp;
    }


    if (a > b) {
        tmp = b;
        b = a;
        a = tmp;
    }

}

int main(int argc, char const* argv[]) {
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " a b c" << endl;
        return 1;
    }

    string a = argv[1];
    string b = argv[2];
    string c = argv[3];

    sort(a, b, c);

    cout << a << ' ' << b << ' ' << c << endl;

    return 0;
}
