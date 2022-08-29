#include <iostream>






  class Person{
    private:
      int name, height;
    public:
      void walk(){
        std::cout << "Walking " << std::endl;
        }

      void write(){
        std::cout << "Writing " << std::endl;
     }
  };

 class Student : public Person{
   public:
     void attend_class(){
       std::cout << "Attending class" << std::endl;
     }
   };


 int main (){
    Student tim = Student();
    tim.walk(); // walk to college
    tim.attend_class(); // Attend the class
    tim.write(); // Take notes maybe
}
