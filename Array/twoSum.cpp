/*
This question is asked by Google. Given an array of integers, return whether or not two numbers sum to a given target, k.
Note: you may not sum a number with itself.

Ex: Given the following...

[1, 3, 8, 2], k = 10, return true (8 + 2)
[3, 9, 13, 7], k = 8, return false
[4, 2, 6, 5, 2], k = 4, return true (2 + 2)
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> mp;

  for (int i = 0; i < nums.size(); i++) {
    if (mp.find(target - nums[i]) != mp.end()) {
      return true;
    }
    mp[nums[i]] = i;
  }
  return false;
}

int main() {
  vector<int> v1 = {1, 3, 8, 2};
  int target1 = 10;
  vector<int> v2 = {3, 9, 13, 7};
  int target2 = 8;
  vector<int> v3 = {4, 2, 6, 5, 2};
  int target3 = 4;
  vector<int> v4 = {4, 2, 0, 5, 2};
  int target4 = 0;

  cout << twoSum(v1, target1) << endl;
  cout << twoSum(v2, target2) << endl;
  cout << twoSum(v3, target3) << endl;
  cout << twoSum(v4, target4) << endl;

  return 0;
}