#include "pch.h"
#include "ifoo.h"
#include "foo.h"

IFoo::IFoo() {}
IFoo::~IFoo() {}
int IFoo::process() { return -1; }

std::shared_ptr<IFoo> createFooA() { return std::shared_ptr<IFoo>(new FooA); }
std::shared_ptr<IFoo> createFooB() { return std::shared_ptr<IFoo>(new FooB); }
