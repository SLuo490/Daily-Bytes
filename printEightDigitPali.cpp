#include <iostream>
#include <vector>

using namespace std; 

void printAllEightDigitPali() {
  for (int i = 1000; i <= 9999; i++) {
    int reverse = 0, num = i, palindrome = 0; 

    // this will reverse the num i 
    while (num != 0) {
      reverse = (reverse * 10) + num % 10; 
      num /= 10; 
    }

    // combine originalNum and reverse
    palindrome = i * 10000 + reverse;
    cout << palindrome << endl;
  }  
}

int main() {
  printAllEightDigitPali();
  return 0; 
}