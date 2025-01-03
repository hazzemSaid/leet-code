class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int sz=nums.size();
        /*
        i using the long long data type 
        becuse the max_value can store in 
        both prfix or sufix 
        is equal (1e5 * 1e5) => 1e10
        is not valid in range the (int)
        */
        vector<long long>prfix(sz,0);
        vector<long long>sufix(sz,0);
        
        //make a sufix of sum of all nums from 0 to n
        sufix[sz-1]=nums[sz-1];
        for(int i=sz-2;i>=0;i--){
            sufix[i]=sufix[i+1]+nums[i];
        }

        //make a prfix of sum of all nums from 0 to n
        prfix[0]=nums[0];
        for(int i=1;i<sz;i++){
                prfix[i]=nums[i]+prfix[i-1];
        }

        int cnt=0;
        for(int i=0;i<sz-1;i++){
            //check if the prfix (from 0 to i) is greater than or equal to sufix (from i+1 to n )
            if(prfix[i] >= sufix[i+1])cnt++;
        }
        return cnt;
    }
};