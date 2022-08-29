// Calculate the weight of mass on earth and moon. The value of g in earth is 9.8 m/s^2 and the value of g in moon is 1.67  m/s^2.

#include <iostream>

using namespace std;

void print(double i){
	cout << "DOUBLE: " <<  i << endl;
}

void print(int i){
	cout << "INT: " <<  i << endl;
}

void print(char i){
	cout << "CHAR: "  << i << endl;
}



int main()
{
	print(1);
	print(9.8);
	print('a');
	return 0;
}
