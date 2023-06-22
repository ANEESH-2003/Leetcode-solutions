//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        vector<int> v(21,0);
        for(auto i:bills)
        {
            v[i]++;
            if(i==10)
            {
                if(!v[5])
                    return 0;
                v[5]--;
            }
            if(i==20)
            {
                if(v[10])
                {
                    if(!v[5])
                        return 0;
                    else
                    {
                        v[10]--;
                        v[5]--;
                    }
                }
                else
                {
                    if(v[5]<3)
                        return 0;
                    else
                    {
                        v[5]-=3;
                    }
                }
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends