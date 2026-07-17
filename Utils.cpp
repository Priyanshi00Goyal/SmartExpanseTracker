#include "Utils.h"

#include <iostream>
#include <conio.h>

using namespace std;

string inputPassword()
{
    string password;
    char ch;

    while(true)
    {
        ch = _getch();

        if(ch == '\r')      // Enter key
        {
            cout << endl;
            break;
        }

        else if(ch == '\b') // Backspace
        {
            if(!password.empty())
            {
                password.pop_back();
                cout << "\b \b";
            }
        }

        else
        {
            password += ch;
            cout << '*';
        }
    }

    return password;
}
