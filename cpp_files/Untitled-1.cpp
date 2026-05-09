#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {

      int N;
        cin>>N;
        int glassprice = 50;
        int income = glassprice * N;


        int sugarcane = 20;
        int saltmint = 20;
        int rent = 30;
        

        int totalcost = (sugarcane + saltmint + rent);




        int costpercent = (income * totalcost )/100;

        int profit = income - costpercent;

        cout<<profit<<endl;
     
        
    }




    return 0;
}