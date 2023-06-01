#include<iostream>
#include<cmath>
#include<iomanip>
#include<Windows.h>
#include<vector>
#include<algorithm>
#include<fstream>
#include<chrono>
using namespace std;
const int MAX_SACH = 2000;

//Hàm kiểm tra ngày tháng năm
bool datecheck(int ngay, int thang, int nam) {
    if (ngay < 1 || ngay > 31 || thang < 1 || thang > 12 || nam < 1500 || nam > 2023) {
        return false;
    }
    if ((thang == 4 || thang == 6 || thang == 9 || thang == 11) && ngay > 30) {
        return false;
    }
    if (thang == 2) {
        if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) {
            if (ngay > 29) {
                return false;
            }
        } else {
            if (ngay > 28) {
                return false;
            }
        }
    }
    return true;
}

//Hàm set màu cho terminal
void setColor(int color) {
    cout << "\033[38;5;" << color << "m";
}
void resetColor() {
    std::cout << "\033[0m";
}

//Lớp sách
class sach{
   private:
      string tensach;
      string tacgia;
      string nxb;
      string masach;
      int namxuatban;
      int soluong;
      int ngay; 
      int thang;
      int nam;
   public:
   //Hàm tạo mặc định   
      sach(){
         tensach ="";
         nxb = "";
         masach = "";
         tacgia = "";
         namxuatban = 0;
         soluong = 0;
         ngay = 0;
         thang = 0; 
         nam = 0;
      }
      sach(string tensach,string tacgia,string nxb,string masach,int namxuatban,int soluong,int ngay,int thang,int nam){
            this->tensach = tensach;
            this->tacgia = tacgia;
            this->nxb = nxb;
            this->masach = masach;
            this->namxuatban = namxuatban;
            this->soluong = soluong;
            this->ngay = ngay;
            this->thang = thang;
            this->nam = nam;
      }

      string gettensach();
      string getmasach();
      string gettacgia();
      string getnhaxuatban();
      int getsoluong();
      int getnamxuatban();
      int getngay();
      int getthang();
      int getnam();

      void settensach(string tensach);
      void settacgia(string tacgia);
      void setnxb(string nxb);
      void setmasach(string masach);
      void setnamxuatban(int namxuatban);
      void setngay(int ngay);
      void setthang(int thang);
      void setnam(int nam);
      void setsoluong(int soluong);
      //Qua tai toan tu nhap xuat
      friend istream& operator>>(istream& is,sach &s);
      friend ostream& operator<<(ostream& os,sach &s);
      //Hàm dọc ghi với lớp ifstream và ofstream
      void doc(ifstream &read);
      void ghi(ofstream &write);
      void timkiem(vector<sach> &listsach);
      void suasach(vector<sach> &listsach);
      void xoasach(vector<sach> &listsach);
      void sapxepsach(vector<sach> &listsach,int &chon);
      void xuatlistsach(vector<sach> &listsach);
      bool datescheck(){
         return datecheck(ngay,thang,nam);
      }
};


//getter
string sach::gettensach(){
   return tensach;
}
string sach::gettacgia(){
   return tacgia;
}
string sach::getnhaxuatban(){
   return nxb;
}
string sach::getmasach(){
   return masach;
}
int sach::getnamxuatban(){
   return namxuatban;
}
int sach::getsoluong(){
   return soluong;
}
int sach::getngay(){
   return ngay;
}
int sach::getthang(){
   return thang;
}
int sach::getnam(){
   return nam;
}

// setter
void sach::settensach(string tensach){
   this->tensach = tensach;
}
void sach::settacgia(string tacgia){
   this->tacgia= tacgia;
}
void sach::setnxb(string nxb){
   this->nxb= nxb;
}
void sach::setmasach(string masach){
   this->masach= masach;
}
void sach::setnamxuatban(int namxuatban){
   this->namxuatban= namxuatban;
}
void sach::setngay(int ngay){
   this->ngay = ngay;
}
void sach::setthang(int thang){
   this->thang = thang;
}
void sach::setnam(int nam ){
   this->nam = nam;
}
void sach::setsoluong(int soluong){
   this->soluong = soluong;
}

//hàm nhập
istream& operator>>(istream& is, sach& s) {
    cout << "Nhap ten sach: ";
    fflush(stdin);
    getline(is, s.tensach);
    cout << "Nhap tac gia: ";
    fflush(stdin);
    getline(is, s.tacgia);
    cout << "Nhap nha xuat ban: ";
    fflush(stdin);
    getline(is, s.nxb);
    cout << "Nhap ma sach: ";
    fflush(stdin);
    getline(is, s.masach);
    do {
        cout << "Nhap nam xuat ban: ";
        is >> s.namxuatban;
        if (s.namxuatban < 1500 || s.namxuatban > 2023) {
            cout << "Nam khong hop le. Vui long nhap lai!" << endl;
        }
    } while (s.namxuatban < 1500 || s.namxuatban > 2023);
    do {
        cout << "Nhap ngay, thang, nam vao kho: ";
        is >> s.ngay >> s.thang >> s.nam;
        if (!datecheck(s.ngay, s.thang, s.nam)) {
            cout << "Ngay thang nam khong hop le. Vui long nhap lai!" << endl;
        }
    } while (!datecheck(s.ngay, s.thang, s.nam));
    do {
        cout << "Nhap so luong: ";
        is >> s.soluong;
        if (s.soluong < 0) {
            cout << "So luong khong hop le. Vui long nhap lai!" << endl;
        }
    } while (s.soluong < 0);
    return is;
}

//Hàm xuất
ostream& operator<<(ostream& os,sach &s){
   os<<setw(50)<<left<<s.tensach<<"\t";
   os<<setw(20)<<left<<s.tacgia<<"\t";
   os<<setw(20)<<left<<s.nxb<<"\t";
   os<<setw(15)<<left<<s.namxuatban<<"\t";
   os<<setw(9)<<left<<s.masach<<"\t";
   os<<setw(12)<<left<<s.soluong<<"\t";
   os<<s.ngay<<"/"<<s.thang<<"/"<<s.nam<<endl;
   return os;
}

