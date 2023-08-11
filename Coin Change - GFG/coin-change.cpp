//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        vector<long long int> c(sum+1,0),p(sum+1,0);
        for(int i=1;i<=N;i++)
        {
            c[0]=1;
            for(int j=1;j<=sum;j++)
            {
                long long int take=0,not_take=0;
                if(coins[i-1]<=j)
                    take=c[j-coins[i-1]];
                not_take=p[j];
                c[j]=take+not_take;
            }
            p=c;
        }
        return p[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends