#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include "SanPham.cpp"
#include "DocFileUser.cpp"
#include "DocFileSP.cpp"
#include "GiaoDien.cpp"
#include "User.cpp"

using namespace std;

class Admin
{
	private:
		string un;
		string pw;
	public:
		Admin() {}
		
		Admin(string un, string pw)
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
		
		void XoaTK(vector<User> &DS_User, const string &tendangnhap)
		{
		    bool kt = false;
		    for (int i = 0; i < DS_User.size(); ++i)
		    {
		        if (DS_User[i].getUN() == tendangnhap)
		        {
		            kt = true;
		            DS_User.erase(DS_User.begin() + i);
		            UpdateFile1(DS_User);
		            break; 
		        }
		    }
		    if(!kt)
		    {
		    	cout << "Khong tim thay ten nguoi dung !" << endl;
			}
		}
		
		string MaxSTT(const vector<SanPham> &DS_SanPham)
		{
			string maxstt = "0";
			for(const SanPham &sp : DS_SanPham)
			{
				if(stoi(sp.getSTT()) > stoi(maxstt))
				{
					maxstt = sp.getSTT();
				}
			}
			return maxstt;
		}
		
		void ad1(const vector<User> &DS_User)
		{
			cout << "\n\n ------------- DANH SACH CAC TAI KHOAN -------------" << endl;
			cout << endl;
			cout << "\t+---------------------+---------------------+" << endl;
			cout << "\t|" << setw(15) << "Tai Khoan " << setw(7) << "|" << setw(15) << "Mat Khau " << setw(7) << "|" << endl;
			cout << "\t+---------------------+---------------------+" << endl;
			for(const User &us : DS_User)
			{
				cout << "\t|" << setw(15) << us.getUN() << setw(7) << "|" << setw(15) << us.getPW() << setw(7) << "|" << endl;
				cout << "\t+---------------------+---------------------+" << endl;
			}
		}
		
		void ad2(vector<SanPham> &DS_SanPham, const SanPham &spnew)
		{
			bool kt = false;
			for(int i = 0; i < DS_SanPham.size(); ++i)
			{
				if(DS_SanPham[i].getHang() == spnew.getHang() && DS_SanPham[i].getTenSanPham() == spnew.getTenSanPham() && DS_SanPham[i].getGia() == spnew.getGia())
				{
					DS_SanPham[i].setSoLuong(DS_SanPham[i].getSoLuong() + spnew.getSoLuong());
					kt = true;
					break;
				}
			}
			if(!kt)
			{
				DS_SanPham.push_back(spnew);
			}
			UpdateFile(DS_SanPham);
			for (const SanPham &sp : DS_SanPham)
		    {
		        cout << "|" << setw(5) << sp.getSTT() << setw(4) << "|" << setw(9) << sp.getHang() << setw(4) << "|" << setw(26) << sp.getTenSanPham() << setw(4) << "|" << setw(10) << sp.getGia() << setw(4) << "|" << setw(10) << sp.getSoLuong() << setw(4) << "|" << endl;
		        cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
		        kt = true;
		    }
		}
		
		void ad3(vector<SanPham> &DS_SanPham, const string &stt) 
		{
		    bool kt = false; 
		    
		    for (int i = 0; i < DS_SanPham.size(); ++i) 
		    {
		        if (DS_SanPham[i].getSTT() == stt && DS_SanPham[i].getSoLuong() == 0) 
		        {
		            DS_SanPham.erase(DS_SanPham.begin() + i);
		            kt = true; 
		            break; 
		        }
		    }
		    
		    if (kt) 
		    {
		        cout << "Da xoa thanh cong!" << endl;
		        
		        int newSTT = 1;
		        
		        for (SanPham &sp : DS_SanPham) 
		        {
		            sp.setSTT(to_string(newSTT++));
		        }
		        
		        UpdateFile(DS_SanPham);
		    } 
		    else 
		    {
		        cout << "Khong tim thay hoac so luong khong bang 0!" << endl;
		    }
		}
		
		void ad4(vector<SanPham> &DS_SanPham, const string &stt, const int newgia)
		{
			bool kt = false;
			for(int i = 0; i < DS_SanPham.size(); i++)
			{
				if(DS_SanPham[i].getSTT() == stt)
				{
					DS_SanPham[i].setGia(newgia);
					kt = true;
					break;
				}
			}
			
			if(kt)
			{
				cout << "Da chinh sua thanh cong gia san pham !" << endl;	
			}
			else
			{
				cout << "Khong tim thay san pham !" << endl;
			}
		}

};

