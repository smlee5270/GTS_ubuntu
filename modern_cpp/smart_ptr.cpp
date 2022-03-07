#include<iostream>
#include<memory>


class Cat
{
public:
	Cat(int age):mAge{age}
	{
		std::cout << "cat constructor" << std::endl;
	}
	~Cat()
	{
		std::cout << "cat destructor" << std::endl;
	}
private:
	int mAge;
};


int main()
{
	Cat* catPtr = new Cat{3};
	std::unique_ptr<Cat> catPtr = std::make_unique<Cat>(3);

	return 0;












