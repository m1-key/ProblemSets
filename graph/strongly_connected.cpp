#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<int> *adj;

    public:
        Graph(int V) {
            this->V = V;
            adj = new vector<int>[V];
        }
        void addEdge(int u,int v);
        void Connected();
        void Discover(int u,bool visited[],stack<int> &s);
        Graph Transpose();
        void Print(int u, bool visited[]);
};

void Graph:: addEdge(int u,int v) {
    adj[u].push_back(v);

}

// conected()
// descover()
// transpose()
// print();
void Graph::Discover(int u,bool visited[],stack<int> &s) {
    visited[u] = true;
    for(auto i:adj[u]) {
        if(visited[i] == false) {
            Discover(i,visited,s);
        }
    }
    s.push(u);
}

void Graph::Print(int u,bool visited[]) {
    visited[u] = true;
    cout<<u<<" ";
    for(auto i:adj[u]) {
        if(visited[i] == false) Print(i,visited);
    }
}

Graph Graph::Transpose() {
    Graph gr(V);
    for(int i=0;i<V;i++) {
        for(auto v:adj[i]){
            gr.adj[v].push_back(i);
        }
    }
    return gr;
}

void Graph::Connected() {
    bool visited[V];
    stack<int> s;
    for(int i=0;i<V;i++) visited[i] = false;
    for(int i=0;i<V;i++) {
        if(visited[i] == false) 
            Discover(i,visited,s);
    }
    Graph gr = Transpose();
    for(int i=0;i<V;i++) visited[i] = false;
    while(s.empty() == false) {
        int u = s.top();
        s.pop();
        if(visited[u] == false) {
            gr.Print(u,visited);
            cout<<endl;
        }
    }
}



int main() {
    // Create graphs given in above diagrams 
    Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
  
    cout << "Following are strongly connected components in "
            "given graph \n"; 
    g.Connected(); 
  
    return 0; 
}