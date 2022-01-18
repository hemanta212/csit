// Wap to find area of Rectangle using Cpp class and argument passing
#include <iostream>

using namespace std;

class Rectangle
{
    private:
	int length;
	int breadth;
    public:
	Rectangle(int l, int b)
	{
	    length = l;
	    breadth = b;
	}
	int area(int len , int wide){
	    return len * wide;
	}
	int area()
	{
	    return area(length, breadth);
	}

};

int main()
{
    int l1, b1, l2, b2;
    cout << "Enter length and breadth of first rectangle: ";
    cin >> l1 >> b1;

    cout << "Enter length and breadth of second rectangle: ";
    cin >> l2 >> b2;

    Rectangle r(l1, b1);
    int area = r.area();
    int area2 = r.area(l2, b2);
    cout << "Area of Rectangle is " << area << endl;
    cout << "Area of Rectangle2 is " << area2 << endl;
    return 0;
}

