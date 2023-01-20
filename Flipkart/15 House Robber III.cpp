    vector<int> helper(TreeNode* root,vector<int>& res) {
        if(!root) return {0,0};

        vector<int> l = helper(root->left,res);
        vector<int> r = helper(root->right,res);

        vector<int> temp;
        temp.push_back(root->val+l[1]+r[1]);
        temp.push_back(max(l[0],l[1])+max(l[1]+r[0]));

        return temp;
    }
    int rob(TreeNode* root) {
        vector<int> res(2,0);
        res = helper(root,res);
        return max(res[0],res[1]);
    }
