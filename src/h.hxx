#include <string.h>

class H {
public:
	static int getRows();
	static int getCols();
	static string getDisabledRows();
private:
	static int rows;
	int cols;
	static string disabled;
}
