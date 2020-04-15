#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int state = 1; //snt, wnt, wt, st
    char c;
    int hit = 0;
    int miss = 0;
    while (1)
    {
        system("cls");
        cout << "hit = " << hit << endl;
        cout << "miss = " << miss << endl;
        cout << "state = ";
        switch (state)
        {
        case 0:
            cout << "strongly not taken";
            break;
        case 1:
            cout << "weakly not taken";
            break;
        case 2:
            cout << "weakly taken";
            break;
        case 3:
            cout << "strongly taken";
            break;
        }
        c = _getch();
        if (c == 't')
        {
            if (state == 2 || state == 3)
                hit++;
            else
                miss++;
            if (state != 3)
                state++;
        }
        else if (c == 'n')
        {
            if (state == 0 || state == 1)
                hit++;
            else
                miss++;
            if (state != 0)
                state--;
        }
    }
}