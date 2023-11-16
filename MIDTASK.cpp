#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=');
}

bool isPunctuation(char c)
{
    return (c == '#' || c == ';' || c == ':' || c == '.' || c == '!' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == '<' || c == '>' || c == '<' || c == '>');
}

// Define arrays for a keyword
string myKeywords[] = {"if", "else", "int", "float", "double", "while"};

// Function to check if a token is a keyword
bool isMyKeyword(const string& token)
{
    for (const string& keyword : myKeywords)
    {
        if (token == keyword)
        {
            return true;
        }
    }
    return false;
}

// Function to check if a token is a valid identifier
bool isValidIdentifier(const string& token)
{
    if (token.empty())
    {
        return false;
    }

    for (char c : token)
    {
        if (!isalnum(c) && c != '_')
        {
            return false;
        }
    }

    return true;
}

void checkStringValidity(const string& x)
{
    if (x.empty())
    {
        return;
    }

    string expression = x;
    char exp;
    bool flag = false;
    bool flag2 = false;
    bool space = false;
    bool specialChar = false;

    for (int i = 0; i < expression.length(); i++)
    {
        exp = expression[i];
        if (!((exp >= 65 && exp <= 90) || (exp >= 97 && exp <= 122) || exp == '(' || exp == ')'))
        {
            flag = true;
            if (flag)
            {
                flag2 = true;

                if (exp == 32) space = true;
                if ((exp >= 33 && exp <= 47) || (exp >= 58 && exp <= 64) || (exp >= 91 && exp <= 96) || (exp >= 123 && exp <= 127)) specialChar = true;
            }
        }
        else
        {
            flag = false;
        }
    }
    if (!flag2) cout << x << " is a Valid Identifier" << endl;
}

int main()
{
    fstream newfile;
    string line;

    newfile.open("input.txt", ios::in);

    if (newfile.is_open())
    {
        while (getline(newfile, line))
        {
            int i = 0;

            while (i < line.length())
            {
                string currentChar = "";

                while (i < line.length() && (isalnum(line[i]) || line[i] == '_'))
                {
                    currentChar += line[i];
                    i++;
                }

                if (!currentChar.empty())
                {
                    if (isdigit(currentChar[0]))
                    {
                        cout << currentChar << " is a Number" << endl;
                    }
                    else if (isMyKeyword(currentChar))
                    {
                        cout << currentChar << " is a keyword" << endl;
                    }
                    else if (currentChar == ">>" || currentChar == "<<" || currentChar == ">>>")
                    {
                        cout << currentChar << " is a punctuation" << endl;
                    }
                    else
                    {
                        checkStringValidity(currentChar);
                    }
                }

                if (i < line.length() && isOperator(line[i]))
                {
                    currentChar = line[i];
                    cout << currentChar << " is an operator" << endl;
                    i++;
                }

                if (i < line.length() && isPunctuation(line[i]))
                {
                    currentChar = line[i];
                    cout << currentChar << " is a punctuation" << endl;
                    i++;
                }

                while (i < line.length() && line[i] == ' ')
                {
                    i++;
                }
            }
        }

        newfile.close();
    }

    return 0;
}
