# AVRUtils
This library aims to abstract away the hardware modules on an AVR microcontroller in an efficient and straightforward manner.
Please be aware that at this time the library was only tested on an ATMega2560.

More comprehensive tests will follow, this includes showing the generated assembly as well as timing measurements with an oscilloscope.

At the time there is only one module available which is demonstrated below:

### I/O example: LED
```c
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
```

As you can see, the logic of the code is completely isolated from the physical locations of the pins!
And guess what? The code is efficient as well! Have a look at the generated [assembly](https://github.com/marco-a/AVRUtils/blob/master/example.s), if you dare :-)


### I/O bus example
Sometimes it is not possible (due physical constraints) to route all positions from a bus to the same port on the microcontroller.
For example: you have a 4 bit wide bus where 2 bits are on port C and 2 bits are on port F.
A real mess! You know what I'm talking about if you ever had this situation before!
Well, those days are finally gone! The included I/O module provides an easy and straightforward solution to that problem!

How? You simply define each position with the `io__sfr` macro and then join them together with the `io__bus` macro:

```c
#include <AVRUtil/IO/IO.h>

/*!
 *	Target:		ATMega2560
 */
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

// Create the 8 bit wide bus
// where I0 = LSB ; Q0 = LSB
// and   I7 = MSB ; Q7 = MSB
#define I		io__bus(8, I0, I1, I2, I3, I4, I5, I6, I7)
#define Q		io__bus(8, Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7)

int main(void) {

	// Configure the whole `I` bus as INPUT
	io__setDirection(I, IO__INPUT);
	// Configure the whole `Q` bus as OUTPUT
	io__setDirection(Q, IO__OUTPUT);

	for (;;) {
		// Continuously write the state of `I`
		// to `Q`.
		io__write(Q, io__read(I));
	}

}
```

Easy!

## Getting Started
Have a look at this [wiki](https://github.com/marco-a/AVRUtils/wiki/I-O-Module) page, where each macro / function is explained in more detail.

## How to use it

Just download the library and include it in your project.
Don't forget to compile at least with  `Os` optimization level.
Also use the `-flto` flag while compiling. (very important!)
The library is tested to work with `avr-gcc 4.8.3`.

## Roadmap

- Even more optimization for I/O operations.
- Comprehensive tests (Assembly / Oscilloscope).
- Timer / TWI / UART module...

## Bugs & Contributions 

Please report bugs by the [issues](https://github.com/marco-a/AVRUtils/issues) function provided by GitHub.
Contributions are very welcome! Please use the issues tool for these as well, thank you.



