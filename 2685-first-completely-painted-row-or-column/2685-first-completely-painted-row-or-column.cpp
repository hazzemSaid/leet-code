class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
       vector<pair<int,int>>mp(int(1e5)+1,{0,0});
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        vector<int>r(n,0),c(m,0);
        for(int i=0;i<arr.size();i++){
            auto &it=arr[i];
            r[mp[it].first]++;
            c[mp[it].second]++;
            if(r[mp[it].first] == m || c[mp[it].second] == n){
                return i;
            }
        }
        return -1;
    }
};