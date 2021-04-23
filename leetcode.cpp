#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
/****************
* 剑指offer 03. 找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
*****************/
int findRepeatNumber(vector<int>& nums) {
    unordered_map<int, int> num_map;
    int len = nums.size();
    for(int i = 0; i < len; i++){
        auto it = num_map.find(nums[i]);
        if(it != num_map.end()) {
            return nums[i];
        } else {
            num_map[nums[i]] = i;
        }
    }
    return len;
} 

/****************
* 剑指offer 04. 
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

解题要点：
线性查找，可以从左下角或者右上角开始查找，这样子每次都可以去掉一行/列
*****************/
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0)
        return false;
    int rows = matrix.size();
    int columns = matrix[0].size();
    int i = rows - 1, j = 0;
    while(i >= 0 && j < columns) {
        if(matrix[i][j] < target) {
            j++;
        }else if(matrix[i][j] > target) {
            i--;
        }else {
            return true;
        }
    }
    return false;
}

/****************
* 剑指offer 05. 替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

解题思路：
从尾到头开始查找，使得时间复杂度为O(n)
直接原地替换，空间开销最小
*****************/
string replaceSpace(string s) {
    int len = s.size();
    if(len == 0) {
        return s;
    }

    int space_num = 0;
    for(int i = 0; i < len; i++) {
        if(s[i] == ' ') {
            space_num++;
        }
    }

    if(space_num == 0)
        return s;
    
    int index = len -1 + space_num * 2;
    s.resize(index + 1);
    int i = len - 1;
    while(i >= 0 && index > i) {
        if(s[i] == ' ') {
            s[index--] = '0';
            s[index--] = '2';
            s[index] = '%';
        }else {
            s[index] = s[i];
        }
        index--;
        i--;
    }
    return s;
}

/****************
* 剑指offer 05. 变形题
有两个排序数组A1和A2，内存A1的末尾有足够多的空余空间容纳A2。
请实现一个函数，把A2中所有的数字插入到A1，并且所有的数字都是排序的。
*****************/
void arrayMerge(vector<int>& a1, vector<int>& a2) {
    
}

};