//Hàm đọc file của lớp sách
void sach::doc(ifstream &read){
        getline(read, tensach, ',');
        getline(read, tacgia, ',');
        getline(read, nxb, ',');
        getline(read, masach, ',');
        read >> namxuatban;
        read.ignore();
        read >> ngay;
        read.ignore();
        read >> thang;
        read.ignore();
        read >> nam;
        read.ignore();
        read >> soluong;
        read.ignore();
}

//Hàm ghi file của lớp sách
void sach::ghi(ofstream &write){
      write<<tensach<<",";
      write<<tacgia<<",";
      write<<nxb<<",";
      write<<masach<<",";
      write<<namxuatban<<",";
      write<<ngay<<",";
      write<<thang<<",";
      write<<nam<<",";
      write<<soluong<<endl;
   }

//Hàm tìm kiếm với tham chiếu vào là các đối tượng sách 
void sach::timkiem(vector<sach> &listsach) {
    string tim;
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    cout<<"<        TIM KIEM        <"<<endl;
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    cout<<"Nhap tu khoa can tim: ";
    fflush(stdin);
    getline(cin, tim);
    //chuyển chuỗi về chữ thường
    transform(tim.begin(),tim.end(),tim.begin(),::tolower);
    bool temp = false;
    int dem = 0;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(50) << left << "|Ten sach|" << "\t"
         << setw(20) << left << "|Tac gia|" << "\t"
         << setw(20) << left << "|Nha xuat ban|" << "\t"
         << setw(15) << left << "|Nam xuat ban|" << "\t"
         << setw(9) << left << "|Ma sach|" << "\t"
         << setw(12) << left << "|so luong|" << "\t"
         << setw(12) << left << "|Ngay nhap|" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < listsach.size(); i++) {
        string ten = listsach[i].gettensach();
        transform(ten.begin(),ten.end(),ten.begin(),::tolower); 
        string tg  = listsach[i].gettacgia();
        transform(tg.begin(),tg.end(),tg.begin(),::tolower);
        string nxban = listsach[i].getnhaxuatban(); 
        transform(nxban.begin(),nxban.end(),nxban.begin(),::tolower);
        string code = listsach[i].getmasach();
        transform(code.begin(),code.end(),code.begin(),::tolower);
        int namtb = listsach[i].getnamxuatban();
        //Kiểm tra chuỗi tim có xuất hiện trong chuỗi gốc hay không. string::npos là một hằng số có giá trị đặc biệt trong string và đại diện cho việc không tìm thấy trong chuỗi
        if (ten.find(tim) != string::npos || tg.find(tim) != string::npos || nxban.find(tim) != string::npos || code.find(tim) != string::npos || to_string(namtb).find(tim) != string::npos) {
            temp = true;
            dem++;
            cout << "|";
            cout<<listsach[i];
        }
    }
    if (temp == true) {
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "**Da tim thay " << dem << " thong tin chua tu khoa '" << tim << "'!**" << endl;
        cout << "**An phim bat ki de tro lai menu!**" << endl;
    } else {
        cout << "**Khong tim thay sach voi tu khoa '"<<tim<<"' hoac ban nhap sai. An phim bat ki de ve menu chinh!**" << endl;
    }
}

//Hàm sửa sách
void sach::suasach(vector<sach> &listsach){
   string suasach;
   int chon;
   string check;
   bool temp = false;
   cout<<"Chon thuoc tinh can sua(1: Ten sach,2: Tac gia,3: Nha xuat ban,4: Nam xuat ban ): ";
   cin>>chon;
   if(chon == 1){
         cout<<"Nhap ma sach cua sach can sua: ";
         cin>>check;
         for(int i = 0 ; i< listsach.size()  ;i++){
            if(listsach[i].getmasach() == check){
               temp = true;
               cout<<"Nhap ten sach moi: ";
               fflush(stdin);
               getline(cin,suasach);
               listsach[i].settensach(suasach);
            }
         }
      } else if(chon ==2){
         cout<<"Nhap ma sach cua sach can sua: ";
         cin>>check;
         for(int i = 0 ; i< listsach.size()  ;i++){
            if(listsach[i].getmasach() == check){
               temp = true;
               cout<<"Nhap tac gia moi: ";
               fflush(stdin);
               getline(cin,suasach);
               listsach[i].settacgia(suasach);
            }
         }
      } else if(chon == 3){
         cout<<"Nhap ma sach cua sach can sua: ";
         cin>>check;
         for(int i = 0 ; i< listsach.size()  ;i++){
            if(listsach[i].getmasach() == check){
               temp = true;
               cout<<"Nhap nha xuat ban moi: ";
               fflush(stdin);
               getline(cin,suasach);
               listsach[i].setnxb(suasach);
            }
         }
      } else if(chon == 4){
         cout<<"Nhap ma sach cua sach can sua: ";
         cin>>check;
         for(int i = 0 ; i< listsach.size()  ;i++){
            if(listsach[i].getmasach() == check){
               temp = true;
               cout<<"Nhap nam xuat ban moi: ";
               fflush(stdin);
               getline(cin,suasach);
               listsach[i].setnamxuatban(stoi(suasach));
            }
         }
      } 
    if(temp == true){
      cout<<"Sua sach thanh cong.An phim bat ki de ve menu truoc!"<<endl;
   }else{
      cout<<"**Sua khong thanh cong. An phim bat ki de ve menu truoc!**"<<endl;
   }
      
}

