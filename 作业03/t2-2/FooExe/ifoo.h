#pragma once
#include <memory>
#define FOOAPI __declspec(dllexport)

class FOOAPI IFoo
{
public:
	virtual ~IFoo();
	virtual int process();
protected:
	IFoo();
};

std::shared_ptr<IFoo> FOOAPI createFooA();
std::shared_ptr<IFoo> FOOAPI createFooB();
