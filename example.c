#include <AVRUtils/IO/IO.h>

/*!
 *	Target:		ATMega2560
 */
#define LED		io__sfr(C, 3)	// PC3
#define SW		io__sfr(K, 4)	// PK4

int main(void) {

	// Configure I/O

	// LED as an OUTPUT
	io__setDirection(LED, IO__OUTPUT);
	// SW as an INPUT
	io__setDirection(SW, IO__INPUT);

	for (;;) {
		// Continuously write the state of `SW`
		// to `LED`.
		// This code is independent of the physical
		// locations of LED and SW. :)
		io__write(LED, io__read(SW));
	}

}