void MenuAdmin(Admin &ad, User &us, vector<SanPham> &DS_SanPham, vector<User> &DS_User)
{
	bool kt = true;
	do {
		system("cls");
		cout << "\n\n\t\t\t +------------- MENU ADMIN -------------+ " << endl;
		cout << "	   \t\t | 1. DANH SACH THONG TIN NGUOI DUNG    | " << endl;
		cout << "	   \t\t | 2. THEM SAN PHAM                     | " << endl;
		cout << "	   \t\t | 3. XOA SAN PHAM                      | " << endl;
		cout << "	   \t\t | 4. CHINH SUA SAN PHAM                | " << endl;
		cout << "	   \t\t | 5. EXIT                              | " << endl;
		cout << "	   \t\t +--------------------------------------+ " << endl;
		
		int luachon;
		cout << "\n\t\t\t Moi ban nhap lua chon: " << endl;
        cout << "\t\t\t " << char(26) << " ";
        cin >> luachon;
		
		switch(luachon)
		{
			case 1:
			{
				ad.ad1(DS_User);
				
				while(kt)
				{
					cout << endl;
					cout << "---------------------------------------------" << endl;
					cout << "1. Xoa tai khoan " << endl;                      
	                cout << "2. Tro ve MENU Admin " << endl;
	                int chon;
	                cout << "Moi ban nhap lua chon: " << endl;
	                cout << (char)26 << " " ;
	                cin >> chon;
	                
	                switch(chon)
	                {
	                	case 1: 
	                	{
		                	string tendangnhap;
						    cout << "Nhap ten dang nhap tai khoan can xoa: ";
						    cin.ignore();
						    getline(cin, tendangnhap);
							ad.XoaTK(DS_User, tendangnhap);
							break;
						}
						case 2: 
						{
							system("cls");
							MenuAdmin(ad, us, DS_SanPham, DS_User);
							break;
						}
						default:
						{
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;	
						}
					}
					cout << "Ban co muon tiep tuc xoa tai khoan khong ? " << endl;
					cout << "1. Co " << endl;
					cout << "2. Khong " << endl;
					cout << "Moi ban nhap lua chon: " << endl;
					cout << (char)26 << " " ;
					int tieptuc;
					cin >> tieptuc;
					
					switch(tieptuc)
					{
						case 1:
						{
							system("cls");
							ad.ad1(DS_User);
							break;
						}
						case 2:
						{
							kt = false;
							break;
						}
						default:
						{
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;
						}
					}
				}
			}
			break;
			case 2:
			{
				us.us1(DS_SanPham);
				cout << "---------------------------------------------------------------------------------" << endl;
				string stt, hang, tensp;
				int gia, soluong;
				string NextSTT = ad.MaxSTT(DS_SanPham);
				int nextstt =  stoi(NextSTT) + 1;
				NextSTT = to_string(nextstt);
			    
			    cout << "Nhap hang san xuat: ";
			    cin.ignore();
			    getline(cin, hang);
			    cout << "Nhap ten san pham: ";
			    getline(cin, tensp);
			    cout << "Nhap gia san pham: ";
			    cin >> gia;
			    cout << "Nhap so luong san pham can them: ";
			    cin >> soluong;
			
			    SanPham spnew(NextSTT, hang, tensp, gia, soluong);
			
			    ad.ad2(DS_SanPham, spnew);
			    
				cout << "Ban co muon tiep tuc them san pham khong ? " << endl;
				cout << "1. Co " << endl;
				cout << "2. Khong " << endl;
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
						ad.ad2(DS_SanPham, spnew);
						break;
					}
					case 2:
					{
						kt = false;
						break;
					}
					default:
					{
						cout << "Vui long nhap lai lua chon ! " << endl;
						break;
					}
				}
			}
			break;
			case 3:
			{
				us.us1(DS_SanPham);
				string stt;
				cout << "Nhap STT san pham can xoa: ";
				cin.ignore();
				getline(cin, stt);
				ad.ad3(DS_SanPham, stt);
				
				cout << "Ban co muon tiep tuc xoa san pham khong ? " << endl;
				cout << "1. Co " << endl;
				cout << "2. Khong " << endl;
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
						ad.ad3(DS_SanPham, stt);
						break;
					}
					case 2:
					{
						kt = false;
						break;
					}
					default:
					{
						cout << "Vui long nhap lai lua chon ! " << endl;
						break;
					}
				}
			}
			break;
			case 4:
			{
				us.us1(DS_SanPham);
				string stt;
				int gia;
				cout << "Nhap STT san pham can chinh sua: ";
				cin.ignore();
				getline(cin ,stt);
				cout << "Nhap gia can chinh sua cho san pham: ";
				cin >> gia;
				ad.ad3(DS_SanPham, stt);
				
				cout << "Ban co muon tiep tuc xoa san pham khong ? " << endl;
				cout << "1. Co " << endl;
				cout << "2. Khong " << endl;
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
						ad.ad4(DS_SanPham, stt);
						break;
					}
					case 2:
					{
						kt = false;
						break;
					}
					default:
					{
						cout << "Vui long nhap lai lua chon ! " << endl;
						break;
					}
				}
 			}
	} while(kt);
}












































