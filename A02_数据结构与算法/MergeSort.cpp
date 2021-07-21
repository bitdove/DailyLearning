#include <iostream>
#include <vector>

std::vector<int> temp;

void MergeSort(std::vector<int> &arr, int left, int right){
    if(left >= right)
        return;
    int mid = left + (right - left) >> 1;

    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);

    int 
}

int main(){
    std::vector<int> arr;
    int num;
    while(std::cin >> num)
        arr.push_back(num);
    temp.resize(arr.size());
    MergeSort(arr, 0, arr.size()-1);
    for(auto e : arr)
        std::cout << e << " ";
    std::cout << std::endl;
    return 0;
}