#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

// Cycle detection in an undirected graph using DFS:
// 1. Traverse the graph using DFS, marking each node as visited.
// 2. For each node, check its neighbors:
//    - If a neighbor is not visited, recursively call DFS for that neighbor.
//    - If a neighbor is already visited and is not the parent of the current node,
//      it means we found a back edge, which indicates a cycle in the graph.
// 3. If we find such a back edge during DFS, return true (cycle detected).
// 4. If no back edge is found by the end of the DFS, return false (no cycle).

//  this is for undirected graph
class Graph {
public:
    unordered_map<int, list<int> > adjList;

    void addEdge(int u, int v, bool direction) {
        adjList[u].push_back(v);
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
    bool isCyclicDfs(int node,int parent,unordered_map<int, bool> &visited){
        visited[node] = true;
       
        //  cheching the neighbour of the nodes
        for(auto neighbour : adjList[node]){
            if(!visited[neighbour]){ // if the neighbour is not visited we will call the function for next iteration
                bool ans = isCyclicDfs(neighbour,node,visited);
                if(ans){
                    return true;
                }
            }
            else if(neighbour != parent){ // if we have encountered a node that has a visited neighbour but it is not
                                         // it's parent then we found that the graph contains a cycle...
                return true;
            }
        }
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
        g.addEdge(u, v, 0);  // Assume undirected graph
    }

    // Print the graph structure
    cout << "Graph representation:" << endl;
    g.printGraph();

    unordered_map<int, bool> visited;
    // int startNode;
    // cout<< "Enter the starting node -> ";
    // cin>> startNode;
    bool ans = false;
    for(int i = 0;i<n;i++){
        if(!visited[i]){

           if(g.isCyclicDfs(i,-1,visited)){
            ans = true;
            break;
           };
           
        }
    }
   if(ans){
    cout<< " It is a cyclic Graph"<<endl;
   }
   else{
    cout<< "Not a cyclic graph"<<endl;
   }
}
