#include<iostream>
#include<vector>
using namespace std;

vector<int> getSneakyNumbers(vector<int>& nums) {
    vector<int> visited(nums.size(), 0);
    vector<int>ans;
    for(int i = 0; i < nums.size(); i++){
        if(visited[nums[i]] == 0){
            visited[nums[i]] = 1;
        }else{
            ans.push_back(nums[i]);
        }
    }
    return ans;
}