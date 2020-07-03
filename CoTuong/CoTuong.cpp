
#include <string.h>
#include <vector>
#include <string>
#include <ctime>
#include<fstream>

#include <iostream>
#include <cstdlib>

#include "source.h"
#include "QuanCo.h"
#include "BanCo.h"
using namespace std;


int main()
{
    //tăng kích cỡ chữ
    setFontSize(18);

    //Tạo mới bàn cờ
    BanCo* b;
    b = new BanCo;

    //Thực thi bàn cờ
    b->Run();
    
    gotoXY(0, 17);

    //Giải phóng bộ nhớ
    delete b;
    system("pause");

}