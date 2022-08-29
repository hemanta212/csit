#include <iostream>






class Test{
  public:
    Test(){std::cout << "Constructor called." << std::endl;}
    ~Test(){std::cout << "Destructor called." << std::endl;}
};

int scopedFunc(){
  std::cout << "<Func>" << std::endl;
  Test t = Test();
  std::cout << "</Func>" << std::endl;
  return 0;
}

int main(){
  std::cout << "<Main>" << std::endl;
  scopedFunc();
  std::cout << "</Main>" << std::endl;
}
