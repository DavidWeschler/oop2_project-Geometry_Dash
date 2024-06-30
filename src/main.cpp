#include "ScreenStates/Controller.h"

int main() try {
	Controller controller;
	controller.run();
	return EXIT_SUCCESS;
}
catch (std::exception e) {
	std::cout << e.what();
}
