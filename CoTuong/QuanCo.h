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

class Point
{
public:
    int x; int y;
    Point();
    Point(int a, int b)
    {
        x = a; y = b;
    }
};
class QuanCo
{
private:
protected:
    int consox1 = 1, consox2 = 9, consoy1 = 1, consoy2 = 10;
    int x1, x2, y1, y2;
    bool thua = 0;
    vector <Point> trong;
    vector <Point> cham;
    vector <QuanCo*>* trang;
    vector <QuanCo*>* den;
    Point p;
    string TenQuanCo;
    string kihieuquanco;
public:
    //1
    QuanCo()
    {

    }

    virtual void NuocDiCoBan() = 0;
    //2
    virtual void XoaChamTuong();
    //3
    void XoaChamDongDoi();
    //5
    void XoaChamDoiPhuong();
    //6
    virtual void DiChuyen() = 0;
    //6.1
    void Menu();
    //Getter and Setter
    int Getpx() { return p.x; }
    int Getpy() { return p.y; }
    bool Getthua()
    {
        return thua;
    }
    string GetTenQuanCo()
    {
        return TenQuanCo;
    }

    void Setpx(int a)
    {
        p.x = a;
    }
    void Setpy(int a)
    {
        p.y = a;
    }
    virtual void VeQuanCo();
       
    
    virtual ~QuanCo()
    {
        trong.clear();
        cham.clear();
    }
};

class Tuong : public QuanCo
{
public:
    Tuong();
    Tuong(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y)
    {
        TenQuanCo = "Tuong";
        kihieuquanco = '+';
        p.x = x; p.y = y;
        if (mau == 0)
        {
            den = team1;
            trang = team2;
            y1 = consoy1, y2 = 3, x1 = 4, x2 = 6;
        }
        else
        {
            den = team2;
            trang = team1;
            y1 = 8, y2 = consoy2, x1 = 4, x2 = 6;
        }
        thua = 1;
        
    }

    void NuocDiCoBan();
    
    void DiChuyen();
    
    ~Tuong()
    {
    }
};

class Si : public QuanCo
{
public:
    Si();
    Si(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y)
    {
        
        TenQuanCo = "Si";
        kihieuquanco = 'O';
        p.x = x; p.y = y;
        
        if (mau == 0)
        {
            den = team1;
            trang = team2;
            y1 = consoy1, y2 = 3, x1 = 4, x2 = 6;
        }
        else
        {
            den = team2;
            trang = team1;
            y1 = 8, y2 = consoy2, x1 = 4, x2 = 6;
        }
    }

    void NuocDiCoBan();

    void DiChuyen();
    
    ~Si()
    {
    }
};


class Tinh : public QuanCo
{
public:
    Tinh();
    Tinh(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y)
    {
       
        TenQuanCo = "Tinh";
        kihieuquanco = '#';
        p.x = x; p.y = y;
        if (mau == 0)
        {
            den = team1;
            trang = team2;
            y1 = consoy1, y2 = 5, x1 = consox1, x2 = consox2;
        }
        else
        {
            den = team2;
            trang = team1;
            y1 = 6, y2 = consoy2, x1 = consox1, x2 = consox2;
        }
    }

    void NuocDiCoBan();
    
    void XoaBiChan();
    
    void DiChuyen();
    
    ~Tinh()
    {
    }
};


class Ma : public QuanCo
{
public:
    Ma();

    Ma(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y)
    {
       
        TenQuanCo = "Ma";
        kihieuquanco = '~';
        p.x = x; p.y = y;
        y1 = consoy1, y2 = consoy2, x1 = consox1, x2 = consox2;
        if (mau == 0)
        {
            den = team1;
            trang = team2;
        }
        else
        {
            den = team2;
            trang = team1;
        }
    }
    void NuocDiCoBan();
    
    void XoaBiChan();
    
    void DiChuyen();
   
    ~Ma()
    {
    }
};


class Xe : public QuanCo
{
public:
    Xe();
    Xe(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y)
    {
       
        TenQuanCo = "Xe";
        kihieuquanco = 'X';
        p.x = x; p.y = y;
        y1 = consoy1, y2 = consoy2, x1 = consox1, x2 = consox2;
        if (mau == 0)
        {
            den = team1;
            trang = team2;
        }
        else
        {
            den = team2;
            trang = team1;
        }
    }

    void NuocDiCoBan();

    void XoaBiChan();
  
    void DiChuyen();
   
    ~Xe()
    {
    }
};


class Phao : public QuanCo
{
public:
    Phao();
    Phao(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y)
    {
       
        TenQuanCo = "Phao";
        kihieuquanco = '@';
        p.x = x; p.y = y;
        y1 = consoy1, y2 = consoy2, x1 = consox1, x2 = consox2;
        if (mau == 0)
        {
            den = team1;
            trang = team2;
        }
        else
        {
            den = team2;
            trang = team1;
        }
    }
    void NuocDiCoBan();

    void XoaBiChan();
  
    void DiChuyen();
    
    ~Phao()
    {
    }
};

class Tot : public QuanCo
{
    int doi;
public:
    Tot();
    Tot(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y)
    {
       

        TenQuanCo = "Tot";
        kihieuquanco = ':';
        p.x = x; p.y = y;
        doi = mau;
        y1 = consoy1, y2 = consoy2, x1 = consox1, x2 = consox2;
        if (mau == 0)
        {
            den = team1;
            trang = team2;
        }
        else
        {
            den = team2;
            trang = team1;
        }
    }
    void NuocDiCoBan();
 
    void DiChuyen();

    ~Tot()
    {
    }
};