#include <iostream>
#include "ifoo.h"
#pragma comment(lib, "..\\Debug\\FooDll.lib")

class User {
public:
	User(std::shared_ptr<IFoo> foo) { impl = foo; }
	int myProcess() { return impl->process(); }
private:
	std::shared_ptr<IFoo> impl;
};

int main()
{
	User qwq(createFooA()), qaq(createFooB());
	std::cout << "Hello World!" << std::endl;
	std::cout << qwq.myProcess() << std::endl;
	std::cout << qaq.myProcess() << std::endl;
	return 0;
}
