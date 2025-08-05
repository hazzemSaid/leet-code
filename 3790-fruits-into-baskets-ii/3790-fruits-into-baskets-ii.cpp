class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size();
        int cnt=0;
        vector<bool>vis(n+1,false);
        for(int i=0;i<n;i++){
            //fur
            for(int j=0;j<n;j++){
                //back
                if(fruits[i]<=baskets[j] and !vis[j]){
                    vis[j]=1;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i])cnt++;
        }
        return cnt;
    }
};