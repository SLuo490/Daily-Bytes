/*
This question is asked by Apple. Given two binary strings (strings containing only 1s and 0s) return their sum (also as a binary string).
Note: neither binary string will contain leading 0s unless the string itself is 0

Ex: Given the following binary strings...

"100" + "1", return "101"
"11" + "1", return "100"
"1" + "0", return  "1"
*/

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

string addBinary(string s, string t) {
  string res = "";
  int carry = 0;
  int i = s.length() - 1, j = t.length() - 1;

  while (i >= 0 || j >= 0 || carry != 0) {
    // if the last element is a 1 increment carry
    if (i >= 0) {
      carry += s[i] == '0' ? 0 : 1;
      i--;
    }

    // if the last element is a 1 increment carry
    if (j >= 0) {
      carry += t[j] == '0' ? 0 : 1;
      j--;
    }

    // if carry % 2 == 0 add 0 if 1 add 1 to res
    res = ((carry % 2) == 0 ? "0" : "1") + res;
    carry /= 2;
  }
  return res;
}

int main() {
  string a = "11";
  string b = "1";

  cout << addBinary(a, b) << endl;
}