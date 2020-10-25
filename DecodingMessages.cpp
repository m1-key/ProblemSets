// A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// You have to determine the total number of ways that message can be decoded.
// Example:
// Input:
// 2
// 3
// 123
// 4
// 2563
// Output:
// 3
// 2

#include<bits/stdc++.h>
using namespace std;

int dec(string s,int n)
{
    int dp[n+1],c=0;
    dp[0]=1;
    dp[1]=1;
    if(s[0]=='0')
    return 0;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]=='0'&&s[i+1]=='0')
        return 0;
        
    }
    for(int i=2;i<n+1;i++)
    {
        dp[i]=0;
        if(s[i-1]>'0')
        dp[i]=dp[i-1];
        if(s[i-2]=='1'||s[i-2]=='2'&&s[i-1]<'7')
        dp[i]+=dp[i-2];
        
    }
    return dp[n];
}
int main() {
	//code
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    cout<<dec(s,n)<<"\n";
	}
	return 0;
}
