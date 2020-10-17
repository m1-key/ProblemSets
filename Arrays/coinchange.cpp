#include <bits/stdc++.h>

using namespace std;


int countWaysToMakeChange(int arr[], int n, int v){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    
  int dp[v][n];
  dp[0][0] = 0;

  for (int i = 1; i < n; i++)
  {
      /* code */
      dp[0][i]=1;
  }
  for (int i = 1; i < v; i++)
  {
      /* code */
      dp[0][i]=0;
  }

  for (int i = 2; i < v; i++)
  {
      for (int j = 2; j < n; j++)
      {
          dp[i][j]=dp[i][j-1] + dp[i-j][j];
      }
      
  }
  

}


int main() {

    int n; cin>>n;
    int arr[n];
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
    }
    int v;cin>>v;
    int x  = countWaysToMakeChange(arr,n,v);

    return 0;
}