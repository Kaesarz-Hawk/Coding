#include <iostream>
using namespace std;
class coord
{
private:
    int x, y;

public:
    coord()
    {
        x = 0;
        y = 0;
    }
    coord(int a, int b)
    {
        x = a;
        y = b;
    }

    coord operator+(coord c)
    {
        coord temp;
        temp.x = x + c.x;
        temp.y = y + c.y;
        return temp;
    }

    bool operator==(coord c)
    {
        return (x == c.x and y == c.y);
    }

    bool operator&&(coord c)
    {
        return (x != 0 && y != 0 && c.x != 0 && c.y != 0);
    }

    void display()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};
int main()
{
    coord c1;
    coord c2(3, 4);
    coord c3(5, 6);
    c1.display();
    c2.display();
    c3.display();

    coord c4 = c2 + c3;
    c4.display();

    if (c2 == c3)
    
        cout << "c2 and c3 are equal" << endl;
    
    else
    
        cout << " not equal" << endl;
    

    if (c2 && c3)
    
        cout << "c2 and c3 are not 0" << endl;
    
    else
    
        cout << " 0 possible " << endl;
    
    return 0;
}
