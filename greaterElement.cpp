/*
This question is asked by Amazon. Given two arrays of numbers, where the first array is a subset of the second array, return an array containing all the next greater elements for each element in the first array, in the second array. If there is no greater element for any element, output -1 for that number.

Ex: Given the following arrays…

nums1 = [4,1,2], nums2 = [1,3,4,2], return [-1, 3, -1] because no element in nums2 is greater than 4, 3 is the first number in nums2 greater than 1, and no element in nums2 is greater than 2.
nums1 = [2,4], nums2 = [1,2,3,4], return [3, -1] because 3 is the first greater element that occurs in nums2 after 2 and no element is greater than 4.
*/

#include <iostream>
#include <vector>

using namespace std;

int findElement(vector<int>& nums2, int target) {
  for (int i = 0; i < nums2.size(); i++) {
    if (nums2[i] == target) {
      return i;
    }
  }
  return -1;
}

int findGreater(vector<int>& nums2, int idx) {
  if (idx + 1 == nums2.size()) return -1;

  int greater = -1;
  for (int i = idx + 1; i < nums2.size(); i++) {
    if (nums2[i] > nums2[idx]) {
      greater = nums2[i];
      break;
    }
  }
  return greater;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
  vector<int> res;
  for (int i = 0; i < nums1.size(); i++) {
    int idx = findElement(nums2, nums1[i]);
    int nextGreater = findGreater(nums2, idx);
    res.push_back(nextGreater);
  }
  return res;
}

void print(vector<int>& res) {
  for (auto num : res) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  vector<int> nums1 = {4, 1, 2};
  vector<int> nums2 = {1, 3, 4, 2};

  vector<int> res = nextGreaterElement(nums1, nums2);
  print(res);

  return 0;
}