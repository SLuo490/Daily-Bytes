/*
This question is asked by Microsoft. Design a class, MovingAverage, which contains a method, next that is responsible for returning the moving average from a stream of integers.
Note: a moving average is the average of a subset of data at a given point in time.

Ex: Given the following series of events...

// i.e. the moving average has a capacity of 3.
MovingAverage movingAverage = new MovingAverage(3);
m.next(3) returns 3 because (3 / 1) = 3
m.next(5) returns 4 because (3 + 5) / 2 = 4 
m.next(7) = returns 5 because (3 + 5 + 7) / 3 = 5
m.next(6) = returns 6 because (5 + 7 + 6) / 3 = 6
*/

#include <queue>
#include <iostream>

using namespace std; 

class MovingAverage {
public:
    MovingAverage(int size) {
        this -> size = size; 
    }
    
    double next(int val) {
        sum += val; 
        q.push(val); 
        
        // if q size is greater than size then slide window
        if (q.size() > size) {
            sum -= q.front(); 
            q.pop(); 
        }
        
        return sum / q.size(); 
    }
private: 
    queue<int> q; 
    int size = 0;
    double sum = 0; 
};

int main() {
  return 0; 
}