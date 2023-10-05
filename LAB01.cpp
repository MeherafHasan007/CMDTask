//determine whether operator or not

#include <iostream>
using namespace std;

int main()
{
    string input = "7+3*5=22";
    string temp;

    for(int i=0; i<input.length(); i++)
    {
        temp = input[i];
        if(temp== "+" || temp== "-" || temp== "*" || temp== "/" || temp== "=")
        {
            cout<<temp<<" is an operator"<<endl;
        }
        else
        {
            cout << temp << " is not an operator." << endl;
        }

    }
}
