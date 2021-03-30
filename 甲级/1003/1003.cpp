#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
int num[501],d[501],nums[501],w[501];
bool vis[501];
int map[501][501];
int n,m,s,t;
int max(int a,int b){
    return a>b?a:b;
}
void Dijkstra(){
    for(int i = 0; i < n; ++i){
        d[i] = 9999999;
        nums[i] = 0;
        w[i] = 0;
        vis[i] = 0;
    }
    d[s] = 0;
    w[s] = num[s];
    nums[s] = 1;
    for(int i = 0; i < n ; ++i){
        int  u = -1;
        int minn = 9999999;
        for(int j = 0 ;j < n; ++j){
            if(!vis[j] && d[j] < minn){
                u = j;
                minn = d[j];
            }
        }
        if(u == -1)return;
        vis[u] = 1;
        for(int j = 0 ;j < n; ++j){
            if(map[u][j]!=9999999 && !vis[j]){
                if(d[j] > map[u][j] + d[u]){
                    d[j] = map[u][j] + d[u];
                    w[j] = w[u] + num[j];
                    nums[j] = nums[u];
                }
                else if(d[j] == map[u][j] + d[u]){
                    w[j] = max(w[j], w[u] + num[j]);
                    nums[j] += nums[u];
                }
            }
        }
    }
}


int main(){
    scanf("%d %d %d %d",&n, &m, &s, &t);
    for(int i = 0 ;i < n ; ++i){
        scanf("%d", &num[i]);
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n;++j)
            map[i][j] = 9999999;
    }
    int u,v,ww;
    for(int i = 0; i < m; ++i){
        scanf("%d %d %d",&u, &v, &ww);
        map[u][v] = ww;
        map[v][u] = ww;
    }
    Dijkstra();
//     for(int i = 0 ;i < n ; ++i){
//         printf("%d ",w[i]);
//     }
//     cout<<endl;
    printf("%d %d", nums[t], w[t]);
    return 0;
}