
class IFoo {
public:
	virtual void do1(A &aA) {}
	virtual void do2(B &aB) {}
protected:
	int mVal1, mVal2;
	IFoo(int v1, int v2) : mVal1(v1), mVal2(v2) {}
};

class FooV1 : public IFoo {
public:
	Foo(int v1, int v2) : IFoo(v1, v2) {}
	virtual void do1(A &aA) { mVal1 = 100; mVal2 = 200; aA.function(); ... }
	virtual void do2(B &aB) { ... }
};
