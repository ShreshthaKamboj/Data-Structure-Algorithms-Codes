#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isSafe(int result[], int x2, int y2)
{
	for(int i=0;i<x2;i++)
	{
		if(y2==result[i] || abs(x2-i)==abs(result[i]-y2))
		{
			return 0;
		}
	}
	return 1;
}

void nQueen(int result[],int x,int size)
{
	if(x==size)
	{
		cout<<"\nSolution Found!\n";
		for(int j=0;j<size;j++)
		{
			cout<<result[j]<<" ";
		}
		return;
	}
	for(int i=0;i<size;i++)
	{
		if(isSafe(result,x,i))
		{
			result[x]=i;
			nQueen(result,x+1,size);
		}
		
	}
}

int main()
{
	int result[4];
	nQueen(result,0,4);
	return 0;
}