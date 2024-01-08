#include<iostream>
using namespace std;

int main(){
    char A[2]={'b','d'};
    char B[4]={'a','b','c','d'};
    int lcs[3][5];
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            if(i==0 or j==0){
                lcs[i][j]=0;
            }
            else if(A[i]==B[j]){
                lcs[i][j]=1+lcs[i-1][j-1];
            }
            else{
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
            cout<<lcs[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}