#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
using namespace std;

//  topological sort only happens in directed acyclic graph
// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of 
// vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.

class Graph {
public:
    unordered_map<int, list<int> > adjList;

    void addEdge(int u, int v, bool direction) {
        adjList[u].push_back(v);
        // since our graph is directed so we don't reach this condition because direction is 1;
        if (direction == 0) {
            adjList[v].push_back(u);
        }
    }

    void printGraph() {
        for (auto i : adjList) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
    void Topo(int node,unordered_map<int, bool> &visited,stack<int> &st){
        visited[node] = true;
        
        
       
        //  cheching the neighbour of the nodes
        for(auto neighbour : adjList[node]){
            if(!visited[neighbour]){ // if the neighbour is not visited we will call the function for next iteration
                Topo(neighbour,visited,st);
            }
           
        }
        st.push(node);
        
    }
    
    
};

int main(){
       Graph g;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 1);  // Since this is directed graph so we only make one edge
    }

    // Print the graph structure
    cout << "Graph representation:" << endl;
    g.printGraph();

    unordered_map<int, bool> visited;
    vector<int> topologicalSort;
    // int startNode;
    // cout<< "Enter the starting node -> ";
    // cin>> startNode;
    stack<int> st;
    for(int i = 0;i<n;i++){
        if(!visited[i]){
           g.Topo(i,visited,st);
        }
    }
        while(!st.empty()){
            int top = st.top();
            topologicalSort.push_back(top);
            st.pop();
        }

        for(int i = 0;i<topologicalSort.size();i++){
            cout<< topologicalSort[i]<< " ";
        }
  
}
