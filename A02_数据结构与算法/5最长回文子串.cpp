#include <iostream>
#include <string>
#include <vector>

std::string Solution(std::string s){
    int n = s.size();
    if(n < 2)   return s;

    int maxLen = 1;
    int beginPos = 0;

    std::vector<std::vector<bool> > dp(n, std::vector<bool>(n));
    for(int i = 0; i < n; ++i){
        dp[i][i] = true;
    }

    for(int j = 1; j < n; ++j){
        for(int i = 0; i < n - 1 && i < j; ++i){
            if(s[i] != s[j]){
                dp[i][j] = false;
            }
            else{
                if((j-1) - (i+1) + 1 == 0){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = dp[i+1][j-1];
                }
            }
            if(dp[i][j] && j - i + 1 > maxLen){
                maxLen = j - i + 1;
                beginPos = i;
            }
        }
    }
    return s.substr(beginPos, maxLen);
}

int main(int argc, char* argv[]){
    std::string s;
    std::cin >> s;
    std::cout << Solution(s) << std::endl;
    return 0;
}