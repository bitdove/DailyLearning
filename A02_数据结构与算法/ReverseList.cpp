#include <iostream>

//链表节点结构
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//迭代法反转链表
ListNode* ReverseList(ListNode* root){
    if(root == nullptr || root->next == nullptr){
        return root;
    }
    ListNode *pre = nullptr;
    ListNode *cur = root;
    ListNode *nxt = root->next;
    while(cur){
        cur->next = pre;
        pre = cur;
        cur = nxt;
        if(nxt){
            nxt = nxt->next;
        }
    }
    return pre;
}

//递归法反转链表。单链表其实就是一叉树
ListNode* ReverseListCur(ListNode* head){
    //终止条件
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    //递归调用
    ListNode* ret = ReverseListCur(head->next);
    //遍历
    head->next->next = head;
    head->next = nullptr;
    return ret;
}

int main(int argc, char *argv[]){
    ListNode *dummy = new ListNode(-1);
    ListNode *curr = dummy;
    int num;
    while(std::cin >> num){
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    //打印原始链表
    curr = dummy->next;
    std::cout << "原始链表：";
    while(curr){
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
    
    //反转链表并打印
    curr = ReverseList(dummy->next); //迭代反转
    //curr = ReverseListCur(dummy->next); //递归反转
    std::cout << "反转链表：";
    while(curr){
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;

    return 0;
}