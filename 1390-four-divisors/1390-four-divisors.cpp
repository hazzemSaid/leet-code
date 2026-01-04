class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int s=0;
            int d=0;
            for(int n=2;n*n<=nums[i];n++){
                if(nums[i]%n == 0){
                        if(nums[i]/n != n)
                      {  s+=2;d=n;}
                        else s++;
                }
            }
            if(s==2){
                cnt+=1+nums[i]+(nums[i]/d)+d;
            }
        }
        return cnt;
    }
};