//Hàm xoá sách
void sach::xoasach(vector<sach> &listsach ){
   string xoamasach;
   string kiemtra;
   int n;
   do{
        cout<<"Nhap so luong sach can xoa: ";
        cin>>n;
        if(n < 0 || n > listsach.size()){
            cout<<"So luong khong hop le. Vui long nhap lai!"<<endl;
        }
   }while(n < 0 || n > listsach.size());
   bool temp = false;
   for(int i = 0 ; i< n ;i++){
      cout<<"Nhap ma sach can xoa thu "<<i+1<<": ";
      cin>>xoamasach;
      cout << "Ban co chac muon xoa cac sach nay? (Y/N): ";
      cin >> kiemtra;
      for(int j = 0 ; j < listsach.size();j++){
         if(listsach[j].getmasach() == xoamasach && (kiemtra == "Y" || kiemtra == "y")){
               temp = true;
               //Xoá phần tử thứ j
               listsach.erase(listsach.begin()+j);
         }
      }
   }
   if(temp == true){
      cout<<"Xoa sach co ma sach '"<<xoamasach<<"' thanh cong.An phim bat ki de ve menu truoc!"<<endl;
   }else{
      cout<<"**Xoa khong thanh cong. An phim bat ki de ve menu truoc!**"<<endl;
   }
}

void sach::sapxepsach(vector<sach> &listsach,int &chon){
   if(chon == 1){
      for(int i  = 0 ; i< listsach.size()-1 ; i++ ){
         for(int j = i + 1;  j < listsach.size() ; j++ ){
            if(listsach[i].gettensach() > listsach[j].gettensach()){
               sach temp = listsach[i];
               listsach[i] =listsach[j];
               listsach[j] = temp;
            }
         }
      }
   } else if(chon == 2){
      for(int i = 0 ; i < listsach.size() - 1 ; i++){
         for(int j = i +1; j < listsach.size(); j++ ){
         if(listsach[i].getnamxuatban() > listsach[j].getnamxuatban()){
               sach temp = listsach[i] ;
               listsach[i] = listsach[j];
               listsach[j] = temp;
         }
         }
      }
   } else if(chon == 3) {
      for(int i = 0 ; i < listsach.size() - 1 ; i++){
         for(int j = i +1; j < listsach.size(); j++ ){
         if(listsach[i].getnamxuatban() < listsach[j].getnamxuatban()){
               sach temp = listsach[i] ;
               listsach[i] = listsach[j];
               listsach[j] = temp;
         }
         }
      }
   } else if(chon == 4 ){
      for(int i  = 0 ; i< listsach.size()-1 ; i++ ){
         for(int j = i + 1; j < listsach.size() ; j++ ){
            if(listsach[i].getsoluong() > listsach[j].getsoluong()){
               sach temp = listsach[i];
               listsach[i] =listsach[j];
               listsach[j] = temp;
            }
         }
      }
   } else if(chon == 5) {
      for(int i  = 0 ; i< listsach.size()-1 ; i++ ){
         for(int j = i + 1;  j < listsach.size() ; j++ ){
            if(listsach[i].getsoluong() < listsach[j].getsoluong()){
               sach temp = listsach[i];
               listsach[i] =listsach[j];
               listsach[j] = temp;
            }
         }
      }
   } 
   
}

//hàm xuất list sách
void sach::xuatlistsach(vector<sach> &listsach){
   cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   cout<<setw(50)<<left<<"|Ten sach|"<<"\t"
       <<setw(20)<<left<<"|Tac gia|"<<"\t"
       <<setw(20)<<left<<"|Nha xuat ban|"<<"\t"
       <<setw(15)<<left<<"|Nam xuat ban|"<<"\t"
       <<setw(9)<<left<<"|Ma sach|"<<"\t"
       <<setw(12)<<left<<"|so luong|"<<"\t"
       <<setw(12)<<left<<"|Ngay nhap|"<<endl;
   cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
      for(int i = 0 ; i< listsach.size() ; i++){
         cout<<"|";
         cout<<listsach[i];

      }
   cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;    

}
//Lớp bạn đọc
class bandoc: public sach{
      string hoten;
      string masachmuon;
      string mabandoc;
      string email;
      int namsinh;
      int ngaymuon;
      int thangmuon;
      int nammuon;
   public:
      bandoc(){
         masachmuon ="";
         hoten = "";
         mabandoc = "";
         namsinh = 0;
         email = "";
         ngaymuon = 0;
         thangmuon = 0;
         nammuon = 0;
      }
      ~bandoc(){};

      bandoc(string hoten,string masachmuon,string mabandoc, string email,int namsinh,int ngaymuon, int thangmuon , int nammuon ){
            this->hoten = hoten;
            this->masachmuon = masachmuon;
            this->mabandoc = mabandoc ;
            this->email = email;
            this->namsinh = namsinh;
            this->ngaymuon = ngaymuon;
            this->thangmuon = thangmuon;
            this->nammuon = nammuon;
      }

	   void setmsm(string masachmuon);
      void setnamsinh(int namsinh);
      void sethoten(string hoten);
      void setmabandoc(string mabanndoc);
      void setemail(string email);
      void setngaymuon(int ngaymuon);
      void setthangmuon(int thangmuon);
      void setnammuon(int nammuon);
		   
      string gethoten(){
         return hoten;
      }
      string getmabandoc(){
         return mabandoc;
      }
      string getemail(){
         return email;
      }
      string getmsm(){
         return masachmuon;
      }
      int getnamsinh(){
         return namsinh;
      }
      int getngaymuon(){
        return ngaymuon;
      }
      int getthangmuon(){
        return thangmuon;
      }
      int getnammuon(){
        return nammuon;
      }

      friend istream& operator>>(istream& is,bandoc &b);
      friend ostream& operator<<(ostream& os,bandoc &b);
      void docbd(ifstream &dbd);
      void ghibd(ofstream &gbd);
      void timkiembd(vector<bandoc> &listbandoc);
      void suabd(vector<bandoc> &listbandoc);
      void xoabd(vector<bandoc> &listbandoc);
      void muonsach(bandoc b[],int bd,vector<sach> &listsach,vector<bandoc> &listbandoc);
      void trasach(vector<sach> &listsach, vector<bandoc> &listbandoc);
      void xuatlistbandoc(vector<bandoc> &listbandoc);
      void sapxepbandoc(vector<bandoc> &listbandoc,int &chon);
      void kiemtratrasach(vector<bandoc> &listbandoc,int &ngaytra,int &thangtra,int &day, int &month);
      bool datescheck(){
         return datecheck(ngaymuon,thangmuon,nammuon);
      }
      bool sosanhngay(int &ngaytra,int &thangtra,int &day, int &month);
};

//setter
void bandoc::setmsm(string masachmuon){
		   this->masachmuon = masachmuon;
	   }
void bandoc::setnamsinh(int namsinh){
   this->namsinh = namsinh;
}
void bandoc::sethoten(string hoten){
		   this->hoten = hoten;
	   }
void bandoc::setmabandoc(string mabandoc){
		   this->mabandoc = mabandoc;
	   }
void bandoc::setemail(string email){
		   this->email = email;
	   }
void bandoc::setngaymuon(int ngaymuon){
		   this->ngaymuon = ngaymuon;
	   }
void bandoc::setthangmuon(int thangmuon){
		   this->thangmuon = thangmuon;
	   }
void bandoc::setnammuon(int nammuon){
		   this->nammuon = nammuon;
	   }

//Hàm nhập ttin bạn đọc
istream& operator>>(istream& is,bandoc &b){
    cout<<"Nhap ho va ten cua ban doc: ";
    fflush(stdin);
    getline(is,b.hoten);
    do{
    cout<<"Nhap nam sinh cua ban doc: ";
    is>>b.namsinh;
    if(b.namsinh < 0 || b.namsinh >2023){
      cout<<"Vui long nhap lai"<<endl;
    }
    }while(b.namsinh < 0 || b.namsinh > 2023);
    cout<<"Nhap email cua ban doc: ";
    fflush(stdin);
    getline(is,b.email);
    cout<<"Nhap ma ban doc: ";
    fflush(stdin);
    getline(is,b.mabandoc);
    do {
        cout << "Nhap ngay, thang, nam muon sach: ";
        is >> b.ngaymuon >> b.thangmuon >> b.nammuon;
        if (!datecheck(b.ngaymuon,b.thangmuon,b.nammuon)) {
            cout << "Ngay thang nam khong hop le. Vui long nhap lai!" << endl;
        }
    } while (!datecheck(b.ngaymuon,b.thangmuon,b.nammuon));
   return is;
}

//Hàm xuất ttin bạn đọc
ostream& operator<<(ostream& os,bandoc &b){
   os<<setw(20)<<left<<b.hoten<<"\t";
   os<<setw(20)<<left<<b.namsinh<<"\t";
   os<<setw(20)<<left<<b.email<<"\t";
   os<<setw(20)<<left<<b.mabandoc<<"\t";
   os<<setw(20)<<left<<b.masachmuon<<"\t";
   os<<b.ngaymuon<<"/"<<b.thangmuon<<"/"<<b.nammuon<<endl;
   return os;
}

//Hàm đọc file bạn đọc
void bandoc::docbd(ifstream &dbd){
        getline(dbd, hoten, ',');
        dbd >> namsinh;
        dbd.ignore();
        getline(dbd, email, ',');
        getline(dbd, mabandoc, ',');
        getline(dbd, masachmuon, ',');
        dbd >> ngaymuon;
        dbd.ignore();
        dbd >> thangmuon;
        dbd.ignore();
        dbd >> nammuon;
        dbd.ignore();
}

//Hàm ghi file bạn đọc
void bandoc::ghibd(ofstream &gbd){
      gbd<<hoten<<",";
      gbd<<namsinh<<",";
      gbd<<email<<",";
      gbd<<mabandoc<<",";
      gbd<<masachmuon<<",";
      gbd<<ngaymuon<<",";
      gbd<<thangmuon<<",";
      gbd<<nammuon<<endl;
}

//Hàm tìm kiếm thông tin sách đang được mượn
void bandoc::timkiembd(vector<bandoc>& listbandoc) {
    string tim;
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    cout<<"<        TIM KIEM        <"<<endl;
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    cout<<"Nhap tu khoa can tim: ";
    fflush(stdin);
    getline(cin, tim);
    transform(tim.begin(),tim.end(),tim.begin(),::tolower);
    bool temp = false;
    int dem = 0;
    cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(20)<<left<<"|Ten|"<<"\t"
        <<setw(20)<<left<<"|Nam sinh|"<<"\t"
        <<setw(20)<<left<<"|Email|"<<"\t"
        <<setw(20)<<left<<"|Ma ban doc|"<<"\t"
        <<setw(20)<<left<<"|Ma sach muon|"<<"\t"
        <<setw(20)<<left<<"|Ngay muon|"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for (int i = 0; i < listbandoc.size(); i++) {
        string ten = listbandoc[i].gethoten();
        transform(ten.begin(),ten.end(),ten.begin(),::tolower); 
        string ma  = listbandoc[i].getmabandoc();
        transform(ma.begin(),ma.end(),ma.begin(),::tolower);
        string masm = listbandoc[i].getmsm(); 
        transform(masm.begin(),masm.end(),masm.begin(),::tolower);
        string mail = listbandoc[i].getemail();
        transform(mail.begin(),mail.end(),mail.begin(),::tolower);
        int nsinh = listbandoc[i].getnamsinh();
        if (ten.find(tim) != string::npos || ma.find(tim) != string::npos || masm.find(tim) != string::npos || mail.find(tim) != string::npos || to_string(nsinh).find(tim) != string::npos) {
            temp = true;
            dem++;
            cout << "|"<<listbandoc[i];
        }
    }
    if (temp == true) {
        cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout << "**Da tim thay " << dem << " thong tin chua tu khoa '" << tim << "'!**" << endl;
        cout << "**An phim bat ki de tro lai menu!**" << endl;
    } else {
        cout << "**Khong tim thay sach voi tu khoa '"<<tim<<"' hoac ban nhap sai. An phim bat ki de ve menu chinh!**" << endl;
    }
}

