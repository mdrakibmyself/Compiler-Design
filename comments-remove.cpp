#include <iostream>
#include <fstream>
#include <string>7
using namespace std;

int main()
{
    ifstream input("sample.txt");
    ofstream output("output.txt");

    if (!input.is_open())
    {
        cout << "File not found!";
        return 1;
    }

    string line;
    bool inComment = false;

    while (getline(input, line))
    {
        string result = "";

        for (int i = 0; i < line.length(); i++)
        {
            // Check multiline comment start
            if (!inComment && i + 1 < line.length()
                && line[i] == '/' && line[i + 1] == '*')
            {
                inComment = true;
                i++;
            }
            // Check multiline comment end
            else if (inComment && i + 1 < line.length()
                     && line[i] == '*' && line[i + 1] == '/')
            {
                inComment = false;
                i++;
            }
            // Check single line comment
            else if (!inComment && i + 1 < line.length()
                     && line[i] == '/' && line[i + 1] == '/')
            {
                break;
            }
            // Copy normal characters
            else if (!inComment)
            {
                result += line[i];
            }
        }

        if (!result.empty())
        {
            output << result << endl;
        }
    }

    input.close();
    output.close();

    cout << "Comments removed successfully!";
    cout << "\nCheck output.txt file.";

    return 0;
}
