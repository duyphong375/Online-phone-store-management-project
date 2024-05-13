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
		    	SetColor(0, 12);
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
		
		void DanhSachBan()
		{
		    ifstream filein("thongtinmua.csv");
		    if (!filein.is_open())
		    {
		        cerr << "Khong the mo file thongtinmua.csv!" << endl;
		        return;
		    }
			SetColor(0, 10);
		    cout << "\n\n--------------------------- DANH SACH SAN PHAM DA BAN ---------------------------" << endl;
		    cout << endl;
		    SetColor(0, 15);
		    cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
		    cout << "|" << setw(5) << "STT" << setw(4) << "|" << setw(9) << "Hang" << setw(4) << "|" << setw(26) << "Ten San Pham" << setw(4) << "|" << setw(10) << "So Luong" << setw(4) << "|" << setw(10) << "Gia" << setw(4) << "|" << endl;
		    cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
		
		    string line;
		    while (getline(filein, line))
		    {
		        stringstream ss(line);
		        string stt, hang, tensp, soluong, gia;
		
		        getline(ss, stt, ',');
		        getline(ss, hang, ',');
		        getline(ss, tensp, ',');
		        getline(ss, soluong, ',');
		        getline(ss, gia, '\n');
				SetColor(0, 15);
		        cout << "|" << setw(5) << stt << setw(4) << "|" << setw(9) << hang << setw(4) << "|" << setw(26) << tensp << setw(4) << "|" << setw(10) << soluong << setw(4) << "|" << setw(10) << gia << setw(4) << "|" << endl;
		    }
		    SetColor(0, 15);
		    cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
		
		    filein.close();
		}
		
		void ad1(const vector<User> &DS_User)
		{
			SetColor(0, 10);
			cout << "\n\n ------------- DANH SACH CAC TAI KHOAN -------------" << endl;
			cout << endl;
			SetColor(0, 15);
			cout << "\t+---------------------+---------------------+" << endl;
			cout << "\t|" << setw(15) << "Tai Khoan " << setw(7) << "|" << setw(15) << "Mat Khau " << setw(7) << "|" << endl;
			cout << "\t+---------------------+---------------------+" << endl;
			for(const User &us : DS_User)
			{
				SetColor(0, 15);
				cout << "\t|" << setw(20) << us.getUN() << setw(7) << "|" << setw(20) << us.getPW() << setw(7) << "|" << endl;
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
			SetColor(0, 12);
			cout << "Them san pham thanh cong !" << endl;
			system("pause");
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
		        cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
		    }
		}
		
		void ad3(vector<SanPham> &DS_SanPham, const string &stt) 
		{
		    bool kt = false; 
		    for (int i = 0; i < DS_SanPham.size(); i++) 
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
		    	SetColor(0, 12);
		        cout << "Da xoa thanh cong !" << endl;
		        
		        int newSTT = 1;
		        
		        for (SanPham &sp : DS_SanPham) 
		        {
		            sp.setSTT(to_string(newSTT++));
		        }
		        
		        UpdateFile(DS_SanPham);
		        SetColor(0, 10);
		        system("pause");
				cout << "--------------------------- DANH SACH SAN PHAM HIEN CO --------------------------" << endl;
			    cout << endl;
			    SetColor(0, 15);
			    cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
			    cout << "|" << setw(5) << "STT" << setw(4) << "|" << setw(9) << "Hang" << setw(4) << "|" << setw(26) << "Ten San Pham" << setw(4) << "|" << setw(10) << "Gia" << setw(4) << "|" << setw(10) << "So Luong" << setw(4) << "|" << endl;
			    cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
				for (const SanPham &sp : DS_SanPham)
			    {
			    	SetColor(0, 15);
			        cout << "|" << setw(5) << sp.getSTT() << setw(4) << "|" << setw(9) << sp.getHang() << setw(4) << "|" << setw(26) << sp.getTenSanPham() << setw(4) << "|" << setw(10) << sp.getGia() << setw(4) << "|" << setw(10) << sp.getSoLuong() << setw(4) << "|" << endl;
			        cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
			    }
		    } 
		    else 
		    {
		    	SetColor(0, 12);
		        cout << "Khong tim thay hoac so luong khong bang 0 !" << endl;
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
				SetColor(0, 12);
				cout << "Da chinh sua thanh cong gia san pham !" << endl;
				UpdateFile(DS_SanPham);
				system("pause");
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
			        cout << "+--------+------------+-----------------------------+-------------+-------------+" << endl;
			    }	
			}
			else
			{
				SetColor(0, 12);
				cout << "Khong tim thay san pham !" << endl;
			}
		}
	
		void ad5(vector<SanPham> &DS_SanPham)
		{
			ifstream filein("thongtinmua.csv");
			if (!filein.is_open())
			{
			    cerr << "Khong the mo file de doc!" << endl;
			    return;
			}
			
			int tongdonhang = 0;
			long long tongdoanhthu = 0;
			string line;
			while (getline(filein, line))
			{
			    stringstream ss(line);
			    string stt, tensp, hang, soluong1, gia1;
			
			    getline(ss, stt, ',');
			    getline(ss, tensp, ',');
			    getline(ss, hang, ',');
			    getline(ss, soluong1, ',');
			    getline(ss, gia1, '\n');
			
			    int soluong = stoi(soluong1);
			    long long gia = stoll(gia1);

			    tongdonhang += soluong;
			    tongdoanhthu += gia * soluong; 
			}
			    
			DanhSachBan();
			cout << endl;
			SetColor(0, 10);
			cout << "---------------------------------------------------------------------------------" << endl;
			cout << (char)26 << " " << "Tong so luong da ban: " << tongdonhang << " cai dien thoai " << endl;
			cout << (char)26 << " " << "Tong doanh thu cua cua hang: " << tongdoanhthu << " vnd " << endl;
				
			filein.close();
		}
};

