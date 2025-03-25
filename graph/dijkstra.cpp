#include<iostream>
#include<vector>
#include <unordered_map>
#include<set>
#include<limits>
#include<list>
using namespace std;
class graph{
    public:
    // Adjacency list to store the graph (node -> list of {neighbor, weight})
    unordered_map<int,list<pair<int,int> > > adj;
    // Function to add an undirected edge between two nodes with a specified weight
    void addEdge(int u,int v,int weight){
        adj[u].push_back(make_pair(v,weight)); // Add edge from u to v
        adj[v].push_back(make_pair(u,weight)); // Add edge from v to u (since undirected)
    }

    // Function to print the adjacency list of the graph
    void printAdj(){
        // Iterate through each node and its neighbors
        for(auto i: adj){
            cout<< i.first << " -> ";
            for(auto j: i.second){
                cout<< "( "<<j.first << ", "<< j.second << ") "; // Print the neighbor and its weight
            }
            cout<<endl;
        }
    }

    // Function to implement Dijkstra's algorithm
    // shortestPath stores the shortest path from source to each node
    // s is a set that helps find the node with the minimum cost (distance) efficiently
    void dijkstra(vector<int> &shortestPath, set<pair<int,int> > &s){
        int src = 0; // Source node (starting point of Dijkstra's algorithm)
        s.insert(make_pair(0, src)); // Insert source node with distance 0
        shortestPath[src] = 0; // Distance from source to itself is 0

        // Run the algorithm while there are nodes to process in the set
        while(!s.empty()){
            // Pick the node with the smallest distance (minimum cost) from the set
            auto top = *s.begin(); 
            int node = top.second; // Current node
            int cost = top.first; // Current cost (distance) of the node
            s.erase(s.begin()); // Remove the node from the set (processed)

            // Loop through each neighbor of the current node
            for(auto neighbours: adj[node]){
                // If a shorter path to the neighbor is found, update the shortestPath
                if(neighbours.second + cost < shortestPath[neighbours.first]){
                    // Remove the old pair for this neighbor from the set if it exists
                    auto record = s.find(make_pair(shortestPath[neighbours.first], neighbours.first));
                    if(record != s.end()){
                        s.erase(record);
                    }
                    
                    // Update the shortest path to the neighbor
                    shortestPath[neighbours.first] = neighbours.second + cost;
                    
                    // Insert the updated pair into the set (with the new cost)
                    s.insert(make_pair(shortestPath[neighbours.first], neighbours.first));
                }
            }
        }
    }
};

int main(){
    graph g;

    int n, e;

    // Input: number of nodes and edges in the graph
    cout << "enter the number of nodes ";
    cin >> n;
    cout << endl;
    cout << "enter the number of edges ";
    cin >> e;

    // Input edges and their weights
    for(int i = 0; i < e; i++){
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight); // Add the edge to the graph
    }

    // Print the graph to visualize its structure
    g.printAdj();

    // Initialize the shortestPath array with infinity (INT_MAX)
    vector<int> shortestPath(n, INT_MAX);

    // Set for Dijkstra's algorithm: stores {cost, node} pairs
    set<pair<int, int> > s;

    // Call Dijkstra's algorithm to find the shortest paths
    g.dijkstra(shortestPath, s);

    // Output the shortest distances from the source node (0) to all other nodes
    for(int i = 0; i < n; i++){
        cout << shortestPath[i] << " ";
    }

    return 0;
}
