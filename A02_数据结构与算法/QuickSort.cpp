#include <iostream>
#include <vector>
#include <algorithm>

void QuickSort(std::vector<int> &arr, int left, int right){
    if(left >= right)
        return;
    int i = left;
    int j = right;
    while(i < j){
        while(i < j && arr[j] > arr[left])  --j;
        while(i < j && arr[i] <= arr[left])  ++i;
        std::swap(arr[i], arr[j]);
    }
    std::swap(arr[i], arr[left]);

    QuickSort(arr, left, i-1);
    QuickSort(arr, i+1, right);
}

int main(){
    std::vector<int> vec;
    int num;
    while(std::cin >> num)
        vec.push_back(num);
    for(auto e : vec)
        std::cout << e << " ";
    std::cout << std::endl;

    QuickSort(vec, 0, vec.size()-1);
    for(auto e : vec)
        std::cout << e << " ";
    std::cout << std::endl;

    return 0;
}