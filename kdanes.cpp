#include<bits/stdc++.h>
using namespace std;

int main()
{
    long n;
    cin>>n;
    long a[n];
    for (long i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    long max_so_far = a[0]; 
    long curr_max = a[0]; 
  
   for (long i = 1; i < n; i++) 
   { 
        curr_max = max(a[i], curr_max+a[i]); 
        max_so_far = max(max_so_far, curr_max); 
   } 
   cout<<max_so_far; 

}