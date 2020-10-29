#include<bits/stdc++.h>
using namespace std;


int dp[102][102];


// function to find longest common subSTRING
int LCS(string s1, string s2,int n,int m) {
    int mr = 0;
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 0; 
// in case of longest common subsequence write dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

            mr= max(dp[i][j],mr);
        }
    }
    return mr;
}


int main() { 
    int t;
    cin>>t;
    string s1;
    string s2;
    int n,m;
    while(t--) {
    cin>>n>>m;
    cin>>s1;
    cin>>s2;
    memset(dp,-1,sizeof(dp));
    cout<<LCS(s1,s2,n,m)<<"\n";
    }
}