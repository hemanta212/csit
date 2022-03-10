#include <iostream>
using namespace std;
class set{
	int m,n;
public:
	void input(void);
	void display(void);
	int largest(void);
};

int set::largest(void){
	if(m >= n)
		return m;
	else
		return n;
}

void set::input(void){
	cout << "input value of m and n " << endl ;
	cin >> m >> n ;
}

void set::display(void){
	cout << "largest value: " << largest() << endl;
}

int main(){
	set s;
	s.input();
	s.display();
	return 0;
}
			
