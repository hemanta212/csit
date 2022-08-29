// wap to demonstrate the constructor and destructor
#include  <iostream>

class Test
{
public:
	int id;
	Test(int no)
	{
		id = no;
		std::cout << "Constructor called " << id << std::endl;
	}
	~Test()
	{
		std::cout << "Destructor called " << id << std::endl;
	}
};

int main()
{
	Test t(1), t2(2), t3(3);
	return 0;
}
