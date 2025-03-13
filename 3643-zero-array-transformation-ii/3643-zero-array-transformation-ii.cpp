class Solution {
public:
int binary(vector<int>&nums,vector<vector<int>>&quer){
    int l=0,r=quer.size(),ans=-1;
    if(!cando_it(nums,quer,r))return -1;
    while(l<=r){
        int mid= (l+r)>>1;
        if(cando_it(nums,quer,mid)){
            ans=mid;
            r=mid-1;
        }
        else
        l=mid+1;
    }
    return l;
}
bool cando_it(vector<int>&nums,vector<vector<int>>&q,int k){
    vector<int>arr(nums.size()+1,0);
    for(int i=0;i<k;i++){
        int l=q[i][0];
        int r=q[i][1];
        int v=q[i][2];
        arr[l]+=v;
        arr[r+1]-=v;
    }
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=arr[i];
        if(sum<nums[i])return false;
    }
    return true;
}
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        return binary(nums,queries);
    }
};