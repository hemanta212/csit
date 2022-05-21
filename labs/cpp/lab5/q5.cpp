// WAP to compare the age of three persons and display the information of elder
// one. Use "this" pointer to return the information of the person

#include <iostream>
using namespace std;

class person {
  const char *name;

public:
  person(const char *name_) : name(name_) {}
  virtual void after_death() = 0;
  const char *get_name() { return name; }
};

class SuperHero : public person {
public:
  SuperHero(const char *name_) : person(name_) {}
  void after_death() { cout << "Game Over. You died." << endl; }
};

class Villain : public person {
public:
  Villain(const char *name_) : person(name_) {}
  void after_death() { cout << "Game Over. You win." << endl; }
};

void kill(person *p) {
  cout << "Killed " << p->get_name() << endl;
  p->after_death();
}

int main() {
  SuperHero s("H");
  Villain v("V");
  person *p;
  p = &s;
  kill(p);
  p = &v;
  kill(p);
  return 0;
}
