// Wap to find the sum of two numbers by defining memeber function outside the
// class
#include <iostream>
using namespace std;

class sum {
private:
  int a, b, sum;

public:
  void getdata() {
    cout << "Enter the value of a and b:";
    cin >> a >> b;
  }
  void display() { cout << " The sum of a and b is: " << sum; }
  void process();
};

// Add process function to sum class
void sum::process() { sum = a + b; }

int main() {
  sum s;
  s.getdata();
  s.process();
  s.display();
  return 0;
}
