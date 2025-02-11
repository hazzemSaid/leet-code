/**
 * @param {string} s
 * @param {string} part
 * @return {string}
 */
var removeOccurrences = function(s, part) {
    let psz=part.length;
   let ans=[];
    for(let i of s){
        ans.push(i);
       if (ans.length >= psz && ans.join('').search(part) !== -1) {
            ans.splice(-psz); // Remove last `psz` characters
        }
    }
    return ans.join("");
};