class Solution {
typedef pair<int, int> pii;
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pii> adj[n];
        for(auto &meeting: meetings) {
            adj[meeting[0]].push_back({meeting[1], meeting[2]});
            adj[meeting[1]].push_back({meeting[0], meeting[2]});
        }

        vector<int> knows(n, INT_MAX);
        knows[0] = 0;
        knows[firstPerson] = 0;
        
        queue<int> q;
        q.push(0);
        q.push(firstPerson);
        while(!q.empty()) {
            int person = q.front();
            q.pop();

            for(auto &[i, time]: adj[person]) {
                if(time >= knows[person] && time < knows[i]) {
                    knows[i] = time;
                    q.push(i);
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(knows[i] != INT_MAX) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};