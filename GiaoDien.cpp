#pragma once
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

BOOL WINAPI SetConsoleTitle
(
  _In_ LPCTSTR lpConsoleTitle
);

void SetColor(int mau_nen, int mau_chu)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int color_code = mau_nen * 16 + mau_chu;
	SetConsoleTextAttribute(hStdout, color_code);
}

void SetRandomColor() 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(NULL));
    int color = rand() % 15 + 1; 
    
    SetConsoleTextAttribute(hConsole, color);
}

void GoTo(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}

void hinhnen()
{
	int i = 0;
	while(i < 10)
		{
			system("cls");
			SetRandomColor();
			cout << "\n\n" ;
			cout << "\t  ||||||     ||||||     ||||||   |||||||||||   |||||        |||||||||||   |||||||||||          |||||    |||||          |||||||||||        |||||||||||||   |||||||||||            " << endl;
			cout << "\t   |    |   |      |   |    |    |   |||||||   |   |        |         |   |         |         |     |  |     |         |   |||||||        |           |   |         |            " << endl;
			cout << "\t    |    | |        | |    |     |   |         |   |        |    ||||||   |  |||||  |        |       ||       |        |   |              |||||   |||||   |  |||||  |            " << endl;
			cout << "\t     |    |          |    |      |   ||||||    |   |        |    |        |  |   |  |       |                  |       |   ||||||             |   |       |  |   |  |            " << endl;
			cout << "\t      |                  |       |   ||||||    |   |        |    |        |  |   |  |      |    |          |    |      |   ||||||             |   |       |  |   |  |            " << endl;
			cout << "\t       |       ||       |        |   |         |   ||||||   |    ||||||   |  |||||  |     |    | |        | |    |     |   |                  |   |       |  |||||  |            " << endl;
			cout << "\t        |     |  |     |         |   |||||||   |        |   |         |   |         |    |    |   |      |   |    |    |   |||||||            |   |       |         |            " << endl;
			cout << "\t         |||||    |||||          |||||||||||   ||||||||||   |||||||||||   |||||||||||   ||||||     ||||||     ||||||   |||||||||||            |||||       |||||||||||            " << endl;
			cout << "\n";
			cout << "\t   |||||||||||   ||||||||||||        ||||||||||||   |||||  |||||   |||||||||||   |||||  |||||   |||||||||||        |||||||||||   |||||  |||||   |||||||||||   ||||||||||||       " << endl;
			cout << "\t   |         |   |  ||||    |        |  ||||    |   |   |  |   |   |         |   |    | |   |   |   |||||||        |  ||||||||   |   |  |   |   |         |   |  ||||    |       " << endl;
			cout << "\t   |    ||||||   |  |  |    |        |  |  |    |   |   |  |   |   |  |||||  |   |     ||   |   |   |              |  |          |   |  |   |   |  |||||  |   |  |  |    |       " << endl;
			cout << "\t   |    |        |  ||||    |        |  ||||    |   |   ||||   |   |  |   |  |   |      |   |   |   ||||||         |  ||||||||   |   ||||   |   |  |   |  |   |  ||||    |       " << endl;
			cout << "\t   |    |        |    |||||||        |    |||||||   |   ||||   |   |  |   |  |   |   |      |   |   ||||||         ||||||||  |   |   ||||   |   |  |   |  |   |    |||||||       " << endl;
			cout << "\t   |    ||||||   |    |              |    |         |   |  |   |   |  |||||  |   |   ||     |   |   |                     |  |   |   |  |   |   |  |||||  |   |    |             " << endl;
			cout << "\t   |         |   |    |              |    |         |   |  |   |   |         |   |   | |    |   |   |||||||        ||||||||  |   |   |  |   |   |         |   |    |             " << endl;
			cout << "\t   |||||||||||   ||||||              ||||||         |||||  |||||   |||||||||||   |||||  |||||   |||||||||||        |||||||||||   |||||  |||||   |||||||||||   ||||||             " << endl;
		    Sleep(300);
		    i++;
		}
}

