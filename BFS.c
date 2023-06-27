#include <stdio.h>
int queue[10];
int vis[10];
int matrix[10][10];
int front=1,rear=0;

void push(int a){
    queue[rear]=a;
    rear++;
}
int pop(){
    return queue[front++];
}

void bfs(int n, int size){
    for(int i=1;i<=size;i++){
        if(matrix[n][i]==1 && vis[i]==0){
            push(i);
            printf("%d\t",i);
            vis[i]=1;
        }
    }
    int m=pop();
    bfs(m,size);
};

int main(){
    printf("enter the number of vertices\n");
    int size;
    scanf("%d",&size);
    printf("enter the adjacency matrix\n");
    for(int i =1;i<=size;i++){
        for(int j =1;j<=size;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("BFS Traversal\n");
    for(int i=1;i<=size;i++){
        if(vis[i]==0){
            printf("%d\t",i);
            vis[i]=1;
            push(i);
            bfs(i,size);
        }
    }
    return 0;
}
