#include <iostream>







enum TrafficLight{
  RED, YELLOW, GREEN,
};

enum Grade : unsigned int{
  A_PLUS=90, A=80, B_PLUS=70, B=60,
};

int main(){
  int currentLight = RED;
  if (currentLight < 2){
    std::cout << "STOP" << std::endl;
  }
  Grade level = A_PLUS;
  if (level > A){
    std::cout << "You are an A Plus level student" << std::endl;
  }
  return 0;
}
