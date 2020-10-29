#include<bits/stdc++.h>
using namespace std;
const int V = 9;
int min_element(vector<int> &dist, vector<bool> &visited) {
    int min = INT_MAX;
    int min_ele = 0;
    for(int i=0;i<V;i++) {
        if(!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_ele = i;
        }
    }
    return min_ele;
}

void dijkstra_path(int src, int graph[V][V]) {
    vector<int> dist(V,INT_MAX);
    vector<bool> visited(V,false);
    dist[src] = 0;
    for(int i=0;i<V-1;i++) {
        int u = min_element(dist,visited);
        visited[u] = true;
        for(int j=0;j<V;j++) {
            if(!visited[j] && dist[u] != INT_MAX && graph[u][j] && dist[j] > dist[u] + graph[u][j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
    cout<<"Min dist of elements from "<< src <<" is: \nV | dist\n";
    for(int i=0;i<V;i++) {
        cout<<i<<" | "<<dist[i]<<"\n";
    }
}

int main() {
    
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    dijkstra_path(4, graph);
}