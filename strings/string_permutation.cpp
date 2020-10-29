#include<bits/stdc++.h>
using namespace std;
set<string> v;
void solve(string s,int l,int n) {
    if(l == n) {v.insert(s);}
    else
        for(int i=l;i<s.length();i++) {
            swap(s[l],s[i]);
            solve(s,l+1,n);
            swap(s[l],s[i]);
        }
}
int main() {
    string s;
    s = "ABCDE";
    solve(s,0,5);

    for(auto x:v)   cout<<x<<"\n";
}
