#include <iostream>
using namespace std;

class addition{
	float a, b, result;
public:
	addition(){}
	addition(float x, float y){
		a = x;
		b = y;
	}
	void process(){
		result = a+b;
	}
	void display(){
		cout << a << " + " << b << " = " << result << endl;
	}
};

int main(){
	float x=3,y=5;
	addition a(x,y);
	a.process();
	a.display();
	return 0;
}
