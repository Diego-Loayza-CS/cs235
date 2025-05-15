#include <string>
using std::string;
#include <iostream>
using std::cin, std::cout, std::istream, std::ostream, std::endl, std::cerr;
#include <unordered_map>
using std::unordered_map;
#include <vector>
using std::vector;
#include <cstdlib>
using std::rand, std::atoi;
#include <fstream>
using std::ifstream;
#include <ctime>
using std::time;


string random_element(const vector<string>& v) {

    int index = rand() % v.size();
    return v[index];
}

void train(unordered_map<string, vector<string>>& v, istream& in) {
    string prev = "";
    string curr;
    while (in >> curr) {
        v[prev].push_back(curr);
        prev = curr;
    }
}

void sendout(const unordered_map<string, vector<string>>& model, string& word, const int& num, ostream& out) {
    int count = 0;
    while (model.find(word) != model.end() && count < num) {
        vector<string> words = model.at(word);
        string anyword = random_element(words);
        out << anyword << " ";
        word = anyword;
        count++;
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
    cerr << "More arguments expected" << endl;
    return 1;
    }
    unordered_map<string, vector<string>> dictionary;
    for (int i = 1; i < argc - 2; i++) {
        ifstream infile(argv[i]);
        train(dictionary, infile);
        }
    srand(time(NULL));
    int amount = atoi(argv[argc - 2]);
    string start = argv[argc - 1];

    sendout(dictionary, start, amount, cout);
    return 0;
    }