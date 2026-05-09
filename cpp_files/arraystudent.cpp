#include<bits/stdc++.h>
using namespace std;
class Student{
    public:

    int rollNumber;
    string name;
    double gpa;

    void input(){
        cout << "Enter roll number" << endl;
        cin>>rollNumber;

         cout << "Enter name" << endl;
        cin>>name;

         cout << "Enter GPA" << endl;
        cin>>gpa;
    }

    void display(){
        cout << " Name = " << name << ",Roll = " << rollNumber << ",GPA = " << gpa << endl;
    }
};
int main(){
    int n = 5;
    Student students[60];

    cout << "Enter details of the students" << endl;
    for( int i = 0 ; i < n ; i++){
        cout << "\nStudent " << i+1 << "\n";
        students[i].input();
    }

    int searchRoll;
    cout << "Enter the roll you want to search" << endl;
    cin >> searchRoll;

    bool found = false;
    for(int i=0 ; i < n ; i++){
        if(students[i].rollNumber == searchRoll){
            cout << "\nStudent founded";
            students[i].display();
            found = true ;
            break;
        }
    }

    if(!found){
        cout << " Student with " << searchRoll << "not found " << endl;
    }

    double maxGPA = students[0].gpa;
    int index = 0;
    for(int i = 1 ; i < n ; i++){
        if( students[i].gpa > maxGPA){
            maxGPA = students[i].gpa;
            index = i;
        }
    }

    cout << "Student with the highest gpa" << endl;
    students[index].display();

}
