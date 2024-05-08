#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#include "SanPham.cpp"
#include "DocFileSP.cpp"
#include "GiaoDien.cpp"

using namespace std;

class User
{
	private:
		string un;
		string pw;
		int TongSoLuong;
		long long TongTien;
	public:
		User() {}
		
		User(string un, string pw)
		{
			this->un = un;
			this->pw = pw;
		}
		
		void setUN(string un)
		{
			this->un = un;
		}
		
		void setPW(string pw)
		{
			this->pw = pw;
		}
		
		void setTongSoLuong(int TongSoLuong)
		{
			this->TongSoLuong = TongSoLuong;
		}
		
		void setTongTien(int TongTien)
		{
			this->TongTien = TongTien;
		}
		
		string getUN() const
		{
			return un;
		}
		
		string getPW() const
		{
			return pw;
		}
		
		int getTongSoLuong() const
		{
			return TongSoLuong;
		}
		
		int getTongTien() const
		{
			return TongTien;
		}
		
		void Mua(vector<SanPham> &DS_SanPham, const string &stt, int soluong)
		{
		    bool kt = false;
		    for (SanPham &sp : DS_SanPham)
		    {
		        if (sp.getSTT() == stt)
		        {
		            kt = true;
		            if (soluong <= sp.getSoLuong())
		            {
		                int soluongmoi = sp.getSoLuong() - soluong;
		                sp.setSoLuong(soluongmoi);
		
		                TongSoLuong += soluong;
		                TongTien += sp.getGia() * soluong;
						SetColor(0, 12);
		                cout << "Da mua thanh cong " << soluong << " san pham " << sp.getTenSanPham() << endl;
						SetColor(0, 7);
		                GhiThongTinMuaHang(stt, sp.getTenSanPham(), soluong, sp.getGia());
		                UpdateFile(DS_SanPham);
		            }
		            else
		            {
		            	SetColor(0, 12);
		                cout << "So luong " << sp.getTenSanPham() << " khong du de mua ! " << endl;
		                SetColor(0, 7);
		            }
		            break;
		        }
		    }
		
		    if (!kt)
		    {
		    	SetColor(0, 12);
		        cout << "Khong tim thay san pham trong cua hang !" << endl;
		        SetColor(0, 7);
		    }
		}

		void GiamDan(vector<SanPham> &DS_SanPham)
		{
		    int n = DS_SanPham.size();
		    for (int i = 0; i < n - 1; ++i) {
		        int min = i;
		        for (int j = i + 1; j < n; ++j) {
		            if (DS_SanPham[j].getGia() > DS_SanPham[min].getGia()) {
		                min = j;
		            }
		        }
		        swap(DS_SanPham[min], DS_SanPham[i]);
		    }
		}
		
		void TangDan(vector<SanPham> &DS_SanPham)
		{
		    int n = DS_SanPham.size();
		    for (int i = 0; i < n - 1; ++i) {
		        int max = i;
		        for (int j = i + 1; j < n; ++j) {
		            if (DS_SanPham[j].getGia() < DS_SanPham[max].getGia()) {
		                max = j;
		            }
		        }
		        swap(DS_SanPham[max], DS_SanPham[i]);
		    }
		}
		
		void us1(const vector<SanPham> &DS_SanPham)
		{
			SetColor(0, 10);
			cout << "\n\n--------------------------- DANH SACH SAN PHAM HIEN CO --------------------------" << endl;
			cout << endl;
			SetColor(0, 15);
			cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
		    cout << "|" << setw(5) << "STT" << setw(4) << "|" << setw(9) << "Hang" << setw(4) << "|" << setw(26) << "Ten San Pham" << setw(4) << "|" << setw(10) << "Gia" << setw(4) << "|" << setw(10) << "So Luong" << setw(4) << "|" << endl;
		    cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
		    for (const SanPham &sp : DS_SanPham)
		    {
		    	SetColor(0, 15);
		        cout << "|" << setw(5) << sp.getSTT() << setw(4) << "|" << setw(9) << sp.getHang() << setw(4) << "|" << setw(26) << sp.getTenSanPham() << setw(4) << "|" << setw(10) << sp.getGia() << setw(4) << "|" << setw(10) << sp.getSoLuong() << setw(4) << "|" << endl;
		    }
		    cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
		}
		
//		string convert(string s)
//		{
//			for(int i = 0; i <= s.length(); i++)
//			{
//				s[i] = tolower(s[i]);
//			}
//			return s;
//		}
		
