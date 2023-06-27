#include<stdio.h>

int SIZE = 10;
int hash[10];
void insert_with_linear_probing(int);
int hashing_fun(int);

int main(){
    int item=0;
    for(int i=0; i<10;i++){
        printf("Enter the number to be inserted\n");
        scanf("%d", &item);
        insert_with_linear_probing(item);
        printf("\n");
        for(int j = 0;j<10; j++){
        printf("%d ", hash[j]);
        }
    }


    return 0;
}

void insert_with_linear_probing(int item){
    // hashing_fun(item);10
    int index;
    for(int i =0; i<100; i++){
        index = (item+i)%SIZE;
        if(hash[index]==0){
        hash[index] = item;
        printf("Inserted %d  at index %d\n", item, index);
        break;
        }
    }
}

int hashing_fun(int x){
    return x% SIZE;
}
