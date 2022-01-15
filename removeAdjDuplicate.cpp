/*
This question is asked by Facebook. Given a string s containing only lowercase letters, continuously remove adjacent characters that are the same and return the result.

Ex: Given the following strings...

s = "abccba", return ""
s = "foobar", return "fbar"
s = "abccbefggfe", return "a"
*/

#include <iostream>
#include <string>

using namespace std;

string removeAdjDuplicate(string s) {
  string res = "";
  for (auto& ch : s) {
    if (res.size() && res.back() == ch) {
      res.pop_back();
    } else {
      res.push_back(ch);
    }
  }
  return res;
}

int main() {
  string s = "abccba", s1 = "foobar", s2 = "abccbefggfe";
  cout << removeAdjDuplicate(s) << endl;
  cout << removeAdjDuplicate(s1) << endl;
  cout << removeAdjDuplicate(s2) << endl;

  return 0;
}