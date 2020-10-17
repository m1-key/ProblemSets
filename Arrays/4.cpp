// There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
// Each customer announces the maximum price he or she is willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.
// Input
// The first input line contains integers n and m: the number of tickets and the number of customers.
// The next line contains n integers h1,h2,…,hn: the price of each ticket.
// The last line contains m integers t1,t2,…,tm: the maximum price for each customer.
// Output
// Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.
// If a customer cannot get any ticket, print −1.
// Constraints
// 1≤n,m≤2⋅105
// 1≤hi,ti≤109
// Example
// Input:
// 5 3
// 5 3 7 8 5
// 4 8 3
// Output:
// 3
// 8
// -1

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;    
    cin>>n>>m;
    vector <long> price(n),cus(m);
    for (int i = 0; i <n; i++)
        cin>>price[i];
    for (int i = 0; i <m; i++)
        cin>>cus[i];
    sort(price.begin(),price.end());
    vector<long>::iterator lb;
    for (int i = 0; i <m; i++)
    {
        lb = lower_bound(price.begin(),price.end(),cus[i]);
        if(*lb>cus[i])
            cus[i]=-1;
        else{
            cus[i]=*lb;
            price.erase(lb);
        }
    }
    for (int i = 0; i <m; i++)
        cout<<cus[i]<<" ";
}


