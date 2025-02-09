/**
 * @param {number[]} nums
 * @return {number}
 */
var countBadPairs = function(nums) {
    let mp=new Map();
    for(let i=0;i<nums.length;i++){
    mp.set(nums[i]-i, mp.get(nums[i]-i) + 1 || 1);
    }
    let n=nums.length;
    let ans=0;
  for (let [key, value] of mp) {
    console.log(key+" "+value);
    ans+=(n-value)*value;
    n-=value;
}

    return ans;

};