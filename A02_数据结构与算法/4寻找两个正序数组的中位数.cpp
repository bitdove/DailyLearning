#include <iostream>
#include <vector>

double Solution(std::vector<int> &nums1, std::vector<int> &nums2){
    int m = nums1.size();
    int n = nums2.size();
    
}

int main(int argc, char* argv[]){
    std::vector<int> nums1;
    int num;
    while(std::cin >> num){
        nums1.push_back(num);
        if(getchar() == '\n'){
            break;
        }
    }
    std::vector<int> nums2;
    while(std::cin >> num){
        nums2.push_back(num);
        if(getchar() == '\n'){
            break;
        }
    }
    std::cout << Solution(nums1, nums2) << std::endl;
    return 0;
}