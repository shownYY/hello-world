#include <iostream>
#include <vector>
using namespace std;
//  堆排序
// 递归方式构建大根堆(len是arr的长度，index是第一个非叶子节点的下标)
void adjust(int arr[], int len, int index)
{
    int left = 2 * index + 1;  // index的左子节点
    int right = 2 * index + 2; // index的右子节点

    int maxIdx = index;
    if (left < len && arr[left] > arr[maxIdx])
        maxIdx = left;
    if (right < len && arr[right] > arr[maxIdx])
        maxIdx = right;

    if (maxIdx != index)
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }
}
// 堆排序
void heapSort(int arr[], int size)
{
    // 构建大根堆（从最后一个非叶子节点向上）
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        adjust(arr, size, i);
    }

    // 调整大根堆
    for (int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]); // 将当前最大的放置到数组末尾
        adjust(arr, i, 0);    // 将未完成排序的部分继续进行堆排序
    }
}

int main()
{
    int arr[] = {8, 1, 14, 3, 21, 5, 7, 10};
    int leng=(sizeof(arr)/sizeof(arr[0]));
    heapSort(arr, leng);
    for (int i = 0; i < leng; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}