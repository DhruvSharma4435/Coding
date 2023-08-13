/**
 * Definition for a binary tree node that you might need to get a better understanding of the TreeNode.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// I strongly suggest to try befor you copy it!
class Solution {
public:
     bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p || !q)
      return p == q;
    return p->val == q->val &&              //
           isSameTree(p->left, q->left) &&  //
           isSameTree(p->right, q->right);
  }
};