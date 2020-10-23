// You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one //quantity of each item.
// Example:
// Input:
// 2
// 3
// 4
// 1 2 3
// 4 5 1
// 3
// 3
// 1 2 3
// 4 5 6
// Output:
// 3
// 0
#include<iostream>
using namespace std;
int dp[1001][1001];
int kp(int w[],int v[],int wt,int n)
{
    int i,j;
    for(i=0;i<n+1;i++)
    for(j=0;j<wt+1;j++)
    {
    if(i==0||j==0)
    {
        dp[i][j]=0;
    }
    for(i=1;i<n+1;i++)
    for(j=1;j<wt+1;j++)
    if(w[i-1]<=j)
    {
        dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
    }
    else
    {
        dp[i][j]=dp[i-1][j];
    }
    }
    return dp[n][wt];
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,wt;
	    cin>>n;
	    cin>>wt;
	    int i,w[n],v[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>v[i];
	    }
	    for(i=0;i<n;i++)
	    {
	        cin>>w[i];
	    }
	    int x=kp(w,v,wt,n);
	    cout<<x<<"\n";
	}
	return 0;
}
