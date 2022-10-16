/*
使用广度优先遍历去查询(也可以使用深度优先)
广度优先遍历：先将要访问的地址加入queue中，然后一层层逐级推进
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int sumOfNumber(int x){
        int sum = 0;
        while (x>0){
            sum+=x%10;
            x = x/10;
        }
        return sum;
    }

    int movingCount(int m, int n, int k) {
        if (k==0) return 1;
        queue<pair<int, int>> setFirstLevel;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int xMove[] = {0, 1};
        int yMove[] = {1, 0};
        setFirstLevel.push(make_pair(0, 0));
        visited[0][0] = 1;
        int count = 1;
        while (!setFirstLevel.empty()){
            // auto [x, y] = setFirstLevel.front();
            pair<int,int> p1 = setFirstLevel.front();
            int x = p1.first;
            int y = p1.second;
            setFirstLevel.pop();
            for (int i = 0; i < 2; i++){
                int tx = x+xMove[i];
                int ty = y+yMove[i];
                if(tx>=m || ty>=n || tx<0 || ty<0 || visited[tx][ty]==1 || sumOfNumber(tx)+sumOfNumber(ty)>k) continue;
                setFirstLevel.push(make_pair(tx, ty));
                visited[tx][ty] = 1;
                count +=  1;
            }
        }
        return count;

    }
};

int main(){
    return 0;
}