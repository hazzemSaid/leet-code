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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return {};
        }
       ListNode *p1=head;
       if(head->next==NULL){
        return p1;
       }
       ListNode *p2=head->next;
       if(head->next->next==NULL){
        p1->next=NULL;
        p2->next=p1;
        return p2;
       }
      ListNode *p3=head->next->next;
      p1->next=NULL;
      while(p3!=NULL){
        p2->next=p1;
        p1=p2;
        p2=p3;
        p3=p3->next;
      }
      p2->next=p1;
      return p2;
        
    }
};