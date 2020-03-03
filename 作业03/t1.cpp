class MouseV1 {
public:
	virtual void Walk(int steps) = 0;
	virtual void AddMoney(int m) = 0;
protected:
	MouseV1() {}
};

class MouseV1Impl : public MouseV1 {
public:
	virtual void Walk(int steps)
		{ cout << "Implement for Walk() with Version 1." << endl; }
	virtual void AddMoney(int m)
		{ cout << "Implement for AddMoney() with Version 1." << endl; }
private:
	int posX, posY;
};

class MouseV2 : public MouseV1 {
public:
	virtual void Drive(int steps) = 0;
	virtual void Fly(int steps) = 0;
protected:
	MouseV2() {}
};

class MouseV2Impl : public MouseV2 {
public:
	virtual void Drive(int steps)
		{ cout << "Implement for Drive() with Version 2." << endl; }
	virtual void Fly(int steps)
		{ cout << "Implement for Fly() with Version 2." << endl; }
	virtual void Walk(int steps)
		{ v1->Walk(steps); cout << "Implement for Walk() with Version 2." << endl; }
	virtual void AddMoney(int m)
		{ v1->AddMoney(m); }
	MouseV2Impl(MouseV1Impl *oldVersion) { v1 = oldVersion; }
private:
	int posZ;
	MouseV1Impl *v1;
};

class MouseFactory {
public:
	static MouseV1 *CreateV1Impl() { return new MouseV1Impl(); } //可选当前需要V1的地方是继续使用老版本还是新版本
	static MouseV2 *CreateV2Impl() { return new MouseV2Impl(); }
	static MouseV1 *CreateV1Default() { return CreateV2Impl(); } //可选当前需要V1的地方是继续使用老版本还是新版本
	static MouseV2 *CreateV2Default() { return CreateV2Impl(); }
	static MouseV1 *CreateDefault() { return CreateV1Default(); }
};

/*
 * 变化a: 在MouseV2类中实现新的函数接口
 * 变化b: 在MouseV2Impl中的Walk中修改具体实现
 * 变化c: 在MouseV2Impl中具体操作posZ
 * 变化d: 新建MouseV3, MouseV3Impl等，
 * 		在MouseFactory中添加具体构造函数，
 * 		这样旧版本代码不用改变太多也可以用上新版本的特性。
*/
