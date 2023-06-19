#include <iostream>
#include <vector>

/*
冒泡排序:
    比较相邻的元素。如果第一个比第二个大，就交换它们两个；
    对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对。这一步结束后，排在最后的元素会是所有数据中最大的数；
    针对所有的元素重复以上的步骤，除了最后一个；
    持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
时间复杂度：O(n^2)
空间复杂度：O(1)
稳定性：稳定
*/
void BubbleSort(std::vector<int> &nums){
    const int len = nums.size();
    for(int i = 0; i < len - 1; ++i){
        for(int j = 0; j < len - 1 - i; ++j){
            if(nums[j] > nums[j+1]){
                std::swap(nums[j], nums[j+1]);
            }
        }
    }
}

/*
快速排序：
    快速排序是从冒泡排序演变而来的，实际上是在冒泡排序基础上的递归分治法。
    快速排序在每一轮挑选一个基准元素，并让其他比它大的元素移动到数列一边，
    比它小的元素移动到数列的另一边，从而把数列拆解成了两个部分。
    也是用了分治策略，其本质框架是二叉树的前序遍历。
时间复杂度：O(nlogn)
空间复杂度：O(1)
稳定性：不稳定
*/
void QuickSort(std::vector<int> &nums, int left, int right){
    if(left >= right){
        return;
    }
    
    int i = left;
    int j = right;
    while(i < j){
        while(i < j && nums[j] > nums[left]) --j;
        while(i < j && nums[i] <= nums[left]) ++i;
        std::swap(nums[i], nums[j]);
    }
    std::swap(nums[i], nums[left]);

    QuickSort(nums, left, i - 1);
    QuickSort(nums, i + 1, right);
}



/*
简单选择排序：
    先选择一个位置作为最小元素位置
    通过遍历，将每个元素与这个选定元素做比较并更新最小元素位置
    这样结束后就找到了最小元素的位置，把它与未排序的第一个元素进行交换。
    从下一个位置重复上述过程。
时间复杂度：O(n^2)
空间复杂度：O(1)
稳定性：不稳定
    比如[3,3,1]
*/
void SelectionSort(std::vector<int> &nums){
    const int len = nums.size();
    for(int i = 0; i < len - 1; ++i){
        int minIndex = i;
        for(int j = i + 1; j < len; ++j){
            if(nums[j] < nums[minIndex]){
                minIndex = j;
            }
        }
        std::swap(nums[i], nums[minIndex]);
    }
}

/*
简单插入排序：
    将待排序数据看成由已排序和未排序两部分组成。
    对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
时间复杂度：O(n^2)
空间复杂度：O(1)
稳定性：稳定
*/
void InsertSort(std::vector<int> &nums){
    const int len = nums.size();
    for(int i = 1; i < len; ++i){
        int curr = nums[i];
        int j = i - 1;
        while(j >= 0 && nums[j] > curr){
            nums[j+1] = nums[j];
            --j;
        }
        nums[j+1] = curr;
    }
}

/*
二路归并排序：
    归并排序采用分治策略，其本质框架是二叉树的后序遍历，左右子树的递归就是“分”，根结点的处理部分就是“治”。
时间复杂度：O(nlogn)
空间复杂度：O(n)
稳定性：稳定
*/
//temp是临时存储的中转数组
std::vector<int> temp;
void MergeSort(std::vector<int> &nums, int left, int right){
    if(left >= right){
        return;
    }
    int mid = left + (right - left) / 2;

    //“分”的过程。相当于左右子树递归。
    MergeSort(nums, left, mid);
    MergeSort(nums, mid + 1, right);

    //“治”的过程。相当于根结点的遍历。
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

int main(int argc, char *argv[]){
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
    QuickSort(nums, 0, nums.size() - 1); //快速排序
    //SelectionSort(nums); //简单选择排序
    //InsertSort(nums);  //简单插入排序
    //temp.resize(nums.size()); //归并排序
    //MergeSort(nums, 0, nums.size()-1); //归并排序
    std::cout << "排序数组：";
    for(int num : nums){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}