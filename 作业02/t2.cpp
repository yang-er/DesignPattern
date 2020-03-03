#include <cstdio>
#include <cstring>
int max(int a, int b) { return a < b ? b : a; }

class CharPic
{
public:
	CharPic(const CharPic& rhs) : CharPic(rhs.rows, rhs.cols, ' ') // 拷贝构造函数
	{
		for (int i = 0; i < rhs.rows; i++)
			for (int j = 0; j < rhs.cols; j++)
				data[i][j] = rhs.data[i][j];
	}

	static CharPic AddBorder(const CharPic &a) // 添加边框
	{
		CharPic ret(a.rows+2, a.cols+2, '*');
		for (int i = 0; i < a.rows; i++)
			for (int j = 0; j < a.cols; j++)
				ret.data[i+1][j+1] = a.data[i][j];
		return ret;
	}

	static CharPic VerticalConcat(const CharPic &a, const CharPic &b) // 垂直拼接
	{
		CharPic ret(a.rows+b.rows, max(a.cols, b.cols), ' ');
		for (int i = 0; i < a.rows; i++)
			for (int j = 0; j < a.cols; j++)
				ret.data[i][j] = a.data[i][j];
		for (int i = 0; i < b.rows; i++)
			for (int j = 0; j < b.cols; j++)
				ret.data[i+a.rows][j] = b.data[i][j];
		return ret;
	}

	static CharPic HorizontalConcat(const CharPic &a, const CharPic &b) // 水平拼接
	{
		CharPic ret(max(a.rows, b.rows), a.cols + b.cols, ' ');
		for (int i = 0; i < a.rows; i++)
			for (int j = 0; j < a.cols; j++)
				ret.data[i][j] = a.data[i][j];
		for (int i = 0; i < b.rows; i++)
			for (int j = 0; j < b.cols; j++)
				ret.data[i][j+a.cols] = b.data[i][j];
		return ret;
	}

	static CharPic CreateAutoFilled(int rs, int cs, char def)
	{
		return CharPic(rs, cs, def);
	}
	
	void display() const
	{
		for (int i = 0; i < rows; i++, putchar('\n'))
			for (int j = 0; j < cols; j++)
				putchar(data[i][j]);
	}

	~CharPic()
	{
		for (int i = 0; i < rows; i++)
			delete[] data[i];
		delete[] data;
	}

private:
	CharPic(int rs, int cs, char def) : rows(rs), cols(cs)
	{
		data = new char*[rs];
		for (int i = 0; i < rs; i++)
		{
			data[i] = new char[cs];
			memset(data[i], def, sizeof(char) * cs);
		}
	}

	const int rows, cols;
	char **data;
};

int main()
{
	CharPic a = CharPic::CreateAutoFilled(7,10,'a');
	CharPic b = CharPic::CreateAutoFilled(10,7,'b');
	a.display(); puts(""); b.display(); puts("");
	CharPic::AddBorder(a).display(); puts("");
	CharPic::VerticalConcat(a,b).display(); puts("");
	CharPic::HorizontalConcat(b,a).display(); puts("");
	return 0;
}
