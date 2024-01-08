#include<iostream>
using namespace std;
int array[]={1,2,3,4,5};

void BinarySearch(int h,int m,int l,int e){
    if(array[m]==e)
    cout<<"Element "<<e<<" found at index :"<<m;   
    else if(e<array[m])
    BinarySearch(m-1,l+(h-l)/2,l,e);
    else
    BinarySearch(h,l+(h-l)/2,m+1,e);

};

int main(){
    int size=sizeof(array)/sizeof(array[0]);
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    int high=size-1;
    int mid=size/2;
    int low=0;
    int element;
    cout<<"enter the element to be searched :";
    cin>>element;
    BinarySearch(high,mid,low,element);
    return 0;
}