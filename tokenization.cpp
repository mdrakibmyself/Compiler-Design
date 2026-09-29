//Tokenaization 
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a sentence: ";
    getline(cin, str);

    cout << "Output: " << endl;

    size_t i = 0;
    while (i < str.length()) {
        char c = str[i];
        if (c == ' ' || c == ';' || c == '@' || c == '$' || c == ',' || c == ':' || c == '\n') {
            i++;
            continue;
        }
        cout << "<";
        while (i < str.length() && str[i] != ' ' && str[i] != ';' && str[i] != '@' &&
               str[i] != '$' && str[i] != ',' && str[i] != ':' && str[i] != '\n') {
            cout << str[i];
            i++;
        }
        cout << ">" << endl;
    }

    return 0;
}