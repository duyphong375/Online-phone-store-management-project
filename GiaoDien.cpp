#pragma once
#include <iostream>
#include <ctime>
#include <windows.h>


using namespace std;

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
	        cout << "\t  oooooo     oooooo     oooooo   ooooooooooo   ooooo        ooooooooooo   ooooooooooo          ooooo    ooooo          ooooooooooo        ooooooooooooo   ooooooooooo            " << endl;
		    cout << "\t   o    o   o      o   o    o    o   ooooooo   o   o        o         o   o         o         o     o  o     o         o   ooooooo        o           o   o         o            " << endl;
		    cout << "\t    o    o o        o o    o     o   o         o   o        o    oooooo   o  ooooo  o        o       oo       o        o   o              ooooo   ooooo   o  ooooo  o            " << endl;
		    cout << "\t     o    o          o    o      o   oooooo    o   o        o    o        o  o   o  o       o                  o       o   oooooo             o   o       o  o   o  o            " << endl;
		    cout << "\t      o                  o       o   oooooo    o   o        o    o        o  o   o  o      o    o          o    o      o   oooooo             o   o       o  o   o  o            " << endl;
		    cout << "\t       o       oo       o        o   o         o   oooooo   o    oooooo   o  ooooo  o     o    o o        o o    o     o   o                  o   o       o  ooooo  o            " << endl;
		    cout << "\t        o     o  o     o         o   ooooooo   o        o   o         o   o         o    o    o   o      o   o    o    o   ooooooo            o   o       o         o            " << endl;
		    cout << "\t         ooooo    ooooo          ooooooooooo   oooooooooo   ooooooooooo   ooooooooooo   oooooo     oooooo     oooooo   ooooooooooo            ooooo       ooooooooooo            " << endl;
		    cout << "\n";
		    cout << "\t   ooooooooooo   oooooooooooo        oooooooooooo   oooooooooooo   ooooooooooo   ooooo  ooooo   ooooooooooo        ooooooooooo   oooooooooooo   ooooooooooo   oooooooooooo       " << endl;
		    cout << "\t   o         o   o  oooo    o        o  oooo    o   o   o  o   o   o         o   o    o o   o   o   ooooooo        o  oooooooo   o   o  o   o   o         o   o  oooo    o       " << endl;
		    cout << "\t   o    oooooo   o  o  o    o        o  o  o    o   o   o  o   o   o  ooooo  o   o     oo   o   o   o              o  o          o   o  o   o   o  ooooo  o   o  o  o    o       " << endl;
		    cout << "\t   o    o        o  oooo    o        o  oooo    o   o   oooo   o   o  o   o  o   o      o   o   o   oooooo         o  oooooooo   o   oooo   o   o  o   o  o   o  oooo    o       " << endl;
		    cout << "\t   o    o        o    ooooooo        o    ooooooo   o   oooo   o   o  o   o  o   o   o      o   o   oooooo         oooooooo  o   o   oooo   o   o  o   o  o   o    ooooooo       " << endl;
		    cout << "\t   o    oooooo   o    o              o    o         o   o  o   o   o  ooooo  o   o   oo     o   o   o                     o  o   o   o  o   o   o  ooooo  o   o    o             " << endl;
		    cout << "\t   o         o   o    o              o    o         o   o  o   o   o         o   o   o o    o   o   ooooooo        oooooooo  o   o   o  o   o   o         o   o    o             " << endl;
		    cout << "\t   ooooooooooo   oooooo              oooooo         ooooo  ooooo   ooooooooooo   ooooo  ooooo   ooooooooooo        ooooooooooo   ooooo  ooooo   ooooooooooo   oooooo             " << endl;
		    Sleep(300);
		    i++;
		}
}

void hinhnen1()
{
	cout << "\n\n" ;
	cout << "\t  oooooo     oooooo     oooooo   ooooooooooo   ooooo        ooooooooooo   ooooooooooo          ooooo    ooooo          ooooooooooo        ooooooooooooo   ooooooooooo            " << endl;
	cout << "\t   o    o   o      o   o    o    o   ooooooo   o   o        o         o   o         o         o     o  o     o         o   ooooooo        o           o   o         o            " << endl;
	cout << "\t    o    o o        o o    o     o   o         o   o        o    oooooo   o  ooooo  o        o       oo       o        o   o              ooooo   ooooo   o  ooooo  o            " << endl;
	cout << "\t     o    o          o    o      o   oooooo    o   o        o    o        o  o   o  o       o                  o       o   oooooo             o   o       o  o   o  o            " << endl;
	cout << "\t      o                  o       o   oooooo    o   o        o    o        o  o   o  o      o    o          o    o      o   oooooo             o   o       o  o   o  o            " << endl;
	cout << "\t       o       oo       o        o   o         o   oooooo   o    oooooo   o  ooooo  o     o    o o        o o    o     o   o                  o   o       o  ooooo  o            " << endl;
	cout << "\t        o     o  o     o         o   ooooooo   o        o   o         o   o         o    o    o   o      o   o    o    o   ooooooo            o   o       o         o            " << endl;
	cout << "\t         ooooo    ooooo          ooooooooooo   oooooooooo   ooooooooooo   ooooooooooo   oooooo     oooooo     oooooo   ooooooooooo            ooooo       ooooooooooo            " << endl;
	cout << "\n";
	cout << "\t   ooooooooooo   oooooooooooo        oooooooooooo   oooooooooooo   ooooooooooo   ooooo  ooooo   ooooooooooo        ooooooooooo   oooooooooooo   ooooooooooo   oooooooooooo       " << endl;
	cout << "\t   o         o   o  oooo    o        o  oooo    o   o   o  o   o   o         o   o    o o   o   o   ooooooo        o  oooooooo   o   o  o   o   o         o   o  oooo    o       " << endl;
	cout << "\t   o    oooooo   o  o  o    o        o  o  o    o   o   o  o   o   o  ooooo  o   o     oo   o   o   o              o  o          o   o  o   o   o  ooooo  o   o  o  o    o       " << endl;
	cout << "\t   o    o        o  oooo    o        o  oooo    o   o   oooo   o   o  o   o  o   o      o   o   o   oooooo         o  oooooooo   o   oooo   o   o  o   o  o   o  oooo    o       " << endl;
	cout << "\t   o    o        o    ooooooo        o    ooooooo   o   oooo   o   o  o   o  o   o   o      o   o   oooooo         oooooooo  o   o   oooo   o   o  o   o  o   o    ooooooo       " << endl;
	cout << "\t   o    oooooo   o    o              o    o         o   o  o   o   o  ooooo  o   o   oo     o   o   o                     o  o   o   o  o   o   o  ooooo  o   o    o             " << endl;
	cout << "\t   o         o   o    o              o    o         o   o  o   o   o         o   o   o o    o   o   ooooooo        oooooooo  o   o   o  o   o   o         o   o    o             " << endl;
	cout << "\t   ooooooooooo   oooooo              oooooo         ooooo  ooooo   ooooooooooo   ooooo  ooooo   ooooooooooo        ooooooooooo   ooooo  ooooo   ooooooooooo   oooooo             " << endl;
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
	while(true)
	{
		system("cls");
		SetRandomColor();
		cout << "\n\n" ;
		cout << "\t  oooooooooo   ooooooooooo   ooooooooooo   oooooooooo           oooooooooo    oooooo     ooooooo   ooooooooooo    " << (char)3 << endl;
		cout << "\t  o        o   o         o   o         o   o         o          o        o     ooooo   ooooo       o   ooooooo    " << (char)3 << endl;
		cout << "\t  o       ooo  o  ooooo  o   o  ooooo  o   o  oooo    o         o    ooooo        oooo oooo        o   o          " << (char)3 << endl;
		cout << "\t  o            o  o   o  o   o  o   o  o   o  o   o   o         o   o               ooooo          o   oooooo     " << (char)3 << endl;
		cout << "\t  o    ooooo   o  o   o  o   o  o   o  o   o  o   o   o         o    ooooo           ooo           o   oooooo     " << (char)3 << endl;
		cout << "\t  o    oo  o   o  ooooo  o   o  ooooo  o   o  oooo    o         o         o          ooo           o   o          " << (char)3 << endl;
		cout << "\t  o        o   o         o   o         o   o         o          o         o          ooo           o   ooooooo    " << (char)3 << endl;
		cout << "\t  oooooooooo   ooooooooooo   ooooooooooo   oooooooooo           oooooooooo           ooo           ooooooooooo    " << (char)3 << endl;
		cout << endl << endl;
		Sleep(500);
	}
}
