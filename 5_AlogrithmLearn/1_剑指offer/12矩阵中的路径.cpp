/*
回溯法完成深度遍历
未设置和数组相同大小的visited数组
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
private:
    int rows, cols;
    bool dfs(vector<vector<char>>&board, int i, int j, string word, int wordInd){
        if (i >= rows || j >= cols || i < 0 || j < 0 || board[i][j]!=word[wordInd]) return false;
        if (wordInd == word.size() - 1) return true;
        board[i][j] = '\0';
        bool res = dfs(board, i+1, j, word, wordInd+1) || dfs(board, i, j+1, word, wordInd+1)  || dfs(board, i-1, j, word, wordInd+1) || dfs(board, i, j-1, word, wordInd+1);
        board[i][j] = word[wordInd];
        return res;
    }
};

int main(){
    return 0 ;
}