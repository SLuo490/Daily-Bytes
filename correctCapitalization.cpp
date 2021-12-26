/*
This question is asked by Google. Given a string, return whether or not it uses capitalization correctly. A string correctly uses capitalization if all letters are capitalized, no letters are capitalized, or only the first letter is capitalized.

Ex: Given the following strings...

"USA", return true
"Calvin", return true
"compUter", return false
"coding", return true
*/

#include <iostream>
#include <string>

bool correctCapitalization(std::string str) {
  /*
    1. Only the First letter is capitalizat then it is correct
    2. All letters are capitalized
    3. No letters are capitalized
  */
  bool firstLetterCap = false;
  bool allLetterCap = false;
  bool noLetterCap = false;

  // If there is only one character
  if (str.length() == 1 && isupper(str[0])) {
    allLetterCap = true;
  }
  if (str.length() == 1 && islower(str[0])) {
    noLetterCap = true;
  }

  // If there is no character
  if (str.length() == 0) {
    return true;
  }

  // loop to check if only first letter is correct
  for (int i = 1; i < str.length(); i++) {
    if (isupper(str[0]) && islower(str[i])) {
      firstLetterCap = true;
    } else {
      firstLetterCap = false;
      break;
    }
  }

  // Loop to check if all letter is not capitalized
  for (int i = 1; i < str.length(); i++) {
    if (!isupper(str[i]) && !isupper(str[i - 1])) {
      noLetterCap = true;
    } else {
      noLetterCap = false;
      break;
    }

    if (i == str.length() - 1 && isupper(str[i])) {
      noLetterCap = false;
      break;
    }
  }

  // Loop to check if all letter is capitalized
  for (int i = 1; i < str.length(); i++) {
    if (!islower(str[i]) && !islower(str[i - 1])) {
      allLetterCap = true;
    } else {
      allLetterCap = false;
      break;
    }

    if (i == str.length() - 1 && islower(str[i])) {
      allLetterCap = false;
      break;
    }
  }

  return firstLetterCap || noLetterCap || allLetterCap ? true : false;
}

void print(bool x) {
  x ? std::cout << "True" : std::cout << "False";
  std::cout << std::endl;
}

int main() {
  std::string str1 = "USA";
  std::string str2 = "Calvin";
  std::string str3 = "compUter";
  std::string str4 = "coding";
  std::string str5 = "A";
  std::string str6 = "";

  bool test1 = correctCapitalization(str1);
  print(test1);
  bool test2 = correctCapitalization(str2);
  print(test2);
  bool test3 = correctCapitalization(str3);
  print(test3);
  bool test4 = correctCapitalization(str4);
  print(test4);
  bool test5 = correctCapitalization(str5);
  print(test5);
  bool test6 = correctCapitalization(str6);
  print(test6);

  return 0;
}