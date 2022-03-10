// wap to input name, address, faculty and roll no of a student and display it. use both member function defining inside the class and outside the class.
#include <iostream>
using namespace std;

class student{
	string name, address, faculty;
	int roll;
public:
	void get_info(){
		cout << "Enter the name: " << endl;
		cin >> name;
		cout << "Enter the address: " << endl;
		cin >> name;
		cout << "Enter the faculty: " << endl;
		cin >> faculty;
		cout << "Enter the roll no: " << endl;
		cin >> roll;
	}
	void display();
};

void student::display(){
	cout << "Student " << name << " with address " << address << " and of faculty " << faculty << " has roll no " << roll << endl;
}

int main(){
	student s;
	s.get_info();
	s.display();
}
