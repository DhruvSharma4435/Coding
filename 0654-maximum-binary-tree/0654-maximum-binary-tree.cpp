/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return build(nums, 0, nums.size() - 1);
  }

 private:
  TreeNode* build(const vector<int>& nums, int i, int j) {
    if (i > j)
      return nullptr;

    const auto it = max_element(nums.begin() + i, nums.begin() + j + 1);
    const int maxNum = *it;
    const int maxIndex = it - nums.begin();

    TreeNode* root = new TreeNode(maxNum);
    root->left = build(nums, i, maxIndex - 1);
    root->right = build(nums, maxIndex + 1, j);
    return root;
  }
};