#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

// This function checks if a graph is cyclic using BFS traversal.
// The core idea is to detect if there is a back edge in the graph that forms a cycle.
// A cycle exists if, during BFS traversal, we encounter a node that has already been visited 
// and is not the parent of the current node being explored. This indicates a back edge,
// which completes a cycle in an undirected graph.
//
// Steps:
// 1. Start BFS from any unvisited node, marking it as visited.
// 2. For each node, explore its neighbors:
//    - If a neighbor has already been visited, and it is not the parent of the current node, 
//      it means we found a back edge, and hence the graph contains a cycle.
//    - If a neighbor is unvisited, mark it as visited and continue the BFS by adding it to the queue.
// 3. If BFS completes without detecting any back edge, then the graph is acyclic.
//
// In an undirected graph, we maintain a parent array to ensure that we don’t falsely
// detect a back edge to the node's parent as a cycle. This helps in distinguishing
// a valid back edge (forming a cycle) from a normal bidirectional edge between two adjacent nodes.
//
// This BFS cycle detection method ensures that each node is processed only once,
// leading to a time complexity of O(V + E), where V is the number of vertices
// and E is the number of edges in the graph.

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
    bool isCyclicBFS(unordered_map<int,bool> &visited,int start){
      unordered_map<int,int> parent;
      queue<int> q;
      q.push(start);
      visited[start] = 1;
      parent[start] = -1;
      while(!q.empty()){
          int front = q.front();
          q.pop();
          
          for(auto neighbours: adjList[front]){
              if(visited[neighbours] == true && neighbours != parent[front]){
                  return true;
              }
              else if(!visited[neighbours])
              {
                  q.push(neighbours);
                  visited[neighbours] = 1;
                  parent[neighbours] = front;
              }
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
     for (auto node : g.adjList) {
        if (!visited[node.first]) {  // If node is not visited
            if (g.isCyclicBFS(visited, node.first)) {
                ans = true;
                break;  // Exit loop as cycle is found
            }
        }
    }
   if(ans){
    cout<< " It is a cyclic Graph"<<endl;
   }
   else{
    cout<< "Not a cyclic graph"<<endl;
   }
}
