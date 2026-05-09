#include <iostream>
#include <string>
using namespace std;

class point {
    private:
    int x;
    int y;

    public:

point(int xVal , int yVal){
    x = xVal;
    y = yVal;
    
}

point(const point &obj){
    x = obj.x;
    y = obj.y;

}

int getX(){
    return x;
}

int getY(){
    return y;
}

void display(){
    cout << x << "," << y << endl;
}

};

int main(){
  point  p1(5,10);
   point p2 = p1;


    cout << "Point 1 is = " ;
    p1.display();
    cout << "Point 2 is = " ;
    p2.display();


   return 0;
}
