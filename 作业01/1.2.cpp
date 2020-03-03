// 将对三个数据的处理分离成为接口
class IProcessor {
public:
	void Process(int &temp, int &mVal1, int &mVal2) {}
protected:
	IProcessor() {}
};

// 原来的类
class Foo {
public:
	Foo(int v1, int v2, IProcessor *p1) : mVal1(v1), mVal2(v2), proc(p1) {}
	void do1() { mVal1 = 100; mVal2 = 200; }
	void do2() {
		// 语句块1
		// 处理结果赋值给临时变量temp
		
		// 调用抽象处理过程类
		proc->Process(temp, mVal1, mVal2);
	}
private:
	int mVal1, mVal2;
	IProcessor *proc;
};

// 然后实现各个版本的 ProcessorV1, ProcessorV2 即可，通过工厂方法/依赖注入容器等来调节使用的处理实现。
