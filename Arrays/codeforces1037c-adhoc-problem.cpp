#include<bits/stdc++.h>

using namespace std;

int main(){

    long long  n;cin>>n;
    int a[n],b[n];

    for(int i=0;i<n;i++)
    cin>>a[i];

    for(int i=0;i<n;i++)
    cin>>b[i];

    long cost=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i])
            continue;
        if(a[i]!=a[i+1]&& a[i+1]!=b[i+1])
        {swap(a[i],a[i+1]);cost++;}
        else{
            if(a[i]==0)
                a[i]=1;
            else
                a[i]=0;
            cost++;
        }
    }
    cout<<cost;
}
