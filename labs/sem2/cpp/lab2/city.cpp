// create a new class named city that will have two member variables cityname(char[20]) and distfromktm(float).
// add member functions to set and retrive the cityname and distfromktm separetely.
// add new member functions adddistance that takes two args of class city and returns the sum of
// distfromktm of two arguments. in main func, initialize 3 city objects. set the first and second city to be
// pokhara and dhangadi. display the sum of disfromktm of pokhara and dhangadi calling adddistance func of third city.
// use objects as function args.
#include <iostream>
using namespace std;

class city{
	const char *cityname;
	float distfromktm;
public:
	city(){}
	city(const char *name, float f){
		cityname = name;
		distfromktm = f;
	}
	void set_cityname(const char *name){
		cityname = name;
	}
	void set_distfromktm(float f){
		distfromktm = f;
	}
	const char * get_cityname(){
		return cityname;
	}
	float get_distfromktm(){
		return distfromktm;
	}
	float add_distance(city &c1, city &c2);
	void show_dist(city &c1, city &c2);
};
float  city::add_distance(city &c1, city &c2){
	return c1.get_distfromktm() + c2.get_distfromktm();
}

void city::show_dist(city &c1, city &c2){
	cout << "The combined distance from ktm of " << c1.get_cityname() << " and " << c2.get_cityname() << " is: " << add_distance(c1, c2) << endl ;
}

int main(){
	city c1("kathmandu", 0), c2("nuwakot", 40.5), c3("kavre", 59.98);
	c1.show_dist(c2, c3);
}
