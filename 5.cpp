// You are given the arrival and leaving times of n customers in a restaurant.

// What was the maximum number of customers?

// Input

// The first input line has an integer n: the number of customers.

// After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.

// You may assume that all arrival and leaving times are distinct.

// Output

// Print one integer: the maximum number of customers.

// Constraints

//     1≤n≤2⋅105


// 1≤a<b≤109


// Example

// Input:
// 3
// 5 8
// 2 4
// 3 9

// Output:
// 2

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y;cin>>n;
    map <int, int> m;
    for (int i = 0; i < n; i++)
    {
            cin>>x>>y;
            m[x]+=1;
            m[y]+=-1;
    }
    int mx=0,sum=0;
    for(auto it: m){
    sum+=it.second;
    mx=max(mx,sum);
    }
    cout<<mx;

}