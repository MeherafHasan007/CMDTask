//determine weather Number or not

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    bool flag=false;
    string mystr;
    cout<<"Enter a number:";
    cin>>mystr;

    char ch;
    for(int i=0; i<mystr.length(); i++)
    {

        ch=mystr[i];
        if(!(ch>=48 && ch<=57))
        {
            flag = true;

        }


    }

    if(flag)
    {

        cout<<"This is not number"<<endl;
    }
    else
        cout<<"This is Number"<<endl;

}
