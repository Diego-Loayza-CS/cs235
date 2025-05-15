#include <iostream>
using std::cout, std::endl;

#include <fstream>
using std::ifstream, std::ofstream;

#include <string>
using std::string, std::getline;

#include <sstream>
using std::istringstream;


int main(int argc, char* argv[]) {
    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);

    int max_word_count = 0;
    string longest_line;

    string line;
    while (getline(infile, line)) {
        int word_count = 0;

        istringstream linestream(line);
        string word;
        while (linestream >> word) {
            word_count++;
        }

        if (word_count > max_word_count) {
            max_word_count = word_count;
            longest_line = line;
        }
    }
    cout << longest_line << endl;
    return 0;
}