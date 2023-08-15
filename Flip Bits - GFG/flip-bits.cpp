//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int maxi=0;
        int s=0;
        for(int i=0;i<n;i++)
        {
            s+=1-(2*a[i]);
            if(s<0)
                s=0;
            maxi=max(maxi,s);
        }
        for(int i=0;i<n;i++)
            maxi+=a[i];
        return maxi;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends