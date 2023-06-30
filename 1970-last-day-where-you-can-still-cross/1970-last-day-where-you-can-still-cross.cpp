class Solution {
public:
    using MyTuple = tuple<int, int, int>;
    struct CustomComp{
        

           bool operator()(const MyTuple& a, const MyTuple& b) const {
                return std::get<2>(a) < std::get<2>(b);
            }
    };
    
    


    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
     //last day when you can still cross   
        
        vector<vector<int>> v(row,vector<int>(col, 0));


        for(int i = 0; i < row*col; i++){
            int r = cells[i][0]; int c = cells[i][1];
            v[r-1][c-1] = i;
        }

        int ans = 0;
        vector<vector<int>> vis(row, vector<int>(col, 0));
        
        priority_queue<Solution::MyTuple, vector<Solution::MyTuple>, Solution::CustomComp> q;
        for(int i = 0; i < col; i++){
            q.push(forward_as_tuple(0, i, v[0][i]));
        }

        while(!q.empty()){
            auto [i, j, minw] = q.top(); q.pop();
            if(vis[i][j]) continue;
            vis[i][j] = true;

            if(i == row-1) return minw;

            for(int dx = -1; dx <=1 ; dx+=2){
                for(int dy = -1; dy <= 1; dy+= 2){
                    int di = (dx  + dy)/2;
                    int dj = (dx - dy)/2;

                    if(i + di < 0 || i + di >= row || j + dj < 0 || j + dj >= col) continue;
                    if(vis[i + di][j + dj]) continue;
                    q.push(forward_as_tuple(i + di, j + dj, min(minw, v[i + di][j + dj])));
                }
            }
        }
        
        return 0;
    }
};