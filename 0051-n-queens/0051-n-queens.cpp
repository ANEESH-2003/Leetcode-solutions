class Solution {
public:
    int n;
    string make(int i)
    {
        string s="";
        for(int j=0;j<i;j++)
            s+=".";
        s+="Q";
        for(int j=i+1;j<n;j++)
            s+=".";
        return s;
    }
    bool val(int a,int b)
    {
        return (a>=0 && a<n && b>=0 && b<n);
    }
    bool check(int a,int b,vector<vector<int>>& m)
    {
        for(int i=0;i<a;i++)
        {
            if(m[i][b])
                return 0;
        }
        for(int i=-1;i<=1;i++)
        {
            if(i==0)
                continue;
            for(int j=-1;j<=1;j++)
            {
                if(j==0)
                    continue;
                int x=a+i,y=b+j;
                while(val(x,y))
                {
                    if(m[x][y])
                        return 0;
                    x+=i;
                    y+=j;
                }
            }
        }
        return 1;
    }
    void cal(vector<vector<string>>& ans,vector<string>& v,int i,vector<vector<int>>& m)
    {
        if(i==n)
        {
            ans.push_back(v);
            return;
        }
        for(int j=0;j<n;j++)
        {
            if(check(i,j,m))
            {
                m[i][j]++;
                v.push_back(make(j));
                cal(ans,v,i+1,m);
                v.pop_back();
                m[i][j]--;
            }
        }
    }
    vector<vector<string>> solveNQueens(int x) {
        vector<vector<string>> ans;
        vector<string> v;
        n=x;
        vector<vector<int>> m(n,vector<int>(n,0));
        cal(ans,v,0,m);
        return ans;
    }
};