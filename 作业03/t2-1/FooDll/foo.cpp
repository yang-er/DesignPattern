#include "pch.h"
#include "foo.h"

Foo::~Foo() {}
FooA::~FooA() {}
FooB::~FooB() {}

int Foo::process() { return 0; }
int FooA::process() { return 1; }
int FooB::process() { return 2; }
