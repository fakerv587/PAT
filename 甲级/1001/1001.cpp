#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    a = a + b;
    if(a < 0){
        a = -a;
        printf("-");
    }
    string s = to_string(a);
    int i = s.size() % 3 ? s.size() % 3 : 3;
    cout<<s.substr(0,i);
    for(; i < s.size(); i+=3){
        cout<<","<<s.substr(i,3);
    }
    
    return 0;
}