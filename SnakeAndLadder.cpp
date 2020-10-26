// Given a snake and ladder board of order 5x6, find the minimum number of dice throws required to reach the destination or last cell (30th cell) from source (1st cell) .
// Example:
// Input:
// 2
// 6
// 11 26 3 22 5 8 20 29 27 1 21 9
// 1
// 2 30

// Output:
// 3
// 1

#include<bits/stdc++.h>
using namespace std;
int func(int move[30],int dis[30],int i)
{
    if(dis[i]==INT_MAX)
    {
        if(move[i]==-1)
        {
            for(int j=i+1;j<=i+6&&j<30;j++)
            {
                dis[i]=min(dis[i],1+func(move,dis,j));
            }
        }
        else
        {
            dis[i] = func(move,dis,move[i]);
        }
    }
    return dis[i];
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,a,b;
	    cin>>n;
	    int move[30],dis[30];
	    int i;
	    for(i=0;i<30;i++)
	    {
	        move[i]=-1;
	        dis[i]=INT_MAX;
	    }
	    for(i=0;i<n;i++)
	    {
	        cin>>a>>b;
	        move[a-1]=b-1;
	        if(a>b)
	        dis[a-1]=100;
	    }
	    dis[29]=0;
	    cout<<func(move,dis,0)<<"\n";
	}
	return 0;
}
