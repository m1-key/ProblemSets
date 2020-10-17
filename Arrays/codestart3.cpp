#include <bits/stdc++.h>

using namespace std;


long main()
{
    long n;cin>>n;long a[n];long b[n];
    
    for (long i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for (long i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    long k;
    cin>>k;

    long long sum=0;
    
    map<long,long> m;
    map<long, long>::iterator it;

    for (long i= 0; i < n; i++)
    {
        m[a[i]]=i;
    }
    
    set<long> s;
    long count=0;

    for(it=m.begin();it!=m.end();it++)
    {
        if(count<k)
        {
            if(a[it->second]<b[it->second])
            {sum+=it->first;
            s.insert(it->second);}
            else
            {
                continue;
            }
            count++;
        }
        else
        {
            break;
        }
    }

    for(int i = 0;i<n;i++)
    {
        if(s.find(i)!=s.end())
            continue;
        else{

            sum+=min(a[i],b[i]);

        }
    }
    
    cout<<sum;
}