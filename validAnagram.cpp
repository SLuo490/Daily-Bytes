/*
This question is asked by Facebook. Given two strings s and t return whether or not s is an anagram of t.
Note: An anagram is a word formed by reordering the letters of another word.

Ex: Given the following strings...

s = "cat", t = "tac", return true
s = "listen", t = "silent", return true
s = "program", t = "function", return false
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool validAnagram(string s, string t) {
  unordered_map<char, int> mp;

  for (auto ch : t) {
    mp[ch]++;
  }

  for (int i = 0; i < s.length(); i++) {
    char currChar = s[i];

    if (mp.find(currChar) != mp.end()) {
      mp[currChar]--;
      if (mp[currChar] == 0) {
        mp.erase(currChar);
      }
    }
  }

  return mp.size() == 0 ? true : false;
}

int main() {
  string s = "cat";
  string t = "tac";

  cout << validAnagram(s, t) << endl;

  string s1 = "program";
  string t1 = "function";

  cout << validAnagram(s1, t1) << endl;

  string s2 = "listen";
  string t2 = "silent";

  cout << validAnagram(s2, t2) << endl;
  return 0;
}