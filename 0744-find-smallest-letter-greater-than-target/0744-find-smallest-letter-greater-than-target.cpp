 class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int sz=letters.size(),left=0;
        int right=sz-1;
     
    
        while (left<=right)
        {
            int mid=left+(right-left)/2;
 if(letters[mid]<=target)
{
  left=mid+1;
}
else if(letters[mid]>target)
{
  right=mid-1;
}
        }
        return letters[left%sz];
    }
};