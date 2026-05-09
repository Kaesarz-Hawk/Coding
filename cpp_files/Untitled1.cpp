#include <iostream>
#include <string>
using namespace std;

class Book{
   public:

    string Author;
    string title;
    float price;


    Book(){
        Author = "Unknown";
        title = "Untitled";
        price = 0.0;
    }

    Book(string t , string a , float p){
        title = t;
        Author = a;
        price = p;
    }

    void display(){
        cout << "Title = " << title << endl;
         cout << "Author = " << Author << endl;
          cout << "Price = " << price << endl;

    }


};

int main(){
    Book b1;
    Book b2("C++ by KH" , "Kawsar" , 99.50);

    b1.display();
    b2.display();
    


return 0;
}