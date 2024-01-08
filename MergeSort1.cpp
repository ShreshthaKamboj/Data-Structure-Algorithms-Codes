#include<iostream>
using namespace std;

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
};

int merge(int array[],int l,int m,int r){
    int subarray1=m-l+1;
    int subarray2=r-m;
    int* leftarray=new int[subarray1];
    int* rightarray=new int[subarray2];
    for(int i=0;i<subarray1;i++){
        leftarray[i]=array[l+i];
    }
    for(int j=0;j<subarray2;j++){
        rightarray[j]=array[m+1+j];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<subarray1 && j<subarray2){
        if(leftarray[i]<=rightarray[j]){
            array[k++]=leftarray[i];
            i=i+1;
        }
        else{
            array[k++]=rightarray[j];
            j=j+1;
        }
    }
    while(i<subarray1){
        array[k++]=leftarray[i];
        i=i+1;
    }
    while(j<subarray2){
        array[k++]=rightarray[j];
        j=j+1;
    }
    delete[] leftarray;
    delete[] rightarray;
};

int mergesort(int array[],int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        mergesort(array,l,mid);
        mergesort(array,mid+1,r);
        merge(array,l,mid,r);
    }
};

int main(){
    int array[]={20,7,14,10,11,9,3};
    int size=sizeof(array)/sizeof(array[0]);
    int left=0;
    int right=size-1;
    mergesort(array,left,right);
    print(array,size);
    return 0;
}