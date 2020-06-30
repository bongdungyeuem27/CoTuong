
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
    setFontSize(18);
    
    BanCo* b;
    b = new BanCo;
    b->Run();
    


    
    gotoXY(0, 17);
    delete b;
    system("pause");

}