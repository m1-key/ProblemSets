// Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.
// Example:
// Input: 
// 2
// 7
// 6 2 5 4 5 1 6
// 4
// 6 3 4 2
// Output:
// 12
// 9

#include<iostream>
using namespace std;
#define arr a
#define left p
#define right q
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    long n;
	    cin>>n;
	    long i,a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    stack<long>s;
	    vector<long>p;
	    vector<long>q;
	    //nsl
	    for(i=0;i<n;i++)
	    {
	        if(s.size()==0)
	        p.push_back(-1);
	        else if(s.size()>0&&a[s.top()]<a[i])
	        p.push_back(s.top());
	        else if(s.size()>0&&a[s.top()]>=a[i])
	        {
	            while(s.size()>0&&a[s.top()]>=a[i])
	            s.pop();
	            if(s.size()==0)
	            p.push_back(-1);
	            else
	            p.push_back(s.top());
	        }
	        s.push(i);
	    }
	    while(!s.empty()) s.pop();
	    //nsr
	    for(i=n-1;i>=0;i--)
	    {
	        if(s.size()==0)
	        q.push_back(n);
	        else if(s.size()>0&&a[s.top()]<a[i])
	        q.push_back(s.top());
	        else if(s.size()>0&&a[s.top()]>=a[i])
	        {
	            while(s.size()>0&&a[s.top()]>=a[i])
	            s.pop();
	            if(s.size()==0)
	            q.push_back(n);
	            else
	            q.push_back(s.top());
	        }
	        s.push(i);
	    }
	    int area=0,ma=0;
	    for(i=0;i<n;i++)
	    {
	        area=a[i]*(q[n-i-1]-p[i]-1);
	        ma=max(area,ma);
	    }
	    cout<<ma<<"\n";
	    }
	return 0;
}
