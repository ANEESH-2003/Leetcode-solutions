//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        // Code here
        vector<int> v(n,INT_MAX);
        vector<vector<pair<int,int>>> g(n);
        for(int j=0;j<n;j++)
        {
            for(auto i:adj[j])
            {
                g[j].push_back({i[0],i[1]});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,s});
        v[s]=0;
        while(!q.empty())
        {
            pair<int,int> p=q.top();
            q.pop();
            for(auto i:g[p.second])
            {
                if(v[i.first]>i.second+p.first)
                {
                    v[i.first]=i.second+p.first;
                    q.push({v[i.first],i.first});
                }
            }
        }
        return v;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends