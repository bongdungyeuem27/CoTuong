#pragma once
#include <string.h>
#include <vector>
#include <string>
#include <ctime>
#include<fstream>
#include <iostream>
#include <cstdlib>
#include "source.h"
#include "QuanCo.h"

using namespace std;

//Toạ độ một quân cờ
struct Point
{
public:
    int x; int y;
    Point();
    Point(int a, int b)
    {
        x = a; y = b;
    }
};

//Lớp cha
class QuanCo
{
protected:
    //Giới hạn trái, giới hạn phải, giới hạn dưới, giới hạn trên của kích thước bàn cờ
    int consox1 = 1, consox2 = 9, consoy1 = 1, consoy2 = 10;
    //Giới hạn trái, giới hạn phải, giới hạn dưới, giới hạn trên của con tướng
    int x1, x2, y1, y2;

    //Biến lưu vị trí quân cờ
    Point p;
    //Tên của quân cờ
    string TenQuanCo;
    //Kí hiệu quân cờ
    string kihieuquanco;

    //Biến kiểm tra quân vua 
    bool thua = 0;
    //Mảng lưu các vị trí trống
    vector <Point> trong;
    //Mảng lưu các vị trí chạm đối phương
    vector <Point> cham;
    
    //Con trỏ tới tất cả các quân cờ trắng
    vector <QuanCo*>* trang;

    //Con trỏ tới tất cả các quân cờ đen
    vector <QuanCo*>* den;
     
public:
    //Contructor QuanCo
    QuanCo()
    {
    }

    //B1: Lưu các nước đi cơ bản có thể có của quân cờ nếu ko tính đến các vật cản
    virtual void NuocDiCoBan() = 0;

    //B2: Loại trừ vật cả là giới hạn 4 bên của tường hoặc cung
    virtual void XoaChamTuong();
   
    //B3: Loại trừ vật cản là đồng đội
    void XoaChamDongDoi();

    //B4: Loại trừ vật cản là các quân cờ chặn ở giữa đường đi như mã bị chăn,..
    //Hàm cục bộ của từng đội tượng

    //B5: Loại trừ vật cản là đối phương, và đưa cái vị trí này vào mảng chạm để biết rằng sẽ ăn được các quân này
    void XoaChamDoiPhuong();
    
    //B6.1: Thực hiện kiểm tra các ô có thể di chuyển
    virtual void DiChuyen() = 0;

    //B6.2: Hiển thị các ô đi được   
    void Menu();
 
    //Getter and Setter
    int Getpx();
    int Getpy();
    bool Getthua(); 
    string GetTenQuanCo();
    void Setpx(int a);
    void Setpy(int a);  

    //Xuất ra kí hiệu quân cờ
    virtual void VeQuanCo();
       
    //Detructor
    virtual ~QuanCo();    
};

class Tuong : public QuanCo
{
public:
    
    Tuong();
    //Contructor
    Tuong(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y);

    void NuocDiCoBan();
    void DiChuyen();

    //Detructor
    ~Tuong()
    {
    }
};

class Si : public QuanCo
{
public:
    Si();
    //Contructor
    Si(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y);

    void NuocDiCoBan();
    void DiChuyen();
    
    //Detructor
    ~Si()
    {
    }
};


class Tinh : public QuanCo
{
public:
    Tinh();
    //Contructor
    Tinh(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y);

    void NuocDiCoBan();   
    void XoaBiChan();   
    void DiChuyen();
    
    //Detructor
    ~Tinh()
    {
    }
};


class Ma : public QuanCo
{
public:
    Ma();
    //Contructor
    Ma(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y);
    
    void NuocDiCoBan();
    void XoaBiChan();
    void DiChuyen();
   
    //Detructor
    ~Ma()
    {
    }
};


class Xe : public QuanCo
{
public:
    Xe();
    //Contructor
    Xe(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y);

    void NuocDiCoBan();
    void XoaBiChan();  
    void DiChuyen();
   
    //Detructor
    ~Xe()
    {
    }
};


class Phao : public QuanCo
{
public:
    Phao();
    //Contructor
    Phao(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y);
    
    void NuocDiCoBan();
    void XoaBiChan();
    void DiChuyen();
    
    //Detructor
    ~Phao()
    {
    }
};

class Tot : public QuanCo
{
    int doi;
public:
    Tot();
    //Contructor
    Tot(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y);
    
    void NuocDiCoBan();
    void DiChuyen();

    //Detructor
    ~Tot()
    {
    }
};