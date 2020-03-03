#pragma once
#include "ifoo.h"

class Foo : public IFoo
{
public:
	virtual ~Foo();
	virtual int process();
};

class FooA : public Foo
{
public:
	virtual ~FooA();
	virtual int process();
};

class FooB : public Foo
{
public:
	virtual ~FooB();
	virtual int process();
};
