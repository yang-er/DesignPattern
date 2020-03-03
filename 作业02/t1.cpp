#include <cstdio>
int max(int a, int b) { return a < b ? b : a; }

class CharPic
{
public:
	CharPic(int type, // 1-普通字符图像  2-加框的字符图像
			int rs, int cs, char** arrayChars)
				: rows(type==1?rs:rs+2), cols(type==1?cs:cs+2)
	{
		data = new char*[rows];
		for (int i = 0; i < rows; i++)
			data[i] = new char[cols];

		if (type == 1)
		{
			for (int i = 0; i < rs; i++)
				for (int j = 0; j < cs; j++)
					data[i][j] = arrayChars[i][j];
		}
		else
		{
			for (int i = 0; i < rs; i++)
				for (int j = 0; j < cs; j++)
					data[i+1][j+1] = arrayChars[i][j];
			for (int i = 0; i <= rs+1; i++)
				data[i][0] = data[i][cols-1] = '*';
			for (int i = 0; i <= cs+1; i++)
				data[0][i] = data[rows-1][i] = '*';
		}
	}

	CharPic(int type, // 3-水平连接的字符图像  4-垂直连接的字符图像
			int rs1, int cs1, char** arrayChars1,
			int rs2, int cs2, char** arrayChars2)
				: rows(type==3?max(rs1,rs2):rs1+rs2), cols(type==3?cs1+cs2:max(cs1,cs2))
	{
		data = new char*[rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new char[cols];
			for (int j = 0; j < cols; j++)
				data[i][j] = ' ';
		}
		
		for (int i = 0; i < rs1; i++)
			for (int j = 0; j < cs1; j++)
				data[i][j] = arrayChars1[i][j];
		for (int i = 0, di = type==3?0:rs1; i < rs2; i++)
			for (int j = 0, dj = type==3?cs1:0; j < cs2; j++)
				data[i+di][j+dj] = arrayChars2[i][j];
	}

	CharPic(int type, // 2-加框的字符图像
			const CharPic& aCenter)
				: CharPic(type, aCenter.rows, aCenter.cols, aCenter.data) {}
	CharPic(int type, // 3-水平连接的字符图像  4-垂直连接的字符图像
			const CharPic& aLeftOrTop,
			int rs2, int cs2, char** arrayChars2)
				: CharPic(type, aLeftOrTop.rows, aLeftOrTop.cols, aLeftOrTop.data, rs2, cs2, arrayChars2) {}
	CharPic(int type, // 3-水平连接的字符图像  4-垂直连接的字符图像
			int rs1, int cs1, char** arrayChars1,
			const CharPic& aRightOrBottom)
				: CharPic(type, rs1, cs1, arrayChars1, aRightOrBottom.rows, aRightOrBottom.cols, aRightOrBottom.data) {}
	CharPic(int type, // 3-水平连接的字符图像  4-垂直连接的字符图像
			const CharPic& aLeftOrTop,
			const CharPic& aRightOrBottom)
				: CharPic(type, aLeftOrTop.rows, aLeftOrTop.cols, aLeftOrTop.data, aRightOrBottom.rows, aRightOrBottom.cols, aRightOrBottom.data) {}
	CharPic(const CharPic& rhs)
				: CharPic(1, rhs.rows, rhs.cols, rhs.data) {} // 拷贝构造函数

	// CharPic& operator=(const CharPic& rhs) // 赋值函数没什么用，拷贝构造函数够了

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
	const int rows, cols;
	char **data;
};

int main()
{
	char **aa = new char*[9];
	for (int i = 0; i < 9; i++)
	{	
		aa[i] = new char[8];
		for (int j = 0; j < 8; j++)
			aa[i][j] = 'a';
	}
	
	char **bb = new char*[8];
	for (int i = 0; i < 8; i++)
	{	
		bb[i] = new char[9];
		for (int j = 0; j < 9; j++)
			bb[i][j] = 'b';
	}
	
	CharPic a(1,9,8,aa), b(1,8,9,bb);
	for (int i = 0; i < 9; i++)
		delete[] aa[i];
	for (int i = 0; i < 8; i++)
		delete[] bb[i];
	delete[] aa; delete[] bb;
	a.display();
	puts("");
	b.display();
	puts("");
	CharPic(2,a).display();
	puts("");
	CharPic(3,a,b).display();
	puts("");
	CharPic(4,b,a).display();
	return 0;
}
