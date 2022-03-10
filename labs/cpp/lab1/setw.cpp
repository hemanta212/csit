#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int sum = 12345;
	cout << "setw(0)=" << endl << setw(0) << sum << endl;
	cout << "setw(20)=" << endl << setw(20) << sum << endl;
	cout << "setw(12)=" << endl << setw(12) << sum << endl;
	cout << "setw(5)=" << endl << setw(5) << sum << endl;
	cout << "setw(2)=" << endl << setw(2) << sum << endl;
	cout << "setw(1)=" << endl << setw(1) << sum << endl;
	return 0;
}
