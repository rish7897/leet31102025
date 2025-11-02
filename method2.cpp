#include<iostream>
using namespace std;

// We XOR all the numbers in nums with all the numbers from 0 to n−1.
// The result is the XOR of the two extra numbers, denoted as y.
// The lowest differing bit between these two numbers can be found using lowBit = y & -y.
// Using this bit, we divide all the numbers in nums and the numbers from 0 to n−1 into two groups, then compute the XOR of each group. The results are the two missing numbers.

vector<int> getSneakyNumbers(vector<int>& nums) {
    int n = nums.size() - 2;
    int totalXOR  = 0;
    for(int i = 0; i < nums.size(); i++){
        totalXOR ^= nums[i];
    }
    for(int i = 0; i < n; i++){
        totalXOR ^= i;
    }
    int lowestBit = totalXOR & (-1 * totalXOR);
    int num1 = 0;
    int num2 = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] & lowestBit){
            num1 ^= nums[i];
        }else{
            num2 ^= nums[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(i & lowestBit){
            num1 ^= i;
        }else{
            num2 ^= i;
        }
    }
    vector<int> ans;
    ans.push_back(num1);
    ans.push_back(num2);
    return ans;
}