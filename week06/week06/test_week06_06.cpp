#include <iostream>
#include "test_week06_06.Box_3D.h"
#include "test_week06_06Box_2D.h"

using namespace std;
using namespace three_dim;
void main() {
	Box box;
	box.height = 3; box.width = 5;  box.length = 7;
	box.print();
}