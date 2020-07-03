#include "QuanCo.h"

void QuanCo::XoaChamTuong()
{
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

void QuanCo::VeQuanCo()
{
    cout << kihieuquanco;
}
void Tuong::NuocDiCoBan()
{
    trong.push_back(Point(p.x + 1, p.y));
    trong.push_back(Point(p.x - 1, p.y));
    trong.push_back(Point(p.x, p.y + 1));
    trong.push_back(Point(p.x, p.y - 1));
}

void Tuong::DiChuyen()
{
    NuocDiCoBan();
    XoaChamTuong();
    XoaChamDongDoi();
    XoaChamDoiPhuong();
    Menu();
    trong.clear();
    cham.clear();
}

void Si::NuocDiCoBan()
{
    trong.push_back(Point(p.x + 1, p.y + 1));
    trong.push_back(Point(p.x - 1, p.y + 1));
    trong.push_back(Point(p.x - 1, p.y - 1));
    trong.push_back(Point(p.x + 1, p.y - 1));
}

void Si::DiChuyen()
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

void Tinh::NuocDiCoBan()
{
    trong.push_back(Point(p.x + 2, p.y + 2));
    trong.push_back(Point(p.x - 2, p.y + 2));
    trong.push_back(Point(p.x - 2, p.y - 2));
    trong.push_back(Point(p.x + 2, p.y - 2));
}

void Tinh::XoaBiChan()
{
    for (int i = trong.size() - 1; i >= 0; i--)
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

void Tinh::DiChuyen()
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

void Ma::NuocDiCoBan()
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

void Ma::XoaBiChan()
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

void Ma::DiChuyen()
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

void Xe::NuocDiCoBan()

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

void Xe::XoaBiChan()

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

            if (trong[i].x < den->at(j)->Getpx() && den->at(j)->Getpx() < p.x && p.y == den->at(j)->Getpy())
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

void Xe::DiChuyen()
{
    NuocDiCoBan();
    XoaBiChan();
    XoaChamDongDoi();
    XoaChamDoiPhuong();
    Menu();
    trong.clear();
    cham.clear();
}

void Phao::NuocDiCoBan()

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

void Phao::XoaBiChan()

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

void Phao::DiChuyen()
{
    NuocDiCoBan();
    XoaChamDongDoi();
    XoaChamDoiPhuong();
    XoaBiChan();
    Menu();

    trong.clear();
    cham.clear();
}

void Tot::NuocDiCoBan()

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
        if (p.y <= 5)
        {
            trong.push_back(Point(p.x + 1, p.y));
            trong.push_back(Point(p.x - 1, p.y));
        }
    }
}

void Tot::DiChuyen()
{
    NuocDiCoBan();
    XoaChamTuong();
    XoaChamDongDoi();
    XoaChamDoiPhuong();
    Menu();
    trong.clear();
    cham.clear();
}