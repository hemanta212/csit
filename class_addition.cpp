#include <iostream>

using namespace std;

class Addition {
private:
  int a, b, sum;

public:
  int add(int x, int y) {
    a = x;
    b = y;

    sum = a + b;
    return sum;
  }
  void print_sum() {
    cout << "sum of " << a << " and " << b << " is " << sum << endl;
  }
};

int main() {
  Addition A;
  int a, b;
  cout << "Get two numbers: ";
  cin >> a >> b;
  A.add(a, b);
  A.print_sum();
  return 0;
}
