// There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.

// Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.

// What is the minimum number of gondolas needed for the children?

// Input

// The first input line contains two integers n and x: the number of children and the maximum allowed weight.

// The next line contains n integers p1,p2,…,pn: the weight of each child.

// Output

// Print one integer: the minimum number of gondolas.

// Constraints

//     1≤n≤2⋅105


// 1≤x≤109

// 1≤pi≤x


// Example

// Input:
// 4 10
// 7 2 3 9

// Output:
// 3



#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long x;
    cin>>n>>x;
    long a[n];

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int count=0;
    int temp = 0;
    sort(a,a+n);
    for (int i = 0; i <n; i++)
    {
        if(temp+a[i]==x)
        {count++;temp=0;}
        else if(temp+a[i]>x)
        {
            count++;
            temp=a[i];
        }
        else{
            temp+=a[i];
        }
    }
    if(temp>x)
    cout<<count+1;
    else
    {
        cout<<count;
    }
    

}