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

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int id;
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int id_, int val_) : id(id_), val(val_), left(nullptr), right(nullptr) {}
};

int GetSum(TreeNode* root){
    queue<TreeNode*> q;
    if(root != nullptr){
        q.push(root);
    }
    int sum = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; ++i){
            TreeNode* node = q.front();
            q.pop();
            sum += node->val;
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return sum;
}

int BestNode(vector<int> subsum){
    vector<int> diff(subsum.size(), 0);
    for(int i = 1; i < subsum.size(); ++i){
        diff[i] = abs(subsum[0] - (subsum[0]-subsum[i]));
    }
    int best_id = 0;
    int max_diff = INT_MIN;
    for(int i = 1; i < subsum.size(); ++i){
        if(diff[i] > max_diff){
            best_id = i;
            max_diff = diff[i];
        }
    }
    return best_id;
}

int main(){
    int num = 0;
    cin >> num;
    vector<TreeNode*> nodes(num);
    int sum = 0;
    for(int i = 0; i < num; ++i){
        int val_temp;
        cin >> val_temp;
        sum += val_temp;
        TreeNode* node_temp = new TreeNode(i, val_temp);
        nodes[i] = node_temp;
    }
    for(int i = 0; i < num-1; ++i){
        int parent, child;
        cin >> parent >> child;
        if(nodes[parent]->left == nullptr){
            nodes[parent]->left = nodes[child];
        }
        else{
            nodes[parent]->right = nodes[child];
        }
    }
    vector<int> subsum(num, 0);
    subsum[0] = sum;
    for(int i = 1; i < num; ++i){
        subsum[i] = GetSum(nodes[i]);
    }
    cout << BestNode(subsum) << endl;
    return 0;
}