		string convert(string s)
		{
			for(char &c : s)
			{
			    c = tolower(c);
			}
			return s;
		}

		
		void us2(const vector<SanPham> &DS_SanPham, const string &tensp)
		{
		    bool kt = false;
		    string tentim = convert(tensp);
		    SetColor(0, 15);
		    cout << "Ket qua tim kiem san pham " << tensp << " :" << endl;
		    SetColor(0, 10);
		    cout << "\n\n--------------------------- DANH SACH SAN PHAM HIEN CO --------------------------" << endl;
		    cout << endl;
		    SetColor(0, 15);
		    cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
		    cout << "|" << setw(5) << "STT" << setw(4) << "|" << setw(9) << "Hang" << setw(4) << "|" << setw(26) << "Ten San Pham" << setw(4) << "|" << setw(10) << "Gia" << setw(4) << "|" << setw(10) << "So Luong" << setw(4) << "|" << endl;
		    cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
		    for (const SanPham &sp : DS_SanPham)
		    {
		        string TenspHienCo = convert(sp.getTenSanPham()); 
		        if (TenspHienCo.find(tentim) != string::npos)
		        {
		        	SetColor(0, 15);
		            cout << "|" << setw(5) << sp.getSTT() << setw(4) << "|" << setw(9) << sp.getHang() << setw(4) << "|" << setw(26) << sp.getTenSanPham() << setw(4) << "|" << setw(10) << sp.getGia() << setw(4) << "|" << setw(10) << sp.getSoLuong() << setw(4) << "|" << endl;
		            cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
		            kt = true;
		        }
		    }
		    if (!kt)
		    {
		    	SetColor(0, 12);
		        cout << "Khong tim thay san pham !" << endl;
		    }
		}

		
		void us3(vector<SanPham> &DS_SanPham, const string &hang)
	    {
	        bool kt = false;
	        string hangtim = convert(hang);
	        SetColor(0, 15);
	        cout << "Ket qua loc hang " << hang << " : ";
	        SetColor(0, 10);
	        cout << "\n\n--------------------------- DANH SACH SAN PHAM HIEN CO --------------------------" << endl;
	        cout << endl;
	        SetColor(0, 15);
	        cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
	        cout << "|" << setw(5) << "STT" << setw(4) << "|" << setw(9) << "Hang" << setw(4) << "|" << setw(26) << "Ten San Pham" << setw(4) << "|" << setw(10) << "Gia" << setw(4) << "|" << setw(10) << "So Luong" << setw(4) << "|" << endl;
	        cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
	        for (const SanPham &sp : DS_SanPham)
	        {
	            string TenhangHienCo = convert(sp.getHang());
	            if (TenhangHienCo == hang)
	            {
	                SetColor(0, 15);
	                cout << "|" << setw(5) << sp.getSTT() << setw(4) << "|" << setw(9) << sp.getHang() << setw(4) << "|" << setw(26) << sp.getTenSanPham() << setw(4) << "|" << setw(10) << sp.getGia() << setw(4) << "|" << setw(10) << sp.getSoLuong() << setw(4) << "|" << endl;
	                cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
	                kt = true;
	            }
	        }
	        if (!kt)
	        {
	            SetColor(0, 12);
	            cout << "Khong tim thay san pham !" << endl;
	        }
	    }
		
