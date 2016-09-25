//
//  main.cpp
//  ShellSort_C++
//
//  Created by chenyufeng on 9/25/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

/**
 *  Shell排序时间复杂度O(n^1.3),空间复杂度O(1),不稳定排序
 */

using namespace std;

void ShellSort(vector<int> &vec);

int main(int argc, const char * argv[])
{
    int arr[] = {4,2,8,9,0,1};
    vector<int>vectorArray(arr, arr + sizeof(arr)/sizeof(int));
    ShellSort(vectorArray);

    for (int i = 0; i < vectorArray.size(); i++)
    {
        cout << vectorArray[i] << " ";
    }

    return 0;
}

void ShellSort(vector<int> &vec)
{
    long gap;
    long i;
    long size = vec.size();
    // 注意：gap为多少，就把序列分为多少组；
    // 最后一次插入排序时，gap = 1；
    for (gap = size / 2; gap > 0; gap = gap / 2)
        for (i = 0; i < gap; i++)
            // 对每一组分别进行直接插入排序
            for (long j = i + gap; j < size; j = j + gap)
            {
                if (vec[j] < vec[j - gap])
                {
                    int temp = vec[j];
                    long m;
                    for (m = j - gap; m >= i && temp < vec[m]; m = m - gap)
                    {
                        // 查找元素位置，并移动数组
                        vec[m + gap] = vec[m];
                    }
                    vec[m + gap] = temp;
                }
            }
}








