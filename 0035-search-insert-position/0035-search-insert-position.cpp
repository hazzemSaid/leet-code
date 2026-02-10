class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int sz=nums.size();
        int left=0;
        int right=sz-1;
        int mid=left+(right-left)/2;
        if(target<nums[0])
        {
            return 0;
        }
        while(left<=right)
        {
mid=left+(right-left)/2;
if(nums[mid]==target)
{
    return mid;
}
else if(nums[mid]<target)
{
    left=mid+1;
}
else if(nums[mid]>target)
        {
            right=mid-1;
        }
        }
       if(nums[mid]<target)
       {
           return mid+1;
       }
       else return mid;
    }
};