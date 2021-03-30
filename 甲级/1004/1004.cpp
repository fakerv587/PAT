#include<cstdio>
#include<iostream>

using namespace std;
int maxx = 0;
int ans[101],d[101],f[101][101];
int n;
bool bo[101];
int read(){
    char ch = getchar();
    int num = 0;
    while(ch < '0' || ch >'9')ch = getchar();
    while(ch >= '0' && ch <= '9'){
        num = num*10 + (int)(ch - '0');
        ch = getchar();
    }
    return num;
}
void dfs(int x){
    for(int i = 1; i <= n; ++i){
        if(f[x][i]){
            bo[x] = 1;
            d[i] = d[x] + 1;
            dfs(i);
        }
    }
    if(!bo[x]){
        ans[d[x]]++;
        maxx = max(maxx,d[x]);
    }
}
int main(){
    n = read();
    int k = read();
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j)
            f[i][j] = 0;
        bo[i] = 0;
    }

    for(int i = 0; i < k; ++i){
        int id = read();
        int sonNum = read();
        for(int j = 0; j < sonNum; ++j){
            int sonId = read();
            f[id][sonId] = 1;
            bo[sonId] = 1;
        }
    }
    int root = -1;
    for(int  i = 1; i <= n; ++i){
        if(!bo[i]){
            root = i;
            break;
        }
    }
    for(int i = 1; i <= n; ++i)
        bo[i] = 0;
    d[root] = 0;
    dfs(root);
    
    for(int i = 0; i < maxx; ++i){
        printf("%d ",ans[i]);
    }
    printf("%d",ans[maxx]);
    return 0;
}