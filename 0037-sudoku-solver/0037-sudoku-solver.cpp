class Solution {
public:
    vector<vector<int>> ret;
    pair<int,int> next(int x,int y)
    {
        if(y==8)
        {
            x++;
            y=0;
        }
        else
        {
            y++;
        }
        return {x,y};
    }
    vector<int> val(vector<vector<int>>& v,int x,int y)
    {
        vector<int> f(10,0);
        for(int i=0;i<9;i++)
        {
            f[v[i][y]]++;
            f[v[x][i]]++;
        }
        int a,b,c,d;
        if(x<3)
        {
            a=0;
            b=2;
        }
        else if(x<6)
        {
            a=3;
            b=5;
        }
        else
        {
            a=6;
            b=8;
        }
        if(y<3)
        {
            c=0;
            d=2;
        }
        else if(y<6)
        {
            c=3;
            d=5;
        }
        else
        {
            c=6;
            d=8;
        }
        for(int i=a;i<=b;i++)
        {
            for(int j=c;j<=d;j++)
            {
                f[v[i][j]]++;
            }
        }
        return f;
    }
    void cal(vector<vector<int>>& ans,int x,int y)
    {
        if(x==9)
        {
            ret=ans;
            return;
        }
        pair<int,int> nex=next(x,y);
        //cout<<x<<" "<<y<<"\n";
        if(ans[x][y]!=0)
        {
            cal(ans,nex.first,nex.second);
            return;
        }
        vector<int> f=val(ans,x,y);
        for(int i=1;i<=9;i++)
        {
            if(f[i]==0)
            {
                ans[x][y]=i;
                cal(ans,nex.first,nex.second);
                ans[x][y]=0;
            }
        }
    }
    void solveSudoku(vector<vector<char>>& v) {
        vector<vector<int>> ans(9,vector<int>(9,0));
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(v[i][j]!='.')
                    ans[i][j]=(int)(v[i][j]-'0');
            }
        }
        cal(ans,0,0);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                v[i][j]=(char)(ret[i][j]+'0');
            }
        }
        return ;
    }
};