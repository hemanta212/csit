// wap to calculate for a given mass. ; g=9.8 as default argument.

#include <iostream>

using namespace std;

float weight(float mass, float g=9.8){
	return mass*g;
}

int main(){
	cout << "Enter the mass: " ;
	float mass;
	cin >> mass;
	cout << "The weight is: " << weight(mass) << endl;
	return 0;
}
