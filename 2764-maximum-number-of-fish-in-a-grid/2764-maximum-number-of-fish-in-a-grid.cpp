class Solution {
public:
bool valid(int i,int j,vector<vector<int>>&grid){
    return (i>=0 and i<grid.size() and j>=0 and j<grid[0].size());
}
vector<int>dx={1,-1,0,0},dy={0,0,-1,1};
int dfs(int i,int j,vector<vector<int>>&grid){
    if(!valid(i,j,grid) || grid[i][j]==0)return 0;
    int res=grid[i][j];
    grid[i][j]=0;
    int cnt=0;
    for(int d=0;d<4;d++){
        int ni=dx[d]+i;
        int nj=dy[d]+j;
        cnt+=dfs(ni,nj,grid);
    }
    return cnt+res;
}
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(grid[i][j] != 0){
                    ans=max(ans,dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};