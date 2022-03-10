#include <iostream>
using namespace std;

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

int main(){
	int m=10, n=20;
	cout << "before swap: n = " << n << " m = " << m << endl;
	swap1(m,n);
	cout << "after swap: n = " << n << " m = " << m << endl;
	return 0;
}
