#include <iostream>
#include "foo.h"
#pragma comment(lib, "..\\Debug\\FooDll.lib")

class UserA {
public:
	UserA(Foo* foo) { impl = foo; }
	~UserA() { delete impl; }
	int myProcess() { return impl->process(); }
private:
	Foo* impl;
};

class UserB : FooB {
public:
	int myProcess() { return process(); }
};

int main()
{
	UserA qwq(new FooA);
	UserB qaq;
	std::cout << "Hello World!" << std::endl;
	std::cout << qwq.myProcess() << std::endl;
	std::cout << qaq.myProcess() << std::endl;
	return 0;
}
