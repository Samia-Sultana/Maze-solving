#include<bits/stdc++.h>
#define ll long long int

using namespace std;
bool block[100][100], path[100][100];
int n, x;

bool maze(int a,int b)
{
    if(a==x && b==x)
    {
        path[a][b]=true;
        return true;
    }
    else if(!block[a][b])
        return false;
    if(a<x)
    {
        if(maze(a+1,b))
        {
            path[a][b]=true;
            return true;
        }
    }
    if(b<x)
    {
        if(maze(a,b+1))
        {
            path[a][b]=true;
            return true;
        }
    }
    return false;
}
bool Bpath(int a,int b)
{
     if(a==0 && b==0)
     {
         cout<<"["<<a+1<<","<<b+1<<"] ";
         return 1;
     }
     if(path[a-1][b])
     {
         Bpath(a-1,b);
         cout<<"-> "<<"["<<a+1<<","<<b+1<<"] ";
         return 1;
     }
     if(path[a][b-1])
     {
         Bpath(a,b-1);
         cout<<"-> "<<"["<<a+1<<","<<b+1<<"] ";
         return 1;
     }
     return false;
}
int main()
{
    int i,j,k;
    cin>>n;
    x=n-1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cin>>block[i][j];
    }
    path[0][0]=maze(0,0);
    cout<<endl<<"path matrix:"<<endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
    bool t;
    cout<<"path: ";
    t=Bpath(x,x);
    cout<<endl<<endl;


    return 0;
}

/*
4
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1
*/
