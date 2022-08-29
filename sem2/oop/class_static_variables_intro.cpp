#include <iostream>






class Test{
  public:
  static int y;
  static int x;

  public:
  void print_x_y(){
    std::cout << x << ", " << y <<std::endl;
    }
  };

int Test::x;
int Test::y;

int main(){
  Test t = Test();
  t.x = 3;
  t.y = 4;
  t.print_x_y();

  Test t1 = Test();
  t1.x = 9;
  t1.y = 8;
  t.print_x_y();

  Test::x = 100;
  Test::y = 200;

  t.print_x_y();
  t1.print_x_y();
}
