#include <iostream>
using std::endl;

#include <fstream>
using std::ifstream, std::ofstream;

#include <string>
using std::string, std::getline;

#include <sstream>
using std::istringstream;

int main(int argc, char* argv[]) {
    ifstream input(argv[1]);
    ofstream output(argv[2]);
    string line;
    string name;
    string last_name;
    int points;
    double factor;

    while (getline(input, line)) {
        istringstream linestream(line);
        linestream >> name >> last_name >> points >> factor;
        double recalculated = points * factor;
        output << last_name << ", " << name << ": " << recalculated << endl;
    }
    return 0;
}



