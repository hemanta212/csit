// Calclulate the simple interest of following staff of bank
#include <iostream>

using namespace std;


class Interest{
private:
  int interest;
  static const int def_rate = 4;

public:
int calculate_interest(int principle, int time, int rate=def_rate){
  interest = principle * time * rate / 100;
  return interest;
}

};

int main(){
  Interest i;

  cout << "CEO gets ";
  cout << i.calculate_interest(1000000, 4, 6);
  cout << " interest" << endl;

  cout << "Accountant gets ";
  cout << i.calculate_interest(500000, 3);
  cout << " interest" << endl;

  cout << "Assistant Accountant gets ";
  cout << i.calculate_interest(500000, 5);
  cout << " interest" << endl;

  cout << "Helper gets ";
  cout << i.calculate_interest(200000, 10, 5);
  cout << " interest" << endl;

  return 0;
}

