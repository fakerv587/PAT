#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
double num[2001],b[2001];
bool bo[2001];
int a[2001];
int main(){
    int n1,n2;
    scanf("%d",&n1);
    memset(bo,0,sizeof(bo));
    memset(num, 0 ,sizeof(num));
    int x;
    double nums;
    for(int i = 0; i < n1; ++i){
        scanf("%d",&a[i]);
        scanf("%lf",&b[i]);
    }
    scanf("%d",&n2);
    for(int i = 0; i < n2; ++i){
        scanf("%d",&x);
        scanf("%lf",&nums);
        for(int j = 0 ; j < n1; ++j){
            num[a[j]+x] += b[j]*nums;
            bo[a[j]+x]=1;
        }
        
    }
    int i = 2000;
    int cnt = 0;
    for(; i >= 0; --i){
        if(bo[i] && num[i] != 0){
            cnt++;
        }
    }
    printf("%d",cnt);
    i = 2000;
    for(; i >= 0;--i){
        if(bo[i] && num[i] != 0)
        printf(" %d %.1lf",i, num[i]);
    }
    
}