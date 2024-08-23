class Solution {
public:

    void dfs(int r, int c , int m , int n, vector<vector<int>>& grid , vector<vector<int>>&visited , int deltar[] , int deltac[]){
        visited[r][c] = 1;
        for(int i=0 ; i<4 ; i++){
            int newr = r + deltar[i];
            int newc = c + deltac[i];
            if(newr >=0 && newr < m && newc >=0 && newc <n && !visited[newr][newc] && grid[newr][newc] == 1 ){
                dfs(newr,newc,m,n,grid,visited,deltar,deltac);
            }
        }
    }

    int num_of_islands(vector<vector<int>>& grid , int m , int n){
        
        vector <vector<int>> visited(m , vector<int>(n,0));
        int deltar[] = {-1,0,1,0};
        int deltac[] = {0,1,0,-1};
        int ans = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    ans++;
                    dfs(i,j,m,n,grid,visited,deltar,deltac);
                }
            }
        }
        return ans;
    }

    int minDays(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int num = num_of_islands(grid,m,n);
        if(num == 0 || num > 1) return 0;

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    int num2 = num_of_islands(grid,m,n);
                    if(num2 ==0 || num2 > 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};