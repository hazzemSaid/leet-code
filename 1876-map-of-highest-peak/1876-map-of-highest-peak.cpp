class Solution {
public:

    bool unvalid(int x,int y,int n,int m){
        return (x<0 || x>=n || y<0 || y>=m);
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,pair<int,int>>>q;
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j] == 1){
                    q.push({0,{i,j}});
                    ans[i][j]=0;
                }
            }
        }
      vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,-1,1};
        while(!q.empty()){
            auto [c, innerPair] = q.front(); // Unpack the outer pair
            auto [x, y] = innerPair;    
            q.pop();
            if( unvalid(x,y,n,m) || vis[x][y] )continue;
            vis[x][y]=1;
            ans[x][y]=c;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                q.push({c+1,{nx,ny}});
            }
        }
        return ans;
    }
};