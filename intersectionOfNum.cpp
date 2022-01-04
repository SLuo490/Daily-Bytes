/*
This question is asked by Google. Given two integer arrays, return their intersection.
Note: the intersection is the set of elements that are common to both arrays.

Ex: Given the following arrays...

nums1 = [2, 4, 4, 2], nums2 = [2, 4], return [2, 4]
nums1 = [1, 2, 3, 3], nums2 = [3, 3], return [3]
nums1 = [2, 4, 6, 8], nums2 = [1, 3, 5, 7], return []
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> findIntersection(vector<int>& nums1, vector<int>& nums2) {
  unordered_map<int, int> mp;
  vector<int> res;

  // add nums1 to map
  for (auto num : nums1) {
    mp[num]++;
  }

  for (auto num : nums2) {
    // if the current num in nums2 is in the map, then it is an intersection
    if (mp.find(num) != mp.end()) {
      res.push_back(num);
      // erase the num
      mp.erase(num);
    }
  }
  return res;
}

void printVector(vector<int>& nums) {
  for (auto num : nums) {
    cout << num << endl;
  }
}

int main() {
  vector<int> nums1 = {2, 4, 4, 2};
  vector<int> nums2 = {2, 4};
  vector<int> res = findIntersection(nums1, nums2);
  // printVector(res);

  vector<int> nums3 = {1, 2, 3, 3};
  vector<int> nums4 = {3, 3};
  vector<int> res2 = findIntersection(nums3, nums4);
  // printVector(res2);

  vector<int> nums5 = {2, 4, 6, 8};
  vector<int> nums6 = {3, 3};
  vector<int> res3 = findIntersection(nums5, nums6);
  printVector(res3);

  return 0;
}