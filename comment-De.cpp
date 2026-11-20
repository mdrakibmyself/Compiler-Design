#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    while (true) {
        cout << "\nEnter a comment (or exit): ";
        if (!getline(cin, line) || line == "exit")
            break;

        bool inString = false, singleLine = false, multiLine = false;

        for (size_t i = 0; i + 1 < line.size(); i++) {
            // toggle string state (ignore escaped quotes)
            if (line[i] == '"' && (i == 0 || line[i - 1] != '\\'))
                inString = !inString;

            if (inString) continue;

            if (line[i] == '/' && line[i + 1] == '/') {
                singleLine = true;
                break;
            }
            if (line[i] == '/' && line[i + 1] == '*') {
                multiLine = true;
                break;
            }
        }

        cout << "Result: ";
        if (singleLine)      cout << "Single-line comment\n";
        else if (multiLine)  cout << "Multi-line comment\n";
        else                 cout << "No comment\n";
    }
    return 0;
}
