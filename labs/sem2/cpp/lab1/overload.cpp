#include <iostream>
using namespace std;
int twice(int i){
	return i*i;
}
float twice(float i){
	return i*i;
}
char twice(char i){
	return i*i;
}

int main(){
	int i=1;
	float j=2.0;
	char c=  'a';

	cout << "twice(int) = " << twice(i) << endl;
	cout << "twice(float) = " << twice(j) << endl;
	cout << "twice(char) = " << twice(c) << endl;

	return 0;
}
