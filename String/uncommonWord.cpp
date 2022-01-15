/*
This question is asked by Amazon. Given two strings representing sentences, return the words that are not common to both strings (i.e. the words that only appear in one of the sentences). You may assume that each sentence is a sequence of words (without punctuation) correctly separated using space characters.

Ex: given the following strings...

sentence1 = "the quick", sentence2 = "brown fox", return ["the", "quick", "brown", "fox"]
sentence1 = "the tortoise beat the haire", sentence2 = "the tortoise lost to the haire", return ["beat", "to", "lost"]
sentence1 = "copper coffee pot", sentence2 = "hot coffee pot", return ["copper", "hot"]
*/

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> uncommonWord(string A, string B) {
  unordered_map<string, int> mp;
  istringstream iss(A + " " + B);
  while (iss >> A) mp[A]++;

  vector<string> res;
  for (auto it : mp) {
    if (it.second == 1) {
      res.push_back(it.first);
    }
  }
  return res;
}

void print(vector<string>& res) {
  for (auto word : res) {
    cout << word << endl;
  }
}

int main() {
  string sentence1 = "the quick", sentence2 = "brown fox";
  vector<string> res = uncommonWord(sentence1, sentence2);
  // print(res);

  string sentence3 = "the tortoise beat the haire", sentence4 = "the tortoise lost to the haire";
  vector<string> res2 = uncommonWord(sentence3, sentence4);
  // print(res2);

  string sentence5 = "copper coffee pot", sentence6 = "hot coffee pot";
  vector<string> res3 = uncommonWord(sentence5, sentence6);
  print(res3);

  return 0;
}