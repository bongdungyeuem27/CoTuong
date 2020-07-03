#include "QuanCo.h"

//Class QuanCo
void QuanCo::XoaChamTuong()
{
    //Duyệt từng phần tử của mảng trong
    for (int i = trong.size() - 1; i >= 0; i--)
    {
        //Xét điều kiện ngoài phạm vi tường 
        if (trong.at(i).x > x2 || trong.at(i).x < x1 || trong.at(i).y<y1 || trong.at(i).y>y2)
		{
			trong.erase(trong.begin() + i);
		}
	}
    cout << endl;
}

void QuanCo::XoaChamDongDoi()
{
    //Duyệt từng phần tử của mảng trong
    for (int i = trong.size() - 1; i >= 0; i--)
    {
        //Duyệt từng phần tử của mảng den
        for (int j = 0; j < den->size(); ++j)
        {
            //Xét điều kiện cham mặt đồng đội
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
    //Duyệt từng phần tử của mảng trong
    for (int i = trong.size() - 1; i >= 0; i--)
    {
        //Duyệt từng phần tử của mảng den
        for (int j = 0; j < trang->size(); ++j)
        {
            // Xét điều kiện chạm mặt đối phương
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
    //Hiển thị các vị trí khả thi
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

    //Đưa ra báo hiệu quân cờ không thể di chuyển 
    if ((trong.size() + cham.size()) == 0)
    {
        cout << "Khong the di chuyen! Nhap phim [0] de tiep tuc!";
        char key;
        cin >> key;
        return;
    }

    //Lựa chọn vị trí di chuyển
    while (1)
    {
        cout << "Lua chon: ";
        int key;
        cin >> key;

        //Báo hiệu nhập các vị trí không tồn tại
        if (key < 0 || key >= trong.size() + cham.size()) cout << "Moi nhap lai!";
        else
        {
            //Di chuyển đến vị trí trống
            if (key < trong.size())
                select = Point(trong[key].x, trong[key].y);
            //Di chuyển đến vị trí chạm đối phương
            else if (key >= trong.size())
            {
                select = Point(cham[key-trong.size()].x, cham[key - trong.size()].y);
                for (int i = trang->size()-1; i >=0; --i)
                {
                    if (select.x == trang->at(i)->Getpx() && select.y == trang->at(i)->Getpy())
                    {
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

    //Thiết đặt lại toạ độ mới của quân cờ
    p.x = select.x; p.y = select.y;
}

int QuanCo::Getpx()
{
    return p.x;
}

int QuanCo::Getpy()
{
    return p.y;
}

bool QuanCo::Getthua()
{
    return thua;
}

string QuanCo::GetTenQuanCo()
{
    return TenQuanCo;
}

void QuanCo::Setpx(int a)
{
    p.x = a;
}
void QuanCo::Setpy(int a)
{
    p.y = a;
}
void QuanCo::VeQuanCo()
{
    cout << kihieuquanco;
}

QuanCo::~QuanCo()
{
    trong.clear();
    cham.clear();
}

//Class Tuong
Tuong::Tuong(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y)
{
    TenQuanCo = "Tuong";
    kihieuquanco = '+';
    p.x = x; p.y = y;

    //bên đen mau==0 bên trắng mau==1
    if (mau == 0)
    {
        den = team1;
        trang = team2;
        y1 = consoy1, y2 = 3, x1 = 4, x2 = 6;
    }
    else
    {
        den = team2;
        trang = team1;
        y1 = 8, y2 = consoy2, x1 = 4, x2 = 6;
    }
    thua = 1;
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

Si::Si(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y)
{
    TenQuanCo = "Si";
    kihieuquanco = 'O';
    p.x = x; p.y = y;

    //bên đen mau==0 bên trắng mau==1
    if (mau == 0)
    {
        den = team1;
        trang = team2;
        y1 = consoy1, y2 = 3, x1 = 4, x2 = 6;
    }
    else
    {
        den = team2;
        trang = team1;
        y1 = 8, y2 = consoy2, x1 = 4, x2 = 6;
    }
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

//Class Tinh
Tinh::Tinh(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y)
{
    TenQuanCo = "Tinh";
    kihieuquanco = '#';
    p.x = x; p.y = y;

    //bên đen mau==0 bên trắng mau==1
    if (mau == 0)
    {
        den = team1;
        trang = team2;
        y1 = consoy1, y2 = 5, x1 = consox1, x2 = consox2;
    }
    else
    {
        den = team2;
        trang = team1;
        y1 = 6, y2 = consoy2, x1 = consox1, x2 = consox2;
    }
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
    //Duyệt tất cả vị trí trống
    for (int i = trong.size() - 1; i >= 0; i--)
    {
        //Ở giữa đường đi có đồng đội thì xoá điểm này
        for (int j = 0; j < den->size(); ++j)
        {
            if ((trong[i].x + p.x == 2 * den->at(j)->Getpx()) && (trong[i].y + p.y == 2 * den->at(j)->Getpy()))
            {
                trong.erase(trong.begin() + i);
                break;
            }
        }

        //Ở giữa đường đi có đối phương thì xoá điểm này
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

//Class Ma
Ma::Ma(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y)
{

    TenQuanCo = "Ma";
    kihieuquanco = '~';
    p.x = x; p.y = y;
    //bên đen mau==0 bên trắng mau==1
    y1 = consoy1, y2 = consoy2, x1 = consox1, x2 = consox2;
    if (mau == 0)
    {
        den = team1;
        trang = team2;
    }
    else
    {
        den = team2;
        trang = team1;
    }
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
    //Duyệt tất cả vị trí trống
    for (int i = 0; i < den->size(); ++i)
    {
        //Ở giữa đường đi có đồng đội thì xoá điểm này
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

    //Duyệt tất cả vị trí trống
    for (int i = 0; i < trang->size(); ++i)
    {
        //Ở giữa đường đi có đối phương thì xoá điểm này
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

//Class Xe
Xe::Xe(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y)
{
    TenQuanCo = "Xe";
    kihieuquanco = 'X';
    p.x = x; p.y = y;
    y1 = consoy1, y2 = consoy2, x1 = consox1, x2 = consox2;
    //bên đen mau==0 bên trắng mau==1
    if (mau == 0)
    {
        den = team1;
        trang = team2;
    }
    else
    {
        den = team2;
        trang = team1;
    }
}

//Nạp tất cả các ô theo chiều x,y
void Xe::NuocDiCoBan()
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

void Xe::XoaBiChan()
{
    //Loại trừ các ô mà đường đi tới nó có đồng đội chặn
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

    //Loại trừ các ô mà đường đi tới nó có đối phương chặn
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

//Class Phao
Phao::Phao(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y)
{
    TenQuanCo = "Phao";
    kihieuquanco = '@';
    p.x = x; p.y = y;
    y1 = consoy1, y2 = consoy2, x1 = consox1, x2 = consox2;
    //bên đen mau==0 bên trắng mau==1
    if (mau == 0)
    {
        den = team1;
        trang = team2;
    }
    else
    {
        den = team2;
        trang = team1;
    }
}

//Nạp các ô theo chiều x và y giống xe
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
    //Loại trừ các ô mà đường đi tới nó có đồng đội chặn
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

    //Loại trừ các ô mà đường đi tới nó có đối phương chặn
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

    int count;

    //Xét mỗi ô chạm mặt đối phương, nếu đến được có 1 quân cờ trên đường đi tới ô đó thì cho phép ăn quân đối phương
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

        for (int j = 0; j < trang->size(); ++j)
        {
            if (p.x < trang->at(j)->Getpx() && trang->at(j)->Getpx() < cham[i].x && p.y == trang->at(j)->Getpy())
            {
                count++;

            }
            else
                if (cham[i].x < trang->at(j)->Getpx() && trang->at(j)->Getpx() < p.x && p.y == trang->at(j)->Getpy())
                {
                    count++;
                }
                else
                    if (p.y < trang->at(j)->Getpy() && trang->at(j)->Getpy() < cham[i].y && p.x == trang->at(j)->Getpx())
                    {
                        count++;
                    }
                    else
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

//Class Tot
Tot::Tot(vector<QuanCo*>* team1, vector<QuanCo*>* team2, int mau, int x, int y)
{
    TenQuanCo = "Tot";
    kihieuquanco = ':';
    p.x = x; p.y = y;
    doi = mau;
    y1 = consoy1, y2 = consoy2, x1 = consox1, x2 = consox2;
    if (mau == 0)
    {
        den = team1;
        trang = team2;
    }
    else
    {
        den = team2;
        trang = team1;
    }
}

void Tot::NuocDiCoBan()
{ 
    if (doi == 0)
        //Nạp đường đi cho tốt đen
    {
        //Bên nhà thì đi thẳng
        trong.push_back(Point(p.x, p.y + 1));

        //Bên sông thì thêm đi ngang
        if (p.y >= 6)
        {
            trong.push_back(Point(p.x + 1, p.y));
            trong.push_back(Point(p.x - 1, p.y));
        }
    }
    else
        //Nạp đường đi cho tốt trắng
    {
        //Bên nhà thì đi thẳng
        trong.push_back(Point(p.x, p.y - 1));

        //Bên sông thì thêm đi ngang
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

Point::Point()
{
}
