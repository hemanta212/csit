#include <iostream>
using namespace std;

class integers{
	int a, b;
public:
	integers(){
		cout << "Enter two integers" << endl;
		cin >> a >> b;
	}
	void display(){
		cout << "you entered: " << a << " and " << b << endl;
	}
};

int main(){
	integers i;
	i.display();
}
