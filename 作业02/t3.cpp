#include <cstdio>
#include <cstring>
int max(int a, int b) { return a < b ? b : a; }

class Pic {
public:
	virtual Pic* clone() const { return NULL; }
	const int cols, rows;
	virtual void drawToBuffer(char **buf, int x, int y) {}
	
	void display()
	{
		char **buf = new char*[rows];
		for (int i = 0; i < rows; i++)
		{
			buf[i] = new char[cols+1];
			for (int j = 0; j < cols; j++)
				buf[i][j] = ' ';
			buf[i][cols] = '\0';
		}
		drawToBuffer(buf, 0, 0);
		for (int i = 0; i < rows; i++)
		{
			puts(buf[i]);
			delete[] buf[i];
		}
		delete[] buf;
	}
protected:
	Pic(int r, int c) : cols(c), rows(r) {}
};

class SimplePic : public Pic {
public:
	const char ch;
	SimplePic(int r, int c, char _ch) : Pic(r, c), ch(_ch) {}
	virtual Pic* clone() const { return new SimplePic(rows, cols, ch); }
protected:
	virtual void drawToBuffer(char **buf, int x, int y) {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				buf[x+i][y+j] = ch; }
};

class FramePic : public Pic {
public:
	Pic *const inn;
	FramePic(Pic *inner) : Pic(inner->rows+2, inner->cols+2), inn(inner) {}
	virtual Pic* clone() const { return new FramePic(inn); }

	virtual void drawToBuffer(char **buf, int x, int y) {
		inn->drawToBuffer(buf, x+1, y+1);
		for (int i = 0; i < rows; i++)
			buf[x+i][y] = buf[x+i][y+cols-1] = '*';
		for (int i = 0; i < cols; i++)
			buf[x][y+i] = buf[x+rows-1][y+i] = '*'; }
};

class VCatPic : public Pic {
public:
	Pic *const top, *const bottom;
	VCatPic(Pic *t, Pic *b) : Pic(t->rows+b->rows, max(t->cols,b->cols)), top(t), bottom(b) {}
	virtual Pic* clone() const { return new VCatPic(top, bottom); }

	virtual void drawToBuffer(char **buf, int x, int y) {
		top->drawToBuffer(buf, x, y);
		bottom->drawToBuffer(buf, x+top->rows, y); }
};

class HCatPic : public Pic {
public:
	Pic *const left, *const right;
	HCatPic(Pic *t, Pic *b) : Pic(max(t->rows, b->rows), t->cols+b->cols), left(t), right(b) {}
	virtual Pic* clone() const { return new HCatPic(left, right); }

	virtual void drawToBuffer(char **buf, int x, int y) {
		left->drawToBuffer(buf, x, y);
		right->drawToBuffer(buf, x, y+left->cols); }
};

int main()
{
	Pic *a = new SimplePic(5,10,'a');
	Pic *b = new SimplePic(10,5,'b');
	Pic *c = new HCatPic(a,b);
	Pic *d = new FramePic(c);
	Pic *e = new VCatPic(d,a);
	Pic *f = new FramePic(e);
	f->display();
	return 0;
}
