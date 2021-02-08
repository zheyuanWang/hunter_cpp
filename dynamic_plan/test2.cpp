#include <vector>
#include <iostream>
using namespace std; 

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root)
            return NULL;
        TreeNode* l = removeLeafNodes(root->left, target);
        TreeNode* r = removeLeafNodes(root->right, target);
        if(!l)//左边节点可删，空也可以
            root->left = NULL;
        if(!r)//右边节点可删
            root->right = NULL;
        if(!l && !r && root->val == target)
            return NULL;//左右都没有，且val==target，可删，返回NULL
        else
            return root;
    }
};

