#include<bits/stdc++.h>
using namespace std;


bool possible(int n, int k)
{
    int temp;
    if(n%2==0)
        temp=n/2;
    else
        temp= (n/2)+1;
    //68//34
    int sharma=0;
    if(k==0)
        return false;
    while(n>k)
    {   n-=k;
        sharma+=k;
        n-=n/10;
	}
    sharma+=n;
    if(sharma>=temp)
        return true;
    else
        return false;
}

int main()
{
    int n;cin>>n;
    int k;

	int start = 0;
    int end =n;
    int mid;
    int ans=n;
    while(start<=end)
    {

        mid=start+(end-start)/2;

        if(possible(n,mid))
        { if(mid<ans)
            ans=mid;
        end=mid-1;
        }

        else{
            start = mid+1;
        }

    }

    cout<<ans;




    return 0;



}
