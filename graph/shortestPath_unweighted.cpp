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
    void shortestPath(unordered_map<int,bool> &visited,int src,int destination,vector<int> &path,unordered_map<int,int> &parent){
            visited[src] = 1;
            parent[src] = -1;
            queue<int> q;

            q.push(src);

            while(!q.empty()){
                int front = q.front();
                q.pop();

                for(int i: adjList[front]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i] = 1;
                        parent[i] = front;
                    }
                }
            }
            path.push_back(destination);

            while(destination != src){
                destination = parent[destination];
                path.push_back(destination);
            }
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
    unordered_map<int,int> parent;
    vector<int> path;

    int destination;
    cout<< "enter the destination you want to reach: ";
    cin>> destination;
    
    g.shortestPath(visited,0,destination,path,parent);

    reverse(path.begin(),path.end());

    for(int i = 0;i<path.size();i++){
        cout<< path[i] << "-> ";
    }
    // int startNode;
    // cout<< "Enter the starting node -> ";
    // cin>> startNode;
}

