//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void cal(vector<string>& v,int i,string& s,string x,vector<int>& vis)
    {
        if(i==s.size())
        {
            v.push_back(x);
            return;
        }
        for(int j=0;j<s.size();j++)
        {
            if(vis[j])
                continue;
            vis[j]++;
            string f=x;
            f+=s[j];
            cal(v,i+1,s,f,vis);
            vis[j]--;
        }
    }
    vector<string> permutation(string s)
    {
        vector<string> v;
        string x="";
        vector<int> vis(s.size(),0);
        cal(v,0,s,x,vis);
        sort(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends