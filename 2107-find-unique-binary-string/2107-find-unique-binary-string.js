/**
 * @param {string[]} nums
 * @return {string}
 */
var findDifferentBinaryString = function(nums) {
     let mp = new Map();
    nums.forEach((val) => {
        mp.set(val, true);
    });
    let sz=nums[0].length;
    let ans="";
    let x= function ( indx, str){
        if(indx == sz){
           if (!mp.has(str)) {
                ans = str;
                return true;
            }
            return false;
        }
        return (x(indx+1,str+'1')||x(indx+1,str+'0'));
    }
    x(0,"");
    return ans;
};