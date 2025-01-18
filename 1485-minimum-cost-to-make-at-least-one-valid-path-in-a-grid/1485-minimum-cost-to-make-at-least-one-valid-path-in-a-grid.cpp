class Solution {
public:

    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    bool valid(int x,int y,vector<vector<int>>&grid){
        return (x>=0 and x<grid.size() and y>=0 and y<grid[0].size());
    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
       set<pair<int,int>>visit;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            // cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
            if(visit.find({it.second.first,it.second.second}) != visit.end())continue;
            visit.insert({it.second.first,it.second.second});
            if(it.second.first == n-1 and it.second.second == m-1){
                return it.first;
            }
            for(int i=0;i<4;i++){
                int cost=it.first;
                int nx=it.second.first+dx[i];
                int ny=it.second.second+dy[i];
                if(valid(nx,ny,grid)){
                    if(grid[it.second.first][it.second.second]==i+1)
                    pq.push({cost,{nx,ny}});
                    else 
                    pq.push({cost+1,{nx,ny}});
                }
            }
        }
        return -1;
    }
};