#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<int> *adj;
    void APUtil(int u,int disc[],int low[],int parent[],bool ap[],bool visited[]);
    public:
        Graph(int V) {
            this->V = V;
            adj = new vector<int>[V];
        }
        void addEdge(int u,int v);
        void AP();
};

void Graph:: addEdge(int u,int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph:: AP() {
    int disc[V];
    int low[V];
    int parent[V];
    bool ap[V];
    bool visited[V];
    for(int i=0;i<V;i++) {
        parent[i] = -1;
        disc[i] = -1;
        ap[i] = false;
        visited[i] = false;
    }
    for(int i=0;i<V;i++) {
        if(visited[i] == false) {
            APUtil(i,disc,low,parent,ap,visited);
        }
    }
    for(int i=0;i<V;i++) {
        if(ap[i] == true) cout<<i<<" ";
    }
    cout<<"\n";
}

void Graph::  APUtil(int u,int disc[],int low[],int parent[],bool ap[],bool visited[]) {
    static int time = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    for(auto i = adj[u].begin();i != adj[u].end();i++) {
        int v = *i;
        if(!visited[v]) {
            children++;
            parent[v] = u;
            APUtil(v,disc,low,parent,ap,visited);
            low[u] = min(low[v],low[u]);
            if(parent[u] == -1 && children > 1)
                ap[u] = true;
            if(parent[u] != -1 && low[v] >= disc[u])
                ap[u] = true;
        }
        else {
            low[u] = min(low[u],disc[v]);
        }
    }
}

int main() {
    // Create graphs given in above diagrams 
    cout << "\nArticulation points in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.AP(); 
  
    cout << "\nArticulation points in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.AP(); 
  
    cout << "\nArticulation points in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.AP(); 
  
    return 0; 
}