/*
This question is asked by Amazon. Given a string representing the sequence of moves a robot vacuum makes, return whether or not it will return to its original position. The string will only contain L, R, U, and D characters, representing left, right, up, and down respectively.

Ex: Given the following strings...

"LR", return true
"URURD", return false
"RUULLDRD", return true
*/

#include <iostream>
#include <string>
using namespace std;

bool solution(string str) {
  // R and U = 1
  // L and D = -1

  int pos = 0;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'R' || str[i] == 'U') {
      pos += 1;
    } else {
      pos -= 1;
    }
  }

  return (pos == 0) ? true : false;
}

void print(bool x) {
  x ? cout << "True" : cout << "False";
  cout << endl;
}

int main() {
  string s = "LR";
  string s1 = "URURD";
  string s2 = "RUULLDRD";

  bool test = solution(s);
  print(test);
  bool test1 = solution(s1);
  print(test1);
  bool test2 = solution(s2);
  print(test2);

  return 0;
}