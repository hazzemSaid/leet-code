class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 0;
        int sz = nums.size();
        bool f = false;
        for (; i < sz - 1; i++) {
            if (nums[i] >= nums[i + 1])
                break;
            else
                f = true;
        }
        if (!f)
            return false;
               f = false;

        if (i >= sz - 2)
            return false;
        for (; i < sz - 1; i++) {
            if (nums[i] <= nums[i + 1])
                break;
            else
                f = true;
        }
        if (!f)
            return false;
        f = false;
        cout<<i<<endl;
        for (; i < sz - 1; i++) {
            if (nums[i] >= nums[i + 1])
                break;
            else
                f = true;
        }
        cout<<i<<endl;
        if (!f) return false;
             return i + 1 == sz;
    }
};