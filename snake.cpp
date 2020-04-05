#include <iostream>
#include <deque>
#include <utility>
#if _WIN32
#include <conio.h>
#include<Windows.h>
#else
//#include <alternate for conio.h>
#include<unistd.h>
#endif

#define mp make_pair

using namespace std;

bool over;
int score;
int n, m, fx, fy, i, j;
char inp = 's', curr = 's';
deque<pair<int, int>> body;
pair<int, int> head;

bool in_body(int x, int y)
{
	pair<int, int> temp = mp(x, y);
	for (auto x : body)
	{
		if (temp == x)
			return true;
	}
	return false;
}

void input()
{
	if (_kbhit())
		curr = _getch();
	if (inp == 's' || inp == 'w')
	{
		if (curr == 'a' || curr == 'd')
			inp = curr;
	}
	else if (inp == 'a' || inp == 'd')
	{
		if (curr == 's' || curr == 'w')
			inp = curr;
	}
	//body.push_front(head);//------------------------------possible bug
	//body.pop_back();//do this is backend part because of food is eaten then dont pop
	switch (inp)
	{
	case 'w':
		head.first--;
		break;
	case 'a':
		head.second--;
		break;
	case 's':
		head.first++;
		break;
	case 'd':
		head.second++;
		break;
	}
}

void backend()
{
	if (head.first == fx && head.second == fy)
	{
		score = score + 10;
		fx = rand() % (n - 1) + 1;
		fy = rand() % (m - 1) + 1;
		while (in_body(fx, fy))
		{
			fx = rand() % (n - 1) + 1;
			fy = rand() % (m - 1) + 1;
		}
	}
	else
	{
		body.pop_back();
	}
	if (head.first == 0 || head.first == n + 1 || head.second == 0 || head.second == m + 1 || in_body(head.first, head.second))
		over = true;
}

void print()
{
	cout << "\033[2J\033[1;1H";

	for (i = 0; i <= n + 1; i++)
	{
		for (j = 0; j <= m + 1; j++)
		{
			if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
				cout << "#";
			else if (i == head.first && j == head.second)
			{
				if (inp == 'a')
					cout << '<';
				else if (inp == 'd')
					cout << '>';
				else if (inp == 's')
					cout << 'v';
				else if (inp == 'w')
					cout << '^';
				//cout << "O";
			}
			else if (in_body(i, j))
			{
				cout << "o";
			}
			else if (i == fx && j == fy)
			{
				cout << "X";
			}
			else
				cout << " ";

		}
		cout << endl;
	}
	cout << "Score : " << score << endl;
}

void setup()
{
	n = 20;
	m = 20;
	head.second = n / 2;
	head.first = m / 4;
	over = false;
	score = 0;
	fx = rand() % (n - 1) + 1;
	fy = rand() % (m - 1) + 1;
}


int main()
{
	setup();
	print();
	while (!over)
	{
		body.push_front(head);//possible bug---------------------
		input();
		backend();
		print();
		Sleep(200);
		#if _WIN32
				Sleep(200);//in milliseconds//adjust this for the pace of the game
		#else
				usleep(1000000);//in microseconds
		#endif
	}

}
