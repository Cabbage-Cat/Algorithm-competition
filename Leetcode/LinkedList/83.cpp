/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      auto before = head;
      auto travel = head;      
      while (travel){
        while (travel && travel->val==before->val) { travel = travel->next; }
        before->next = travel;
        before = travel;  
        if (travel) travel = travel->next;
      }
      return head;
    }
};