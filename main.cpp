#include "SanPham.cpp"
#include "User.cpp"
#include "Admin.cpp"
#include "DocFileSP.cpp"
#include "DocFileUser.cpp"
#include "GiaoDien.cpp"
#include <iostream>
#include <ctime>

using namespace std;

void DangKi(vector<SanPham> &DS_SanPham) 
{
	SetColor(0, 11);
    cout << "\t ---------- MOI BAN DANG KI TAI KHOAN ---------" << endl;
    string un, pw;
    SetColor(0, 15);
    cout << "\t " << (char)26 << " " << "Ten dang nhap: ";
    cin.ignore();
    getline(cin, un);
    SetColor(0, 15);
    cout << "\t " << (char)26 << " " << "Mat khau: ";
    getline(cin, pw);

    ofstream fileout("data.csv", ios::app);
    if (!fileout.is_open()) 
	{
        cerr << "Khong the mo file data.csv !" << endl;
        return;
    }

    fileout << un << "," << pw << endl;
    SetColor(0, 11);
    cout << "\t " << (char)26 << " " << "Da tao tai khoan thanh cong ! " << endl;
    system("pause");
    fileout.close();
    SetColor(0, 7);
}

void DangNhap(vector<SanPham> &DS_SanPham, vector<User> &DS_User) 
{
	SetColor(0, 11);
	cout << "\t --------- MOI BAN DANG NHAP TAI KHOAN --------" << endl;
    string un, pw;
    SetColor(0, 15);
    cout << "\t " << (char)26 << " " << "Ten dang nhap: ";
    cin.ignore();
    getline(cin, un);
    SetColor(0, 15);
    cout << "\t " << (char)26 << " " << "Mat khau: ";
    getline(cin, pw);

    ifstream filein("data.csv");
    if (!filein.is_open()) 
	{
        cerr << "Khong the mo file data.csv !" << endl;
        return;
    }

    string line;
    bool kt = false;
    while (getline(filein, line)) 
	{
        stringstream ss(line);
        string uname, pword;

        getline(ss, uname, ',');
        getline(ss, pword, '\n');

        if (uname == un && pword == pw) 
		{
            kt = true;
            break;
        }
    }

    if(kt) 
	{
		SetColor(0, 12);
        cout << "\t " << (char)26 << " " << "Dang nhap thanh cong !" << endl;
        system("pause");
        if (un == "AdminCP" && pw == "AdminCP") 
		{
			SetColor(0,7);
			Admin ad(un, pw);
			User us(un, pw);
            MenuAdmin(ad, us, DS_SanPham, DS_User);
        } 
		else 
		{
            User us(un, pw);
            MenuUser(us, DS_SanPham);
        }
    } 
	else 
	{
		SetColor(0, 12);
        cout << "\t " << (char)26 << " " << "Dang nhap that bai !" << endl;
        cout << "\t " << (char)26 << " " << "Moi ban dang nhap lai !" << endl;
        system("pause");
    }
    SetColor(0, 7);
}

void DoiMatKhau() 
{
	SetColor(0, 11);
    cout << "\t ------------ MOI BAN DOI MAT KHAU ------------ " << endl;
    string un, pw;
    SetColor(0, 15);
    cout << "\t " << (char)26 << " " << "Ten dang nhap: ";
    cin.ignore();
    getline(cin, un);
    SetColor(0, 15);
    cout << "\t " << (char)26 << " " << "Mat khau cu: ";
    getline(cin, pw);

    ifstream filein("data.csv");
    ofstream fileout("datanew.csv");

    if (!filein.is_open() || !fileout.is_open()) 
	{
        cerr << "Khong ton tai file datanew.csv !" << endl;
        return;
    }

    string line;
    bool kt = false;
    while (getline(filein, line)) 
	{
        string uname, pword;
        stringstream ss(line);
        getline(ss, uname, ',');
        getline(ss, pword, '\n');

        if (uname == un && pword == pw) 
		{
            kt = true;
            SetColor(0, 15);
            cout << "\t " << (char)26 << " " << "Mat khau moi: ";
            string new_pw;
            getline(cin, new_pw);
            fileout << un << "," << new_pw << endl;
            SetColor(0, 11);
            cout << "\t " << (char)26 << " " << "Doi mat khau thanh cong !" << endl;
            system("pause");
        } 
		else 
		{
            fileout << line << endl;
        }
    }

    filein.close();
    fileout.close();

    remove("data.csv");
    rename("datanew.csv", "data.csv");

    if (!kt) 
	{
		SetColor(0, 12);
        cout << "\t  " << (char)26 << " " << "Sai ten tai khoan hoac mat khau cu !" << endl;
        system("pause");
    }
    SetColor(0, 7);
}



int main() 
{
    vector<SanPham> DS_SanPham;
    DocFileSP(DS_SanPham);
    vector<User> DS_User;
    DocFileUser(DS_User);

    int luachon;
    hinhnen();
    do 
	{
		system("cls");
		SetColor(0, 12);
		hinhnen1();
		SetColor(0, 15);
		ve();
		SetColor(0, 11);
		GoTo(0, 22);
		cout << "\t +--------- QUAN LI CUA HANG ---------+" << endl;
		GoTo(0, 23);                               
        cout << "\t | 1. DANG KI                         |" << endl;
		GoTo(0, 24);                        
        cout << "\t | 2. DANG NHAP                       |" << endl;
		GoTo(0, 25);                  
        cout << "\t | 3. DOI MAT KHAU                    |" << endl;  
		GoTo(0, 26);                                                                 
        cout << "\t | 4. EXIT                            |" << endl; 
		GoTo(0, 27);             
        cout << "\t +------------------------------------+" << endl;  
        GoTo(0, 28);
		SetColor(0,15);           
		cout << "\t Moi ban nhap lua chon: "                << endl; 
		GoTo(0, 29);            
		cout << "\t " << (char)26 << " " ;             
		cin >> luachon;                                                    
                                                    
        switch (luachon) 
		{
            case 1:
                DangKi(DS_SanPham);
                system("cls");
                break;
            case 2:
                DangNhap(DS_SanPham, DS_User);
                system("cls");
                break;
            case 3:
                DoiMatKhau(); 
                system("cls");
                break;
            case 4:
            	SetColor(0, 11);
                cout << "\t CHUC BAN CO MOT NGAY TOT LANH " << (char)3 << (char)3 << (char)3 <<  endl;
                system("pause");
                SetColor(0, 7);
                break;
            default:
            	SetColor(0, 12);
                cout << "\t" << (char)26 << " " << "Vui long nhap lai lua chon tu (1 - 4) !" << endl;
                system("pause");
                break;
                SetColor(0, 7);
        }
    } while (luachon != 4);	
    return 0;
}

