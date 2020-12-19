#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //执行用时： 44 ms , 在所有 C++ 提交中击败了 86.60% 的用户 内存消耗： 22.9 MB , 在所有 C++ 提交中击败了 42.42% 的用户
        int store_max = nums[0];
        for(int i=1; i<nums.size(); i++){
            if (nums[i-1]>0){
                nums[i] = nums[i-1]+nums[i];
            }
            if (store_max < nums[i])
            {
                store_max = nums[i];
            }
        }
        return store_max;
    }



    int maxSubArray_sub(vector<int>& nums) {
    //执行用时： 132 ms , 在所有 C++ 提交中击败了 6.87% 的用户 内存消耗： 24.3 MB , 在所有 C++ 提交中击败了 5.00% 的用户
    //新开辟空间保存每一步的临时计算值, 而且最后整体求max, 不如上面不断更新一个单一的max快
        vector<int> store_max;
        store_max.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if (store_max[i-1]>0){
                store_max.push_back(store_max[i-1]+nums[i]);
            }
            else{
                store_max.push_back(nums[i]);
            }
        }
        for(int i=0; i<nums.size(); i++){
            std::cout<<store_max[i]<<" ";
        }
        return *max_element(store_max.begin(),store_max.end());
    }
};