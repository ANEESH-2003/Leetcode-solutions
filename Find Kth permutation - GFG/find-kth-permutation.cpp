//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string ans="";
    void cal(set<char>& s,int n,int k,int t)
    {
        if(n==0)
        {
            ans+=*s.begin();
            return;
        }
        t/=n;
        int x=k/t;
        ans+=*next(s.begin(), x);
        s.erase(next(s.begin(), x));
        cal(s,n-1,k%t,t);
    }
    string kthPermutation(int n, int k)
    {
        set<char> s;
        int t=1;
        for(int i=1;i<=n;i++)
        {
            s.insert((char)i+'0');
            t*=i;
        }
        ans="";
        cal(s,n,k-1,t);
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
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends