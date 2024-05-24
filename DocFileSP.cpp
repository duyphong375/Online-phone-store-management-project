#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "SanPham.cpp"
#include "GiaoDien.cpp"

using namespace std;


void DocFileSP(vector<SanPham> &DS_SanPham)
{
	ifstream filein("cuahangcp.csv");
	if(!filein.is_open())
	{
		cerr << "Khong the mo file cuahangcp.csv !" << endl;
		return;
	}
	string line;
	getline(filein, line); // Bo qua dong tieu de
	while(getline(filein, line)) // Doc tung dong trong file cuahangcp.csv va them vao DS_SanPham
	{
		SanPham sp;
		stringstream ss(line);
		string stt, hang, tensp, gia, soluong;
			
		getline(ss, stt, ',');
		getline(ss, hang, ',');
		getline(ss, tensp, ',');
		getline(ss, gia, ',');
		getline(ss, soluong, '\n');
		
		sp.setSTT(stt);
		sp.setHang(hang);
		sp.setTenSanPham(tensp);
		sp.setGia(stoi(gia));
		sp.setSoLuong(stoi(soluong));
			
		DS_SanPham.push_back(sp);
	}
	filein.close();
}

void GhiThongTinBanHang(const string &stt, string hang, string tensp, int soluong, long long gia)
{
    ofstream fileout("thongtinban.csv", ios::app);
    if (!fileout.is_open())
    {
        cerr << "Khong the mo file de ghi!" << endl;
        return;
    }

    fileout << stt << "," << hang << "," << tensp << "," << soluong << "," << gia << endl;
    fileout.close();
}

void UpdateFile(const vector<SanPham> &DS_SanPham)
{
    ofstream fileout("cuahangcpnew.csv", ios::out);

    if (!fileout.is_open())
    {
        cerr << "Khong the mo file cuahangcpnew.csv !" << endl;
        return;
    }

    fileout << "STT,HANG,TEN SAN PHAM,GIA,SO LUONG" << endl;

    for (const SanPham &sp : DS_SanPham)
    {
        fileout << sp.getSTT() << ',' << sp.getHang() << ',' << sp.getTenSanPham() << ',' << sp.getGia() << ',' << sp.getSoLuong() << endl;
    }

    fileout.close();
    remove("cuahangcp.csv");
    rename("cuahangcpnew.csv", "cuahangcp.csv");
}
