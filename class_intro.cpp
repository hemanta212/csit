// Create a CPP program to do additon of two numbers.

#include <iostream>

using namespace std;

class Addition
{
    private:
	int sum;
	int x,y;

    public:
	int add()
	{
	    sum = x + y;
	    return sum;
	}
    public:
    	void display_sum()
	{
	    cout << "Sum of " << x << " and " << y << " is " << sum << endl;
	}
    public:
    	int get_input()
	{
	    cout << "Enter two numbers: ";
	    cin >> x >> y;
	    return 0;
	}
};

int main()
{
    Addition A, B;

    A.get_input();
    B.get_input();

    A.add();
    A.display_sum();

    B.add();
    B.display_sum();

    return 0;
}
