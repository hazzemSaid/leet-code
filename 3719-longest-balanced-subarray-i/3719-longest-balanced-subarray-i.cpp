class Solution {
public:
    int longestBalanced(vector<int>& nums) {
       int sz=nums.size(),maxx=0;
       for(int i=0;i<sz;i++){
            unordered_map<int,int>mp;
           int evencnt=0,oddcnt=0;
            for(int j=i;j<sz;j++){
                if(mp[nums[j]]==0){
                    mp[nums[j]]++;
                    if(nums[j]%2==0)evencnt++;
                    else oddcnt++;
                }
                if(evencnt==oddcnt)
               { 
                maxx=max(maxx,j-i+1);}
            }
       }
       return maxx;
    }
};