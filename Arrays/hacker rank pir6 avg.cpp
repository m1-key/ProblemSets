#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int n;cin>>n;
    long arr[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);

    int max_diff = arr[n-1]-arr[0];
    long min_diff=0;

    for (int  i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; i++)
            if(arr[i]-arr[j]<min_diff)
                min_diff=arr[i]-arr[j];
    }
    long count=0;
    std::cout<<"makichu"<<endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; i++)
        {
            long d_min = min_diff;
            long d_max = max_diff;
            long mid;
            std::cout<<mid<<" ";
            while (d_min<=d_max)
            {
                mid = d_min+(d_max-d_min)/2;
                if(arr[j]-arr[i]>mid)
                    d_min=mid-1;
                else if(arr[j]-arr[i]==mid)
                {
                    count++;
                    break;
                }
                else
                {
                    d_max=mid+1;
                }
                
            }
            
        }
        std::cout<<count<<" "<<endl;
    }
    std::cout<<count;
    
    
    
    
    return 0;
}