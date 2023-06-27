#include<stdio.h>
#include<conio.h>
int a[10][10],vis[10],E[10],n,J=0;
void dfs(int v);
void main(){
    int m,c,d;
    printf("Enter the number of vertices");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            a[i][j]=0;
        }
    }
    printf("Enter the number of edges");
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        printf("Enter the edges");
        scanf("%d%d",&c,&d);
        a[c][d]=1;
    }

    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
        }
    }
    printf("Topological Order\n");
    for(int i=n-1;i>=0;i--){
        printf("%d\t",E[i]);
    }
}

void dfs(int v){
    vis[v]=1;
    for(int i=1;i<=n;i++){
        if(a[v][i]==1 && vis[i]==0){
            dfs(i);

        }
    }
    E[J++]=v;
}

