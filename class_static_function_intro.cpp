#include <iostream>






  class Test{
    public:
    static int y;
    static int x;

    public:
    static void print_x_y(){
      std::cout << x << ", " << y <<std::endl;
      }
    };

  int Test::x;
  int Test::y;

  int main(){
    Test::x = 10;
    Test::y = 10;

    Test t = Test();
    t.print_x_y();
    Test::print_x_y();

    t.x = 100;
    t.y = 200;

    t.print_x_y();
    Test::print_x_y();
}
