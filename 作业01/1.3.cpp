// 将参数抽象为类
struct ParameterForDo1V1 {
	A &aA; int Version;
	ParameterForDo1V1(A &a) : aA(a) { Version = 1; }
};

// 第一个版本的Foo
class FooV1 {
public:
	Foo(int v1, int v2) : mVal1(v1), mVal2(v2) {}
	virtual void do1(ParameterForDo1V1 &param) { mVal1 = 100; mVal2 = 200; param.aA.function(); ... }
	void do2(B &aB) {}
private:
	int mVal1, mVal2;
};

// 修改参数的时候
struct ParameterForDo1V2 : public ParameterForDo1V1 {
	int n, k;
	ParameterForDo1V1(A &a, int nn, int kk) : ParameterForDo1V1(a, nn, kk) { Version = 2; }
};

// 修改的函数实现可以保证向前兼容
class FooV2 : public FooV1 {
public:
	Foo(int v1, int v2) : FooV1(v1, v2) {}
	virtual void do1(ParameterForDo1V1 &param) { FooV1::do1(param); if (param.Version == 2) { ... } }
};
