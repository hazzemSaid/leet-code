/**
 * @param {number[]} nums
 * @return {number}
 */
var tupleSameProduct = function(nums) {
    let mp=new Map();
    let size=nums.length;
    for(let i=0;i<size;i++){
        for(let j=i+1;j<size;j++){
            mp.set(nums[i]*nums[j], (mp.get(nums[i]*nums[j]) || 0) + 1);
        }
    }
    let ans=0;
    for(let [key,value] of mp){
        if(value>1){
            ans+=((value*(value-1))/2)*8;
        }
    }
    return ans;
};