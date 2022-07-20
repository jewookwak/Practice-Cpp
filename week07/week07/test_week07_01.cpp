#include <iostream>

using namespace std;

class Image {
public:
	Image();
	Image(int width, int height);
	~Image();

	void save_BMP(const char* filename) const;
	void read_BMP(const char* filename);

	void save_JPEG(const char* filename) const;
	void readJPEG(const char* filename);

	void setColor(int i, int j, unsigned char red, unsigned char green, unsigned blue);
private:
	unsigned char* data;
	int width;
	int height;

};

int main() {
	return 0;
}