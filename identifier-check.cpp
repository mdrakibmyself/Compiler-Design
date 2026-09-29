//Check an identifer is valid or invalid
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;

    while (true) {
        bool isValid = true;

        cout << "Enter an identifier: ";
        cin >> input;

        int len = input.length();

        if (len == 0) {
            isValid = false;
        }

        if (isValid) {
            if (input == "int" || input == "float" ||
                input == "char" || input == "if" ||
                input == "else" || input == "for" ||
                input == "while" || input == "return" ||
                input == "void" || input == "break") {
                isValid = false;
            }
        }

        if (isValid) {
            char first = input[0];
            if (!((first >= 'a' && first <= 'z') || (first >= 'A' && first <= 'Z'))) {
                isValid = false;
            }
        }

        if (isValid) {
            for (int i = 0; i < len; i++) {
                char ch = input[i];
                if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
                      (ch >= '0' && ch <= '9'))) {
                    isValid = false;
                    break;
                }
            }
        }

        if (isValid) {
            cout << "\"" << input << "\" VALID" << endl << endl;
        } else {
            cout << "\"" << input << "\" INVALID" << endl << endl;
        }
    }

    return 0;
}