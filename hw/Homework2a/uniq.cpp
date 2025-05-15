#include <iostream>
using std::cout, std::cin, std::endl, std::getline;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;

bool in_vector(const vector<string>& list, const string& object) {
    for (string elem : list) {
        if (object == elem) {
            return true;
        }
    }
    return false;
}

int main(int argc, char const* argv[]) {
    vector<string> items;
    string line;

    if (argc > 1) {
        ifstream infile(argv[1]);
        while (getline(infile, line)) {
            if (!in_vector(items, line)) {
                items.push_back(line);
            }
        }
        for (string item : items) {
            cout << item << endl;
        }
    }

    else if (argc == 1) {
        while (getline(cin, line)) {
            if (!in_vector(items, line)) {
                items.push_back(line);
                cout << line << endl;
            }
        }
    }

    return 0;
}
