/*
This question is asked by Facebook. Given a string and the ability to delete at most one character, return whether or not it can form a palindrome.
Note: a palindrome is a sequence of characters that reads the same forwards and backwards.

Ex: Given the following strings...

"abcba", return true
"foobof", return true (remove the first 'o', the second 'o', or 'b')
"abccab", return false
*/

#include <iostream>
#include <string>
using namespace std;

bool isValid(string str, int left, int right) {
  while (left < right) {
    if (str[left] != str[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

bool isValidPaliWithRemoval(string str) {
  int left = 0, right = str.length() - 1;

  while (left < right) {
    if (str[left] != str[right]) {
      return isValid(str, left + 1, right) || isValid(str, left, right - 1);
    }
    left++;
    right--;
  }
  return true;
}

int main() {
  string s1 = "abcba";
  cout << isValidPaliWithRemoval(s1) << endl;
  string s2 = "foobof";
  cout << isValidPaliWithRemoval(s2) << endl;
  string s3 = "abccab";
  cout << isValidPaliWithRemoval(s3) << endl;
}