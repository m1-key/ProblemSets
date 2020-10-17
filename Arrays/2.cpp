/*
There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.
Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.
Input
The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum allowed difference.
The next line contains n integers a1,a2,…,an: the desired apartment size of each applicant. If the desired size of an applicant is x, he or she will accept any apartment whose size is between x−k and x+k.
The last line contains m integers b1,b2,…,bm: the size of each apartment.
Output
Print one integer: the number of applicants who will get an apartment.
Constraints
    1≤n,m≤2⋅105
0≤k≤109
1≤ai,bi≤109
Example
Input:
4 3 5
60 45 80 60
30 60 75
Output:
2
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    
    cin>>n>>m>>k;
    
    int app[n],apar[m];

    for (int i = 0; i <n; i++)
        cin>>app[i];
    
    for (int i = 0; i <m; i++)
        cin>>apar[i];

    sort(app,app+n);
    sort(apar,apar+m);
    int count =0;
    int i =0,j=0;
    while(i<m && j<n)
    {
        if(apar[i]<=app[j]+k && apar[i]>=app[j]-k)
        {
            count++;
            i++;
            j++;
        }
        else if (apar[i]<app[j]-k ){
            i++;
        }
        else if(apar[i]>app[j]+k){
            j++;
        }
    }
    
    cout<<count<<endl;
}