/**
 * @param {number[]} nums
 * @param {number} pivot
 * @return {number[]}
 */
var pivotArray = function(nums, pivot) {
    let before_piv=[],after_piv=[],piv=[];
    for(let i = 0;i<nums.length;i++){
        if(nums[i] == pivot){
            piv.push(i);
        }
        else if(nums[i]<pivot){
            before_piv.push(i);
        }
        else {
            after_piv.push(i);
        }
    }
        let res=[];
        before_piv.forEach((x)=>{
            res.push(nums[x]);
        });
          piv.forEach((x)=>{
            res.push(nums[x]);
        });
          after_piv.forEach((x)=>{
            res.push(nums[x]);
        });
        return res;
};