#include <iostream>
#include <vector>

std::vector<int> temp;

void MergeSort(std::vector<int> &arr, int left, int right){
    if(left >= right)
        return;
    int mid = left + ((right - left) >> 1);

    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);

    int i = left;
    int j = mid + 1;
    int count = left;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j])
            temp[count++] = arr[i++];
        else
            temp[count++] = arr[j++];
    }
    while(i <= mid)
        temp[count++] = arr[i++];
    while(j <= right)
        temp[count++] = arr[j++];
    for(int k = left; k <= right; ++k)
        arr[k] = temp[k];
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