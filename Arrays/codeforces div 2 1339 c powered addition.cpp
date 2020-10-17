#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--)
    {
        long n;
        cin>>n;
        long long arr[n];
        for(long i=0;i<n;i++)
        cin>>arr[i];
        unsigned long long t=0;
        for(long i=0;i<n-1;i++)
            {
                if(arr[i]>arr[i+1])
                {
                    cout<<"main hu yhaa tu khaa"<<endl;
                    long long dif = arr[i]-arr[i+1];
                    long double aka = (logl(dif)/logl(2));
                    cout<<dif<<" "<<aka;
                    unsigned long long temp = ceil((logl(dif)/logl(2)));
                    cout<<temp<<endl;
                    t= max(temp,t);
                    arr[i+1]=arr[i];
                }

            }
        cout<<t;
}

}
