// 一个接口类
class IFoo {
public:
	virtual void do1() {}
	virtual void do2() {}
protected:
	IFoo() {}
};

// 第一个版本的Foo实现
class FooV1 : public IFoo {
public:
	FooV1(int v1, int v2) : mVal1(v1), mVal2(v2) {}
	virtual void do1() { mVal1 = 100; mVal2 = 200; }
	virtual void do2() { mVal2 = 200; mVal2 = 50; }
protected:
	int mVal1, mVal2;
};

// 如果改动代码对于FooV1相对较少，继承FooV1
class FooV2 : public FooV1 {
public:
	FooV2(int v1, int v2, int v3) : FooV1(v1, v2), mVal3(v3) {}
	virtual void do1() { FooV1::do1(); mVal3 = 233; }
	virtual void do2() { FooV1::do2(); mVal3 = 233; }
protected:
	int mVal3;
};

// 如果改动代码对于FooV1相对较多，实现接口IFoo
class FooV3 : public IFoo {
public:
	FooV3(int v1, int v2, int v3) : mVal1(v1), mVal2(v2), mVal3(v3) {}
	virtual void do1() { mVal1 = -1; mVal2 = -1; mVal3 = 233; }
	virtual void do2() { mVal1 = -1; mVal2 = -1; mVal3 = 233; }
protected:
	int mVal1, mVal2, mVal3;
};

// 在原来引用Foo的地方改为IFoo，在构造时选定使用的Foo实现版本。
