// 输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
/*
先序遍历：
[ 根节点, [左子树的前序遍历结果], [右子树的前序遍历结果] ]

中序遍历：
[ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]

在先序遍历中找到根节点，在中序遍历中确认左右子树进行递归抽取
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for(int i =0;i<inorder.size();i++){
            dic[inorder[i]] = i;
        }
        return recur(0, 0, inorder.size()-1);
        // 第一个0是前序序列中的索引
        // 第二个和第三个是对应中序序列中的边界值
    }
private:
    vector<int> preorder;
    unordered_map<int, int> dic;
    TreeNode* recur(int root, int left, int right){
        if(left>right) return NULL;
        TreeNode* node = new TreeNode(preorder[root]);
        int ind = dic[preorder[root]];
        node->left = recur(root+1, left, ind - 1);
        node->right = recur(root + (ind-1-left+1)+1, ind+1, right);
        return node;
    }
};


int main(){
    return 0;
}