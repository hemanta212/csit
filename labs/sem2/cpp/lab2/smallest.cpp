// wap that reads two numbers. Calculate the smallest one and then print the smallest one defining functions outside the class.
#include <iostream>
using namespace std;

class Numbers{
	float a,b;
	
public:
	float smaller();
	void display();
	void read();
};

void Numbers::read(){
	cout << "Enter two numbers " << endl;
	cin >> a >> b;
}

float Numbers::smaller(){
	if(a<b)
		return a;
	return b;
}

void Numbers::display(){
	cout << "the smallest among " << a << " and " << b << " is: " << smaller() << endl;
}


int main(){
	Numbers n;
	n.read();
	n.display();
}
