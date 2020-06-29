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

    vector <QuanCo*> trang;
    vector <QuanCo*> den;

protected:
public:
    BanCo()
    {
        den.push_back(new TuongDen());
        den.push_back(new SiDen(4, 1));
        den.push_back(new SiDen(6, 1));
        den.push_back(new TinhDen(3, 1));
        den.push_back(new TinhDen(7, 1));
        ReFresh();
    }

    void ReFresh()
    {
        system("cls");
        for (int i = 0; i < trang.size(); ++i)
        {
            gotoXY(9 - trang[i]->Getpx(), 10 - trang[i]->Getpy()); cout << "O";
        }
        for (int i = 0; i < den.size(); ++i)
        {
            gotoXY(den[i]->Getpx()-1, 10 - den[i]->Getpy()); cout << "O";
        }
    }
    void Run()
    {
        while (trang.size() == 0 || den.size() == 0)
        {
            
            den[0]->DiChuyen(trang, den);
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
    }
};

