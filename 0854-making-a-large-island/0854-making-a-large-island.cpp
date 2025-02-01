class Solution {
public:
bool valid(int i,int j,vector<vector<int>>&grid){
    return (i>=0 and i<grid.size() and j>=0 and j<grid[0].size());
}
vector<int>dx={1,-1,0,0};
vector<int>dy={0,0,1,-1};
int dfs(int i,int j,int id,vector<vector<int>>&grid,vector<vector<bool>>&vis){
    if(!valid(i,j,grid) || vis[i][j]==true || grid[i][j]==0)return 0;
    vis[i][j]=true;
    grid[i][j]=id;
    int cnt=1;
    for(int d=0;d<4;d++){
        cnt+=dfs(i+dx[d],j+dy[d],id,grid,vis);
    }
    return cnt;
}
    int largestIsland(vector<vector<int>>& grid) {
        int id=2;
        int n=grid.size();
        int m=grid[0].size();
        unordered_map<int,int>grp;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 and vis[i][j]==false){
                    grp[id]=dfs(i,j,id,grid,vis);
                    id++;
                }
            }
        }
        if(grp.size() == 1){
            return grp[2]==n*m?n*m:grp[2]+1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    set<int>cur_g;
                    if(valid(i+1,j,grid) and grid[i+1][j]>1){
                            cur_g.insert(grid[i+1][j]);
                    }
                    if(valid(i-1,j,grid) and grid[i-1][j]>1){
                            cur_g.insert(grid[i-1][j]);
                    }
                    if(valid(i,j+1,grid) and grid[i][j+1]>1){
                            cur_g.insert(grid[i][j+1]);
                    }
                    if(valid(i,j-1,grid) and grid[i][j-1]>1){
                            cur_g.insert(grid[i][j-1]);
                    }
                    int cnt=0;
                    for(auto &it:cur_g){
                        cout<<it<<" "<<grp[it]<<endl;
                        cnt+=grp[it];
                    }
                    ans=max(cnt+1,ans);
                }
            }
        }

return ans;


    }
};