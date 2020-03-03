#pragma once
#define FOOAPI __declspec(dllexport)

class FOOAPI Foo
{
public:
	virtual ~Foo();
	virtual int process();
};

class FOOAPI FooA : public Foo
{
public:
	virtual ~FooA();
	virtual int process();
};

class FOOAPI FooB : public Foo
{
public:
	virtual ~FooB();
	virtual int process();
};
