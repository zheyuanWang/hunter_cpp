#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { //前序遍历 & 中序遍历
        this->preorder = preorder;  //todo:this
        for(int i = 0; i < inorder.size(); i++)
            dic[inorder[i]] = i;  //数值到index的字典
        return recur(0, 0, inorder.size() - 1);
    }
private:
    vector<int> preorder;
    unordered_map<int, int> dic;

//递推参数： 根节点在前序遍历的索引 root 、子树在中序遍历的左边界 left 、子树在中序遍历的右边界 right ；
    TreeNode* recur(int root, int left, int right) { 
        if(left > right) return nullptr;                        // 递归终止
        TreeNode* node = new TreeNode(preorder[root]);          // 建立根节点, 前序遍历的第一个就是根节点
        int i = dic[preorder[root]];                            // 计算中序根节点坐标; 划分根节点、左子树、右子树

        node->left = recur(root + 1,              left, i - 1);   // 开启左子树递归: 范围=left到中序位置的左边
        node->right = recur((i - left) + root + 1, i + 1, right); // 开启右子树递归: 范围=中序位置的右边到right, 
        //“i-in_left+pre_root+1”，其实就是右子树根节点=(中序根节点坐标-中序左边界）+先序根节点坐标+1，其中括号内=左子树长度
        return node;                                            // 回溯返回根节点
    }
};

