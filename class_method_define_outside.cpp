#include <iostream>

class Addition{
private:
  int a, b, sum;
public:
  void get(int x, int y);
  void process();
  void print();
};

void Addition::get(int x, int y){
  a = x;
  b = y;
}

void Addition::process(){
  sum = a+b;
}

void Addition::print(){
  std::cout << "Sum of the " << a << " and " << b << " is " << sum << std::endl;
}

int main(){
  Addition A;
  A.get(10, 20);
  A.process();
  A.print();
  return 0;
  }