void MenuAdmin(Admin &ad, User &us, vector<SanPham> &DS_SanPham, vector<User> &DS_User)
{
	bool kt = true;
	do {
		system("cls");
		SetColor(0, 11);
		cout << "\n\n\t\t\t +------------- MENU ADMIN ----------------+ " << endl;
		cout << "	   \t\t | 1. DANH SACH THONG TIN NGUOI DUNG       | " << endl;
		cout << "	   \t\t | 2. THEM SAN PHAM                        | " << endl;
		cout << "	   \t\t | 3. XOA SAN PHAM                         | " << endl;
		cout << "	   \t\t | 4. CHINH SUA SAN PHAM                   | " << endl;
		cout << "	   \t\t | 5. THONG KE TONG DOANH THU LOI NHUAN    | " << endl;
		cout << "	   \t\t | 6. DANG XUAT                            | " << endl;
		cout << "	   \t\t +-----------------------------------------+ " << endl;
		
		int luachon;
		SetColor(0, 15);
		cout << "\n\t\t\t Moi ban nhap lua chon: " << endl;
        cout << "\t\t\t " << char(26) << " ";
        cin >> luachon;
		
		switch(luachon)
		{
			case 1:
			{
			    ad.ad1(DS_User);
			
			    bool kt1 = true;
			    while (kt1)
			    {
			        cout << endl;
			        SetColor(0, 10);
			        cout << "---------------------------------------------" << endl;
			        cout << "1. Xoa tai khoan " << endl;
			        cout << "2. Tro ve MENU ADMIN " << endl;
			        int chon;
			        SetColor(0, 15);
			        cout << "Moi ban nhap lua chon: " << endl;
			        cout << (char)26 << " ";
			        cin >> chon;
			
			        switch (chon)
			        {
			            case 1:
			            {
			                string tendangnhap;
			                SetColor(0, 15);
			                cout << "Nhap ten dang nhap tai khoan can xoa: ";
			                cin.ignore(); 
			                getline(cin, tendangnhap);
			                ad.XoaTK(DS_User, tendangnhap);
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
			                break;
			            }
			        }
			        
			        if (!kt1) 
					{
            			break; 
        			}
        			
					SetColor(0, 10);
			        cout << "Ban co muon tiep tuc xoa tai khoan khong ? " << endl;
			        cout << "1. Co " << endl;
			        cout << "2. Khong " << endl;
			        SetColor(0, 15);
			        cout << "Moi ban nhap lua chon: " << endl;
			        cout << (char)26 << " ";
			        int tieptuc;
			        cin >> tieptuc;
			
			        switch (tieptuc)
			        {
			            case 1:
			            {
			                system("cls");
			                ad.ad1(DS_User);
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
			                break;
			            }
			        }
			    }
			    break;
			}
			break;
			case 2:
			{
			    us.us1(DS_SanPham);
			    SetColor(0, 10);
			    cout << "---------------------------------------------------------------------------------" << endl;
			    string stt, hang, tensp;
			    int gia, soluong;
			    string NextSTT = ad.MaxSTT(DS_SanPham);
			    int nextstt = stoi(NextSTT) + 1;
			    NextSTT = to_string(nextstt);
				SetColor(0, 15);
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
			    system("cls");
			    ad.ad2(DS_SanPham, spnew); 
			
			    bool kt1 = true; 
			    while (kt1) 
				{
					SetColor(0, 10);
					cout << "---------------------------------------------------------------------------------" << endl;
			        cout << "Ban co muon tiep tuc them san pham khong ? " << endl;
			        cout << "1. Co " << endl;
			        cout << "2. Khong " << endl;
			        SetColor(0, 15);
			        cout << "Moi ban nhap lua chon: ";
			        int tieptuc;
			        cin >> tieptuc;
			
			        switch (tieptuc) 
					{
			            case 1:
			            {
			            	SetColor(0, 15);
			                cout << "Nhap hang san xuat: ";
			                cin.ignore();
			                getline(cin, hang);
			                cout << "Nhap ten san pham: ";
			                getline(cin, tensp);
			                cout << "Nhap gia san pham: ";
			                cin >> gia;
			                cout << "Nhap so luong san pham can them: ";
			                cin >> soluong;
			
			                spnew = SanPham(NextSTT, hang, tensp, gia, soluong);
			                ad.ad2(DS_SanPham, spnew);
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
			                cout << "Vui long nhap lai lua chon (1 - 2) ! " << endl;
			                break;
			            }
			        }
			    }
			    break; 
			}
			break;
			case 3:
			{
				us.us1(DS_SanPham);
				string stt;
				SetColor(0, 10);
				cout << "---------------------------------------------------------------------------------" << endl;
				SetColor(0, 15);
				cout << "Nhap STT san pham can xoa: ";
				cin.ignore();
				getline(cin, stt);
				ad.ad3(DS_SanPham, stt);
				
				bool kt1 = true; 
			    while (kt1)
				{
					SetColor(0, 10);
					cout << "---------------------------------------------------------------------------------" << endl;
					cout << "Ban co muon tiep tuc xoa san pham khong ? " << endl;
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
							SetColor(0, 15);
			                cout << "Nhap STT san pham can xoa: ";
			                cin.ignore();
			                getline(cin, stt);
							ad.ad3(DS_SanPham, stt);
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
							break;
						}
					}
				}
			}
			break;
			case 4:
			{
				us.us1(DS_SanPham);
				string stt;
				int gia;
				SetColor(0, 10);
				cout << "---------------------------------------------------------------------------------" << endl;
				SetColor(0, 15);
				cout << "Nhap STT san pham can chinh sua: ";
				cin.ignore();
				getline(cin ,stt);
				cout << "Nhap gia can chinh sua cho san pham: ";
				cin >> gia;
				ad.ad4(DS_SanPham, stt, gia);
				
				bool kt1 = true; 
			    while (kt1)
				{
					SetColor(0, 10);
					cout << "---------------------------------------------------------------------------------" << endl;
					cout << "Ban co muon tiep tuc chinh sua san pham khong ? " << endl;
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
							SetColor(0, 15);
							cout << "---------------------------------------------------------------------------------" << endl;
							cout << "Nhap STT san pham can chinh sua: ";
							cin.ignore();
							getline(cin ,stt);
							cout << "Nhap gia can chinh sua cho san pham: ";
							cin >> gia;
							ad.ad4(DS_SanPham, stt, gia);
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
							break;
						}
					}
				}
 			}
 			break;
 			case 5:
			{
			    ad.ad5(DS_SanPham);
			    system("pause");
			    break;
			}
			break;
			case 6:
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
				cout << "vui long nhap lai lua chon (1 - 6) ! " << endl;
				SetColor(0, 7);
				system("pause");
				break;
			}
		} 
	} while(kt);
}