//Hàm mượn sách
void bandoc::muonsach(bandoc b[],int bd,vector<sach> &listsach,vector<bandoc> &listbandoc){
		string ms;
		cout<<"Nhap ma sach can muon: ";
		cin>>ms;
      bool temp = false;
		for(int i = 0 ; i < listsach.size() ; i ++){
			if(listsach[i].getmasach() == ms && listsach[i].getsoluong() > 0 ){
            temp = true;
				int sl =listsach[i].getsoluong();
				sl--;
            listsach[i].setsoluong(sl);
				for(int j = 0 ; j < bd ; j++){
					b[j].setmsm(ms);
               listbandoc.push_back(b[j]);
				}
			} 
		}
       if(temp == true){
            cout<<"Muon sach co ma '"<<ms<<"' thanh cong!"<<endl;
         }else{
            cout<<"Muon sach khong thanh cong hoac sach khong con sach!"<<endl;
         }
}

//Hàm trả sách
void bandoc::trasach(vector<sach> &listsach, vector<bandoc> &listbandoc) {
    string mbd, mst;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
    cout << "<        TRA SACH        <\n";
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
    cout << "**Thong tin sach muon hien co**\n";
    cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(20)<<left<<"|Ten|"<<"\t"
        <<setw(20)<<left<<"|Nam sinh|"<<"\t"
        <<setw(20)<<left<<"|Email|"<<"\t"
        <<setw(20)<<left<<"|Ma ban doc|"<<"\t"
        <<setw(20)<<left<<"|Ma sach muon|"<<"\t"
        <<setw(20)<<left<<"|Ngay muon|"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            for(int i = 0 ; i < listbandoc.size();i++){
               cout<<"|"<<listbandoc[i];
            }
    cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Nhap ma ban doc can tra: ";
    cin>>mbd;
    cout<<"Nhap ma sach can tra: ";
    cin>>mst;
    bool temp =false;
    for(int i = 0 ; i < listbandoc.size(); i++){
        if(listbandoc[i].getmabandoc() == mbd && listbandoc[i].getmsm() == mst){
            temp = true;
            listbandoc.erase(listbandoc.begin() + i);
            for(int j = 0; j < listsach.size(); j++){
                if(listsach[j].getmasach() == mst){
                    int sl = listsach[j].getsoluong();
                    sl++;
                    listsach[j].setsoluong(sl);
                    
                }
            } 
        } 
    }
    if(temp == true){
      cout<<"**Tra sach co ma '"<<mst<<"' thanh cong. An phim bat ki de tro lai menu!"<<endl;
   } else {
      cout<<"**Tra sach khong thanh cong.Vui long thu lai!. An phim bat ki de tro lai menu!"<<endl;
      }
}

//Sửa ttin bạn đọc
void bandoc::suabd(vector<bandoc> &listbandoc){
   string suabd;
   int chon;
   string check;
   bool temp = false;
   cout<<"Chon thuoc tinh can sua(1: Ten ,2: Nam sinh,3: Email,4: Ma ban doc ): ";
   cin>>chon;
   if(chon == 1){
         cout<<"Nhap ma ban doc cua ban doc can sua: ";
         cin>>check;
         for(int i = 0 ; i< listbandoc.size()  ;i++){
            if(listbandoc[i].getmabandoc() == check){
               temp = true;
               cout<<"Nhap ten moi: ";
               fflush(stdin);
               getline(cin,suabd);
               listbandoc[i].sethoten(suabd);
            }
         }
      } else if(chon ==2){
         cout<<"Nhap ma ban doc cua ban doc can sua: ";
         cin>>check;
         for(int i = 0 ; i< listbandoc.size()  ;i++){
            if(listbandoc[i].getmabandoc() == check){
               temp = true;
               cout<<"Nhap nam sinh moi: ";
               fflush(stdin);
               getline(cin,suabd);
               listbandoc[i].setnamsinh(stoi(suabd));
            }
         }
      } else if(chon == 3){
         cout<<"Nhap ma ban doc cua ban doc can sua: ";
         cin>>check;
         for(int i = 0 ; i< listbandoc.size()  ;i++){
            if(listbandoc[i].getmabandoc() == check){
               temp = true;
               cout<<"Nhap email moi: ";
               fflush(stdin);
               getline(cin,suabd);
               listbandoc[i].setemail(suabd);
            }
         }
      } else if(chon == 4){
         cout<<"Nhap ma ban doc cua ban doc can sua: ";
         cin>>check;
         for(int i = 0 ; i< listbandoc.size()  ;i++){
            if(listbandoc[i].getmabandoc() == check){
               temp = true;
               cout<<"Nhap ma ban doc moi: ";
               fflush(stdin);
               getline(cin,suabd);
               listbandoc[i].setmabandoc(suabd);
            }
         }
      }
    if(temp == true){
      cout<<"Sua sach thanh cong.An phim bat ki de ve menu truoc!"<<endl;
   }else{
      cout<<"**Sua khong thanh cong. An phim bat ki de ve menu truoc!**"<<endl;
   }
      
}

//Hàm sắp xếp
void bandoc::sapxepbandoc(vector<bandoc> &listbandoc,int &chon){
   if(chon == 1){
      for(int i  = 0 ; i< listbandoc.size()-1 ; i++ ){
         for(int j = i + 1;  j < listbandoc.size() ; j++ ){
            if(listbandoc[i].gethoten() > listbandoc[j].gethoten()){
               bandoc temp = listbandoc[i];
               listbandoc[i] =listbandoc[j];
               listbandoc[j] = temp;
            }
         }
      }
   } else if(chon == 2){
      for(int i = 0 ; i < listbandoc.size() - 1 ; i++){
         for(int j = i +1; j < listbandoc.size(); j++ ){
         if(listbandoc[i].getnamsinh() > listbandoc[j].getnamsinh()){
               bandoc temp = listbandoc[i] ;
               listbandoc[i] = listbandoc[j];
               listbandoc[j] = temp;
         }
         }
      }
   } else {
      for(int i = 0 ; i < listbandoc.size() - 1 ; i++){
         for(int j = i +1; j < listbandoc.size(); j++ ){
         if(listbandoc[i].getnamsinh() < listbandoc[j].getnamsinh()){
               bandoc temp = listbandoc[i] ;
               listbandoc[i] = listbandoc[j];
               listbandoc[j] = temp;
         }
         }
      }
   }
   
}

