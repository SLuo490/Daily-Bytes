/*
This question is asked by Amazon. Given two strings s and t, which represents a sequence of keystrokes, where # denotes a backspace, return whether or not the sequences produce the same result.

Ex: Given the following strings...

s = "ABC#", t = "CD##AB", return true
s = "como#pur#ter", t = "computer", return true
s = "cof#dim#ng", t = "code", return false
*/

#include <iostream>
#include <string>

using namespace std;

bool compareKeystroke(string s, string t) {
  int i = s.length() - 1, j = t.length() - 1, backspace = 0;

  while (true) {
    backspace = 0;
    while (i >= 0 && (backspace > 0 || s[i] == '#')) {
      backspace += s[i] == '#' ? 1 : -1;
      i--;
    }
    backspace = 0;
    while (j >= 0 && (backspace > 0 || t[j] == '#')) {
      backspace += t[j] == '#' ? 1 : -1;
      j--;
    }

    if (i >= 0 && j >= 0 && s[i] == t[j]) {
      i--;
      j--;
    } else {
      break;
    }
  }
  return i == -1 && j == -1;
}

int main() {
  string s = "ABC#", t = "CD##AB";
  cout << compareKeystroke(s, t) << endl;
  string s1 = "como#pur#ter", t1 = "computer";
  cout << compareKeystroke(s1, t1) << endl;
  string s2 = "cof#dim#ng", t2 = "code";
  cout << compareKeystroke(s2, t2) << endl;

  return 0;
}