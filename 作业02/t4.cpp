#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <functional>
int max(int a, int b) { return a < b ? b : a; }

/////////////////////////////////////////////////////////////////////////

class PicImpl {
public:
	virtual PicImpl* clone() const { return NULL; }
	const int cols, rows;
	virtual void drawToBuffer(char **buf, int x, int y) const {}
	virtual void swap() {}
protected:
	PicImpl(int r, int c) : cols(c), rows(r) {}
};

class Pic {
private:
	static std::map<PicImpl*,int> countRef;
protected:
	PicImpl *src;
public:
	Pic(PicImpl *impl) : src(impl) { countRef[src]++; }
	Pic(const Pic &pic) : src(pic.src) { countRef[src]++; }
	~Pic() { if ((--countRef[src]) == 0) { countRef.erase(src); delete src; } }
	
	void display(std::function<char(char)> transform) const
	{
		char **buf = new char*[getRow()];
		for (int i = 0; i < getRow(); i++)
		{
			buf[i] = new char[getCol()+1];
			for (int j = 0; j < getCol(); j++)
				buf[i][j] = ' ';
			buf[i][getCol()] = '\0';
		}
		drawToBuffer(buf, 0, 0);
		for (int i = 0; i < getRow(); i++)
		{
			for (int j = 0; j < getCol(); j++)
				putchar(transform(buf[i][j]));
			putchar('\n');
			delete[] buf[i];
		}
		delete[] buf;
	}
	
	void display() const { display([] (char t) -> char { return t; }); }
	virtual void drawToBuffer(char **buf, int x, int y) const { src->drawToBuffer(buf, x, y); }
	int getRow() const { return src->rows; }
	int getCol() const { return src->cols; }
	Pic clone() const { return src->clone(); }
	void swap() { src->swap(); }
}; // 桥接模式用的类，使用了引用计数

std::map<PicImpl*,int> Pic::countRef;

class SimplePic : public PicImpl {
public:
	const char ch;
	SimplePic(int r, int c, char _ch) : PicImpl(r, c), ch(_ch) {}
	virtual PicImpl* clone() const { return new SimplePic(rows, cols, ch); }
protected:
	virtual void drawToBuffer(char **buf, int x, int y) const {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				buf[x+i][y+j] = ch; }
};

class FramePic : public PicImpl {
public:
	const Pic inn; const char border;
	FramePic(Pic inner, char bor = '*') : PicImpl(inner.getRow()+2, inner.getCol()+2), inn(inner), border(bor) {}
	virtual PicImpl* clone() const { return new FramePic(inn); }

	virtual void drawToBuffer(char **buf, int x, int y) const {
		inn.drawToBuffer(buf, x+1, y+1);
		for (int i = 0; i < rows; i++)
			buf[x+i][y] = buf[x+i][y+cols-1] = border;
		for (int i = 0; i < cols; i++)
			buf[x][y+i] = buf[x+rows-1][y+i] = border; }
};

class VCatPic : public PicImpl {
public:
	Pic top, bottom;
	VCatPic(Pic t, Pic b) : PicImpl(t.getRow()+b.getRow(), max(t.getCol(),b.getCol())), top(t), bottom(b) {}
	virtual PicImpl* clone() const { return new VCatPic(top, bottom); }
	virtual void swap() { std::swap(top, bottom); }

	virtual void drawToBuffer(char **buf, int x, int y) const {
		top.drawToBuffer(buf, x, y);
		bottom.drawToBuffer(buf, x+top.getRow(), y); }
};

class HCatPic : public PicImpl {
public:
	Pic left, right;
	HCatPic(Pic t, Pic b) : PicImpl(max(t.getRow(), b.getRow()), t.getCol()+b.getCol()), left(t), right(b) {}
	virtual PicImpl* clone() const { return new HCatPic(left, right); }
	virtual void swap() { std::swap(left, right); }

	virtual void drawToBuffer(char **buf, int x, int y) const {
		left.drawToBuffer(buf, x, y);
		right.drawToBuffer(buf, x, y+left.getCol()); }
};

/////////////////////////////////////////////////////////////

// 增加对角线连接的字符图像

class XCatPic : public PicImpl {
public:
	Pic left, right;
	XCatPic(Pic t, Pic b) : PicImpl(t.getRow()+b.getRow(), t.getCol()+b.getCol()), left(t), right(b) {}
	virtual PicImpl* clone() const { return new XCatPic(left, right); }
	virtual void swap() { std::swap(left, right); }

	virtual void drawToBuffer(char **buf, int x, int y) const {
		left.drawToBuffer(buf, x, y);
		right.drawToBuffer(buf, x+left.getRow(), y+left.getCol()); }
};

//////////////////////////////////////////////////////////////

// 变更FamePic中外框的字符（如变更为$号）
// 传入构造函数参数

// 显示时，可通过指定图像间隔(空白字符个数)显示字符图像
// 看不懂啥意思。。。。。。。。

// 增加以加密的形式显示字符图像功能，如将字符图像中的A显示成Z，Z显示成Y
// 已在Pic里修改

////////////////////////////////////////////////////////////////

int main()
{
	Pic a = new SimplePic(5,10,'a');
	Pic b = new SimplePic(10,5,'b');
	Pic c = new HCatPic(a,b);
	Pic d = new FramePic(c);
	Pic e = new VCatPic(d,a);
	Pic f = new FramePic(e);
	f.display([] (char t) -> char { if (t > 'z' || t < 'a') return t; return (t-'a'+346)%26+'A'; });
	e.swap();
	Pic g = new FramePic(e);
	g.display();
	return 0;
}
