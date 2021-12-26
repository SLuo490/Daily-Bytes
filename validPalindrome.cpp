/*
This question is asked by Facebook. Given a string, return whether or not it forms a palindrome ignoring case and non-alphabetical characters.
Note: a palindrome is a sequence of characters that reads the same forwards and backwards.

Ex: Given the following strings...

"level", return true
"algorithm", return false
"A man, a plan, a canal: Panama.", return true
*/

#include <iostream>
#include <string>

using namespace std;

bool isValidPalindrome(string &str) {
  // add both digit and alphabet to res
  string res = "";

  for (auto ch : str) {
    if (isalnum(ch)) {
      res += tolower(ch);
    }
  }

  // check if valid palindrome
  int j = res.length() - 1;
  int i = 0;
  while (i < j) {
    if (res[i++] != res[j--]) {
      return false;
    }
  }
  return true;
}

void print(bool valid) {
  valid ? cout << "True" : cout << "False";
  cout << endl;
}

int main() {
  string str = "level";
  string str2 = "algorithm";
  string str3 = "A man, a plan, a canal: Panama";
  string str4 = "0A";

  bool valid1 = isValidPalindrome(str);
  print(valid1);

  bool valid2 = isValidPalindrome(str2);
  print(valid2);

  bool valid3 = isValidPalindrome(str3);
  print(valid3);

  bool valid4 = isValidPalindrome(str4);
  print(valid4);

  return 0;
}