#pragma once
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include "SanPham.cpp"
#include "DocFileSP.cpp"
#include "GiaoDien.cpp"


using namespace std;


class User
{
	private:
		string un;
		string pw;
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
		
		string getUN() const
		{
			return un;
		}
		
		string getPW() const
		{
			return pw;
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
		
						SetColor(0, 12);
		                cout << "Da mua thanh cong " << soluong << " san pham " << sp.getTenSanPham() << endl;
						SetColor(0, 7);
		                GhiThongTinBanHang(stt, sp.getHang(), sp.getTenSanPham(), soluong, sp.getGia());
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
		    for(int i = 0; i < n - 1; i++)
		    {
		    	for(int j = i + 1; j < n; j++)
		    	{
		    		if(DS_SanPham[i].getGia() < DS_SanPham[j].getGia())
		    		{
		    			SanPham x = DS_SanPham[i];
		    			DS_SanPham[i] = DS_SanPham[j];
		    			DS_SanPham[j] = x;
					}
				}
			}
		}
		
		void TangDan(vector<SanPham> &DS_SanPham)
		{
			int n = DS_SanPham.size();
		    for(int i = 0; i < n - 1; i++)
		    {
		    	for(int j = i + 1; j < n; j++)
		    	{
		    		if(DS_SanPham[i].getGia() > DS_SanPham[j].getGia())
		    		{
		    			SanPham x = DS_SanPham[i];
		    			DS_SanPham[i] = DS_SanPham[j];
		    			DS_SanPham[j] = x;
					}
				}
			}
		}
		
		void TangDanSTT(vector<SanPham> &DS_SanPham)
		{
			int n = DS_SanPham.size();
		    for(int i = 0; i < n - 1; i++)
		    {
		    	for(int j = i + 1; j < n; j++)
		    	{
		    		if(stoi(DS_SanPham[i].getSTT()) > stoi(DS_SanPham[j].getSTT()))
		    		{
		    			SanPham x = DS_SanPham[i];
		    			DS_SanPham[i] = DS_SanPham[j];
		    			DS_SanPham[j] = x;
					}
				}
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
		        cout << "\n\n--------------------------- SAP XEP SAN PHAM THEO GIA ---------------------------" << endl << endl;
		        SetColor(0, 15);
		        cout << "+----------------------------------+" << endl;
		        cout << "|1. Sap xep theo gia tang dan      |" << endl;
		        cout << "|2. Sap xep theo gia giam dan      |" << endl;
		        cout << "+----------------------------------+" << endl;
		        SetColor(0, 15);
	            cout << "Moi ban nhap lua chon: " << endl;
	            cout << (char)26 << " " ;
	            cin >> chon;
		
		        switch (chon) 
				{
		            case 1:
		            {
		                TangDan(DS_SanPham);
		                kt = false;
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
					    TangDanSTT(DS_SanPham);
		                break;
		            }
		            case 2:
		            {    
						GiamDan(DS_SanPham);
		                kt = false;
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
					    TangDanSTT(DS_SanPham);
		                break;
		            }
		            default:
		        	{
		            	SetColor(0, 12);
		                cout << "Vui long nhap lai lua chon (1 - 3) !" << endl;
		                system("pause");
		                SetColor(0, 7);
		                system("cls");
		                break;
		            }
		        }
		    } while (kt);
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
		cout << "    \t\t\t | 5. DANG XUAT                            | " << endl;
		cout << "	   \t\t +-----------------------------------------+ " << endl;

        int luachon;
        SetColor(0, 15);
        cout << "\n\t\t\t Moi ban nhap lua chon: " << endl;
        cout << "\t\t\t " << (char)26 << " ";
        cin >> luachon;

        switch (luachon) 
		{
            case 1: 
			{	
				system("cls");
                us.us1(DS_SanPham);
                
                bool kt1 = true;
				while(kt1)
				{
					a:
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
							kt1 = false;
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon (1 - 2)! " << endl;
							system("pause");
							SetColor(0, 7);
							goto a;
							break;	
						}
					}
					
					if (!kt1) 
					{
            			break; 
        			}
					
					SetColor(0, 10);
					cout << "---------------------------------------------------------------------------------" << endl;
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
							kt1 = false;
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon (1 - 2)! " << endl;
							system("pause");
							SetColor(0, 7);
							break;
						}
					}
				}
        	}
        	break;
        	case 2:
        	{
        		system("cls");
        		string tentim;
        		SetColor(0, 15);
        		cout << "\n\tNhap ten san pham can tim (iPhone, OPPO, realme, Xiaomi, Samsung): ";
        		cin.ignore();
        		getline(cin, tentim);
        		us.us2(DS_SanPham, tentim);
        		
				bool kt1 = true;	
				while(kt1)
				{
					b:
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
							kt1 = false;
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon (1 - 2)! " << endl;
							system("pause");
							SetColor(0, 7);
							goto b;
							break;	
						}
					}
					
					if (!kt1) 
					{
            			break; 
        			}
        			
					SetColor(0, 10);
					cout << "---------------------------------------------------------------------------------" << endl;
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
							kt1 = false;
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon (1 - 2)! " << endl;
							system("pause");
							SetColor(0, 7);
							break;
						}
					}
				}
			}
			break;
			case 3:
			{
				system("cls");
				string tenhang;
				SetColor(0, 15);
				cout << "\n\tNhap ten hang can tim (iPhone, OPPO, realme, Xiaomi, Samsung): ";
				cin.ignore();
				getline(cin, tenhang);
				us.us3(DS_SanPham, tenhang);
				
				bool kt1 = true;
				while(kt1)
				{
					c:
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
							kt1 = false;
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon (1 - 2)! " << endl;
							system("pause");
							SetColor(0, 7);
							goto c;
							break;	
						}
					}
					
					if (!kt1) 
					{
            			break; 
        			}
        			
					SetColor(0, 10);
					cout << "---------------------------------------------------------------------------------" << endl;
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
							kt1 = false;
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon (1 - 2)! " << endl;
							system("pause");
							SetColor(0, 7);
							break;
						}
					}
				}
			}
			break;
			case 4:
			{
				system("cls");
				us.us4(DS_SanPham);
				
				bool kt1 = true;
				while(kt1)
				{
					d:
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
							kt1 = false;
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon (1 - 2)! " << endl;
							system("pause");
							SetColor(0, 7);
							goto d;
							break;	
						}
					}
					
					if (!kt1) 
					{
            			break; 
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
							kt1 = false;
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon (1 - 2)! " << endl;
							system("pause");
							SetColor(0, 7);
							break;
						}
					}
				}		
			}
			break;
			case 5:
			{
				kt = false;
				SetColor(0, 12);
				cout << "	   \t\t BAN DA DANG XUAT THANH CONG ! " << endl;
				SetColor(0, 7);
    			system("pause");
				break;
			}
			break;
			default:
			{
				SetColor(0, 12);
				cout << "vui long nhap lai lua chon (1 - 5)! " << endl;
				system("pause");
				SetColor(0, 7);
				break;
			}
        }
    } while (kt);
    SetColor(0, 7);
}
