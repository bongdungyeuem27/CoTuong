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
    vector <QuanCo*> den;
    vector <QuanCo*> trang;
    
protected:
public:
    
    BanCo();

    void ReFresh();

    void Run();

    ~BanCo();
    
};