		void us4(vector<SanPham> &DS_SanPham) 
		{
		    int chon;
		    bool kt = true;
		
		    do 
			{	
				SetColor(0, 10);
		        cout << "\n\n--------------------------- SAP XEP SAN PHAM THEO GIA ---------------------------" << endl;
		        cout << "1. Sap xep theo gia tang dan" << endl;
		        cout << "2. Sap xep theo gia giam dan" << endl;
		        cout << "3. Tro ve MENU USER" << endl;
		        SetColor(0, 15);
	            cout << "Moi ban nhap lua chon: " << endl;
	            cout << (char)16 << " " ;
	            cin >> chon;
		
		        switch (chon) 
				{
		            case 1:
		                TangDan(DS_SanPham);
		                kt = false;
		                break;
		            case 2:
		                GiamDan(DS_SanPham);
		                kt = false;
		                break;
		            case 3:
		                kt = false;
		                break;
		            default:
		            	SetColor(0, 12);
		                cout << "Vui long nhap lai lua chon tu (1 - 3) !" << endl;
		        }
		    } while (kt);
		    SetColor(0, 15);
		    cout << "\n\n---------------------- DANH SACH SAN PHAM SAU KHI SAP XEP -----------------------" << endl;
		    cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
		    cout << "|" << setw(5) << "STT" << setw(4) << "|" << setw(9) << "Hang" << setw(4) << "|" << setw(26) << "Ten San Pham" << setw(4) << "|" << setw(10) << "Gia" << setw(4) << "|" << setw(10) << "So Luong" << setw(4) << "|" << endl;
		    cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
		    for(const SanPham& sp : DS_SanPham) 
			{
				SetColor(0, 15);
		        cout << "|" << setw(5) << sp.getSTT() << setw(4) << "|" << setw(9) << sp.getHang() << setw(4) << "|" << setw(26) << sp.getTenSanPham() << setw(4) << "|" << setw(10) << sp.getGia() << setw(4) << "|" << setw(10) << sp.getSoLuong() << setw(4) << "|" << endl;
		        cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
		    }
		}
		
		void us5()
		{
		    ifstream filein("thongtinmua.csv");
		    if (!filein.is_open())
		    {
		        cerr << "Khong the mo file de doc!" << endl;
		        return;
		    }
		
		    int tongsoluong = 0;
		    long long tongtien = 0;
		    string line;
		    while (getline(filein, line))
		    {
		        stringstream ss(line);
		        string stt, tensp, soluong1, gia1;
		
		        getline(ss, stt, ',');
		        getline(ss, tensp, ',');
		        getline(ss, soluong1, ',');
		        getline(ss, gia1, ',');
		
		        int soluong = stoi(soluong1);
		        long long gia = stoll(gia1);
		        
		        tongsoluong += soluong;
		        tongtien += gia * soluong;
		    }
			SetColor(0, 12);
			cout << endl;
		    cout << " --------------------- THONG KE --------------------- " << endl;
		    SetColor(0, 15);
		    cout << "So luong san pham da mua: " << tongsoluong << " cai " << endl;
		    cout << "Tong tien phai thanh toan: " << tongtien << " vnd " << endl;
		
		    filein.close();
		
		    TongSoLuong = tongsoluong;
		    TongTien = tongtien;
		}
};

