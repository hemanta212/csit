#include <iostream>
using namespace std;

inline float twice(float i){
	return i*i;
}

int main(){
	float j=3;
	cout << "twice(float) = " << twice(j) << endl;
	return 0;
}
