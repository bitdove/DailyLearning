#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

ListNode* Solution(ListNode* l1, ListNode* l2){
    ListNode* dummy = new ListNode(-1);
    ListNode* curNode = dummy;
    while(l1 || l2){
        
    }
}

int main(int argc, char* argv[]){
    ListNode* dummy1 = new ListNode(-1);
    ListNode* curNode = dummy1;
    int num;
    while(std::cin >> num){
        curNode->next = new ListNode(num);
        curNode = curNode->next;
        if(getchar() == '\n'){
            break;
        }
    }
    ListNode* dummy2 = new ListNode(-1);
    curNode = dummy2;
    while(std::cin >> num){
        curNode->next = new ListNode(num);
        curNode = curNode->next;
        if(getchar() == '\n'){
            break;
        }
    }

    curNode = Solution(dummy1->next, dummy2->next);
    while(curNode){
        std::cout << curNode->val << " ";
        curNode = curNode->next;
    }
    std::cout << std::endl;

    delete dummy1;
    delete dummy2;
    return 0;
}