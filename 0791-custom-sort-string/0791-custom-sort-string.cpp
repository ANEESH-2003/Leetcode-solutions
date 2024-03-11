class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mpp;
        for(auto it:s)
        {
            mpp[it]++;
        }
        string ans="";
        for(auto it:order)
        {
            if(mpp.find(it)!=mpp.end())
            ans.append(mpp[it],it);
            mpp.erase(it);
        }
        for(auto it:mpp)
        {
            ans.append(it.second,it.first);
        }
        return ans;
    }
};