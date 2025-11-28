class Solution {
public:
const int MOD = 1e9 + 7;

bool valid(int i,int j,vector<vector<int>>&grid){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())return false;
    return true;
}
 int answer(int i,int j,int sum,int k,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    if(!valid(i,j,grid)){
        return 0;
    }
    if(i == grid.size()-1 and j==grid[0].size()-1){
    sum += grid[i][j];
        if(sum%k == 0)return 1;
        return 0;
    }
    if(dp[i][j][sum%k] != -1){
        return dp[i][j][sum%k];
    }
    int down=answer(i+1,j,sum+grid[i][j],k,grid,dp);
    int right =answer(i,j+1,sum+grid[i][j],k,grid,dp);
    return dp[i][j][sum%k]=((down%MOD)+(right)%MOD)%MOD;
 }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
    vector<vector<vector<int>>>dp(n,vector(m,vector<int>(k,-1)));
    dp[n-1][m-1][0]=1;

    int x= answer(0,0,0,k,grid,dp);        
    
    return x;
    }
};