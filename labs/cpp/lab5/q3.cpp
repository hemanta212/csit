// Rewrite Q2 by defining at least constructor in each class.

#include <iostream>
using namespace std;

class student {
protected:
  int roll_number;

public:
  student(int roll) : roll_number(roll) {}
  void get_number(int a) { roll_number = a; }
  void put_number(void) { cout << "Roll No:" << roll_number << "\n"; }
};

class test : virtual public student {
protected:
  float part1, part2;

public:
  test(float one, float two) : student(one) {
    part1 = one;
    part2 = two;
  }
  void get_marks(float x, float y) {
    part1 = x;
    part2 = y;
  }
  void put_marks(void) {
    cout << "Marks obtained:"
         << "\n"
         << "part1 = " << part1 << "\n"
         << "part2 =" << part2 << "\n";
  }
};

class sports : public virtual student {
protected:
  float score;

public:
  sports(int roll, float score_) : student(roll * 2), score(score_) {}
  void get_score(float s) { score = s; }
  void put_score(void) { cout << "sports wt:" << score << "\n"; }
};

class result : public test, public sports {
  float total;

public:
  result(int roll, float total_)
      : student(roll), test(roll, total_), sports(roll, total_ / 2),
        total(total_) {}
  void display(void);
};
void result::display(void) {
  total = part1 + part2 + score;
  put_number();
  put_marks();
  put_score();
  cout << "\n Total score:" << total << "\n";
}
int main() {
  result res(1, 100.0);
  res.display();
}

/*
# NOtes

- Constructor of base class needs to be called using the : class(arg) {}
notation
- Constructor of base class need not to be called if it takes not arguments.
- If the base class has a contructor that takes one/more args, we must call that
constructor in derived class.
- Order of execution: base class constructor gets called then derived contructor
- if two base class are present, their constructor will be called in order they
were specified in declaration of derived class
- Similarly, if there is a virtual base class, they will be called first. So
order is
  - Virtual base class constructor
  - Ordinary base class contructor
  - derived base class constructor
- In diamond pattern, the last derived class gets to call all three parents,
ie in this case 'result' must call 'sports', 'test' and even 'student' base
clases itself.
- The constructor calls for 'student' in 'sports' and 'test' will be ignored.
  Remeber only the last derived class gets to call all its direct and indirect
parent base class.

LUCKILY, IN REAL WORLD IF YOU FIND YOURSELF USING DIAMOND PATTERN, THINK 10
TIMES, ITS BAD CODE/DESIGN. USE COMPOSITION INSTEAD OF INHERITANCE.
 */
