#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
double a,b,c,maxx,ans;
char ch[3];
int main(){
    ans = 1.0;
    for(int i = 0 ; i < 3; ++i){
        cin>>a>>b>>c;
        maxx = max(a,max(b,c));
        if(maxx == a){
            ch[i] = 'W';
        }
        else if (maxx == b){
            ch[i] = 'T';
        }
        else{
            ch[i] = 'L';
        }
        ans *= maxx;
    }
    ans = (ans * 0.65 - 1)*2;
    printf("%c %c %c %.2lf",ch[0], ch[1],ch[2],ans);
    return 0;
}