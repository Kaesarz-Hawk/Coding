#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity{

    int start,end;
};

bool cmp(Activity a, Activity b){

    return a.end<b.end;
}

int main(){

    int n;
    cin>>n;

    vector<Activity> a(n);

    for(int i=0;i<n;i++)
        cin>>a[i].start>>a[i].end;

    sort(a.begin(),a.end(),cmp);

    cout<<"Selected Activities:\n";

    cout<<"("<<a[0].start<<","<<a[0].end<<")\n";

    int lastEnd=a[0].end;
    int count=1;

    for(int i=1;i<n;i++){

        if(a[i].start>=lastEnd){

            cout<<"("<<a[i].start<<","<<a[i].end<<")\n";

            lastEnd=a[i].end;

            count++;
        }
    }

    cout<<"\nMaximum Activities = "<<count;

    return 0;
}