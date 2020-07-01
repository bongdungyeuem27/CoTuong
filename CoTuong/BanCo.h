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
class BanCo
{
private:

   

protected:
public:
    vector <QuanCo*> trang;
    vector <QuanCo*> den;
    BanCo()
    {
        den.push_back(new Tuong(&den, &trang, 0, 5, 1));
        den.push_back(new Si(&den, &trang, 0, 4, 1));
        den.push_back(new Si(&den, &trang, 0, 6, 1));
        den.push_back(new Tinh(&den, &trang, 0, 3, 1));
        den.push_back(new Tinh(&den, &trang, 0, 7, 1));
        den.push_back(new Ma(&den, &trang, 0, 2, 1));
        den.push_back(new Ma(&den, &trang, 0, 8, 1));
        den.push_back(new Xe(&den, &trang, 0, 1, 1));
        den.push_back(new Xe(&den, &trang, 0, 9, 1));
        den.push_back(new Phao(&den, &trang, 0, 2, 3));
        den.push_back(new Phao(&den, &trang, 0, 8, 3));
        for (int i = 1; i <= 9; i++)
        {
            if (i % 2 == 1)
            {
                den.push_back(new Tot(&den, &trang, 0, i, 4));
            }
        }

        trang.push_back(new Tuong(&den, &trang, 1, 5, 10));
        trang.push_back(new Si(&den, &trang, 1, 4, 10));
        trang.push_back(new Si(&den, &trang, 1, 6, 10));
        trang.push_back(new Tinh(&den, &trang, 1, 3, 10));
        trang.push_back(new Tinh(&den, &trang, 1, 7, 10));
        trang.push_back(new Ma(&den, &trang, 1, 2, 10));
        trang.push_back(new Ma(&den, &trang, 1, 8, 10));
        trang.push_back(new Xe(&den, &trang, 1, 1, 10));
        trang.push_back(new Xe(&den, &trang, 1, 9, 10));
        trang.push_back(new Phao(&den, &trang, 1, 2, 8));
        trang.push_back(new Phao(&den, &trang, 1, 8, 8));
        for (int i = 1; i <= 9; i++)
        {
            if (i % 2 == 1)
            {
                trang.push_back(new Tot(&den, &trang, 1, i, 7));
            }
        }
        ReFresh();
    }

    void ReFresh()
    {
        system("cls");
        changColor(14);
        for (int i = den.size() - 1; i >= 0; i--)
        {
            gotoXY(den[i]->Getpx() - 1, 10 - den[i]->Getpy()); den[i]->VeQuanCo();
        }
        changColor(15);
        for (int i = trang.size() - 1; i >= 0; i--)
        {
            gotoXY(trang[i]->Getpx() - 1, 10 - trang[i]->Getpy()); trang[i]->VeQuanCo();
        }
        changColor(14);
        gotoXY(70, 0); cout << "Ben Den";
        for (int i = den.size() - 1; i >= 0; i--)
        {
            gotoXY(70, i + 1); cout << "[" << setw(2) << right << i << "]:" << setw(6) << left << den[i]->GetTenQuanCo(); den[i]->VeQuanCo();cout << " (" << den[i]->Getpx() << "," << den[i]->Getpy() << ") ";
        }
        changColor(15);
        gotoXY(95, 0); cout << "Ben Trang";
        for (int i = trang.size() - 1; i >= 0; i--)
        {
            gotoXY(95, i + 1); cout << "[" << setw(2) << right << i << "]:" << setw(6) << left << trang[i]->GetTenQuanCo(); trang[i]->VeQuanCo(); cout << " (" << trang[i]->Getpx() << "," << trang[i]->Getpy() << ") ";
        }
 
      
    }
    void Run()
    {
        int n = 0;
        while (trang.size() != 0 || den.size() != 0)
        {                  
            gotoXY(0, 12); cout << "BEN DEN: Chon quan co: "; cin >> n; 
            while (1)
            {
                if (n < 0 || n >= den.size())
                {
                    cout << "Nhap lai!: "; cin >> n;
                }
                else break;
            }
            den.at(n)->DiChuyen();
            ReFresh();
            gotoXY(0, 12); cout << "BEN TRANG: Chon quan co: "; cin >> n;
            while (1)
            {
                if (n < 0 || n >= trang.size())
                {
                    cout << "Nhap lai!: "; cin >> n;
                }
                else break;
            }
            trang.at(n)->DiChuyen();
            ReFresh();
        }
    }

    ~BanCo()
    {
        for (int i = 0; i < den.size(); ++i)
            delete den[i];
        den.clear();

        for (int i = 0; i < trang.size(); ++i)
            delete trang[i];
        trang.clear();
        den.clear();
        trang.clear();
    }
};

