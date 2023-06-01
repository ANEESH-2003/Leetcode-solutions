//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void cal(vector<int>& v,vector<int>& ans,int& n,int i,int s)
    {
        if(i==n)
        {
            ans.push_back(s);
            return;
        }
        cal(v,ans,n,i+1,s);
        cal(v,ans,n,i+1,s+v[i]);
    }
    vector<int> subsetSums(vector<int> v, int n)
    {
        vector<int> ans;
        cal(v,ans,n,0,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends