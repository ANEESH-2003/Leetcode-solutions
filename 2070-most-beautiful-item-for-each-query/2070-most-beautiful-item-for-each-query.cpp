class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        map<int,vector<int>>mp;
        for(vector<int>it:items){
            int p=it[0];
            int b=it[1];
            mp[p].push_back(b);
        }
        int prev_mx=0;
        map<int,int>mp1;
        for(auto it:mp)
        {
            int x=it.first;
            vector<int>y=it.second;
            int mx=*max_element(y.begin(),y.end());
            if(mx>prev_mx)
            {
                prev_mx=mx;
            }
            mp1[x]=prev_mx;
        }
        vector<int>ans;
        int cnt=0;
        for(int x:queries)
        {
            if(mp1.find(x)!=mp1.end())
            {
               ans.push_back(mp1[x]); 
            }
            else if(items.size()==1 && x>items[0][0])
            {
                ans.push_back(items[0][1]);
            }
            else if(items.size()==1 && x<items[0][0])
            {
                ans.push_back(0);
            }
            else
            {
                auto it =mp1.upper_bound(x);
                --it;
                ans.push_back(it->second);
            }
        }
        
        return ans;
    }
};
