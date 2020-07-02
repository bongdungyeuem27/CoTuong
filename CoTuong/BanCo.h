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
    BanCo();

    void ReFresh();

    void Run();

    ~BanCo();
    
};

