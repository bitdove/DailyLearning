#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> Solution(std::vector<int> &nums, int target){
    std::unordered_map<int, int> dic;
    for(int i = 0; i < nums.size(); ++i){
        auto it = dic.find(target - nums[i]);
        if(it != dic.end()){
            return {it->second, i};
        }
        else{
            dic[nums[i]] = i;
        }
    }
    return {};
}

int main(int argc, char* argv[]){
    std::vector<int> nums;
    int num;
    while(std::cin >> num){
        nums.push_back(num);
        if(getchar() == '\n'){
            break;
        }
    }
    int target;
    std::cin >> target;
    
    std::vector<int> result = Solution(nums, target);
    for(auto i : result){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}