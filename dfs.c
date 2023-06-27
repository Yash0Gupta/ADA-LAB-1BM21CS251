#include<stdio.h>
#include<conio.h>
void DFS(int);
int a[10][10],vis[10],n;
void main(){
    int i,j;
    printf("Enter the number of vertices ");
    scanf("%d",&n);
    printf("Enter the Adjacency Matrix\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("DFS Traversal\n");
    for(i=1;i<=n;i++){
        if(vis[i]==0){
            DFS(i);
        }
    }
    check();
    getch();
}

void DFS(int v){
    int i;
    vis[v]=1;
    printf("%d\t",v);
    for(i=1;i<=n;i++){
        if(a[v][i]==1 && vis[i]==0){
            DFS(i);
        }
}
}

void check(){
    for(int i=1;i<=n;i++){
        if(vis[i]!=1){
            printf("\nNot connected");
            return;
        }
    }
    printf("\nConnected");
}
