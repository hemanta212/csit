// wap declaring a class and object to input assignment marks and practical marks
// defining function setmark and publishmark. Define the function inside the class.
#include <iostream>

class marks{
	float amark, pmark;
public:
	void setmark(float f1, float f2){
		amark = f1;
		pmark = f2;
	}
	void publishmark(){
		std::cout << "The assignment marks is: " << amark << " and the practical mark is: " << pmark << std::endl ;
	}
};

int main(){
	marks m;
	m.setmark(5,9);
	m.publishmark();
	return 0;
}
