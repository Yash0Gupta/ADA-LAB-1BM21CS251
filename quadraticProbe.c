#include<stdio.h>
#include<math.h>
#define SIZE 10

int hash[10];
void insert_with_quadratic_probing(int);
int hashing_fun(int);

int main(){
    int item;
    for(int i=0; i<10;i++){
        printf("Enter the number to be inserted\n");
        scanf("%d", &item);
        insert_with_quadratic_probing(item);
        printf("\n");
        for(int j = 0;j<10; j++){
        printf("%d ", hash[j]);
        }
    }

    return 0;
}

void insert_with_quadratic_probing(int item){
    int key = hashing_fun(item);
    int index;
    for(int i =0; i<10; i++){
        index = (key+i*i)%SIZE;
        if(hash[index] == 0 ){
        hash[index] = item;
        printf("Inserted %d at index %d\n", item, index);
        break;
        }
    }
}

int hashing_fun(int x){
    return x%SIZE;
}
