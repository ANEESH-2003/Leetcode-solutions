//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void cal(vector<int>& v,vector<int>& a,int i,vector<int> adj[])
    {
        v.push_back(i);
        a[i]++;
        for(auto j:adj[i])
        {
            if(!a[j])
                cal(v,a,j,adj);
        }
        return;
    }
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        vector<int> v;
        vector<int> a(n,0);
        cal(v,a,0,adj);
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends