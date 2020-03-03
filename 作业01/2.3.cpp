// C#不支持多重继承，预览版能开接口默认实现但是还是用C++写吧。。

class Place {
	
};

template<typename T>
class _SINGLETON_BASE {
private:
	static T* ptr;
public:
	static T* getInstance() {
		if (ptr == nullptr)
			ptr = new T;
		return ptr;
	}
};

class ScienceLibrary : public Place, public _SINGLETON_BASE<ScienceLibrary> {
private:
	friend class _SINGLETON_BASE<ScienceLibrary>;
	ScienceLibrary() { ... }
public:
};