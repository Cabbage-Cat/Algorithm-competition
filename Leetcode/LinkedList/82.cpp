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
      ListNode* guard = new ListNode(-1);
      guard->next = head;
      
      auto before = guard;
      auto first = head;
      auto travel = head;
      int l = 0;
      
      while (travel){
        while (travel && travel->val == first->val) { l++; travel = travel->next; }
        if (l>1)
          before->next = travel;
        else
          before = first;
        l=0;
        if (travel)
          first = travel;
      }
      
      return guard->next;
    }
};