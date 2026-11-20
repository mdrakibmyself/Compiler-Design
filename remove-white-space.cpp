#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream fin("withspace.txt");
    ofstream fout("remove.txt");

    if (!fin || !fout) {
        cout << "File opening error!";
        return 1;
    }

    char ch;
    bool lastSpace = false;

    while (fin.get(ch)) {
        if (isspace(static_cast<unsigned char>(ch))) {
            if (!lastSpace) {
                fout << ' ';
                lastSpace = true;
            }
        }
        else {
            fout << ch;
            lastSpace = false;
        }
    }

    fin.close();
    fout.close();

    cout << "Extra whitespace removed successfully!";

    return 0;
}
