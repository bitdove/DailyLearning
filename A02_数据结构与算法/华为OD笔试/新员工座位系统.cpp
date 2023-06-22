/*
第一题：新员工座位系统
    工位由序列F1，F2，...Fn组成，Fi的值为0、1或2。0代表空位，1代表有人，2代表障碍物。
    定义“某一空位的友好度=左右连续老员工数之和”。给出工位序列，求友好度的最大值。
*/

#include <iostream>
#include <vector>
#include <unordered_map>

int GetFriendlyDegree(std::vector<int> &seats){
    std::unordered_map<int, int> leftToRight;
    int sum = 0;
    for(int i = 0; i < seats.size(); ++i){
        if(seats[i] == 0){
            leftToRight[i] = sum;
            sum = 0;
        }
        else if(seats[i] == 1){
            ++sum;
        }
        else if(seats[i] == 2){
            sum = 0;
        }
    }
    std::unordered_map<int, int> rightToLeft;
    sum = 0;
    for(int i = seats.size() - 1; i >= 0; --i){
        if(seats[i] == 0){
            rightToLeft[i] = sum;
            sum = 0;
        }
        else if(seats[i] == 1){
            ++sum;
        }
        else if(seats[i] == 2){
            sum = 0;
        }
    }
    int max = 0;
    for(auto it : leftToRight){
        max = (max, it.second + rightToLeft[it.first]);
    }
    return max;   
}

/*
第二题：商场优惠活动
*/


int main(){
    std::vector<int> seats;
    int seat;
    while(std::cin >> seat){
        seats.push_back(seat);
    } 
    std::cout << GetFriendlyDegree(seats) << std::endl;
    return 0;
}