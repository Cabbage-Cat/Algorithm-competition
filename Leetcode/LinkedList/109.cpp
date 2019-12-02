/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* travel;
    TreeNode* convertedListToBST(int l,int r){
      if (l>r) return NULL;
      
      int mid = (l+r)/2;
      TreeNode* left = convertedListToBST(l,mid-1);
      
      TreeNode* node = new TreeNode(travel->val);
      travel = travel->next;
      TreeNode* right = convertedListToBST(mid+1,r);
      node->left = left; node->right = right;
      return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
      travel = head;
      auto tmp = head;
      int size = 0;
      while (tmp) { size++; tmp = tmp->next; }
      return convertedListToBST(0,size-1);
    }
};