/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public static void helper(TreeNode root, List<Integer> ans){
        //bast case
        if(root == null){
            return;
        }
        int data = root.val;

        if(root.left != null){
            helper(root.left, ans);
            // ans.add(root.left.val);
        } 
        ans.add(data);

        if(root.right != null){
           helper(root.right, ans);
        //    ans.add(root.right.val); 
        } 

        return;
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<Integer> ();

        helper(root, ans);
        return ans;
    }
}