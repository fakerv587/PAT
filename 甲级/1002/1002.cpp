#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
double num[1001];
bool bo[1001];
int main(){
    int n;
    scanf("%d",&n);
    memset(bo,0,sizeof(bo));
    memset(num, 0 ,sizeof(num));
    int x;
    double nums;
    for(int i = 0; i < n; ++i){
        scanf("%d",&x);
        scanf("%lf",&nums);
        num[x]+=nums;
        bo[x]=1;
    }
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&x);
        scanf("%lf",&nums);
        num[x]+=nums;
        bo[x]=1;
    }
    int i = 1000;
    int cnt = 0;
    for(; i >= 0; --i){
        if(bo[i] && num[i] != 0){
            cnt++;
        }
    }
    printf("%d",cnt);
    i = 1000;
    for(; i >= 0;--i){
        if(bo[i] && num[i] != 0)
        printf(" %d %.1lf",i, num[i]);
    }
    
}