#include "Matrix_Test_AppApp.h"

int main() {
	
	// allocation
	auto app = new Matrix_Test_AppApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}