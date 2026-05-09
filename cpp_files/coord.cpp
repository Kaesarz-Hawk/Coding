#include<iostream>
using namespace std;
class coord{

    int x,y;
public:
    coord(){
    int x = 0;
    int y = 0;
    }

    coord(int a , int b){
    x = a;
    y = b;
    }

    coord operator+(coord const &obj){
    coord temp;

    temp.x= x + obj.x;
       temp.y= y + obj.y;
    return temp;
    }

    bool operator==(coord const &obj){
    return ( x == obj.x && y == obj.y);
    }

    bool operator&&(coord const &obj){
    return ( x != 0 && y != 0 && obj.x != 0 && obj.y != 0 );
    }

    void display(){
    cout << "(" << x << "," << y << ")" << endl;
    }
};
int main(){

coord c1;
c1.display();
coord c2(4,7);
c2.display();
coord c3(5 , 8);
c3.display();

cout << "After + and == and &&" << endl;

coord c4 = c2+c3;
c4.display();

if ( c2 == c4)
    cout << " equal YEs" << endl;
else
    cout << "  equal no" << endl;

    if ( c2 && c4)
    cout << " non zero yes" << endl;
else
    cout << "  non zero no" << endl;




return 0;
}
