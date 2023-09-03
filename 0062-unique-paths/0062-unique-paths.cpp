class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m,vector<int>(n,0));
        v[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int c=0;
                if(i-1>=0)
                    c+=v[i-1][j];
                if(j-1>=0)
                    c+=v[i][j-1];
                v[i][j]+=c;
            }
        }
        return v[m-1][n-1];
    }
};