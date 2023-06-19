#include <iostream>
#include <vector>
#include <algorithm>

void Heapify(std::vector<int>& arr, int index, int heap_size){
    int parent_index = index;
    int leftChild_index = 2 * parent_index + 1;
    while(leftChild_index < heap_size){
        int maxValue_index = leftChild_index+1 < heap_size && arr[leftChild_index+1] > arr[leftChild_index]
                             ? leftChild_index+1 : leftChild_index;
        maxValue_index = arr[maxValue_index] > arr[parent_index] ? maxValue_index : parent_index;
        if(maxValue_index == parent_index)
            return;
        std::swap(arr[maxValue_index], arr[parent_index]);
        parent_index = maxValue_index;
        leftChild_index = 2 * parent_index + 1;
    } 
}

void HeapSort(std::vector<int>& arr){
    if(arr.size() < 2)
        return;
    int heap_size = arr.size();

    for(int i = (heap_size-1)/2; i >= 0; --i)
        Heapify(arr, i, heap_size);

    std::swap(arr[0], arr[--heap_size]);

    while(heap_size > 0){
        Heapify(arr, 0, heap_size);
        std::swap(arr[0], arr[--heap_size]);
    }
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

    HeapSort(arr);

    std::cout << "Sorted   Datas: ";
    for(auto e : arr)
        std::cout << e << " ";
    std::cout << std::endl;

    return 0;
}