/*
第三题：数字加减游戏
    小明在玩一个数字加减游戏，只使用加法或者减法，将一个数字s变成数字t。 
    每个回合，小明可以用当前的数字加上或减去一个数字。 
    现在有两种数字可以用来加减，分别为a,b，其中a!=b且b没有使用次数限制。 
    请问小明最少可以用多少次a，才能将数字s变成数字t。 
    题目保证数字s一定能变成数字t。
    输入：
        输入的唯一一行包含四个正整数s,t,a,b (1≤s,t,a,b≤10^5)，并且a!=b。
    输出：
        输出的唯一一行包含一个整数，表示最少需要使用多少次a才能将数字s变成数字t。
*/
#include <iostream>
#include <vector>
#include <climits>

int min = INT_MAX;
void SolveMethod(int s, int t, int a, int b){
    if(s == t){
        return;
    }
    std::vector<int> choices = {a, -a, b, -b};
    int cnt = 0;
    for(int i = 0; i < 3; ++i){
        s += choices[i];
        if(i < 2){
            ++cnt;
        }
        SolveMethod(s, t, a, b);
        s -= choices[i];
    }

}

int main(int argc, char* argv[]){
    int s, t, a, b;
    std::cin >> s >> t >> a >> b;
    SolveMethod(s, t, a, b);
    std::cout << min << std::endl;
    return 0;
}