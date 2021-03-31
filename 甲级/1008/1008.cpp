#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;
const int N = 1e3+5;

int up(int a,int b)
{
    return 6*(a-b);
}
int down(int a,int b)
{
    return 4*(a-b);
}
int main()
{
    int n;
    int tmp=0,now;
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>now;
        if(now>tmp) ans+=up(now,tmp);
        else if(now<tmp) ans+=down(tmp,now);
        tmp=now;
    }
    cout<<ans+n*5<<endl;
    return 0;
}
