#include "libpsgraph.h"

int main() {
	start("quadrato.ps");
	draw(50);
	turn(90);
	draw(50);
	turn(90);
	draw(50);
	turn(90);
	draw(50);
	end();
	return 0;
}
