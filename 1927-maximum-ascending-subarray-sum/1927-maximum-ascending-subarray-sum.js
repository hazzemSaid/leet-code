/**
 * @param {number[]} nums
 * @return {number}
 */
var maxAscendingSum = function(nums) {
    let cnt=0;
    let cntmaxx=0;
    let num=0;
    for(let i=0;i<nums.length;i++){
        if(num<nums[i]){
            cnt+=nums[i];
        }
        else {
            cnt=nums[i];
            }
            num=nums[i];
            cntmaxx=Math.max(cntmaxx,cnt);
    }
    return cntmaxx;
};