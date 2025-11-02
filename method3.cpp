#include<iostream>
using namespace std;

// Mathematics
vector<int> getSneakyNumbers(vector<int>& nums) {
    int sum = 0;
    int squaredSum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        squaredSum += nums[i] * nums[i];
    }
    int n = nums.size() - 2;
    sum -= (n * (n - 1)) / 2;
    squaredSum -= (n * (n - 1) * (2 * n - 1)) / 6;
    int mul = (sum * sum - squaredSum) / 2;
    int num1 = (sum + sqrt(sum * sum - 4 * mul)) / 2;
    int num2 = (sum - sqrt(sum * sum - 4 * mul)) / 2;
    vector<int> ans;
    ans.push_back(num1);
    ans.push_back(num2);
    return ans;
}