#include <bits/stdc++.h>
using namespace std;

int main()
{

string s1 = "hello";
string s2 = "Hello";

for(char &c : s1) c = tolower(c); // for is used to convert each character to lowercase
for(char &c : s2) c = tolower(c); // for is used to convert each character to lowercase


if(s1 == s2)
    cout << "Equal";
else
    cout << "Not Equal";



    return 0;
}
