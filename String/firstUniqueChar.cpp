/*
This question is asked by Microsoft. Given a string, return the index of its first unique character. If a unique character does not exist, return -1.

Ex: Given the following strings...

"abcabd", return 2
"thedailybyte", return 1
"developer", return 0
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Time: O(2N) -> O(N) Traverse string twice
// Space: O(N) -> Map
int firstUniqueChar(string str) {
  unordered_map<char, int> mp;

  for (auto ch : str) {
    mp[ch]++;
  }

  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    if (mp[ch] == 1) {
      return i;
    }
  }
  return -1;
}

int main() {
  string str = "abcabd";
  cout << firstUniqueChar(str) << endl;

  string str2 = "thedailybyte";
  cout << firstUniqueChar(str2) << endl;

  string str3 = "developer";
  cout << firstUniqueChar(str3) << endl;
  return 0;
}