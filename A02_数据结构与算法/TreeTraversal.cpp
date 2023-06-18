#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

//二叉树节点结构
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*==========******========== 
构造二叉树
例：二叉树 [1,2,2,3,3,null,null,4,4]
vector<string> nodes = { "1","2","2","3","3","null","null","4","4" };
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
==========******==========*/
TreeNode* createBinaryTree(vector<string> nodes) {
	int len = nodes.size();

	if (len == 0) {
		return NULL;
	}
	//LeetCode例题里面往往省略最后一个null
	if (len % 2 == 0) {
		nodes.push_back("null");
	}

	if (nodes[0] == "null") {
		return nullptr;
	}

	TreeNode* root;
	//建立结点队列并将根节点入队
	queue<TreeNode*> nodesQue;
	root = new TreeNode(stoi(nodes[0]));
	nodesQue.push(root);

	//loc遍历数组，每次取两个结点
	for (int loc = 1; loc < len; loc = loc + 2) {
		//获取结点并出队
		TreeNode* node = nodesQue.front();
		nodesQue.pop();
		
		//获取队头结点的左右结点
		string left = nodes[loc];
		string right = nodes[loc + 1];

		//赋予左右结点
		if (left == "null") {
			node->left = nullptr;
		}
		else {
			node->left = new TreeNode(stoi(left));
			nodesQue.push(node->left);
		}

		if (right == "null") {
			node->right = nullptr;
		}
		else {
			node->right = new TreeNode(stoi(right));
			nodesQue.push(node->right);
		}
	}
	return root;
}

//全局变量保存遍历结果
std::vector<int> resPre;
std::vector<int> resIn;
std::vector<int> resPost;

//前序遍历
std::vector<int> GetPreorderTraversal(TreeNode *root){
    if(root != nullptr){
        resPre.push_back(root->val);
        GetPreorderTraversal(root->left);
        GetPreorderTraversal(root->right);
    }        
    return resPre;
}

//中序遍历
std::vector<int> GetInorderTraversal(TreeNode *root){
    if(root != nullptr){
        GetInorderTraversal(root->left);
        resIn.push_back(root->val);
        GetInorderTraversal(root->right);
    }        
    return resIn;
}

//后序遍历
std::vector<int> GetPostorderTraversal(TreeNode *root){
    if(root != nullptr){
        GetPostorderTraversal(root->left);
        GetPostorderTraversal(root->right);
        resPost.push_back(root->val);
    }        
    return resPost;
}

int main(int argc, char* argv[]){
    std::vector<string> tmp;
    string curval;
    while(std::cin >> curval){
        tmp.push_back(curval);
    }

    std::cout << "输入的字符串序列为：";
    for(string s : tmp){
        std::cout << s << " ";
    }
    std::cout << std::endl;

    TreeNode *root = createBinaryTree(tmp);
    GetPreorderTraversal(root);
    GetInorderTraversal(root);
    GetPostorderTraversal(root);

    std::cout << "前序遍历结果为：";
    for(int node : resPre){
        std::cout << node << " ";
    }
    std::cout << std::endl;

    std::cout << "中序遍历结果为：";
    for(int node : resIn){
        std::cout << node << " ";
    }
    std::cout << std::endl;

    std::cout << "后序遍历结果为：";
    for(int node : resPost){
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
}