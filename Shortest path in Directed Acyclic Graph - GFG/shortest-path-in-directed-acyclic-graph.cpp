//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> v(n);
        for(auto i:edges)
        {
            v[i[0]].push_back({i[1],i[2]});
        }
        vector<int> ans(n,INT_MAX);
        set<pair<int,int>> p;
        p.insert({0,0});
        ans[0]=0;
        while(!p.empty())
        {
            auto x=p.begin();
            pair<int,int> f=*x;
            p.erase(x);
            for(auto i:v[f.second])
            {
                if(ans[i.first]>f.first+i.second)
                {
                    if(ans[i.first]!=INT_MAX)
                        p.erase(p.find({ans[i.first],i.first}));
                    ans[i.first]=f.first+i.second;
                    p.insert({ans[i.first],i.first});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]==INT_MAX)
                ans[i]=-1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends