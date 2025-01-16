class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        //map to count frquence for number into num1 and num2 
        map<int,long long>mp;
        int sz1=nums1.size();
        //sz1 for num1
        int sz2=nums2.size();
        //sz2 for num2
        for(int i=0;i<sz1;i++){
            // the counter of num1[i] -> times the size of num2 length
            mp[nums1[i]]+=sz2;
        }
        for(int i=0;i<sz2;i++){
            // the counter of num2[i] -> times the size of num1 length
            mp[nums2[i]]+=sz1;
        }
        //cnt to calculate the answer
        int cnt=-1;
        for(auto &it:mp){
            //it it counter is odd 
            if(it.second % 2 == 1){
                if(cnt == -1)
                cnt=it.first; // first time 
                else cnt^=it.first; // xor the new value
            }
        } 
        //if the cnt is still -1 return 0 else return cnt 
        return cnt==-1?0:cnt;

    }
};