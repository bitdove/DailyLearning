/*
    题目：梅花桩阵
        一个M*N的梅花桩阵，每个桩都有允许跳跃的最大步数，用户从0，0的位置开始跳跃，
        允许向右和向下两个方向跳跃，求最少跳跃多少次能到达M-1，N-1的位置。无法到达
        目的地时返回-1.
        M<=100,N<=100，每个桩上允许跳跃的最大步数均为小于10的正整数，0表示不允许
        跳跃到该位置。
    输入描述：
        1. 第一行为M和N，用“，”隔开；
        2. 第二行为M*N的梅花桩（格式参考样例），数组位置为允许跳跃的最大步数，0表示
           该位置为空，不能跳到该位置。
    输出描述：
        最少跳跃的步数
    
    示例1:
        输入：
            3,3
            3 2 2 0 1 0 1 1 1
        输出：
            2
*/

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int MinSteps(vector<vector<int>>& grid, int M, int N){
    vector<vector<int> > dp(M, vector<int>(N, INT_MAX));
    dp[0][0] = 0;
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            for(int x = 1; x <= grid[i][j] && j + x < N; ++x){
                dp[i][j+x] = min(dp[i][j+x], dp[i][j]+1);
            }
            for(int y = 1; y <= grid[i][j] && i + y < M; ++y){
                dp[i+y][j] = min(dp[i+y][j], dp[i][j]+1);
            }
        }
    }
    return dp[M-1][N-1];
}

int main(){
    string str;
    getline(cin, str);
    int M, N;
    int pos = str.find(',', 0);
    M = stoi(str.substr(0,pos));
    N = stoi(str.substr(pos+1, str.size()-pos));
    vector<vector<int> > grid(M, vector<int>(N));
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            cin >> grid[i][j];
        }
    }

    cout << MinSteps(grid, M, N);

    return 0;
}