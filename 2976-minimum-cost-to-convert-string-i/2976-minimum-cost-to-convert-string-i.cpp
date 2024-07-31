class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long N=10000000000;
        vector<vector<long long>>dis(26,vector<long long>(26,N));
        for(int i=0;i<original.size();i++){
            if(dis[original[i]-'a'][changed[i]-'a']>cost[i])dis[original[i]-'a'][changed[i]-'a']=cost[i];
        }
        for(int i=0;i<26;i++)dis[i][i]=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    if(dis[j][i]==N || dis[i][k]==N)continue;
                    dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<source.length();i++){
            if(dis[source[i]-'a'][target[i]-'a']==N)return -1;
            ans+=dis[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};