void hinhnen1()
{
	cout << "\n\n" ;
	cout << "\t  ||||||     ||||||     ||||||   |||||||||||   |||||        |||||||||||   |||||||||||          |||||    |||||          |||||||||||        |||||||||||||   |||||||||||            " << endl;
	cout << "\t   |    |   |      |   |    |    |   |||||||   |   |        |         |   |         |         |     |  |     |         |   |||||||        |           |   |         |            " << endl;
	cout << "\t    |    | |        | |    |     |   |         |   |        |    ||||||   |  |||||  |        |       ||       |        |   |              |||||   |||||   |  |||||  |            " << endl;
	cout << "\t     |    |          |    |      |   ||||||    |   |        |    |        |  |   |  |       |                  |       |   ||||||             |   |       |  |   |  |            " << endl;
	cout << "\t      |                  |       |   ||||||    |   |        |    |        |  |   |  |      |    |          |    |      |   ||||||             |   |       |  |   |  |            " << endl;
	cout << "\t       |       ||       |        |   |         |   ||||||   |    ||||||   |  |||||  |     |    | |        | |    |     |   |                  |   |       |  |||||  |            " << endl;
	cout << "\t        |     |  |     |         |   |||||||   |        |   |         |   |         |    |    |   |      |   |    |    |   |||||||            |   |       |         |            " << endl;
	cout << "\t         |||||    |||||          |||||||||||   ||||||||||   |||||||||||   |||||||||||   ||||||     ||||||     ||||||   |||||||||||            |||||       |||||||||||            " << endl;
	cout << "\n";
	cout << "\t   |||||||||||   ||||||||||||        ||||||||||||   |||||  |||||   |||||||||||   |||||  |||||   |||||||||||        |||||||||||   |||||  |||||   |||||||||||   ||||||||||||       " << endl;
	cout << "\t   |         |   |  ||||    |        |  ||||    |   |   |  |   |   |         |   |    | |   |   |   |||||||        |  ||||||||   |   |  |   |   |         |   |  ||||    |       " << endl;
	cout << "\t   |    ||||||   |  |  |    |        |  |  |    |   |   |  |   |   |  |||||  |   |     ||   |   |   |              |  |          |   |  |   |   |  |||||  |   |  |  |    |       " << endl;
	cout << "\t   |    |        |  ||||    |        |  ||||    |   |   ||||   |   |  |   |  |   |      |   |   |   ||||||         |  ||||||||   |   ||||   |   |  |   |  |   |  ||||    |       " << endl;
	cout << "\t   |    |        |    |||||||        |    |||||||   |   ||||   |   |  |   |  |   |   |      |   |   ||||||         ||||||||  |   |   ||||   |   |  |   |  |   |    |||||||       " << endl;
	cout << "\t   |    ||||||   |    |              |    |         |   |  |   |   |  |||||  |   |   ||     |   |   |                     |  |   |   |  |   |   |  |||||  |   |    |             " << endl;
	cout << "\t   |         |   |    |              |    |         |   |  |   |   |         |   |   | |    |   |   |||||||        ||||||||  |   |   |  |   |   |         |   |    |             " << endl;
	cout << "\t   |||||||||||   ||||||              ||||||         |||||  |||||   |||||||||||   |||||  |||||   |||||||||||        |||||||||||   |||||  |||||   |||||||||||   ||||||             " << endl;
}

