/*
This question is asked by Google. Given a string only containing the following characters (, ), {, }, [, and ] return whether or not the opening and closing characters are in a valid order.

Ex: Given the following strings...
"(){}[]", return true
"(({[]}))", return true
"{(})", return false
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
  stack<char> st;

  // if first character is a closing parent return false
  if (s[0] == '}' || s[0] == ']' || s[0] == ')') return false;

  for (int i = 0; i < s.length(); i++) {
    if (st.empty() && s[i] == '}' || st.empty() && s[i] == ']' || st.empty() && s[i] == '}') {
      return false;
    }

    if (s[i] == '}' && st.top() == '{' || s[i] == ']' && st.top() == '[' || s[i] == ')' && st.top() == '(') {
      st.pop();
    } else {
      st.push(s[i]);
    }
  }
  return st.empty();
}

int main() {
  string s = "(){}[]";
  string s1 = "(({[]}))";
  string s2 = "{[]{{})";

  cout << isValid(s) << endl;
  cout << isValid(s1) << endl;
  cout << isValid(s2) << endl;

  return 0;
}