void MenuUser(User &us, vector<SanPham> DS_SanPham) 
{
	bool kt = true;
    do {
        system("cls");
        SetColor(0, 11);
        cout << "\n\n\t\t\t +--------------- MENU USER ---------------+ " << endl;
		cout << "	   \t\t | 1. DANH SACH SAN PHAM HIEN CO           | " << endl;
		cout << "	   \t\t | 2. TIM KIEM TEN SAN PHAM                | " << endl;
		cout << "	   \t\t | 3. LOC DANH SACH SAN PHAM THEO HANG     | " << endl;
		cout << "	   \t\t | 4. SAP XEP SAN PHAM THEO GIA TIEN       | " << endl; 
		cout << "	   \t\t | 5. THONG KE TONG SAN PHAM VA TONG TIEN  | " << endl;
		cout << "    \t\t\t | 6. EXIT                                 | " << endl;
		cout << "	   \t\t +-----------------------------------------+ " << endl;

        int luachon;
        SetColor(0, 15);
        cout << "\n\t\t\t Moi ban nhap lua chon: " << endl;
        cout << "\t\t\t " << char(26) << " ";
        cin >> luachon;

        switch (luachon) 
		{
            case 1: 
			{
                us.us1(DS_SanPham);

				while(kt)
				{
					SetColor(0, 10);
					cout << endl;
	                cout << "---------------------------------------------------------------------------------" << endl;
	                cout << "1. Mua hang " << endl;                      
	                cout << "2. Tro ve MENU USER " << endl;
	                int chon;
	                SetColor(0, 15);
	                cout << "Moi ban nhap lua chon: " << endl;
	                cout << (char)26 << " " ;
	                cin >> chon;
	                
	                switch(chon)
	                {
	                	case 1: 
	                	{
		                	string stt;
		                	int soluong;
		                	SetColor(0, 10);
		                	cout << "Nhap STT san pham can mua: ";
		                	cin.ignore();
		                	getline(cin, stt);
		                	SetColor(0, 10);
		                	cout << "Nhap so luong can mua: ";
		                	cin >> soluong;
		                	us.Mua(DS_SanPham, stt, soluong);
		                	break;
						}
						case 2: 
						{
							system("cls");
							MenuUser(us, DS_SanPham);
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;	
						}
					}
					SetColor(0, 10);
					cout << "Ban co muon tiep tuc mua san pham ko ? " << endl;
					cout << "1. Co " << endl;
					cout << "2. Khong " << endl;
					SetColor(0, 15);
					cout << "Moi ban nhap lua chon: " << endl;
					cout << (char)26 << " " ;
					int tieptuc;
					cin >> tieptuc;
					
					switch(tieptuc)
					{
						case 1:
						{
							system("cls");
							us.us1(DS_SanPham);
							break;
						}
						case 2:
						{
							kt = false;
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;
						}
					}
				}
        	}
        	break;
        	case 2:
        	{
        		string tentim;
        		SetColor(0, 15);
        		cout << "Nhap ten san pham can tim (iPhone, OPPO, realme, Xiaomi, Samsung): ";
        		cin.ignore();
        		getline(cin, tentim);
        		us.us2(DS_SanPham, tentim);
        		
				while(kt)
				{
					SetColor(0, 10);
					cout << endl;
	                cout << "---------------------------------------------------------------------------------" << endl;
	                cout << "1. Mua hang " << endl;                      
	                cout << "2. Tro ve MENU USER " << endl;
	                int chon;
	                SetColor(0, 15);
	                cout << "Moi ban nhap lua chon: " << endl;
	                cout << (char)26 << " " ;
	                cin >> chon;
	                
	                switch(chon)
	                {
	                	case 1: 
	                	{
		                	string stt;
		                	int soluong;
		                	SetColor(0, 10);
		                	cout << "Nhap STT san pham can mua: ";
		                	cin.ignore();
		                	getline(cin, stt);
		                	SetColor(0, 10);
		                	cout << "Nhap so luong can mua: ";
		                	cin >> soluong;
		                	us.Mua(DS_SanPham, stt, soluong);
		                	break;
						}
						case 2: 
						{
							system("cls");
							MenuUser(us, DS_SanPham);
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;	
						}
					}
					SetColor(0, 10);
					cout << "Ban co muon tiep tuc mua san pham ko ? " << endl;
					cout << "1. Co " << endl;
					cout << "2. Khong " << endl;
					SetColor(0, 15);
					cout << "Moi ban nhap lua chon: " << endl;
					cout << (char)26 << " " ;
					int tieptuc;
					cin >> tieptuc;
					
					switch(tieptuc)
					{
						case 1:
						{
							system("cls");
							us.us2(DS_SanPham, tentim);
							break;
						}
						case 2:
						{
							kt = false;
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;
						}
					}
				}
			}
			break;
			case 3:
			{
				string tenhang;
				SetColor(0, 15);
				cout << "Nhap ten hang can tim (iPhone, OPPO, realme, Xiaomi, Samsung): ";
				cin.ignore();
				getline(cin, tenhang);
				us.us3(DS_SanPham, tenhang);
				
				while(kt)
				{
					SetColor(0, 10);
					cout << endl;
	                cout << "---------------------------------------------------------------------------------" << endl;
	                cout << "1. Mua hang " << endl;                      
	                cout << "2. Tro ve MENU USER " << endl;
	                int chon;
	                SetColor(0, 15);
	                cout << "Moi ban nhap lua chon: " << endl;
	                cout << (char)26 << " " ;
	                cin >> chon;
	                
	                switch(chon)
	                {
	                	case 1: 
	                	{
		                	string stt;
		                	int soluong;
		                	SetColor(0, 10);
		                	cout << "Nhap STT san pham can mua: ";
		                	cin.ignore();
		                	getline(cin, stt);
		                	SetColor(0, 10);
		                	cout << "Nhap so luong can mua: ";
		                	cin >> soluong;
		                	us.Mua(DS_SanPham, stt, soluong);
		                	break;
						}
						case 2: 
						{
							system("cls");
							MenuUser(us, DS_SanPham);
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;	
						}
					}
					SetColor(0, 10);
					cout << "Ban co muon tiep tuc mua san pham ko ? " << endl;
					cout << "1. Co " << endl;
					cout << "2. Khong " << endl;
					SetColor(0, 15);
					cout << "Moi ban nhap lua chon: " << endl;
					cout << (char)26 << " " ;
					int tieptuc;
					cin >> tieptuc;
					
					switch(tieptuc)
					{
						case 1:
						{
							system("cls");
							us.us3(DS_SanPham, tenhang);
							break;
						}
						case 2:
						{
							kt = false;
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;
						}
					}
				}
			}
			break;
			case 4:
			{
				us.us4(DS_SanPham);
				while(kt)
				{
					SetColor(0, 10);
					cout << endl;
	                cout << "---------------------------------------------------------------------------------" << endl;
	                cout << "1. Mua hang " << endl;                      
	                cout << "2. Tro ve MENU USER " << endl;
	                int chon;
	                SetColor(0, 15);
	                cout << "Moi ban nhap lua chon: " << endl;
	                cout << (char)26 << " " ;
	                cin >> chon;
	                
	                switch(chon)
	                {
	                	case 1: 
	                	{
		                	string stt;
		                	int soluong;
		                	SetColor(0, 10);
		                	cout << "Nhap STT san pham can mua: ";
		                	cin.ignore();
		                	getline(cin, stt);
		                	SetColor(0, 10);
		                	cout << "Nhap so luong can mua: ";
		                	cin >> soluong;
		                	us.Mua(DS_SanPham, stt, soluong);
		                	break;
						}
						case 2: 
						{
							system("cls");
							MenuUser(us, DS_SanPham);
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;	
						}
					}
					SetColor(0, 10);
					cout << "Ban co muon tiep tuc mua san pham ko ? " << endl;
					cout << "1. Co " << endl;
					cout << "2. Khong " << endl;
					SetColor(0, 15);
					cout << "Moi ban nhap lua chon: " << endl;
					cout << (char)26 << " " ;
					int tieptuc;
					cin >> tieptuc;
					
					switch(tieptuc)
					{
						case 1:
						{
							system("cls");
							us.us4(DS_SanPham);
							break;
						}
						case 2:
						{
							kt = false;
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;
						}
					}
				}
				
			}
			break;
			case 5:
			{
				us.us5();
				system("pause");
			}
			break;
			case 6:
			{
				kt = false;
				break;
			}
			break;
			default:
			{
				SetColor(0, 12);
				cout << "vui long nhap lai lua chon (1 - 6) ! " << endl;
				system("pause");
				break;
			}
        }
    } while (kt); 
}






