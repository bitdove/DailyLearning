/*
    题目：
        给出一棵二叉树，每个节点有一个编号和一个值，该值可能为负数，请你找出一个最优节点（除根节点外），使得在该节点将树
        分成两棵树后（原来的树移除这个节点及其子节点，新的树以该节点为根节点），分成的两棵树各节点的和之间的差绝对值最大。
        请输出该节点的编号，如有多个相同的差，输出编号最小的节点。
    输入描述：
        4
        4 9 -7 -8
        0 1
        0 3
        1 2
        第一行：四个节点，编号0~3，范围1-10000
        第二行：节点0~3的权值
        第三行到第五行：表示二叉树各节点间的父子关系
            0 1  //节点0的左节点是1
            0 3  //节点0的右节点是3
            1 2  //节点1的左节点是2
        注意：左节点永远出现在右节点之前
                    0：4
                    /  \
                1: 9    3: -8
                /
            2: -7
    输出描述：
        3
        第一行：节点编号，示例中编号为3的节点是最优节点
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int BestNode(vector<int>& weight, vector<int>& root, const int num){
    int max_diff = -1;
    int sum = 0;
    for(int val : weight){
        sum += val;
    }
    for(int i = 1; i < num; ++i){
        max_diff = max(max_diff, abs(sum - ChildTreeSum()));
    }
}

int main(){
    int num = 0;
    cin >> num;
    vector<int> weight(num);
    for(int i = 0; i < num; ++i){
        cin >> weight[i];
    }
    vector<int> root(num);
    while(--num){
        int m = 0;
        int n = 0;
        cin >> m >> n;
        root[n] = m; //n号节点的父节点是m号节点
    }
    cout << BestNode(weight, root, int num) << endl;
    return 0;
}