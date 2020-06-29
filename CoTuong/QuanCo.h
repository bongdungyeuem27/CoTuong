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
protected:
    int consox1 = 1, consox2 = 9, consoy1 = 1, consoy2 = 10;
    int x1, x2, y1, y2;
    vector <Point> trong;
    vector <Point> cham;
    Point p;
public:
    //1
    virtual void NuocDiCoBan() = 0;
    //2
    virtual void XoaChamTuong(vector<QuanCo*>& trang, vector<QuanCo*>& den );
    //3
    virtual void XoaChamDongDoi(vector<QuanCo*>& trang, vector<QuanCo*>& den) = 0;
    //5
    virtual void XoaChamDoiPhuong(vector<QuanCo*>& trang, vector<QuanCo*>& den) = 0;
    //6
    virtual void DiChuyen(vector<QuanCo*>& trang, vector<QuanCo*>& den) = 0;
    //6.1
    virtual void Menu(vector<QuanCo*>& trang, vector<QuanCo*>& den);
    //Getter and Setter
    int Getpx() { return p.x; }
    int Getpy() { return p.y; }
    void Setpx(int a)
    {
        p.x = a;
    }
    void Setpy(int a)
    {
        p.y = a;
    }
    
    virtual ~QuanCo()
    {
        trong.clear();
        cham.clear();
    }

};

class Den : public QuanCo
{
public:
    //3
    void XoaChamDongDoi(vector<QuanCo*>& trang, vector<QuanCo*>& den);
    //5
    void XoaChamDoiPhuong(vector<QuanCo*>& trang, vector<QuanCo*>& den);

    
    virtual ~Den()
    {
    }

};
/*
class Trang : public QuanCo
{
public:
    //3
    void XoaChamDongDoi(vector<QuanCo*>& trang, vector<QuanCo*>& den);
    //5
    void XoaChamDoiPhuong(vector<QuanCo*>& trang, vector<QuanCo*>& den);
    //6
    void Menu(vector<QuanCo*>& trang, vector<QuanCo*>& den);
    virtual ~Trang()
    {
    }

};

*/
class TuongDen : public Den
{
private:
protected:

public:
    TuongDen()
    {
        p = Point(5, 1);
        y1 = consox1, y2 = 3, x1 = 4, x2 = 6;
    }

    void NuocDiCoBan()
    {
        trong.push_back(Point(p.x + 1, p.y));
        trong.push_back(Point(p.x - 1, p.y));
        trong.push_back(Point(p.x, p.y + 1));
        trong.push_back(Point(p.x, p.y - 1));
    }

    void DiChuyen(vector<QuanCo*>& trang, vector<QuanCo*>& den)
    {
        NuocDiCoBan();
        XoaChamTuong(trang, den);
        XoaChamDongDoi(trang, den);
        XoaChamDoiPhuong(trang, den);
        Menu(trang, den);
        trong.clear();
        cham.clear();
    }
    ~TuongDen()
    {
    }
};

class SiDen : public Den
{
private:
protected:

public:
    SiDen()
    {
        y1 = consox1, y2 = 3, x1 = 4, x2 = 6;
    }
    SiDen(int a,int b)
    {
        p = Point(a, b);
        y1 = consox1, y2 = 3, x1 = 4, x2 = 6;
    }
    void NuocDiCoBan()
    {
        trong.push_back(Point(p.x + 1, p.y + 1));
        trong.push_back(Point(p.x - 1, p.y + 1));
        trong.push_back(Point(p.x - 1, p.y - 1));
        trong.push_back(Point(p.x + 1, p.y - 1));
    }

    void DiChuyen(vector<QuanCo*>& trang, vector<QuanCo*>& den)
    {
        NuocDiCoBan();
        XoaChamTuong(trang, den);
        XoaChamDongDoi(trang, den);
        XoaChamDoiPhuong(trang, den);
        Menu(trang, den);
        trong.clear();
        cham.clear();
    }
    ~SiDen()
    {
    }
};


