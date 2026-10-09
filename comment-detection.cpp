#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("input.txt");

    if (!file.is_open()) {
        cout << "Cannot open input.txt" << endl;
        return 1;
    }

    // Check if the file is empty
    if (file.peek() == EOF) {
        cout << "Error: input.txt is empty." << endl;
        file.close();
        return 1;
    }

    string line;
    int singleLine = 0;
 singleLine = 0;
    int multiLine = 0;
    bool insideMulti = false;

    while (getline(file, line)) {
        int i = 0;

        while (i < line.length()) {
            if (i + 1 < line.length() &&
                line[i] == '/' && line[i + 1] == '/') {
                singleLine++;
                break;
            }
            else if (i + 1 < line.length() &&
                     line[i] == '/' && line[i + 1] == '*') {
                multiLine++;
                insideMulti = true;
                i += 2;

                while (i < line.length()) {
                    if (i + 1 < line.length() &&
                        line[i] == '*' && line[i + 1] == '/') {
                        insideMulti = false;
                        i += 2;
                        break;
                    }
                    i++;
                }
            }
            else {
                i++;
            }
        }
    }

    file.close();

    cout << "Single-line comments: " << singleLine << endl;
    cout << "Multi-line comment openings: " << multiLine << endl;

    return 0;
}
