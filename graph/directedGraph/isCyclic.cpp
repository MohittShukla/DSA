#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

// Function to detect a cycle in a directed graph using DFS.
// The approach uses two data structures:
// 1. `visited`: Tracks all nodes that have been visited across all DFS calls.
// 2. `dfsVisited`: Tracks nodes in the current DFS recursion stack.
//
// Steps:
// 1. Mark the current node as visited and part of the recursion stack (`dfsVisited`).
// 2. For each neighbor of the current node:
//    a. If the neighbor is not visited, recursively call the function for that neighbor.
//       If a cycle is found in the recursion, return true.
//    b. If the neighbor is already in the recursion stack (`dfsVisited`), a cycle is detected.
// 3. After exploring all neighbors, remove the current node from the recursion stack (`dfsVisited[node] = false`).
// 4. Check all disconnected components of the graph by iterating over all vertices.
// 5. If any DFS call detects a cycle, return true. Otherwise, return false.



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
    bool isCyclicDfs(int node,unordered_map<int, bool> &visited,unordered_map<int,bool> &dfsVisited){
        visited[node] = true;
        dfsVisited[node] = true;
       
        //  cheching the neighbour of the nodes
        for(auto neighbour : adjList[node]){
            if(!visited[neighbour]){ // if the neighbour is not visited we will call the function for next iteration
                bool ans = isCyclicDfs(neighbour,visited,dfsVisited);
                if(ans){
                    return true;
                }
            }
            else if(dfsVisited[neighbour]){ 
                return true;
            }
        }
        dfsVisited[node] = false;
        return false;
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
    unordered_map<int,bool> dfsVisited;
    // int startNode;
    // cout<< "Enter the starting node -> ";
    // cin>> startNode;
    bool ans = false;
    for(int i = 0;i<n;i++){
        if(!visited[i]){

           if(g.isCyclicDfs(i,visited,dfsVisited)){
            ans = true;
            break;
           };
           
        }
    }
   if(ans){
    cout<< " It is a cyclic directed Graph"<<endl;
   }
   else{
    cout<< "Not a cyclic directed graph"<<endl;
   }
}
