// In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?
// Input
// The first input line has an integer n: the number of movies.
// After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.
// Output
// Print one integer: the maximum number of movies.
// Constraints
//     1≤n≤2⋅105
// 1≤a<b≤109
// Example
// Input:
// 3
// 3 5
// 4 9
// 5 8
// Output:
// 2
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long n,x,y;cin>>n;
    vector<tuple<int, int>> v(n);
    for (long i = 0; i < n; i++)
    {
        cin>>x>>y;
        v[i]={y,x};
    }
    sort(v.begin(),v.end());
    long count=0,temp=0;
    

}