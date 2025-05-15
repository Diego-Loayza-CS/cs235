#include <iostream>
using std::cout, std::endl, std::cerr, std::cin;

#include <string>
using std::string, std::stoi;

#include <fstream>
using std::ifstream;

#include <cstdlib>
using std::atoi;


int main(int argc, char const* argv[]) {

    if (argc == 3) {
		ifstream infile(argv[2]);
        if (!infile.is_open()) {
            cerr << "ERROR: can't open " << argv[2] << endl;
            return 1;
        }

        int n = atoi(argv[1]);
		string line;
        for (int i = 0; i > n && getline(infile, line); i--) {
            cout << line << endl;
        }
    }

    else if (argc == 2) {
        string arg = argv[1];

        if (arg[0] == '-') {
            int n = stoi(arg);
            string line;
            for (int i = 0; i != n && getline(cin, line); i--) {
                cout << line << endl;
            }
        }
        else {
			ifstream infile(arg);
            if (!infile.is_open()) {
                cerr << "ERROR: can't open " << arg << endl;
                return 1;
            }

            int n = 10;
            string line;
            for (int i = 0; i < n && getline(infile, line); i++) {
                cout << line << endl;
            }
        }
    }

    else if (argc == 1) {
        int n = 10;
        string line;
        for (int i = 0; i != n && getline(cin, line); i++) {
            cout << line << endl;
        }
    }
    return 0;
}
