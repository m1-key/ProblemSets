#include <bits/stdc++.h>
using namespace std;

int fact(int n);

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// Returns factorial of n
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int main()
{
    int n;cin>>n;
    int x;cin>>x;

    int temp = n/x;

    int p=n-temp-1;
    if(p>0)
    {
        int ans=(nCr(2*p,p))/(p+1);
        ans = ans % 1000000007;
        cout<<ans;
    }
    else
        cout<<0;


}
