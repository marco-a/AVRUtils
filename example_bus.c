#include <AVRUtils/IO/IO.h>

// Define some switches
#define I0		io__sfr(L, 1)	// PL1
#define I1		io__sfr(B, 3)	// PB3
#define I2		io__sfr(F, 0)	// PF0
#define I3		io__sfr(F, 1)	// PF1
#define I4		io__sfr(F, 4)	// PF4
#define I5		io__sfr(F, 7)	// PF7
#define I6		io__sfr(K, 1)	// PK1
#define I7		io__sfr(K, 4)	// PK4

// Define some LEDs
#define Q0		io__sfr(H, 4)	// PH4
#define Q1		io__sfr(H, 3)	// PH3
#define Q2		io__sfr(E, 3)	// PE3
#define Q3		io__sfr(G, 5)	// PG5
#define Q4		io__sfr(E, 5)	// PE5
#define Q5		io__sfr(E, 4)	// PE4
#define Q6		io__sfr(C, 1)	// PC1
#define Q7		io__sfr(C, 3)	// PC3

// Create an 8 bit wide bus
// where I0 = LSB ; Q0 = LSB
// and   I7 = MSB ; Q7 = MSB
#define I		io__bus(8, I0, I1, I2, I3, I4, I5, I6, I7)
#define Q		io__bus(8, Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7)

int main(void) {

	// Configure the whole switches bus as INPUT
	io__setDirection(I, IO__INPUT);
	// Configure the whole LED bus as OUTPUT
	io__setDirection(Q, IO__OUTPUT);

	for (;;) {
		// Continuously write the state of `I`
		// to `Q`.
		io__write(Q, io__read(I));
	}

}
