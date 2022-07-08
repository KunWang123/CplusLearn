// ����ĳ��������ǰ���������������Ľ�����빹���ö���������������ڵ㡣
// ���������ǰ���������������Ľ���ж������ظ������֡�
/*
���������
[ ���ڵ�, [��������ǰ��������], [��������ǰ��������] ]

���������
[ [������������������], ���ڵ�, [������������������] ]

������������ҵ����ڵ㣬�����������ȷ�������������еݹ��ȡ
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
        // ��һ��0��ǰ�������е�����
        // �ڶ����͵������Ƕ�Ӧ���������еı߽�ֵ
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