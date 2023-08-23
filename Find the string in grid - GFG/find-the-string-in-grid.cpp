//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> v;
    int n,x;
    bool cal(vector<vector<char>> m,string s,int r,int c,int ir,int ic,int h)
    {
        while(r>=0 && r<n && c>=0 && c<x && h!=s.size())
        {
            if(m[r][c]!=s[h])
                break;
            h++;
            r+=ir;
            c+=ic;
        }
        if(h==s.size())
            return true;
        return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>m, string s){
	    vector<vector<int>> v;
	    n=m.size();
	    x=m[0].size();
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<x;j++)
	        {
	            int h=0;
	            if(m[i][j]==s[h])
	            {
	                if(cal(m,s,i,j,1,0,h))
	                {
	                    v.push_back({i,j});
	                    continue;
	                }
	                if(cal(m,s,i,j,0,1,h))
	                {
	                    v.push_back({i,j});
	                    continue;
	                }
	                if(cal(m,s,i,j,1,-1,h))
	                {
	                    v.push_back({i,j});
	                    continue;
	                }
	                if(cal(m,s,i,j,-1,1,h))
	                {
	                    v.push_back({i,j});
	                    continue;
	                }
	                if(cal(m,s,i,j,-1,0,h))
	                {
	                    v.push_back({i,j});
	                    continue;
	                }
	                if(cal(m,s,i,j,0,-1,h))
	                {
	                    v.push_back({i,j});
	                    continue;
	                }
	                if(cal(m,s,i,j,1,1,h))
	                {
	                    v.push_back({i,j});
	                    continue;
	                }
	                if(cal(m,s,i,j,-1,-1,h))
	                {
	                    v.push_back({i,j});
	                    continue;
	                }
	            }
	        }
	    }
	    return v;
	}
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends