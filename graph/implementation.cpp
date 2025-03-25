#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

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
    //  BFS
    void bfs(int node, vector<int>& bfsTraversal, unordered_map<int, bool>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            bfsTraversal.push_back(frontNode);

            for (auto i : adjList[frontNode]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    //  DFS
    void dfs(unordered_map<int,bool> &visitedDfs,int start,vector<int> &dfsTraversal){
        visitedDfs[start] = 1;
        dfsTraversal.push_back(start);
        for(int values: adjList[start]){
            if(!visitedDfs[values]){
                dfs(visitedDfs,values,dfsTraversal);
            }
        }
    }
};

int main() {
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
    vector<int> bfsTraversal;

    // Perform BFS for all unvisited components
    int startNode;
    cout<< "Enter the starting node -> ";
    cin>> startNode;
    //  For bfs
   
    // we are writing this to print nodes that are disconnected from the graph;
    for(int i = 1;i<=n;i++){
        if(!visited[i]){
            g.bfs(i,bfsTraversal,visited);
        }
    }
    // Print BFS traversal result
    cout << "\nBFS Traversal: ";
    for (int i = 0; i < bfsTraversal.size(); i++) {
        cout << bfsTraversal[i] << " ";
    }
    cout << endl;

    //  for DFS

    vector<int> dfsTraversal;
    unordered_map<int,bool> visitedDfs;
    // this is for connected graph 
    

    // suppose if therea are graphs that are disconnected so we have to print every node

   for(int i = 1;i<=n;i++){
    if(!visitedDfs[i]){
        g.dfs(visitedDfs,i,dfsTraversal);
    }
   }
    cout << "\nDFS Traversal: ";
    for(int i= 0;i<dfsTraversal.size();i++){
        cout<< dfsTraversal[i]<< " ";
    }
    cout<<endl;

    return 0;
}
