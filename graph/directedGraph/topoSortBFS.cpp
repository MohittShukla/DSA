#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
using namespace std;
//  so we can use this code to also find if a graph is cyclic or not if the number of nodes are equal to the count of
// numbers in the topological sort then it is an acyclic graph otherwise a cyclic graph
//  because valid topological sort only occur in acyclic graph
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
    void topoBFS(vector<int> &indegree,vector<int> &topologicalSort,int v){
        queue<int> q;
        for(int i = 0;i<v;i++){
            if(indegree[i]== 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            topologicalSort.push_back(front);

            for(auto neighbour : adjList[front]){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0){
                        q.push(neighbour);
                    }
                }
            }
        }
    }   
;
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
    vector<int> indegree(n);
    for(auto i: g.adjList){
        for(auto j: i.second){
            indegree[j]++;
        }
    }
    vector<int> topologicalSort;
    // int startNode;
    // cout<< "Enter the starting node -> ";
    // cin>> startNode;
       g.topoBFS(indegree,topologicalSort,n);
        for(int i = 0;i<topologicalSort.size();i++){
            cout<< topologicalSort[i]<< " ";
        }
        if (topologicalSort.size() != n) {
    cout << "The graph contains a cycle. Topological sort is not possible." << endl;
} 
}
