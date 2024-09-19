#include <iostream>
#include <vector>

//冒泡排序
void BubbleSort(std::vector<int>& nums){
    const int size = nums.size();
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size - i - 1; ++j){
            if(nums[j] > nums[j+1]){
                std::swap(nums[j], nums[j+1]);
            }
        }
    }
}

//插入排序
void InsertSort(std::vector<int>& nums){
    const int size = nums.size();
    for(int i = 1; i < size; ++i){
        int curr = nums[i];
        int j = i - 1;
        while(j >= 0 && curr < nums[j]){
            nums[j+1] = nums[j];
            --j;
        }
        nums[j+1] = curr;
    }
}

//选择排序
void SelectSort(std::vector<int>& nums){
    const int size = nums.size();
    for(int i = 0; i < size; ++i){
        int minIndex = i;
        for(int j = i + 1; j < size; ++j){
            if(nums[j] < nums[minIndex]){
                minIndex = j;
            }
        }
        std::swap(nums[i], nums[minIndex]);
    }
}

//归并排序
std::vector<int> temp;  //辅助数组
void MergeSort(std::vector<int>& nums, int left, int right){
    if(left >= right){
        return;
    }
    int mid = left + (right - left) / 2;

    //“分”
    MergeSort(nums, left, mid);
    MergeSort(nums, mid + 1, right);

    //"治"
    int i = left;
    int j = mid + 1;
    int t = left;
    while(i <= mid && j <= right){
        if(nums[i] <= nums[j]){
            temp[t++] = nums[i++];
        }
        else{
            temp[t++] = nums[j++];
        }
    }
    while(i <= mid){
        temp[t++] = nums[i++];
    }
    while(j <= right){
        temp[t++] = nums[j++];
    }
    for(int k = left; k <= right; ++k){
        nums[k] = temp[k];
    }
}

//快速排序
void QuickSort(std::vector<int>& nums, int left, int right){
    if(left >= right){
        return;
    }
    //"治"
    int i = left;
    int j = right;
    while(i < j){
        while(i < j && nums[j] > nums[left])     --j;
        while(i < j && nums[i] <= nums[left])    ++i;
        std::swap(nums[i], nums[j]);
    }
    std::swap(nums[i], nums[left]);
    //“分”
    QuickSort(nums, left, i - 1);
    QuickSort(nums, i + 1, right);
}

//堆调整
void Heapify(std::vector<int>& nums, int index, int heap_size){
    int parent_index = index;
    int leftChild_index = 2 * parent_index + 1;
    while(leftChild_index < heap_size){
        int maxValue_index = leftChild_index+1 < heap_size && nums[leftChild_index+1] > nums[leftChild_index]
                             ? leftChild_index+1 : leftChild_index;
        maxValue_index = nums[maxValue_index] > nums[parent_index] ? maxValue_index : parent_index;
        if(maxValue_index == parent_index)
            return;
        std::swap(nums[maxValue_index], nums[parent_index]);
        parent_index = maxValue_index;
        leftChild_index = 2 * parent_index + 1;
    } 
}
//堆排序
void HeapSort(std::vector<int>& nums){
    if(nums.size() < 2)
        return;
    int heap_size = nums.size();

    //从下标最大的父节点开始。（最后一个元素的下标是n-1，最后一个父节点的下标是n/2-1）
    for(int i = heap_size/2 - 1; i >= 0; --i)
        Heapify(nums, i, heap_size);

    std::swap(nums[0], nums[--heap_size]);

    while(heap_size > 0){
        Heapify(nums, 0, heap_size);
        std::swap(nums[0], nums[--heap_size]);
    }
}

//希尔排序
void ShellSort(std::vector<int>& nums){
    const int size = nums.size();
    for(int gap = size / 2; gap > 0; gap /= 2){
        for(int i = gap; i < size; ++i){
            int curr = nums[i];
            int j = i - gap;
            while(j >= 0 && curr < nums[j]){
                nums[j+gap] = nums[j];
                j -= gap;
            }
            nums[j+gap] = curr;
        }
    }
}

int main(int argc, char* argv[]){
    std::vector<int> nums;
    int num;
    while(std::cin >> num){
        nums.push_back(num);
    }

    //打印原始数组
    std::cout << "原始数组：";
    for(int num : nums){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    //排序数组并打印
    //BubbleSort(nums); //冒泡排序
    //QuickSort(nums, 0, nums.size() - 1); //快速排序
    //SelectSort(nums); //选择排序
    //HeapSort(nums); //堆排序
    //InsertSort(nums);  //插入排序
    //ShellSort(nums); //希尔排序
    //temp.resize(nums.size()); //归并排序
    //MergeSort(nums, 0, nums.size()-1); //归并排序
    std::cout << "排序数组：";
    for(int num : nums){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}