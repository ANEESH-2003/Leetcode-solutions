class Solution {
public:
    vector<string> fin;
    void cal(vector<string>& ans,map<string,vector<string>>& v,map<vector<string>,int>& m,string s,int x)
    {
        if(x==0)
        {
            if(fin.empty())
                fin=ans;
            return;
        }
        for(int i=0;i<v[s].size() && fin.empty();i++)
        {
            if(!m[{s,v[s][i]}])
                continue;
            m[{s,v[s][i]}]--;
            ans.push_back(v[s][i]);
            cal(ans,v,m,v[s][i],x-1);
            ans.pop_back();
            m[{s,v[s][i]}]++;
        }
    }
    vector<string> findItinerary(vector<vector<string>>& t) {
        fin.clear();
        vector<string> ans;
        map<vector<string>,int> m;
        int n=t.size();
        map<string,vector<string>> v;
        for(auto i:t)
        {
            m[i]++;
            v[i[0]].push_back(i[1]);
        }
        for(auto &i:v)
        {
            sort(i.second.begin(),i.second.end());
            /*for(auto j:i.second)
                cout<<j<<" ";
            cout<<"\n";*/
        }
        ans.push_back("JFK");
        cal(ans,v,m,"JFK",n);
        return fin;
    }
};