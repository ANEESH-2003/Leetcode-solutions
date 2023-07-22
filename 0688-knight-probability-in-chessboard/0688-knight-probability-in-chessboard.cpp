class Solution {
public:
double f(int n, int k, int row, int col, vector<vector<vector<double>>> &dp){
    if(k==0){
        return 1;
    }
    if(dp[row][col][k]!=-1) return dp[row][col][k];

    
    double pos_1 = 0.0, pos_2 = 0.0, pos_3=0.0, pos_4 = 0.0, pos_5 = 0.0, pos_6=0.0, pos_7 = 0.0, pos_8=0.0;
    if(row-2>=0 && row-2<n && col-1>=0 && col-1<n){
        pos_1 = f(n, k-1, row-2, col-1, dp)/8.0;
    }
    if(row-2>=0 && row-2<n && col+1>=0 && col+1<n){
        pos_2 = f(n, k-1, row-2, col+1, dp)/8.0;
    }
    if(row-1>=0 && row-1<n && col-2>=0 && col-2<n){
        pos_3 = f(n, k-1, row-1, col-2, dp)/8.0;
    }
    if(row+1>=0 && row+1<n && col-2>=0 && col-2<n){
        pos_4 = f(n, k-1, row+1, col-2, dp)/8.0;
    }
    if(row+2>=0 && row+2<n && col-1>=0 && col-1<n){
        pos_5 = f(n, k-1, row+2, col-1, dp)/8.0;
    }
    if(row+2>=0 && row+2<n && col+1>=0 && col+1<n){
        pos_6 = f(n, k-1, row+2, col+1, dp)/8.0;
    }
    if(row+1>=0 && row+1<n && col+2>=0 && col+2<n){
        pos_7 = f(n, k-1, row+1, col+2, dp)/8.0;
    }
    if(row-1>=0 && row-1<n && col+2>=0 && col+2<n){
        pos_8 = f(n, k-1, row-1, col+2, dp)/8.0;
    }

    return dp[row][col][k] = (pos_1+pos_2+pos_3+pos_4+pos_5+pos_6+pos_7+pos_8);


}
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k+1, -1)));
        return f(n, k, row, column, dp);
    }
};