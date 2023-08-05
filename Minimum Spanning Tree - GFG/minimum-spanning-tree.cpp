//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<int> vis(v,0);
        int ans=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> p;
        p.push({0,0});
        while(!p.empty())
        {
            vector<int> t=p.top();
            p.pop();
            if(vis[t[1]])
                continue;
            vis[t[1]]=1;
            ans+=t[0];
            for(auto i:adj[t[1]])
            {
                if(vis[i[0]])
                    continue;
                p.push({i[1],i[0]});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends