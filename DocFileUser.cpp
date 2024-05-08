#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "User.cpp"
#include "GiaoDien.cpp"

using namespace std;

void DocFileUser(vector <User> &DS_User)
{
	ifstream filein("data.csv");
	if(!filein.is_open())
	{
		cerr << "Khong the mo file data.csv !" << endl;
		return;
	}
	string line;
	getline(filein, line); // Bo qua tai khoan Admin
	// Doc tung dong trong file data.csv va them vao DS_User
	while(getline(filein, line))
	{
		User us;
		stringstream ss(line);
		string un, pw;
		getline(ss, un, ',');
		getline(ss, pw);
		
		us.setUN(un);
		us.setPW(pw);
			
		DS_User.push_back(us);
	}
	filein.close();
}

void UpdateFile1(const vector<User> &DS_User)
{
    ofstream fileout("datanew.csv", ios::out);

    if (!fileout.is_open())
    {
        cerr << "Khong the mo file datanew.csv !" << endl;
        return;
    }

    for (const User &us : DS_User)
    {
        fileout << us.getUN() << ',' << us.getPW() << '\n';
    }

    fileout.close();
    remove("data.csv");
    rename("datanew.csv", "data.csv");
}
