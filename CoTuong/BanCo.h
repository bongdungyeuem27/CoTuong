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
    //Vector lưu đối tượng đen
    vector <QuanCo*> den;
    //Vector lưu đối tượng trắng
    vector <QuanCo*> trang;
public:
    //Nạp Bàn cờ gồm 16 đen, 16 trắng
    BanCo();

    //Hiển thị ra màn hình 
    void ReFresh();

    //Thực thi toàn bộ toán trình chơi
    void Run();

    ~BanCo();
    
};

