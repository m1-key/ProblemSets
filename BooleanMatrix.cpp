// Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1.
// Example:
// Input:
// 3
// 2 2
// 1 0
// 0 0
// 2 3
// 0 0 0 
// 0 0 1
// 4 3
// 1 0 0
// 1 0 0
// 1 0 0
// 0 0 0

// Output:
// 1 1
// 1 0
// 0 0 1 
// 1 1 1
// 1 1 1
// 1 1 1
// 1 0 0

#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    int i,j,x;
	    int r[m]={0};
	    int c[n]={0};
	    for(i=0;i<m;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            cin>>x;
	            if(x==1)
	            {
	                r[i]=1;
	                c[j]=1;
	            }
	        }
	    }
	    for(i=0;i<m;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            if(r[i]||c[j])
	            cout<<1<<" ";
	            else
	            cout<<0<<" ";
	        }
	        cout<<"\n";
	    }
	    
	}
	return 0;
}
