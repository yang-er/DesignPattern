class Singleton {

public:
	void FooBar() {}

private:
	static Singleton *instance;
	static std::mutex locker;

public:
	static Singleton *getInstance() {
		if (instance == nullptr) {
			locker.lock();
			if (instance == nullptr)
				instance = new Singleton;
			locker.unlock();
		}
		return instance;
	}
};