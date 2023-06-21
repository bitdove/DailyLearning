#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

int Solution(std::string s){
    std::unordered_set<char> occ;
    int res = 0;
    int left = 0;
    for(int i = 0; i < s.size(); ++i){
        while(occ.find(s[i]) != occ.end()){
            occ.erase(s[left]);
            ++left;
        }
        res = std::max(res, i - left + 1);
        occ.insert(s[i]);
    }
    return res;
}

int main(int argc, char* argv[]){
    std::string s;
    std::cin >> s;
    std::cout << Solution(s) << std::endl;
    return 0;
}