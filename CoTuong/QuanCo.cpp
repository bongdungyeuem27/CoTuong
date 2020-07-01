#include "QuanCo.h"

void QuanCo::XoaChamTuong()
{
   // cout << "x1=" << x1 << "x2=" << x2 << "y1=" << y1 << "y2=" << y2 << endl;
    //cout << "tuong";
    for (int i = trong.size() - 1; i >= 0; i--)
    {
        //cout << i;
        /*for (int o = trong.size() - 1; o >= 0; o--)
        cout << "(" << trong[o].x << "," << trong[o].y << ") ";
        cout << endl;*/
        if (trong.at(i).x > x2 || trong.at(i).x < x1 || trong.at(i).y<y1 || trong.at(i).y>y2)
		{
			trong.erase(trong.begin() + i);
		}
	}
    cout << endl;
}

Point::Point()
{
}


void QuanCo::XoaChamDongDoi()
{
    for (int i = trong.size() - 1; i >= 0; i--)
    {
        //cout << i;   //test
        for (int j = 0; j < den->size(); ++j)
        {
            if (trong[i].x == den->at(j)->Getpx() && trong[i].y == den->at(j)->Getpy())
            {
                trong.erase(trong.begin() + i);
                break;
            }            
        }      
    }
}

void QuanCo::XoaChamDoiPhuong()
{
    for (int i = trong.size() - 1; i >= 0; i--)
    {
        //cout << i;   //test
        for (int j = 0; j < trang->size(); ++j)
        {
            if (trong[i].x == trang->at(j)->Getpx() && trong[i].y == trang->at(j)->Getpy())
            {
                cham.push_back(Point(trong[i].x, trong[i].y));
                trong.erase(trong.begin() + i);  
                break;
            }
        }
    }
}

void QuanCo::Menu()
{
    gotoXY(0, 20);
    cout << "Cac vi tri trong: " << endl;
    for (int i = 0; i < trong.size(); ++i)
    {
        cout << "[" << i << "]:(" << trong[i].x << "," << trong[i].y << ")\t";
        if (i % 5 == 4) cout << endl;
    }
    cout << endl;
    cout << "Cac vi tri cham: " << endl;
    for (int i = 0; i < cham.size(); ++i)
    {
        cout << "[" << trong.size() + i << "]:(" << cham[i].x << "," << cham[i].y << ")\t";
        if (i % 5 == 4) cout << endl;
    }
    cout << endl;
    Point select;
    if ((trong.size() + cham.size()) == 0)
    {
        cout << "Khong the di chuyen! Nhap phim bat ky de tiep tuc!";
        char key;
        cin >> key;
        return;
    }
    while (1)
    {
   
        cout << "Lua chon: ";
        int key;
        cin >> key;

        if (key < 0 || key >= trong.size() + cham.size()) cout << "Moi nhap lai!";
        else
        {
            if (key < trong.size())
                select = Point(trong[key].x, trong[key].y);
            else if (key >= trong.size())
            {
                cout << "see!!";
                select = Point(cham[key-trong.size()].x, cham[key - trong.size()].y);
                for (int i = trang->size()-1; i >=0; --i)
                {
                    if (select.x == trang->at(i)->Getpx() && select.y == trang->at(i)->Getpy())
                    {
                       // cout << "see!!";
                        delete trang->at(i);
                        trang->erase(trang->begin() + i);
                        break;
                    }
                }
            }
            gotoXY(0, 25); cout << endl << endl;

            gotoXY(0, 25);
            cout << "Da lua chon: " << key << ":(" << select.x << "," << select.y << ")";


            break;
        }
    }
    p.x = select.x; p.y = select.y;

}