void ve()
{
	GoTo(88, 22);
	cout << "  oooooooooooooooooooooooo "    << endl;
	GoTo(88, 23);
	cout << " o        o ooooo         o "   << endl;
	GoTo(88, 24);
	cout << " o  oooooooooooooooooooo  o   " << endl; 
	GoTo(88, 25);
	cout << " o  o   ooooooooooooo  o  o   " << endl;
	GoTo(88, 26);
	cout << " o  o   o           o  o  o   " << endl;
	GoTo(88, 27);
	cout << " o  o   o           o  o  o   " << endl;
	GoTo(88, 28);
	cout << " o  o   ooooooooooooo  o  o   " << endl;
	GoTo(88, 29);
	cout << " o  o                  o  o   " << endl;
	GoTo(88, 30);
	cout << " o  o   ooooo   ooooo  o  o   " << endl;
	GoTo(88, 31);
	cout << " o  o   o   o   o   o  o  o   " << endl;
	GoTo(88, 32);
	cout << " o  o   ooooo   ooooo  o  o   " << endl;
	GoTo(88, 33);
	cout << " o  o                  o  o   " << endl;
	GoTo(88, 34);
	cout << " o  o   ooooo   ooooo  o  o   " << endl;
	GoTo(88, 35);
	cout << " o  o   o   o   o   o  o  o   " << endl;
	GoTo(88, 36);
	cout << " o  o   ooooo   ooooo  o  o   " << endl;
	GoTo(88, 37);
	cout << " o  o                  o  o   " << endl;
	GoTo(88, 38);
	cout << " o  oooooooooooooooooooo  o   " << endl; 
	GoTo(88, 39);
	cout << " o          oooo          o   " << endl;
	GoTo(88, 40);
	cout << " o          oooo          o   " << endl;
	GoTo(88, 41);
	cout << "  oooooooooooooooooooooooo    " << endl; 
}

void hinhnen2()
{
	int i = 0;
	while(i < 10)
	{
		system("cls");
		cout << "\n\n" ;
		SetRandomColor();
		cout << "\t  ||||||||||   |||||||||||   |||||||||||   ||||||||||           ||||||||||    ||||||     |||||||   |||||||||||    " << (char)3 << endl;
		cout << "\t  ||       |   |         |   |         |   |         |          |        |      |||||   |||||      |   |||||||    " << (char)3 << endl;
		cout << "\t  ||      |||  |  |||||  |   |  |||||  |   |  ||||    |         |    |||||        |||| ||||        |   |          " << (char)3 << endl;
		cout << "\t  ||           |  |   |  |   |  |   |  |   |  |   |   |         |   |               |||||          |   ||||||     " << (char)3 << endl;
		cout << "\t  ||   |||||   |  |   |  |   |  |   |  |   |  |   |   |         |    |||||           |||           |   ||||||     " << (char)3 << endl;
		cout << "\t  ||   ||  |   |  |||||  |   |  |||||  |   |  ||||    |         |         |          |||           |   |          " << (char)3 << endl;
		cout << "\t  ||       |   |         |   |         |   |         |          |         |          |||           |   |||||||    " << endl;
		cout << "\t  ||||||||||   |||||||||||   |||||||||||   ||||||||||           ||||||||||           |||           |||||||||||    " << (char)3 << endl;
			GoTo(50, 17);
		    cout << "   " <<(char)3 << " " << (char)3 << " " << (char)3 << "       " << (char)3 << " " << (char)3 << " " << (char)3 << endl;
		    GoTo(50, 18);
			cout << " " << (char)3 << "       " << (char)3 << "   " << (char)3 << "       " << (char)3 << endl;
			GoTo(50, 19);
			cout << (char)3 << "          " << (char)3 << "          " << (char)3 << endl;
			GoTo(50, 20);
			cout << (char)3 << "                     " << (char)3 << endl;
			GoTo(50, 21);
			cout << (char)3 << "                     " << (char)3 << endl;
			GoTo(50, 22);
			cout << (char)3 << "                     " << (char)3 << endl;
			GoTo(50, 23);
			cout << " " << (char)3 << "                   " << (char)3 << endl;
			GoTo(50, 24);
			cout << "   " << (char)3 << "               " << (char)3 << endl;
			GoTo(50, 25);
			cout << "     " << (char)3 << "           " << (char)3 << endl;
			GoTo(50, 26);
			cout << "       " << (char)3 << "       " << (char)3 << endl;
			GoTo(50, 27);
			cout << "         " << (char)3 << "   " << (char)3 << endl;
			GoTo(50, 28);
			cout << "           " << (char)3 << "       " << endl;
		cout << endl << endl;
		Sleep(500);
		i++;
		SetColor(0, 7);
	}
}
