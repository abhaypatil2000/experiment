#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int state = 1; //not taken, taken
    char c;
    int hit = 0;
    int miss = 0;
    while (1)
    {
        system("cls");
        cout << "state = ";
        if (state == 1)
            cout << "taken";
        else
            cout << "not taken";
        cout << endl;
        cout << "hit = " << hit << endl;
        cout << "miss = " << miss << endl;
        c = _getch();
        if (c == 't')
        {
            if (state == 1)
                hit++;
            else
                miss++;
            state = 1;
        }
        else if (c == 'n')
        {
            if (state == 0)
                hit++;
            else
                miss++;
            state = 0;
        }
    }
}