//hàm xuất list bạn đọc 
void bandoc::xuatlistbandoc(vector<bandoc> &listbandoc){
   cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   cout<<setw(20)<<left<<"|Ten|"<<"\t"
       <<setw(20)<<left<<"|Nam sinh|"<<"\t"
       <<setw(20)<<left<<"|Email|"<<"\t"
       <<setw(20)<<left<<"|Ma ban doc|"<<"\t"
       <<setw(20)<<left<<"|Ma sach muon|"<<"\t"
       <<setw(20)<<left<<"|Ngay muon|"<<endl;
   cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
         for(int i = 0 ; i < listbandoc.size();i++){
             cout<<"|"<<listbandoc[i];
         }
   cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}

void xoazero(vector<sach> &listsach,vector<bandoc> &listbandoc ){
      for(int i = 0 ; i < listsach.size();i++){
         if(listsach[i].getngay() == 0){
            listsach.erase(listsach.begin()+i);
         }
      }
      for(int j = 0 ; j < listbandoc.size();j++){
         if(listbandoc[j].getnamsinh() == 0){
            listbandoc.erase(listbandoc.begin()+j);
         }
      }
}

//Hàm đọc file
void docfile(vector<sach> &listsach,vector<bandoc> &listbandoc,string &readaccount,string &readpassword){
    ifstream read;
      read.open("sach.txt");
      while(!read.eof()){
         sach temp;
         temp.doc(read);
         listsach.push_back(temp);
         if(read.eof() == true){
            break;
         }
      }
      read.close();

   ifstream dbd;
      dbd.open("bandoc.txt");
      while(!dbd.eof()){
         bandoc temp;
         temp.docbd(dbd);
         listbandoc.push_back(temp);
         if(dbd.eof() == true){
            break;
         }
      }
      dbd.close(); 
   ifstream fileacc;
      fileacc.open("account.txt");
      fileacc>>readaccount>>readpassword;
      fileacc.close();
}

//Hàm ghi file
void ghifile(vector<sach> &listsach,vector<bandoc> &listbandoc){
    ofstream write;
    write.open("sach.txt");
    for (int i = 0; i < listsach.size(); i++) {
        listsach[i].ghi(write);
    }
    write.close();

    ofstream gbd;
      gbd.open("bandoc.txt");
      for(int i = 0 ; i < listbandoc.size();i++){
         listbandoc[i].ghibd(gbd);
      }
      gbd.close();
}

//Hàm lấy ngày tháng năm hiện tại
void datesnow(int &day, int &month, int &year) {
    time_t now = time(nullptr);
    tm* timeinfo = localtime(&now);
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon + 1;
    year = timeinfo->tm_year + 1900;
}

//Hàm kiểm tra sách quá hạn
bool bandoc::sosanhngay(int &ngaytra,int &thangtra,int &day, int &month){
      if(thangtra < month || (thangtra == month && ngaytra <  day) ){
         return false;
      } else {
         return true;
      }
   }

//Hàm kiểm tra ngày trả sách
void bandoc::kiemtratrasach(vector<bandoc> &listbandoc,int &ngaytra,int &thangtra,int &day, int &month){
   cout<<"**DANH SACH BAN DOC CHUA TRA SACH DUNG HAN**"<<endl;
   cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   cout<<setw(20)<<left<<"|Ten|"<<"\t"
       <<setw(20)<<left<<"|Nam sinh|"<<"\t"
       <<setw(20)<<left<<"|Email|"<<"\t"
       <<setw(20)<<left<<"|Ma ban doc|"<<"\t"
       <<setw(20)<<left<<"|Ma sach muon|"<<"\t"
       <<setw(20)<<left<<"|Ngay muon|"<<endl;
   cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   int dem = 0;
   for(int i = 0 ; i < listbandoc.size() ;i++){
    if (listbandoc[i].getthangmuon() == 12) {
      if (listbandoc[i].getngaymuon() == 31) {
         ngaytra = 1;
         thangtra = listbandoc[i].getthangmuon() + 3;
      } else {
         ngaytra = 60 - (31 - listbandoc[i].getngaymuon()) - 31;
         thangtra = listbandoc[i].getthangmuon() + 2;
      }
   } else if (listbandoc[i].getthangmuon() == 1) {
      if (listbandoc[i].getngaymuon() == 31) {
         ngaytra = 1;
         thangtra = listbandoc[i].getthangmuon() + 3;
      } else {
         ngaytra = 60 - (31 - listbandoc[i].getngaymuon()) - 28;
         thangtra = listbandoc[i].getthangmuon() + 2;
      }
   } else if (listbandoc[i].getthangmuon() == 2) {
      ngaytra = 60 - (28 - listbandoc[i].getngaymuon()) - 31;
      thangtra = listbandoc[i].getthangmuon() + 2;
   } else if (listbandoc[i].getthangmuon() == 3 || listbandoc[i].getthangmuon() == 5 || listbandoc[i].getthangmuon() == 7 || listbandoc[i].getthangmuon() == 8 || listbandoc[i].getthangmuon() == 10) {
      if (listbandoc[i].getngaymuon() == 1) {
         ngaytra = 30;
         thangtra = listbandoc[i].getthangmuon() + 1;
      } else {
         ngaytra = 60 - (31 - listbandoc[i].getngaymuon()) - 30;
         thangtra = listbandoc[i].getthangmuon() + 2;
      }
   } else if (listbandoc[i].getthangmuon() == 4 || listbandoc[i].getthangmuon() == 6 || listbandoc[i].getthangmuon() == 9 || listbandoc[i].getthangmuon() == 11) {
      if (listbandoc[i].getngaymuon() == 1) {
         ngaytra = 31;
         thangtra = listbandoc[i].getthangmuon() + 1;  
      } else {
         ngaytra = 60 - (30 - listbandoc[i].getngaymuon()) - 31;
         thangtra = listbandoc[i].getthangmuon() + 2;
      }
   }
   if(!sosanhngay(ngaytra,thangtra,day,month)){
      cout<<"|"<<listbandoc[i];
      dem++;
   }
}
   cout<<"--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   cout<<"*Co "<<dem<<" ban doc chua tra sach dung han**"<<endl;
   cout<<"An phim bat ki de tro ve Menu chinh!"<<endl;
}

