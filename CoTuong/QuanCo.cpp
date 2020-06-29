#include "QuanCo.h"

void QuanCo::XoaChamTuong(vector<QuanCo*>& trang, vector<QuanCo*>& den)
{
	for (int i = 0; i < trong.size(); ++i)
	{
		
		if (trong[i].x>x2|| trong[i].x < x1|| trong[i].y<y1|| trong[i].y>y2)
		{
			trong.erase(trong.begin() + i);
			--i;
		}
	}
}

Point::Point()
{
}


void Den::XoaChamDongDoi(vector<QuanCo*>& trang, vector<QuanCo*>& den)
{
    for (int i = 0; i < trong.size(); ++i)
    {

        for (int j = 0; j < den.size(); ++j)
        {

            if (trong[i].x == den[j]->Getpx() && trong[i].y == den[j]->Getpy())
            {
                trong.erase(trong.begin() + i);
                --i;
            }
        }
    }
}

void Den::XoaChamDoiPhuong(vector<QuanCo*>& trang, vector<QuanCo*>& den)
{
    for (int i = 0; i < trong.size(); ++i)
    {
        for (int j = 0; j < trang.size(); ++j)
        {
            if (trong[i].x == trang[j]->Getpx() && trong[i].y == trang[j]->Getpy())
            {
                cham.push_back(trong[i]);
                trong.erase(trong.begin() + i);
                --i;
            }
        }
    }
}

void QuanCo::Menu(vector<QuanCo*>& trang, vector<QuanCo*>& den)
{
    gotoXY(0, 12);
    cout << "Cac vi tri trong: " << endl;
    for (int i = 0; i < trong.size(); ++i)
    {
        cout << "[" << i << "]:(" << trong[i].x << "," << trong[i].y << ")\t";
    }
    cout << endl;
    cout << "Cac vi tri cham: " << endl;
    for (int i = 0; i < cham.size(); ++i)
    {
        cout << "[" << trong.size() + i << "]:(" << cham[i].x << "," << cham[i].y << ")\t";
    }
    cout << endl;
    Point select;
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
                for (int i = 0; i < trang.size(); ++i)
                {
                    if (select.x == trang[i]->Getpx() && select.y == trang[i]->Getpy())
                    {
                        delete trang[i];
                        trang.erase(trang.begin() + i);
                        --i;
                        select = Point(cham[key].x, cham[key].y);

                        break;
                    }
                }
            }
            gotoXY(0, 17); cout << endl << endl;

            gotoXY(0, 17);
            cout << "Da lua chon: " << key << ":(" << select.x << "," << select.y << ")";


            break;
        }
    }
    p.x = select.x; p.y = select.y;

}