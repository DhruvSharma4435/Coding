//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool cycle(int s,  vector<bool>& visited,  vector<bool>& dfsvisited, vector<int> adj[]){
        visited[s]=true;
        dfsvisited[s]=true;
        for(auto x: adj[s]){
            if(!visited[x]){
            if(cycle(x,visited,dfsvisited,adj)) return true;
            }
            else if(visited[x]==true && dfsvisited[x]==true) return true;
        }
        dfsvisited[s]=false;
        return false;
    }
    
    
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V,false);
        vector<bool> dfsvisited(V,false);
        for(int i=0; i<V; i++){
            if(!visited[i]) {
                if(cycle(i,visited,dfsvisited,adj))
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends