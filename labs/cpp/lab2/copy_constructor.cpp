#include <iostream>
using namespace std;

class cls{
	int a;
public:
	cls(cls &obj){
		a = obj.get_int();
	}
	cls(){}
	cls(int b){
		a = b;
	}
	int get_int(){
		return a ;
	}
};

int main(){
	cls a(5),b;
	b = a;
}
