#include <iostream>
#include <vector>
using namespace std;

class Solution {
public: //我的做法
    int maxSubArray(vector<int>& nums) {
        int dp =0;
        int minc = 0;
        int maxv = nums[0];
        for(int id = 0; id<nums.size(); ++id){
            dp+=nums[id]; //dp保存从头到该位置的和(只保留最近的一格)
            maxv = max(maxv,dp-minc);  //更新max值
            minc = min(minc,dp);       //记录之前dp的最小值
            //(发现minc和dp很相似,可以合并这两个参数升级为官方题解)
        }
        return maxv;
    }
};

class Solution {
public:  //官方题解
    int maxSubArray(vector<int>& nums) {
        int dp = 0, maxAns = nums[0];
        for (const auto &x: nums) {
//考虑 nums[i] 单独成为一段还是加入 f(i-1) 对应的那一段，
//这取决于 nums[i] 和 f(i-1) + nums[i] 的大小，
//我们希望获得一个比较大的            
            dp = max(dp + x, x);  //有背包问题的影子
            maxAns = max(maxAns, dp);
        }
        return maxAns;
    }
};





int main(){
    Solution ss;
    vector<int> in_v{-2,-1};
    int out = ss.maxSubArray(in_v);
    cout<<out;
    return 0;
}