int main(){
   int day,month,year,ngaytra,thangtra;
   datesnow(day,month,year);
   string account,readaccount;
   string password,readpassword;
   sach s[MAX_SACH];
   bandoc b[MAX_SACH/2];
   int luachon;
   vector<sach> listsach;
   vector<bandoc> listbandoc;
   ofstream write;
   ofstream gbd;
   docfile(listsach,listbandoc,readaccount ,readpassword);
   xoazero(listsach,listbandoc);
   menudangnhap:
      cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
      cout<<">        DANG NHAP       >"<<endl;
      cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
      cout<<"User Name: ";
      cin>>account;
      cout<<"Password: ";
      cin>>password;
      if (account == readaccount && password == readpassword) {
        system("cls");
        setColor(2);
        cout << "Dang nhap thanh cong!" << endl;
        resetColor();
        goto menuthuvien;
    } else {
        system("cls");
        setColor(1);
        cout << "Tai khoan hoac mat khau chua chinh xac vui long nhap lai!" << endl;
        resetColor();
        goto menudangnhap;
    }
   menuthuvien:
      cout << "|---------------------------------------------|" << endl;
      cout << "|                QUAN THU VIEN                |" << endl;
      cout << "|---------------------------------------------|" << endl;
      cout << "| 1. Quan ly sach                             |" << endl;
      cout << "| 2. Quan li muon sach                        |" << endl;
      cout << "| 3. Dang xuat                                |" << endl;
      cout << "| 0. Thoat chuong trinh                       |" << endl;
      cout << "===============================================" << endl;
   do{
   cout<<"\nVui long nhap lua chon cua ban(0,1,2,3): ";
   cin>>luachon;
   if(luachon < 0 || luachon > 3){
      setColor(1);
      cout<<"**Lua chon chua hop le. Vui long nhap lai!**";
      resetColor();
   }
   }while(luachon < 0 || luachon > 3);
   switch(luachon){
   case 1:
      system("cls");
      goto menusach;
      break;
   case 2:
      system("cls");
      goto menubandoc;
      break;
   case 3:
      system("cls");
      goto menudangnhap;
      break;
   case 0:
      system("cls");
      cout<<"+KET THUC CHUONG TRINH. AN PHIM BAT KI DE THOAT!+"<<endl;
      exit('0');
   }
   menusach: 
      cout << "|---------------------------------------------|" << endl;
      cout << "|                QUAN LY SACH                 |" << endl;
      cout << "|---------------------------------------------|" << endl;
      cout << "| 1. Nhap them sach                           |" << endl;
      cout << "| 2. Xuat sach dang duoc quan ly              |" << endl;
      cout << "| 3. Tim kiem sach                            |" << endl;
      cout << "| 4. Xoa sach                                 |" << endl;
      cout << "| 5. Sua sach                                 |" << endl;
      cout << "| 6. Quay tro lai menu truoc                  |" << endl;
      cout << "| 0. Thoat chuong trinh                       |" << endl;
      cout << "===============================================" << endl;
   do{
   cout<<"\nVui long nhap lua chon cua ban(0,1,2,3,4,5,6): ";
   cin>>luachon;
   if(luachon < 0 || luachon > 6){
      setColor(1);
      cout<<"Lua chon chua hop le. Vui long nhap lai!"<<endl;
      resetColor();
   }
   }while(luachon < 0 || luachon > 6);
   switch (luachon)
   {
   case 1:
      system("cls");
      int n;
      cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
      cout<<">        NHAP SACH       >"<<endl;
      cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
      cout<<"Nhap so sach can nhap vao: ";
      cin>>n;
      if(n > 0){
      for(int i = 0 ; i< n ; i++){
         cout<<"**Nhap quyen sach thu "<<i+1<<"**"<<endl;
         cin>>s[i];
         listsach.push_back(s[i]);
      }
      ghifile(listsach,listbandoc);

      } else {
         system("cls");
         cout<<"Nhap khong thanh cong!"<<endl;
         goto menusach;
      }
      setColor(2);
      cout<<"**Nhap thanh cong. An phim bat ki de tiep tuc**"<<endl;
      resetColor();
      system("pause");
      system("cls");
      goto menusach;
      break;
   case 2:
      system("cls");
      int chon;
      cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
      cout<<"<        XUAT SACH       <"<<endl;
      cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
      s[MAX_SACH].xuatlistsach(listsach);
      cout<<"So luong sach dang quan li: "<<listsach.size()<<endl;
      setColor(2);
      cout<<"**Xuat thanh cong. Vui long chon thao tac tiep theo!**"<<endl;
      resetColor();
      cout<<"**1. Sap xep theo ten sach              **"<<endl;
      cout<<"**2. Sap xep theo nam xuat ban tang dan **"<<endl;
      cout<<"**3. Sap xep theo nam xuat ban giam dan **"<<endl;
      cout<<"**4. Sap xep theo so luong tang dan     **"<<endl;
      cout<<"**5. Sap xep theo so luong giam dan     **"<<endl;
      cout<<"**0. Quay tro lai menu truoc            **"<<endl;
      do{
      cout<<"==>> ";
      cin>>chon;
      if(chon < 0 || chon > 5){
         setColor(1);
         cout<<"Lua chon khong hop le vui long nhap lai!";
         resetColor();
      } else if(chon == 0 ){
         system("cls");
         goto menusach;
      } else{
         s[MAX_SACH].sapxepsach(listsach,chon);
      }
      }while(chon < 0 || chon > 5);
      system("cls");
      setColor(2);
      cout<<"**Sap xep thanh cong!**"<<endl;
      resetColor();
      s[MAX_SACH].xuatlistsach(listsach);
      cout<<"An phim bat ki de tro ve menu truoc!"<<endl;
      system("pause");
      system("cls");
      goto menusach;
      break;
   case 3:
      system("cls");
      s[MAX_SACH].timkiem(listsach);
      system("pause");
      system("cls");
      goto menusach;
      break;
   case 4:
      system("cls");
      cout<<"**Sach hien co trong thu vien**"<<endl;
      s[MAX_SACH].xuatlistsach(listsach);
      s[MAX_SACH].xoasach(listsach);
      ghifile(listsach,listbandoc);
      system("pause");
      system("cls");
      goto menusach;
      break;
   case 5:
      system("cls");
      cout<<"**Sach hien co trong thu vien**"<<endl;
      s[MAX_SACH].xuatlistsach(listsach);
      s[MAX_SACH].suasach(listsach);
      ghifile(listsach,listbandoc);
      system("pause");
      system("cls");
      goto menusach;
      break; 
   case 6:
      system("cls");
      goto menuthuvien;   
      break; 
   case 0:
      system("cls");
      cout<<"+KET THUC CHUONG TRINH. AN PHIM BAT KI DE THOAT!+"<<endl;
      exit('0');
      break;
   }
   menubandoc:
      cout << "|---------------------------------------------|" << endl;
      cout << "|               QUAN LY BAN DOC               |" << endl;
      cout << "|---------------------------------------------|" << endl;
      cout << "| 1. Tao phieu muon sach moi                  |" << endl;
      cout << "| 2. Xuat sach da duoc muon                   |" << endl;
      cout << "| 3. Xuat danh sach ban doc tre han tra sach  |" << endl;
      cout << "| 4. Tim thong tin ban doc                    |" << endl;
      cout << "| 5. Sua thong tin ban doc                    |" << endl;
      cout << "| 6. Tra sach                                 |" << endl;
      cout << "| 7. Quay tro lai menu truoc                  |" << endl;
      cout << "| 0. Thoat chuong trinh                       |" << endl;
      cout << "===============================================" << endl;
      do{
         cout<<"\nVui long nhap lua chon cua ban(0,1,2,3,4,5,6): ";
         cin>>luachon;
      if(luachon < 0 || luachon > 6){
         setColor(1);
         cout<<"**Lua chon chua hop le. Vui long nhap lai!**";
         resetColor();
      }
         }while(luachon < 0 || luachon > 6);
      switch(luachon){
         case 1:
            system("cls");
            cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
            cout<<">            MUON SACH                >"<<endl;
            cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
            int bd;
            cout<<"**So sach hien co trong kho**"<<endl;
            s[MAX_SACH].xuatlistsach(listsach);
            cout<<"Nhap so ban doc can muon sach: ";
            cin>>bd;
            for(int i = 0 ; i< bd; i++){
                cout<<"**Nhap ban doc thu "<<i+1<<"**"<<endl;
                cin>>b[i];
                b[MAX_SACH/2].muonsach(b,bd,listsach,listbandoc);
            }
            ghifile(listsach,listbandoc);
            cout<<"**An phim bat ki de tro ve menu truoc!**"<<endl;
            system("pause");
            system("cls");
            goto menubandoc;
            break;
         case 2:
            system("cls");
            int chon;
            cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
            cout<<"<       XUAT THONG TIN BAN DOC      <"<<endl;
            cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
            b[MAX_SACH/2].xuatlistbandoc(listbandoc);
            cout<<"So thong tin sach muon dang xu li: "<<listbandoc.size()<<endl;
            setColor(2);
            cout<<"**Xuat thanh cong. Vui long chon thao tac tiep theo!**"<<endl;
            resetColor();
            cout<<"**1. Sap xep theo ten nguoi muon    **"<<endl;
            cout<<"**2. Sap xep theo nam sinh tang dan **"<<endl;
            cout<<"**3. Sap xep theo nam sinh giam dan **"<<endl;
            cout<<"**0. Quay tro lai Menu truoc        **"<<endl;
            do{
            cout<<"==>> ";
            cin>>chon;
            if(chon < 0 || chon > 3){
               setColor(1);
               cout<<"Lua chon khong hop le vui long nhap lai!";
               resetColor();
            } else if(chon == 0){
               system("cls");
               goto menubandoc;
            } else{
               b[MAX_SACH/2].sapxepbandoc(listbandoc,chon);
               
            }
            }while(chon < 1 || chon > 3);
            system("cls");
            setColor(2);
            cout<<"**Sap xep thanh cong!**"<<endl;
            resetColor();
            b[MAX_SACH/2].xuatlistbandoc(listbandoc);
            cout<<"An phim bat ki de tro ve menu truoc!"<<endl;
            system("pause");
            system("cls");
            goto menubandoc;
        case 3:
            system("cls");
            b[MAX_SACH/2].kiemtratrasach(listbandoc,ngaytra,thangtra,day,month);
            system("pause");
            system("cls");
            goto menubandoc;
            break;   
        case 4:
            system("cls");
            b[MAX_SACH/2].timkiembd(listbandoc);
            system("pause");
            system("cls");
            goto menubandoc;
            break; 
        case 5:
            system("cls");
            cout << "**Thong tin sach muon hien co**\n";
            b[MAX_SACH/2].xuatlistbandoc(listbandoc);
            b[MAX_SACH/2].suabd(listbandoc);
            ghifile(listsach,listbandoc);
            system("pause");
            system("cls");
            goto menubandoc;
            break;     
        case 6:
            system("cls");
            b[MAX_SACH/2].trasach(listsach,listbandoc);
            ghifile(listsach,listbandoc);
            system("pause");
            system("cls");
            goto menubandoc;
            break;    
        case 7:
            system("cls");
            goto menuthuvien;
            break;
        case 0:
            system("cls");
            cout<<"+KET THUC CHUONG TRINH. AN PHIM BAT KI DE THOAT!+"<<endl;
            system("pause");
            exit('0');
            break;    
      }   
   return 0;
}