class TinhDen : public Den
{
private:
protected:

public:
    TinhDen()
    {
        p = Point(5, 1);
        y1 = consoy1, y2 = 5, x1 = consox1, x2 = consox2;
    }
    TinhDen(int a, int b)
    {
        p = Point(a, b);
        y1 = consoy1, y2 = 5, x1 = consox1, x2 = consox2;
    }
    void NuocDiCoBan()
    {
        trong.push_back(Point(p.x + 2, p.y + 2));
        trong.push_back(Point(p.x - 2, p.y + 2));
        trong.push_back(Point(p.x - 2, p.y - 2));
        trong.push_back(Point(p.x + 2, p.y - 2));
    }
    void XoaBiChan(vector<QuanCo*>& trang, vector<QuanCo*>& den)
    {
        for (int i = 0; i < trong.size(); ++i)
        {
            for (int j = 0; j < den.size(); ++j)
            {
                if ((trong[i].x + p.x == 2 * den[j]->Getpx()) && (trong[i].y + p.y == 2 * den[j]->Getpy()))
                {
                    trong.erase(trong.begin() + i);
                    --j;
                }
            }
            for (int j = 0; j < trang.size(); ++j)
            {
                if ((trong[i].x + p.x == 2 * trang[j]->Getpx()) && (trong[i].y + p.y == 2 * trang[j]->Getpy()))
                {
                    trong.erase(trong.begin() + i);
                    --j;
                }
            }
        }
    }

    void DiChuyen(vector<QuanCo*>& trang, vector<QuanCo*>& den)
    {
        NuocDiCoBan();
        XoaChamTuong(trang, den);
        XoaChamDongDoi(trang, den);
        XoaBiChan(trang, den);
        XoaChamDoiPhuong(trang, den);       
        Menu(trang, den);
        trong.clear();
        cham.clear();
    }
    ~TinhDen()
    {
    }
};


class MaDen : public Den
{
private:
protected:
public:
    MaDen()
    {
        y1 = consoy1, y2 = consoy2, x1 = consox1, x2 = consox2;
    }
    MaDen(int a, int b)
    {
        p = Point(a, b);
        y1 = consoy1, y2 = consoy2, x1 = consox1, x2 = consox2;
    }
    void NuocDiCoBan()
    {
        trong.push_back(Point(p.x + 2, p.y + 1));
        trong.push_back(Point(p.x - 2, p.y + 1));
        trong.push_back(Point(p.x + 2, p.y - 1));
        trong.push_back(Point(p.x - 2, p.y - 1));

        trong.push_back(Point(p.x + 1, p.y + 2));
        trong.push_back(Point(p.x + 1, p.y - 2));
        trong.push_back(Point(p.x - 1, p.y + 2));
        trong.push_back(Point(p.x - 1, p.y - 2));
    }

