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
    ListNode* cur = dummy;
    int carry = 0;
    while(l1 || l2){
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        carry = sum / 10;
        if(l1){
            l1 = l1->next;
        }
        if(l2){
            l2 = l2->next;
        }
    }
    if(carry > 0){
        cur->next = new ListNode(carry);
    }
    return dummy->next;
}

int main(int argc, char* argv[]){
    ListNode* dummy1 = new ListNode(-1);
    ListNode* curnode = dummy1;
    int num;
    while(std::cin >> num){
        curnode->next = new ListNode(num);
        curnode = curnode->next;
        if(getchar() == '\n')
            break;
    }
    ListNode* dummy2 = new ListNode(-1);
    curnode = dummy2;
    while(std::cin >> num){
        curnode->next = new ListNode(num);
        curnode = curnode->next;
        if(getchar() == '\n')
            break;
    }

    curnode = Solution(dummy1->next, dummy2->next);
    while(curnode){
        std::cout << curnode->val << " ";
        curnode = curnode->next;
    }
    std::cout << std::endl;

    delete dummy1;
    delete dummy2;
    return 0;
}