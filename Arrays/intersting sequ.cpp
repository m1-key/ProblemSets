#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,l;cin>>n>>k>>l;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    int min=arr[0];
    int max=arr[n-1];
    int cost;
    long ans =1000000;
     for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    for(int i=min;i<=max;i++)
    {
        cost=0;
        int dec=0;
        int inc=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]>i)
                dec+=(arr[j]-i);
            else{
                inc+=(i-arr[j]);
            }

            cost=k*(dec) + l*(inc-dec);
            cout<<"costs "<<cost<<" ";
        }

       if(cost==0)
           ans=0;
       else if(cost<ans)
            ans=cost;
	}
	cout<<ans;
}
