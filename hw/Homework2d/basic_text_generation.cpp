#include <string>
using std::string;
#include <iostream>
using std::cin, std::cout, std::istream, std::ostream, std::endl;
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

unordered_map<string, vector<string>> train(istream& in) {
    unordered_map<string, vector<string>> tmap;
    string prev = "";
    string curr;
    while (in >> curr) {
        tmap[prev].push_back(curr);
        prev = curr;
    }
    return tmap;
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
    srand(time(NULL));
    ifstream infile(argv[1]);
    int amount = atoi(argv[2]);
    string start = "";
    unordered_map<string, vector<string>> dictionary = train(infile);
    sendout(dictionary, start, amount, cout);
    return 0;
}