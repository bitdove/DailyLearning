/*
第二题：商场优惠活动
    三种券：
        1. 满减券：每满100减10；
        2. 打折券：打92折，一次购物限限使用1张；
        3. 无门槛券：立减5元，无使用次数限制。
    优惠券使用限制：
        1. 每次最多使用2种优惠券；
        2. 使用多张同一类型优惠券时必须一次性使用完，不可同其他优惠券交替使用；
        3. 优惠活动每人仅限参加一次，每人的优惠券的种类和数量相同。
    问题：
        设计一个算法帮消费者用最少的券获得最优惠的价格。
        优惠后价格越低越好，同样的优惠价格，使用的优惠券越少越好。
    输入：
        第一行：每个人的优惠券数量，按[满减、打折、无门槛]顺序输入；
        第二行：购物人数n；
        后n行：每个人的优惠前总金额。
    输出：
        每行输出每个人优惠后的最低价格以及对应使用优惠券的数量。
*/


#include <iostream>
#include <vector>
#include <climits>

std::vector<int> UseCoupon1(int coupon1, std::vector<int> result){
    int tmp = result[0];
    while(tmp >= 100 && coupon1 > 0){
        --coupon1;
        ++result[1];        
        result[0] -= 10;
        tmp -= 100;
    }
    return result;
}

std::vector<int> UseCoupon2(int coupon2, std::vector<int> result){
    if(coupon2 > 0){
        --coupon2;
        ++result[1];
        result[0] = static_cast<int>(result[0] * 0.92);
    }
    return result;
}

std::vector<int> UseCoupon3(int coupon3, std::vector<int> result){
    while(result[0] >= 5 && coupon3 > 0){
        --coupon3;
        ++result[1];
        result[0] -= 5;
    }
    return result;
}

void SolveMethod(std::vector<int> coupons, std::vector<int> &amounts){
    int c1 = coupons[0];
    int c2 = coupons[1];
    int c3 = coupons[2];
    for(int amount : amounts){
        std::vector<int> result = {INT_MAX, INT_MAX};
        std::vector<int> res1 = UseCoupon1(c1, {amount, 0});
        std::vector<int> res2 = UseCoupon2(c2, {amount, 0});
        std::vector<int> res3 = UseCoupon3(c3, {amount, 0});
        
        //金额小于100时，只能用券2和券3，基数越大92折省的越多，所以先用92折
        if(amount < 100){
            result = UseCoupon2(c3, res2);
            std::cout << result[0] << " " << result[1] << std::endl;
            continue;
        }
        //因为无门槛是实打实的减5元，所以不考虑先用它
        //如果用完满减比用完92折更优惠，则有满减+92折 和 满减+无门槛 两种情况
        if(res1[0] < res2[0]){
            std::vector<int> r12 = UseCoupon2(c2, res1);
            std::vector<int> r13 = UseCoupon3(c3, res1);
            result = r12[0] < r13[0] ? r12 : r13;
        }
        //反之，如果用完92折比用完满减更优惠，则有92折+满减 和 92折+无门槛 两种情况
        else{
            std::vector<int> r21 = UseCoupon2(c1, res2);
            std::vector<int> r23 = UseCoupon3(c3, res2);
            result = r21[0] < r23[0] ? r21 : r23;            
        }
        std::cout << result[0] << " " << result[1] << std::endl;
    }
}

int main(int argc, char* argv[]){
    int coupon1, coupon2, coupon3, n;
    std::cin >> coupon1 >> coupon2 >> coupon3 >> n;
    std::vector<int> amounts(n);
    for(int i = 0; i < n; ++i){
        std::cin >> amounts[i];
    }
    SolveMethod({coupon1, coupon2, coupon3}, amounts);
    return 0;
}