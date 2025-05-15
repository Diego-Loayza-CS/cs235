#include <fstream>
using std::ifstream;
#include <string>
using std::string, std::stof;
#include <iostream>
using std::cout, std::endl, std::getline, std::cerr;
#include <sstream>
using std::istringstream;

int main(int argc, char* argv[]) {
    ifstream infile(argv[1]);
    if (!infile.is_open()) {
        cout << "ERROR: could not open file" << endl;
        return 0;
    }

    string _country = argv[2];
    string _year = argv[3];

    string line;
    string country;
    string year;
    string month;
    string rate;

    float sum = 0;
    float count = 0;
    float _rate;

    while (getline(infile, line)) {
        istringstream linestream(line);
        linestream >> country >> year >> month >> rate;
        if (country == _country) {
            if (year == _year) {
                sum += stof(rate);
                count++;
            }
        }
    }

    _rate = sum / count;
    cout << _rate << endl;

    return 0;
}