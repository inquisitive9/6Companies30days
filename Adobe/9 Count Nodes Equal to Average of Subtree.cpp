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
    int res = 0;
    pair<int,int> helper(TreeNode*root) {
        // sum  count
        if(!root) {
            return {0,0};
        }
        auto l = helper(root->left);
        int leftSum = l.first;
        int leftCnt = l.second;
        auto r = helper(root->right);
        int rightSum = r.first;
        int rightCnt = r.second;
        int sum = leftSum + rightSum + root->val;
        int cnt = leftCnt + rightCnt + 1;
        if(sum/cnt == root->val) res++;
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return res;
    }
};
