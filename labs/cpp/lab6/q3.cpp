// Write a program to swap two numbers using function template
#include <iostream>
using namespace std;

template <class T1> void swap_func(T1 &a, T1 &b) {
  T1 temp = a;
  a = b;
  b = temp;
}

int main() {
  int a = 5, b = 10;
  swap_func(a, b);
  cout << "a: " << a << "\nb: " << b << endl;

  float x = 5.5, y = 10.9;
  swap_func(x, y);
  cout << "x: " << x << "\ny: " << y << endl;
  return 0;
}
