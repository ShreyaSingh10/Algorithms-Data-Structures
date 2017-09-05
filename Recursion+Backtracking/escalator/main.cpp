#include <iostream>

using namespace std;

int main()
{
    int t;cin>>t;
    while(t--){
        int ve,vy,l,ti;
        cin>>ve>>vy>>l>>ti;
        float x=(l)/(ve+vy);
        cout<<"x:"<<x<<endl;
        if(x<ti){
            cout<<"a"<<endl;
            if(x==0)
            cout<<0<<endl;
            else
            cout<<((ti)-x)/ti<<endl;
        }
        else if(x>=ti){
            cout<<"c"<<endl;
            cout<<"1.0<<endl;
        }
    }
}