    void XoaBiChan(vector<QuanCo*>& trang, vector<QuanCo*>& den)
    {
        for (int i = 0; i < den.size(); ++i)
        {
            if (den[i]->Getpx() == p.x + 1 && den[i]->Getpy() == p.y)
                for (int j = 0; j < trong.size(); ++j)
                {
                    if (trong[j].x == p.x + 2)
                    {
                        trong.erase(trong.begin() + j);
                        --j;
                    }
                    
                }
            if (den[i]->Getpx() == p.x - 1 && den[i]->Getpy() == p.y)
                for (int j = 0; j < trong.size(); ++j)
                {
                    if (trong[j].x == p.x - 2)
                    {
                        trong.erase(trong.begin() + j);
                        --j;
                    }

                }
            if (den[i]->Getpx() == p.x && den[i]->Getpy() == p.y + 1)
                for (int j = 0; j < trong.size(); ++j)
                {
                    if (trong[j].y == p.y + 2)
                    {
                        trong.erase(trong.begin() + j);
                        --j;
                    }

                }
            if (den[i]->Getpx() == p.x && den[i]->Getpy() == p.y - 1)
                for (int j = 0; j < trong.size(); ++j)
                {
                    if (trong[j].y == p.y - 2)
                    {
                        trong.erase(trong.begin() + j);
                        --j;
                    }
                }
        }

        for (int i = 0; i < trang.size(); ++i)
        {
            if (trang[i]->Getpx() == p.x + 1 && trang[i]->Getpy() == p.y)
                for (int j = 0; j < trong.size(); ++j)
                {
                    if (trong[j].x == p.x + 2)
                    {
                        trong.erase(trong.begin() + j);
                        --j;
                    }

                }
            if (trang[i]->Getpx() == p.x - 1 && trang[i]->Getpy() == p.y)
                for (int j = 0; j < trong.size(); ++j)
                {
                    if (trong[j].x == p.x - 2)
                    {
                        trong.erase(trong.begin() + j);
                        --j;
                    }

                }
            if (trang[i]->Getpx() == p.x && trang[i]->Getpy() == p.y + 1)
                for (int j = 0; j < trong.size(); ++j)
                {
                    if (trong[j].y == p.y + 2)
                    {
                        trong.erase(trong.begin() + j);
                        --j;
                    }

                }
            if (trang[i]->Getpx() == p.x && trang[i]->Getpy() == p.y - 1)
                for (int j = 0; j < trong.size(); ++j)
                {
                    if (trong[j].y == p.y - 2)
                    {
                        trong.erase(trong.begin() + j);
                        --j;
                    }
                }
        }
    }

    void DiChuyen(vector<QuanCo*>& trang, vector<QuanCo*>& den)
    {
        NuocDiCoBan();
        XoaChamTuong(trang, den);
        XoaChamDongDoi(trang, den);
        XoaBiChan(trang, den);
        XoaChamDoiPhuong(trang, den);      
        Menu(trang, den);
        trong.clear();
        cham.clear();
    }
    ~MaDen()
    {
    }
};


class XeDen : public Den
{
private:
protected:
public:
    XeDen()
    {
        y1 = consoy1, y2 = consoy2, x1 = consox1, x2 = consox2;
    }
    XeDen(int a, int b)
    {
        p = Point(a, b);
        y1 = consoy1, y2 = consoy2, x1 = consox1, x2 = consox2;
    }
    void NuocDiCoBan()
    {
        for (int i = p.x + 1; i <= x2; ++i)
        {
            trong.push_back(Point(i, p.y));
        }

        for (int i = p.x - 1; i >= x1; --i)
        {
            trong.push_back(Point(i, p.y));
        }

        for (int i = p.y + 1; i <= y2; ++i)
        {
            trong.push_back(Point(p.x, i));
        }

        for (int i = p.x - 1; i >= y1; --i)
        {
            trong.push_back(Point(p.x, i));
        }        
    }

    void XoaBiChan(vector<QuanCo*>& trang, vector<QuanCo*>& den)
    {
        for (int i = 0; i < trong.size(); ++i)
        {
            for (int j = 0; j < den.size(); ++j)
            {
                if ((trong[i].x - p.x) > den[j]->Getpx() && p.y == den[j]->Getpy())
                {
                    trong.erase(trong.begin() + j);
                    --j;
                }

                if ((p.x - trong[i].x) > den[j]->Getpx() && p.y == den[j]->Getpy())
                {
                    trong.erase(trong.begin() + j);
                    --j;
                }

                if ((p.y - trong[i].y) > den[j]->Getpy() && p.x == den[j]->Getpx())
                {
                    trong.erase(trong.begin() + j);
                    --j;
                }

                if ((trong[i].y - p.y) > den[j]->Getpy() && p.x == den[j]->Getpx())
                {
                    trong.erase(trong.begin() + j);
                    --j;
                }
            }
        }
    }

    void DiChuyen(vector<QuanCo*>& trang, vector<QuanCo*>& den)
    {
        NuocDiCoBan();
        //XoaChamTuong(trang, den);
        XoaBiChan(trang, den);
        XoaChamDongDoi(trang, den);
        XoaChamDoiPhuong(trang, den);
        Menu(trang, den);
        trong.clear();
        cham.clear();
    }
    ~XeDen()
    {
    }
};