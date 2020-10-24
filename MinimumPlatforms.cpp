// Given arrival and departure times of all trains that reach a railway station. Your task is to find the minimum number of platforms required for the railway station so that no train waits.
// Example:
// Input:
// 2
// 6 
// 0900  0940 0950  1100 1500 1800
// 0910 1200 1120 1130 1900 2000
// 3
// 0900 1100 1235
// 1000 1200 1240 

// Output:
// 3
// 1

#include<bits/stdc++.h>
using namespace std;
int pl(int a[],int d[],int n)
{
    sort(a,a+n);
    sort(d,d+n);
    int i=0,j=0,p=0,res=0;
    while(i<n&&j<n)
    {
        if(a[i]<=d[j])
        {
            p++;
            i++;
        }
        else if(d[j]<a[i])
        {
            p--;
            j++;
        }
        if(res<p)
        res=p;
    }
    return res;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int i,a[n],d[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    for(i=0;i<n;i++)
	    cin>>d[i];
	    cout<<pl(a,d,n)<<"\n";
	}
	return 0;
}
