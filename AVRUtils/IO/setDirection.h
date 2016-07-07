/*!
 *	@file		IO/setDirection.h
 */
#if !defined(AVRUtils_INTERN) || AVRUtils_INTERN != 1
	#error "Do not directly include this file. Include <AVRUtils/IO.h> instead!"
#endif

#if !defined(AVRUtils__IO_SETDIRECTION_H)
	#define AVRUtils__IO_SETDIRECTION_H	1

	#define AVRUtils_IOSETDIRECTION0(_data, _direction)				\
		do {														\
			AVRUtils__IO_pin_t _pin = _data;						\
			if (_direction) {										\
				*AVRUtils_DDR(_pin) |=  _BV(AVRUtils_POS(_pin));	\
			} else {												\
				*AVRUtils_DDR(_pin) &= ~_BV(AVRUtils_POS(_pin));	\
			}														\
		} while (0)

	AVRUtils__INLINE	void		io__setDirection0(AVRUtils__IO_t data, uint8_t direction) {
		AVRUtils__IO_pin_t info = data;

		AVRUtils_IOSETDIRECTION0(info, direction);
	}

	AVRUtils__INLINE	void		io__setDirection1(AVRUtils__IO_t data, uint8_t direction) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOSETDIRECTION0(info[1], direction);
	}

	AVRUtils__INLINE	void		io__setDirection2(AVRUtils__IO_t data, uint8_t direction) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOSETDIRECTION0(info[1], direction);
		AVRUtils_IOSETDIRECTION0(info[3], direction);
	}

	AVRUtils__INLINE	void		io__setDirection3(AVRUtils__IO_t data, uint8_t direction) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOSETDIRECTION0(info[1], direction);
		AVRUtils_IOSETDIRECTION0(info[3], direction);
		AVRUtils_IOSETDIRECTION0(info[5], direction);
	}

	AVRUtils__INLINE	void		io__setDirection4(AVRUtils__IO_t data, uint8_t direction) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOSETDIRECTION0(info[1], direction);
		AVRUtils_IOSETDIRECTION0(info[3], direction);
		AVRUtils_IOSETDIRECTION0(info[5], direction);
		AVRUtils_IOSETDIRECTION0(info[7], direction);
	}

	AVRUtils__INLINE	void		io__setDirection5(AVRUtils__IO_t data, uint8_t direction) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOSETDIRECTION0(info[1], direction);
		AVRUtils_IOSETDIRECTION0(info[3], direction);
		AVRUtils_IOSETDIRECTION0(info[5], direction);
		AVRUtils_IOSETDIRECTION0(info[7], direction);
		AVRUtils_IOSETDIRECTION0(info[9], direction);
	}

	AVRUtils__INLINE	void		io__setDirection6(AVRUtils__IO_t data, uint8_t direction) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOSETDIRECTION0(info[1], direction);
		AVRUtils_IOSETDIRECTION0(info[3], direction);
		AVRUtils_IOSETDIRECTION0(info[5], direction);
		AVRUtils_IOSETDIRECTION0(info[7], direction);
		AVRUtils_IOSETDIRECTION0(info[9], direction);
		AVRUtils_IOSETDIRECTION0(info[11], direction);
	}

	AVRUtils__INLINE	void		io__setDirection7(AVRUtils__IO_t data, uint8_t direction) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOSETDIRECTION0(info[1], direction);
		AVRUtils_IOSETDIRECTION0(info[3], direction);
		AVRUtils_IOSETDIRECTION0(info[5], direction);
		AVRUtils_IOSETDIRECTION0(info[7], direction);
		AVRUtils_IOSETDIRECTION0(info[9], direction);
		AVRUtils_IOSETDIRECTION0(info[11], direction);
		AVRUtils_IOSETDIRECTION0(info[13], direction);
	}

	AVRUtils__INLINE	void		io__setDirection8(AVRUtils__IO_t data, uint8_t direction) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOSETDIRECTION0(info[1], direction);
		AVRUtils_IOSETDIRECTION0(info[3], direction);
		AVRUtils_IOSETDIRECTION0(info[5], direction);
		AVRUtils_IOSETDIRECTION0(info[7], direction);
		AVRUtils_IOSETDIRECTION0(info[9], direction);
		AVRUtils_IOSETDIRECTION0(info[11], direction);
		AVRUtils_IOSETDIRECTION0(info[13], direction);
		AVRUtils_IOSETDIRECTION0(info[15], direction);
	}

	AVRUtils__INLINE	void		io__setDirection(uint8_t num, AVRUtils__IO_t data, uint8_t direction) {
		// Multiplex function call
		AVRUtils__MUX8(num, io__setDirection, data, direction);
	}

	#undef AVRUtils_IOSETDIRECTION0

	#if defined(AVRUtils__TEST) && AVRUtils__TEST == 1
		#define AVRUtils__TEST_PA1	io__sfr(A, 1)
		#define AVRUtils__TEST_PA2	io__sfr(A, 2)
		#define AVRUtils__TEST_PA6	io__sfr(A, 6)
		#define AVRUtils__TEST_PA7	io__sfr(A, 7)
		#define AVRUtils__TEST_PA	io__bus(4, AVRUtils__TEST_PA1, AVRUtils__TEST_PA2, AVRUtils__TEST_PA7, AVRUtils__TEST_PA6)

		AVRUtils__INLINE void		io__setDirection__test1(void) {
			DDRA |= _BV(PA1);
			DDRA |= _BV(PA2);
			DDRA |= _BV(PA7);
			DDRA |= _BV(PA6);
		}

		AVRUtils__INLINE void		io__setDirection__test2(void) {
			// Test single bits
			io__setDirection(AVRUtils__TEST_PA1, 1);
			io__setDirection(AVRUtils__TEST_PA2, 1);
			io__setDirection(AVRUtils__TEST_PA7, 1);
			io__setDirection(AVRUtils__TEST_PA6, 1);
		}

		AVRUtils__INLINE void		io__setDirection__test3(void) {
			// Test bus with single bit
			io__setDirection(io__bus(1, AVRUtils__TEST_PA1), 1);
			io__setDirection(io__bus(1, AVRUtils__TEST_PA2), 1);
			io__setDirection(io__bus(1, AVRUtils__TEST_PA7), 1);
			io__setDirection(io__bus(1, AVRUtils__TEST_PA6), 1);
		}

		AVRUtils__INLINE void		io__setDirection__test4(void) {
			// Test bus
			io__setDirection(AVRUtils__TEST_PA, 1);
		}
	#endif

#endif
