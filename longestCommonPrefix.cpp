/*
This question is asked by Microsoft. Given an array of strings, return the longest common prefix that is shared amongst all strings.
Note: you may assume all strings only contain lowercase alphabetical characters.

Ex: Given the following arrays...

["colorado", "color", "cold"], return "col"
["a", "b", "c"], return ""
["spot", "spotty", "spotted"], return "spot"
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
  // find the shortest length word
  int shortest = strs[0].length();

  for (auto word : strs) {
    if (shortest > word.length()) {
      shortest = word.length();
    }
  }

  int idx = 0;
  string res = "";

  for (auto ch : strs[0]) {
    for (int i = 1; i < strs.size(); i++) {
      if (strs[i][idx] != ch || idx > shortest) {
        return res;
      }
    }
    res += ch;
    idx++;
  }
  return res;
}

int main() {
  vector<string> s1 = {"flower", "flow", "flight"};
  vector<string> s2 = {"dog", "racecar", "car"};

  cout << longestCommonPrefix(s1) << endl;
  cout << longestCommonPrefix(s2) << endl;

  return 0;
}