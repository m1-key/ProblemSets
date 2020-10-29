#include<bits/stdc++.h>
using namespace std;

int length_path(string start,string target,set<string> D) {
    if(D.find(target) == D.end()) return 0;
    queue<string> q;
    q.push(start);
    int level = 0;
    while(q.empty() == false) {
        level++;
        for(int j=0;j<q.size();j++) {
            string word = q.front();
            q.pop();
            for(int i=0;i<word.length();i++) {
                char b = word[i];
                for(char c = 'a';c<='z';c++) {
                    word[i] = c;

                    if(word == target) return level+1;

                    if(D.find(word) == D.end()) continue;
                    D.erase(word);

                    q.push(word);
                }
                word[i] = b;
            }
        }    
    }
    return 0;
}

int main() {
    set<string> D; 
    D.insert("poon"); 
    D.insert("plee"); 
    D.insert("same"); 
    D.insert("poie"); 
    D.insert("plie"); 
    D.insert("poin"); 
    D.insert("plea"); 
    string start = "toon"; 
    string target = "plea"; 
    cout<<length_path(start,target,D);
}