class Solution {
public:

    bool static compare(vector<int> &a,vector<int> &b) {
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        sort(flowers.begin(),flowers.end(),compare);
        int count=0;
        map<int,int> flowerFreq;
        vector<int> ans;

        for(int index=0;index<flowers.size();index++) {
            flowerFreq[flowers[index][0]]++;
            flowerFreq[flowers[index][1]+1]--;
        }

        for(auto &it: flowerFreq) {
            count+=it.second;
            it.second=count;
        }

        for(int index=0;index<people.size();index++) {
            auto it=flowerFreq.upper_bound(people[index]);
            if(it==flowerFreq.begin()) {
                ans.push_back(0);
            }
            else {
                ans.push_back(prev(it)->second);
            }
        }

        return ans;

    }
};