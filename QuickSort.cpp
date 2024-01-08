#include<iostream>
using namespace std;

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
};

int partition(int arr[],int l,int h){
    int pivot=arr[l];
    int i=l;
    int j=h;
    while(i<j){
        do{
            i++;
        }while(arr[i]<=pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[l],&arr[j]);
    return j;
};

void quicksort(int arr[],int l,int h){
    if(l<h){
        int j=partition(arr,l,h);
        quicksort(arr,l,j);
        quicksort(arr,j+1,h);
    }
};

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
};

int main(){
    int array[]={10,16,8,12,15,6,3,9,5};
    int size=sizeof(array)/sizeof(array[0]);
    int l=0;
    int h=size;
    quicksort(array,l,h);
    print(array,size);
    return 0;
};