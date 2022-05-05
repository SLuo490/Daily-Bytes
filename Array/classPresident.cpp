#include <iostream> 
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std; 

/*
High school students are voting for their class president and you’re tasked with counting the votes. Each presidential candidates is represented by a unique integer and the candidate that should win the election is the candidate that has received more than half the votes. Given a list of integers, return the candidate that should become the class president.
Note: You may assume there is always a candidate that has received more than half the votes.

Ex: Given the following votes…

votes = [1, 1, 2, 2, 1], return 1.

Ex: Given the following votes…

votes = [1, 3, 2, 3, 1, 2, 3, 3, 3], return 3.
*/

int findClassPresident(vector<int>& votes) {
  unordered_map<int,int> mp; 
  for (auto num: votes) mp[num]++; 

  priority_queue<pair<int,int>> pq; 
  for (auto [a, b] : mp) {
    pq.push({b,a}); 
  }

  int res = pq.top().second; 
  return res; 
}


int main() {
  vector<int> votes = {1, 3, 2, 3, 1, 2, 3, 3, 3}; 
  int res = findClassPresident(votes); 
  cout << res << endl; 

  return 0; 
}