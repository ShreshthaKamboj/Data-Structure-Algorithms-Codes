#include<iostream>
using namespace std;

void compareit(int first, int second, int third)
{
    if(first>second)
    {
        if(first>third)
        {
            cout<<"First is the greatest";
        }
        else
        {
            cout<<"Third is the greatest";
        }
    }
    else
    {
        if(second>third)
        {
            cout<<"Second is the greatest";
        }
        else
        {
            cout<<"Third is the greatest";
        }
    }
}

int main()
{
    int firstnumber,secondnumber,thirdnumber;
    cout<<"Enter First number ";
    cin>>firstnumber;
    cout<<"Enter Second number ";
    cin>>secondnumber;
    cout<<"Enter Third number ";
    cin>>thirdnumber;
    compareit(firstnumber,secondnumber,thirdnumber);
    return 0;
}