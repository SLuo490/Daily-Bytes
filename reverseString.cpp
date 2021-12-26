/*
This question is asked by Google. Given a string, reverse all of its characters and return the resulting string.

Ex: Given the following strings...

“Cat”, return “taC”
“The Daily Byte”, return "etyB yliaD ehT”
“civic”, return “civic”
*/

#include <iostream>
#include <string>
using namespace std;

string reverseString(string& str) {
  int j = str.length() - 1;
  int i = 0;

  while (i < j) {
    swap(str[i], str[j]);
    i++;
    j--;
  }
  return str;
}

int main() {
  string str = "The Daily Byte";
  cout << reverseString(str) << endl;

  string str2 = "";
  cout << reverseString(str2) << endl;
  return 0;
}