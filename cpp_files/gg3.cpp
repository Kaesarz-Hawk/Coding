#include <iostream>

using namespace std;

class Wall {
private:
    double length;
    double height;

public:
    Wall(double len, double hgt) {
        length = len;
        height = hgt;
        cout << "Parameterized constructor called." << endl;
    }

    Wall(const Wall &other) {
        length = other.length;
        height = other.height;
        cout << "Copy constructor called." << endl;
    }

    double calculateArea() {
        return length * height;
    }

    void displayArea() {
        cout << "Area of the wall is: " << calculateArea() << endl;
    }
};

int main() {
   Wall wall1(10.50, 15);
   cout << "Wall 1 details" << endl;
   wall1.displayArea();

   Wall wall2 = wall1;
    cout << "Wall 2 details" << endl;
   wall2.displayArea();
    return 0;
}