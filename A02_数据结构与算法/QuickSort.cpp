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
    std::vector<int> arr;
    int num;

    std::cout << "Enter    Datas: ";
    while(std::cin >> num)
        arr.push_back(num);

    std::cout << "Original Datas: ";
    for(auto e : arr)
        std::cout << e << " ";
    std::cout << std::endl;

    QuickSort(arr, 0, arr.size()-1);

    std::cout << "Sorted   Datas: ";
    for(auto e : arr)
        std::cout << e << " ";
    std::cout << std::endl;

    return 0;
}