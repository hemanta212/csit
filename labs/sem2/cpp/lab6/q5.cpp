// Write a program to show the basic concept of exception handling
#include <iostream>
using namespace std;

void exception_example() {
  try {
    cout << "Enter try block, throwing exception.." << endl;
    throw "Test exception.";
    cout << "Will not print" << endl;
  } catch (const char *e) {
    cout << "Exception catched here: " << e << endl;
  }
}

int main() {
  exception_example();
  return 0;
}
