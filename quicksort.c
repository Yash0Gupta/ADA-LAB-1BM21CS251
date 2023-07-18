# include <stdio.h>
void QuickSort(int a[], int low,int high){
    int mid;
    if(low<high){
        mid=partition(a,low,high);
        QuickSort(a,low,mid);
        QuickSort(a,mid+1,high);
    }
}
int partition(int a[],int low,int high){
    int i=low+1;
    int j=high;
    int temp;
    int pivot=a[low];
    while(i<=j){
        while(a[i]<pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    QuickSort(a, 0, n-1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}