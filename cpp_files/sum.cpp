#include<iostream>
using namespace std;
class Distance{
    private:
    int feet;
    int inches;
    public:
    Distance(){
        feet=0;
        inches=0;
    }
    Distance(int f , int i){
        feet = f;
        inches = i;
        if ( inches >= 12){
            feet += inches / 12;
            inches = inches % 12;
        }

    }
    
    Distance operator++(){
        ++inches;
        if (inches >= 12){
            feet += inches / 12;
            inches = inches % 12;
        }
        return *this;
    }

    Distance operator+(Distance d){
        Distance temp;
        temp.feet = feet + d.feet;
        temp.inches = inches + d.inches;
        if (temp.inches >= 12){
            temp.feet += temp.inches / 12;
            temp.inches = temp.inches % 12;
        }
        return temp;
    }

    void display(){
        cout << "Feet: " << feet << ", Inches: " << inches << endl;
    }
};

int main(){
    Distance d1(5, 10);
    Distance d2(3, 8);
    cout << "Distance 1: ";
    d1.display();
    cout << "Distance 2: ";
    d2.display();
    
    
    Distance d3 = d1 + d2;
    cout << "After Addition: ";
    d3.display();
    
    ++d1;
    cout << "After Incrementing d1: ";
    d1.display();
    
    return 0;
}