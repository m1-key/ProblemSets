#include<bits/stdc++.h>
using namespace std;


//  MINIMUM SPANNING TREE --- KRUSKALS ALGORITHIM

// using DSU ( Disjoint Union Set ) 

vector<pair<int,pair<int,int>>> g; // weight vertex1 vertex2
int v,e;

int *parent;

void make_set() {  // basically all the vertex in itself are unique tree so partent of vertex is vertex itself
    for(int i=0;i<v;i++) {
        parent[i] = i;
    }
}

int find_parent(int x) {  // as sets/tree go on connected we have a parent for all the vertext present in that set/tree 
    while(parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void union_(int p1,int p2) {  // as both parent are belongs to deifferent set or tree so we union that sets or trees ans make common parent (any)
    parent[p1] = parent[p2];
}

int cost_spanning_tree() {
    parent = new int[v];
    make_set();
    vector<pair<int,pair<int,int>>> p_s;
    int p1,p2;
    int a,b,w;
    int cost = 0;
    for(int i=0;i<e;i++) {
        a = g[i].second.first;
        b = g[i].second.second;
        w = g[i].first;
        p1 = find_parent(a);
        p2 = find_parent(b);
        if(p1 != p2) {
            p_s.push_back({w , { a , b }});
            union_(p1,p2);
            cost += w;
        }
    }
    cout<<"weight   |   src     |    dest \n";
    for(auto x:p_s) {
        cout<<x.first<<"    |   "<<x.second.first<<"    |    "<<x.second.second<<"\n";
    }
    return cost;
}


int main() {
    int a,b,w;
    cin>>v>>e;
    for(int i=0;i<e;i++) {
        cin>>a>>b>>w; // vertex1 vertex2 weight
        g.push_back({w,{a,b}}); // weight vertex1 vertex2 
    }
    sort(g.begin(),g.end());
    cout<<cost_spanning_tree();
}