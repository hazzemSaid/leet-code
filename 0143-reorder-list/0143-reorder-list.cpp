/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
       vector<int>nums; 
void fun(ListNode* head){
    if(head==NULL){
        return;
    }
    nums.push_back(head->val);
    fun(head->next);
}
void setHead(ListNode*& head, ListNode*& h) {
    h = head;
}
    void reorderList(ListNode* h) {
        ListNode *k= h;
        fun(h);
        if(nums.size()%2==0){
            int l=0,r=nums.size()-1;
            while(l<r){
               h->val=nums[l];
               h=h->next;
               h->val=nums[r];
               h=h->next;
                l++,r--;
            }
          
        }
        else{
             int l=0,r=nums.size()-1;
            while(l<r){
                  h->val=nums[l];
               h=h->next;
               h->val=nums[r];
               h=h->next;
                l++,r--;
            }
           h->val=nums[r];
           h=h->next;
           
        }
        
    }
};