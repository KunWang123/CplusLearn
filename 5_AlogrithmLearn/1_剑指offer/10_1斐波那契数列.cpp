#include<iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int mod = 1000000007;
        if (n==0) 
            return 0;
        if (n==1) 
            return 1;
        // 动态规划--滚动数组
        int p=0, q=0, r=1;
        for (int i = 2; i <=n; i++){
            p = q;
            q = r;
            r = (p + q) % mod;
        }
        return r;
    }
// 递归求解
// private:
//     int recur(const int m){
//         if (m==0){
//             return 0;
//         }
//         else if (m==1){
//             return 1;
//         }
//         else{
//             return recur(m-1) + recur(m-2);
//         }
//     }
};