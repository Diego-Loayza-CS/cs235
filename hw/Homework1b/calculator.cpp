#include <iostream>
using std::cout, std:: endl, std::cerr, std:: cin;
#include <string>
using std::string, std::stoi;

int main() {
    string operation;
    cout << "operation: ";

    while (getline(cin, operation)) {
        if (operation == "") {
            return 0;
        }

        else if (operation != "add" && operation != "subtract" && operation != "multiply" && operation != "divide" && operation != "mod") {
            cerr << operation << " isn't a valid operation" << endl;
        }

        else {
            int left;
            string response;
            cout << "left operand: ";
            getline(cin, response);
            left = stoi(response);

            int right;
            cout << "right operand: ";
            getline(cin, response);
            right = stoi(response);

            if (operation == "add") {
                cout << left + right << endl;
            }
            else if (operation == "subtract") {
                cout << left - right << endl;
            }
            else if (operation == "multiply") {
                cout << left * right << endl;
            }
            else if (operation == "divide") {
                cout << left / right << endl;
            }
            else if (operation == "mod") {
                cout << left % right << endl;
            }
        }
    cout << "operation: ";
    }
}