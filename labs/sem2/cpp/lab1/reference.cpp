#include <iostream>
using namespace std;

int main(){
	int m = 5;
	int &n = m;
	
	cout << " m " << m << " n " << n << endl ;
	(n)++;
	cout << " m " << m << " n " << n << endl ;
	return 0;
}
