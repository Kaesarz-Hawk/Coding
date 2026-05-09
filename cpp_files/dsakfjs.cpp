#include <iostream>
using namespace std;
class coord
{
private:
    int x, y;

public:
    coord(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }
    void getxy(int &a, int &b)
    {
        a = x;
        b = y;
    }
    coord operator+(coord c)
    {
        coord temp;
        temp.x = x + c.x;
        temp.y = y + c.y;
        return temp;
    }
    coord operator-(coord c)
    {
        coord temp;
        temp.x = x - c.x;
        temp.y = y - c.y;
        return temp;
    }
    void display()
    {
        cout << "x=" << x << ",y=" << y << endl;
    }
};
int main()
{
    coord c1(10, 20), c2(5, 10), c3;
    c3 = c1 + c2;
    c3.display();
    c3 = c1 - c2;
    c3.display();
    return 0;
}