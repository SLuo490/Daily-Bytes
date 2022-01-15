/*
This question is asked by Amazon. Given a string representing your stones and another string representing a list of jewels, return the number of stones that you have that are also jewels.

Ex: Given the following jewels and stones...

jewels = "abc", stones = "ac", return 2
jewels = "Af", stones = "AaaddfFf", return 3
jewels = "AYOPD", stones = "ayopd", return 0
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int jewelsAndStones(string jewels, string stones) {
  int counter = 0;
  unordered_map<char, int> mp;

  for (auto ch : jewels) {
    mp[ch]++;
  }

  for (int i = 0; i < stones.length(); i++) {
    if (mp.find(stones[i]) != mp.end()) {
      counter++;
    }
  }
  return counter;
}

int main() {
  // string jewels = "abc";
  // string stones = "ac";

  // string jewels = "Af";
  // string stones = "AaaddfFf";

  string jewels = "AYOPD";
  string stones = "ayopd";

  cout << jewelsAndStones(jewels, stones) << endl;

  return 0;
}