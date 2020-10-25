// The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all n days. 
// The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
// For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int  i,a[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    stack<int> s;
	    vector<int> v;
	    for(i=0;i<n;i++)
	    {
	        if(s.size()==0)
	        {
	            v.push_back(-1);
	        }
	        else if(s.size()>0&&a[s.top()]>a[i])
	        {
	            v.push_back(s.top());
	        }
	        else if(s.size()>0&&a[s.top()]<=a[i])
	        {
	            while(s.size()>0&&a[s.top()]<=a[i])
	            s.pop();
	            if(s.size()==0)
	            v.push_back(-1);
	            else
	            v.push_back(s.top());
	        }
	        s.push(i);
	    }
	    for(i=0;i<n;i++)
	    {
	        v[i]=i-v[i];
	    }
	    for(i=0;i<n;i++)
	    {
	        cout<<v[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}
