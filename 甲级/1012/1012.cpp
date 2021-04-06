#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct S{
    int id,score[4];
    int rank[4];
    int best;
}student[2100];
int i;
int mm[1000000],n,m;
bool cmp(S a, S b){
    return a.score[i] > b.score[i];
}
int main(){
    cin>>n>>m;
    for(int i = 0 ; i < n; ++i){
        cin>>student[i].id>>student[i].score[1]>>student[i].score[2]>>student[i].score[3];
        student[i].score[0] = (student[i].score[1] + student[i].score[2] + student[i].score[3])/3.0 + 0.5;
    }
    for(i = 0 ; i < 4; ++i){
        sort(student, student + n, cmp);
        student[0].rank[i] = 1;
        for(int j = 1;j < n; ++j){
            student[j].rank[i] = j + 1;
            if(student[j].score[i] == student[j - 1].score[i]){
                student[j].rank[i] = student[j - 1].rank[i];
            }
        }
    }
    for(int j = 0; j < n; ++j){
        mm[student[j].id] = j + 1;
        int minn = student[j].rank[0];
        student[j].best = 0;
        for(int k = 1; k < 4; ++k){
            if(student[j].rank[k] < minn){
                minn = student[j].rank[k];
                student[j].best = k;
            }
        }
    }
    string r = "ACME";
    int x;
    for(int j = 0; j < m ; ++j){
        cin>>x;
        int tmp = mm[x];
        if(!tmp){
            printf("N/A\n");
        }
        else{
            tmp--;
            int q = student[tmp].best;
            printf("%d %c\n",student[tmp].rank[q],r[q]);
        }
    }
    return 0;
}