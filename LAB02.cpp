//determine whether identifier or not

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    bool flag;
    string mystr="Re1wf";

    char ch;
    for(int i=0; i<mystr.length(); i++)
    {

        ch=mystr[i];
        if(!((ch>=65 && ch<=90)||(ch>=97 && ch<=122)))
        {
            flag = true;

        }
    }

    if(flag)
    {

        cout<<"Special character is not allowed"<<endl;
    }


    else
        cout<<"This is valid"<<endl;

}

