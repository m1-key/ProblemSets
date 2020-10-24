// Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
// Example:
// Input:
// 2
// 5
// 3 1 3 3 2
// 3
// 1 2 3

// Output:
// 3
// -1

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n],i;
	    unordered_map<int,int>h;
	    int x=-1;
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	        h[a[i]]++;
	        if(h[a[i]]>n/2)
	        x=a[i];
	    }
	    cout<<x<<"\n";
	}
	return 0;
}
