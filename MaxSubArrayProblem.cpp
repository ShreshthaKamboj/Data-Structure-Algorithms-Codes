#include<iostream>
using namespace std;

int maxcrossingsubarray(int arr[],int l,int m,int h){
    int sum=0;
    int lsum=0;
    int maxl;
    for(int i=m;i>l;i--){
        sum=sum+arr[i];
        if(sum>lsum){
            lsum=sum;
            maxl=i;
        }
    }
    int rsum=0;
    sum=0;
    int maxr;
    for(int j=m+1;j<h;j++){
        sum=sum+arr[j];
        if(sum>rsum){
            rsum=sum;
            maxr=j;
        }
    }
    return(maxl,maxr,lsum+rsum);
};

int maxsubarray(int arr[],int l,int h){
    if(h==l){
        return(l,h,arr[l]);
    }
    else{
        int mid=(l+h)/2;
        int llow=maxsubarray(arr,l,mid),lhigh=maxsubarray(arr,l,mid),lsum=maxsubarray(arr,l,mid);
        int rlow=maxsubarray(arr,mid+1,h),rhigh=maxsubarray(arr,mid+1,h),rsum=maxsubarray(arr,mid+1,h);
        int clow=maxcrossingsubarray(arr,l,mid,h),chigh=maxcrossingsubarray(arr,l,mid,h),csum=maxcrossingsubarray(arr,l,mid,h);
        if(lsum>=rsum and lsum>=csum){
            return (llow,lhigh,lsum);
        }
        else if(rsum>=lsum and rsum>=csum){
            return (rlow,rhigh,rsum);
        }
        else{
            return (clow,chigh,csum);
        }
    }
};

int main(){
    int array[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int size=sizeof(array)/sizeof(array[0]);
    int l=0;
    int h=size-1;
    cout<<maxsubarray(array,l,h);
    return 0;
}