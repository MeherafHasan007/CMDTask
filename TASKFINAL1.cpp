#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cout << "Failed to open the file." << endl;
        return 1;
    }
    char ch;
    while (inputFile.get(ch))
    {
        if (ch == '<' && inputFile.get() == '=')
            cout << ch << "=" << " Less than or equal to" << endl;
        else if (ch == '>' && inputFile.get() == '=')
            cout << ch << "=" << " Greater than or equal to" << endl;
        else if (ch == '<')
            cout << ch << " Less than" << endl;
        else if (ch == '>')
            cout << ch << " Greater than" << endl;
        else if (ch == '=' && inputFile.get() == '=' )
        {
            cout << "== equal to" << endl;
            inputFile.ignore(); //
        }
        else if (ch == '!' && inputFile.get() == '=' )
        {
            cout << "!= Not equal to" << endl;
            inputFile.ignore();
        }
    }
    inputFile.close();
    return 0;
}
