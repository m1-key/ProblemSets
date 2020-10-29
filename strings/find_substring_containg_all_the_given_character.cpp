#include<bits/stdc++.h>
using namespace std;

bool contain(char c[],int n,char chr) {
	for(int i=0;i<n;i++) 
		if(c[i] == chr) return true;
	return false;
}

int size_(string s,char c[],int n) {
	map<char,int> m;
	int ind1,ind2;
	int count = 0,best = INT_MAX;
	int left = 0;
	int right = 0;
	while(right < s.length()) {
		if(contain(c,n,s[right])) {
			if(m.count(s[right])) {
				m[s[right]]++;
				if(count != 0) count++;
			}
			else
				m[s[right]] = 1;
		}
		
		if(count == 0 && m.size() == n) {
			for(auto x:m)
				count += x.second;
		}
		if(m.size() == n) {
			while(m[s[left]] > 1 || m.count(s[left]) == 0 ) {
				if(m.count(s[left]) == 0) {
					left++;
					continue;
				}
				m[s[left]]--;
				count--;
				left++;
			}
		}
		if(count != 0) 
			if(count < best) {
				best = count;
				ind1 = left;
				ind2 = right;
			}
		right++;
	}
	count = min(best,count);
	if(count != 0) {
		while(ind1 <= ind2)
			cout<<s[ind1++];
		cout<<"\n";
	}
	return count;
}

int main() {
	string s;
	char c[3] = {'x','y','z'};
	cin>>s;
	cout<<size_(s,c,3);
}