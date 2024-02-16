class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        map<int,int> m;
        for(auto i:arr)
            m[i]++;
        for(auto i:m)
            pq.push({i.second,i.first});
        while(k && !pq.empty())
        {
            pair<int,int> p=pq.top();
            int x=min(p.first,k);
            p.first-=x;
            k-=x;
            if(p.first==0)
                pq.pop();
        }
        return pq.size();
    }
};