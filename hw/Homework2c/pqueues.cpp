#include <iostream>
using std::cout, std::cin, std::getline, std::endl;
#include <string>
using std::string, std::stoi;
#include <queue>
using std::priority_queue;
#include <utility>
using std::pair;


bool input(string const& prompt, string& response) {
    cout << prompt;
    cout.flush();
    return getline(cin, response) && (!response.empty());
}



int main(int argc, char const* argv[]) {
    priority_queue<pair<int, string>> pqueue;
    string response;
    while (input("What do you want to do? ", response)) {

        if (response == "") {
            break;
        }

        else if (response == "add") {
            string name;
            cout << "Name: ";
            getline(cin, name);

            string strpriority;
            cout << "Priority: ";
            getline(cin, strpriority);
            int priority = stoi(strpriority);


            pqueue.push(make_pair(priority, name));
        }

        else if (response == "take") {
            if (pqueue.empty()) {
                cout << "There are no more people in line" << endl;
            }
            else {
                pair top = pqueue.top();
                pqueue.pop();
                if (top.first == 10) {
                    cout << top.first << " - " << top.second << endl;
                }
                else {
                    cout << "0" << top.first << " - " << top.second << endl;
                }
            }
        }

        else {
            cout << response << " isn't a valid operation" << endl;
        }

    }
    return 0;
}
