#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    void fastSort(vector<int>& arr, int l, int r) { //small to big
        if(l >= r) return;
        int i = l, j = r;
        while(i < j) {  //i左 j右
            while(arr[j] >= arr[l] && i < j) j--;  //以最左为pivot, 右边先动,右边凡是比pivot大的都不用动,下一个j--
            while(arr[i] <= arr[l] && i < j) i++;  //左边后动, 凡是比pivot小的都不用动,i++
            swap(arr[i], arr[j]);  //左右交换, 左右ij继续移动直到相遇
        }
        swap(arr[i], arr[l]);     //将pivot,最左的arr[l]换到ij相遇位置(即它的归宿)
        fastSort(arr, l, i - 1);  //递归调用, 完成对分割后的左右两端的排序, 当前i即为分割位置
        fastSort(arr, i + 1, r);
    }

    void fastSort_big_to_small(vector<int>& arr, int l, int r) {
        if(l >= r) return;
        int i = l;
        int j = r;
        while(i < j) {  //i左 j右
            //没有等号的话,两个相同的数导致死循环
            while(arr[j] <= arr[l] && i < j) j--;  //大于小于号的方向 决定 从大到小or从小到大排序
            while(arr[i] >= arr[l] && i < j) i++;  
            swap(arr[i], arr[j]);  
            
        }
        swap(arr[i], arr[l]);     //将pivot,最左的arr[l]换到ij相遇位置(即它的归宿)
        fastSort(arr, l, i - 1);  //递归调用, 完成对分割后的左右两端的排序, 当前i即为分割位置
        fastSort(arr, i + 1, r);
    }
};


/* Function to print an array */
void printArray(vector<int> arr, int n) 
{ 
    int i; 
	for (i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout <<endl; 
} 


int main(){
	vector<int> arr = {10, 2, 5, 9, 1, 5}; 
	int n = arr.size();
    Solution ss;
	ss.fastSort(arr, 0, n-1);  //size比末尾index大1,要减掉, 否则越界
	//cout << "Sorted array: \n"; 
	printArray(arr, n); 
	return 0; 
} 
