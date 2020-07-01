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
    virtual void VeQuanCo()
    {
        cout << kihieuquanco;

    }   
    
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

    void NuocDiCoBan()
    {
        trong.push_back(Point(p.x + 1, p.y));
        trong.push_back(Point(p.x - 1, p.y));
        trong.push_back(Point(p.x, p.y + 1));
        trong.push_back(Point(p.x, p.y - 1));
    }

    void DiChuyen()
    {
        NuocDiCoBan();
        XoaChamTuong();
        XoaChamDongDoi();
        XoaChamDoiPhuong();
        Menu();
        trong.clear();
        cham.clear();
    }
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

    void NuocDiCoBan()
    {
        trong.push_back(Point(p.x + 1, p.y + 1));
        trong.push_back(Point(p.x - 1, p.y + 1));
        trong.push_back(Point(p.x - 1, p.y - 1));
        trong.push_back(Point(p.x + 1, p.y - 1));
    }

    void DiChuyen()
    {
        NuocDiCoBan();
        XoaChamTuong();
        XoaChamDongDoi();
        XoaChamDoiPhuong();
        Menu();
        //int k; cin >> k;
        trong.clear();
        cham.clear();
    }
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

    void NuocDiCoBan()
    {
        trong.push_back(Point(p.x + 2, p.y + 2));
        trong.push_back(Point(p.x - 2, p.y + 2));
        trong.push_back(Point(p.x - 2, p.y - 2));
        trong.push_back(Point(p.x + 2, p.y - 2));
    }
    void XoaBiChan()
    {
        for(int i = trong.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < den->size(); ++j)
            {
                if ((trong[i].x + p.x == 2 * den->at(j)->Getpx()) && (trong[i].y + p.y == 2 * den->at(j)->Getpy()))
                {
                    trong.erase(trong.begin() + i);
                    break;
                }
            }
            for (int j = 0; j < trang->size(); ++j)
            {
                if ((trong[i].x + p.x == 2 * trang->at(j)->Getpx()) && (trong[i].y + p.y == 2 * trang->at(j)->Getpy()))
                {
                    trong.erase(trong.begin() + i);
                    break;
                }
            }
        }
    }
  
    void DiChuyen()
    {
        NuocDiCoBan();
        XoaChamTuong();
        XoaChamDongDoi();
        XoaBiChan();
        XoaChamDoiPhuong();       
        Menu();
        trong.clear();
        cham.clear();
    }
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

    void XoaBiChan()
    {
        for (int i = 0; i < den->size(); ++i)
        {
            if (den->at(i)->Getpx() == p.x + 1 && den->at(i)->Getpy() == p.y)
                for (int j = trong.size() - 1; j >= 0; j--)
                {
                    if (trong[j].x == p.x + 2)
                    {
                        trong.erase(trong.begin() + j);
                        break;
                    }
                    
                }
            if (den->at(i)->Getpx() == p.x - 1 && den->at(i)->Getpy() == p.y)
                for (int j = trong.size() - 1; j >= 0; j--)
                {
                    if (trong[j].x == p.x - 2)
                    {
                        trong.erase(trong.begin() + j);
                        break;
                    }

                }
            if (den->at(i)->Getpx() == p.x && den->at(i)->Getpy() == p.y + 1)
                for (int j = trong.size() - 1; j >= 0; j--)
                {
                    if (trong[j].y == p.y + 2)
                    {
                        trong.erase(trong.begin() + j);
                        break;
                    }

                }
            if (den->at(i)->Getpx() == p.x && den->at(i)->Getpy() == p.y - 1)
                for (int j = trong.size() - 1; j >= 0; j--)
                {
                    if (trong[j].y == p.y - 2)
                    {
                        trong.erase(trong.begin() + j);
                        break;
                    }
                }
        }

        for (int i = 0; i < trang->size(); ++i)
        {
            if (trang->at(i)->Getpx() == p.x + 1 && trang->at(i)->Getpy() == p.y)
                for (int j = trong.size() - 1; j >= 0; j--)
                {
                    if (trong[j].x == p.x + 2)
                    {
                        trong.erase(trong.begin() + j);
                        break;
                    }

                }
            if (trang->at(i)->Getpx() == p.x - 1 && trang->at(i)->Getpy() == p.y)
                for (int j = trong.size() - 1; j >= 0; j--)
                {
                    if (trong[j].x == p.x - 2)
                    {
                        trong.erase(trong.begin() + j);
                        break;
                    }

                }
            if (trang->at(i)->Getpx() == p.x && trang->at(i)->Getpy() == p.y + 1)
                for (int j = trong.size() - 1; j >= 0; j--)
                {
                    if (trong[j].y == p.y + 2)
                    {
                        trong.erase(trong.begin() + j);
                        break;
                    }

                }
            if (trang->at(i)->Getpx() == p.x && trang->at(i)->Getpy() == p.y - 1)
                for (int j = trong.size() - 1; j >= 0; j--)
                {
                    if (trong[j].y == p.y - 2)
                    {
                        trong.erase(trong.begin() + j);
                        break;
                    }
                }
        }
    }
  
    void DiChuyen()
    {
        NuocDiCoBan();
        XoaChamTuong();
        XoaChamDongDoi();
        XoaBiChan();
        XoaChamDoiPhuong();      
        Menu();
        trong.clear();
        cham.clear();
    }
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

    void NuocDiCoBan()
    {
        ////cout << "dong1:";
        for (int i = p.x + 1; i <= x2; ++i)
        {
            trong.push_back(Point(i, p.y));
            ////cout << trong.back().x << "-" << trong.back().y << "  ";
        }
        //cout << endl << "dong2:";
        for (int i = p.x - 1; i >= x1; --i)
        {
            trong.push_back(Point(i, p.y));
            //cout << trong.back().x << "-" << trong.back().y << "  ";
        }
        //cout << endl<<"dong3:";
        for (int i = p.y + 1; i <= y2; ++i)
        {
            trong.push_back(Point(p.x, i));
            //cout << trong.back().x << "-" << trong.back().y << "  ";
        }
        //cout << endl << "dong4:";
        for (int i = p.y - 1; i >= y1; --i)
        {
            trong.push_back(Point(p.x, i));
            //cout << trong.back().x << "-" << trong.back().y << "  ";
        }        
        //cout << endl << "dong5:";
    }

    void XoaBiChan()
    {
        for (int i = trong.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < den->size(); ++j)
            {
                if (p.x < den->at(j)->Getpx() && den->at(j)->Getpx() < trong[i].x && p.y == den->at(j)->Getpy())
                {
                    //cout << trong[i].x << "," << trong[i].y << "  ";
                    trong.erase(trong.begin() + i);
                    break;
                }

                if (trong[i].x < den->at(j)->Getpx() && den->at(j)->Getpx()< p.x && p.y == den->at(j)->Getpy())
                {
                    //cout << trong[i].x << "," << trong[i].y << "  ";
                    trong.erase(trong.begin() + i);
                    break;
                }

                if (p.y < den->at(j)->Getpy() && den->at(j)->Getpy() < trong[i].y && p.x == den->at(j)->Getpx())
                {
                    //cout << trong[i].x << "," << trong[i].y << "  ";
                    trong.erase(trong.begin() + i);
                    break;
                }

                if (trong[i].y < den->at(j)->Getpy() && den->at(j)->Getpy() < p.y && p.x == den->at(j)->Getpx())
                {
                    //cout << trong[i].x << "," << trong[i].y << "  ";
                    trong.erase(trong.begin() + i);
                    break;
                }
            }
        }

        for (int i = trong.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < trang->size(); ++j)
            {
                if (p.x < trang->at(j)->Getpx() && trang->at(j)->Getpx() < trong[i].x && p.y == trang->at(j)->Getpy())
                {
                    //cout << trong[i].x << "x" << trong[i].y << "  ";
                    trong.erase(trong.begin() + i);
                    break;
                }

                if (trong[i].x < trang->at(j)->Getpx() && trang->at(j)->Getpx() < p.x && p.y == trang->at(j)->Getpy())
                {
                    //cout << trong[i].x << "x" << trong[i].y << "  ";
                    trong.erase(trong.begin() + i);
                    break;
                }

                if (p.y < trang->at(j)->Getpy() && trang->at(j)->Getpy() < trong[i].y && p.x == trang->at(j)->Getpx())
                {
                    //cout << trong[i].x << "x" << trong[i].y << "  ";
                    trong.erase(trong.begin() + i);
                    break;
                }

                if (trong[i].y < trang->at(j)->Getpy() && trang->at(j)->Getpy() < p.y && p.x == trang->at(j)->Getpx())
                {
                    //cout << trong[i].x << "x" << trong[i].y << "  ";
                    trong.erase(trong.begin() + i);
                    break;
                }
            }
        }
    }
  
    void DiChuyen()
    {
        NuocDiCoBan();
        XoaBiChan();
        XoaChamDongDoi();
        XoaChamDoiPhuong();
        Menu();
        trong.clear();
        cham.clear();
    }
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

        for (int i = p.y - 1; i >= y1; --i)
        {
            trong.push_back(Point(p.x, i));
        }
    }

    void XoaBiChan()
    {
        for (int i = trong.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < den->size(); ++j)
            {
                if (p.x < den->at(j)->Getpx() && den->at(j)->Getpx() < trong[i].x && p.y == den->at(j)->Getpy())
                {
                    trong.erase(trong.begin() + i);
                    break;
                }

                if (trong[i].x < den->at(j)->Getpx() && den->at(j)->Getpx() < p.x && p.y == den->at(j)->Getpy())
                {
                    trong.erase(trong.begin() + i);
                    break;
                }

                if (p.y < den->at(j)->Getpy() && den->at(j)->Getpy() < trong[i].y && p.x == den->at(j)->Getpx())
                {
                    trong.erase(trong.begin() + i);
                    break;

                }

                if (trong[i].y < den->at(j)->Getpy() && den->at(j)->Getpy() < p.y && p.x == den->at(j)->Getpx())
                {
                    trong.erase(trong.begin() + i);
                    break;
      
                }
            }
        }

        for (int i = trong.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < trang->size(); ++j)
            {
                if (p.x < trang->at(j)->Getpx() && trang->at(j)->Getpx() < trong[i].x && p.y == trang->at(j)->Getpy())
                {
                    trong.erase(trong.begin() + i);
                    break;
           
                }

                if (trong[i].x < trang->at(j)->Getpx() && trang->at(j)->Getpx() < p.x && p.y == trang->at(j)->Getpy())
                {
                    trong.erase(trong.begin() + i);
                    break;
      
                }

                if (p.y < trang->at(j)->Getpy() && trang->at(j)->Getpy() < trong[i].y && p.x == trang->at(j)->Getpx())
                {
                    trong.erase(trong.begin() + i);
                    break;
                }

                if (trong[i].y < trang->at(j)->Getpy() && trang->at(j)->Getpy() < p.y && p.x == trang->at(j)->Getpx())
                {
                    trong.erase(trong.begin() + i);
                    break;
                }
            }
        }
        
        /*
        cout << "dong1:";
        for (int i = cham.size() - 1; i >= 0; i--)
        {
            cout << cham[i].x << "," << cham[i].y << "\t";
        }
        */

        cout << endl;
        int count;
        for (int i = cham.size() - 1; i >= 0; i--)
        {
            
            count = 0;
            for (int j = 0; j < den->size(); ++j)
            {
                if (p.x < den->at(j)->Getpx() && den->at(j)->Getpx() < cham[i].x && p.y == den->at(j)->Getpy())
                {
                    count++;
                }
                else
                if (cham[i].x < den->at(j)->Getpx() && den->at(j)->Getpx() < p.x && p.y == den->at(j)->Getpy())
                {
                    count++;
                }
                else
                if (p.y < den->at(j)->Getpy() && den->at(j)->Getpy() < cham[i].y && p.x == den->at(j)->Getpx())
                {
                    count++;

                }
                else
                if (cham[i].y < den->at(j)->Getpy() && den->at(j)->Getpy() < p.y && p.x == den->at(j)->Getpx())
                {
                    count++;

                }     
              
            }
            /*cout << "|" << count << "|";
            cout << "dong1." << i << "   ";
            for (int i = cham.size() - 1; i >= 0; i--)
            {
                cout << cham[i].x << "," << cham[i].y << "\t";
            }
            cout << endl;*/
            for (int j = 0; j < trang->size(); ++j)
            {
                if (p.x < trang->at(j)->Getpx() && trang->at(j)->Getpx() < cham[i].x && p.y == trang->at(j)->Getpy())
                {
                    count++;

                }

                if (cham[i].x < trang->at(j)->Getpx() && trang->at(j)->Getpx() < p.x && p.y == trang->at(j)->Getpy())
                {
                    count++;
                }

                if (p.y < trang->at(j)->Getpy() && trang->at(j)->Getpy() < cham[i].y && p.x == trang->at(j)->Getpx())
                {
                    count++;
                }

                if (cham[i].y < trang->at(j)->Getpy() && trang->at(j)->Getpy() < p.y && p.x == trang->at(j)->Getpx())
                {
                    count++;
                }
            }
            if (count != 1)
            {
                cham.erase(cham.begin() + i);
            }
        }
       /* cout << endl;
        cout << "dong2:";
        for (int i = cham.size() - 1; i >= 0; i--)
        {
            cout << cham[i].x << "," << cham[i].y << "\t";
        }
        cout << endl;
        */


  
    }
  
    void DiChuyen()
    {
        NuocDiCoBan();
        XoaChamDongDoi();     
        XoaChamDoiPhuong();
        XoaBiChan();
        Menu();
    
        trong.clear();
        cham.clear();
    }
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
    void NuocDiCoBan()
    {
        if (doi == 0)
        {
            trong.push_back(Point(p.x, p.y + 1));
            if (p.y >= 6)
            {
                trong.push_back(Point(p.x + 1, p.y));
                trong.push_back(Point(p.x - 1, p.y));
            }
        }
        else
        {
            trong.push_back(Point(p.x, p.y - 1));
            if (p.y <=5)
            {
                trong.push_back(Point(p.x + 1, p.y));
                trong.push_back(Point(p.x - 1, p.y));
            }
        }
    }
 
    void DiChuyen()
    {
        NuocDiCoBan();
        XoaChamTuong();
        XoaChamDongDoi();
        XoaChamDoiPhuong();
        Menu();
        trong.clear();
        cham.clear();
    }
    ~Tot()
    {
    }
};