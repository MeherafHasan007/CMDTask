/*LAB 3

Write C++ code to identify relational operators and label them from a given expression.


Input: x == 5 Output: == Equal to

Input: y >= n
Output: >= Greater than or equal to

Input: x > 5
Output: > Greater than

Your code should scan each string one character at a time.

Submit a PDF report with code and screen shot of your console output. Mention your Name & Section*/


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
