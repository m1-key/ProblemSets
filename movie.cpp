#include<bits/stdc++.h>
using namespace std;

bool compare(pair<long, long> p1, pair<long, long> p2){
    return p1.second < p2.second;
}


int main()
{
    long n;cin>>n;
    vector<pair<long,long>> m;
    for (long i = 0; i < n; i++)
    {
        long x,y;cin>>x>>y;
        m.push_back(make_pair(x,y));
    }
    
    sort(m.begin(),m.end(),compare);
    
    long count = 1;
    long prev = 0;
    for (long i = 1; i < n; i++)
    {
        if(m[prev].second<=m[i].first)
        {
        count++;
        prev = i;
        }
    }
    cout<<count;


}