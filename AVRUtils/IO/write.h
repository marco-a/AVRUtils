/*!
 *	@file		IO/write.h
 */
#if !defined(AVRUtils_INTERN) || AVRUtils_INTERN != 2
	#error "Do not directly include this file. Include <AVRUtils/IO.h> instead!"
#endif

#if !defined(AVRUtils__IO_WRITE_H)
	#define AVRUtils__IO_WRITE_H	1

	#define AVRUtils_IOWRITE0(_data, _value)						\
		do {														\
			AVRUtils__IO_pin_t _pin = _data;						\
			if (_value) {											\
				*AVRUtils_PORT(_pin) |=  _BV(AVRUtils_POS(_pin));	\
			} else {												\
				*AVRUtils_PORT(_pin) &= ~_BV(AVRUtils_POS(_pin));	\
			}														\
		} while (0)

	AVRUtils__INLINE	void		io__write0(AVRUtils__IO_t data, uint8_t value) {
		AVRUtils__IO_pin_t info = data;

		AVRUtils_IOWRITE0(info, value);
	}

	AVRUtils__INLINE	void		io__write1(AVRUtils__IO_t data, uint8_t value) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOWRITE0(info[1], value);
	}

	AVRUtils__INLINE	void		io__write2(AVRUtils__IO_t data, uint8_t value) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOWRITE0(info[1], AVRUtils__BITISSET(value, 0));
		AVRUtils_IOWRITE0(info[3], AVRUtils__BITISSET(value, 1));
	}

	AVRUtils__INLINE	void		io__write3(AVRUtils__IO_t data, uint8_t value) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOWRITE0(info[1], AVRUtils__BITISSET(value, 0));
		AVRUtils_IOWRITE0(info[3], AVRUtils__BITISSET(value, 1));
		AVRUtils_IOWRITE0(info[5], AVRUtils__BITISSET(value, 2));
	}

	AVRUtils__INLINE	void		io__write4(AVRUtils__IO_t data, uint8_t value) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOWRITE0(info[1], AVRUtils__BITISSET(value, 0));
		AVRUtils_IOWRITE0(info[3], AVRUtils__BITISSET(value, 1));
		AVRUtils_IOWRITE0(info[5], AVRUtils__BITISSET(value, 2));
		AVRUtils_IOWRITE0(info[7], AVRUtils__BITISSET(value, 3));
	}

	AVRUtils__INLINE	void		io__write5(AVRUtils__IO_t data, uint8_t value) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOWRITE0(info[1], AVRUtils__BITISSET(value, 0));
		AVRUtils_IOWRITE0(info[3], AVRUtils__BITISSET(value, 1));
		AVRUtils_IOWRITE0(info[5], AVRUtils__BITISSET(value, 2));
		AVRUtils_IOWRITE0(info[7], AVRUtils__BITISSET(value, 3));
		AVRUtils_IOWRITE0(info[9], AVRUtils__BITISSET(value, 4));
	}

	AVRUtils__INLINE	void		io__write6(AVRUtils__IO_t data, uint8_t value) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOWRITE0(info[1], AVRUtils__BITISSET(value, 0));
		AVRUtils_IOWRITE0(info[3], AVRUtils__BITISSET(value, 1));
		AVRUtils_IOWRITE0(info[5], AVRUtils__BITISSET(value, 2));
		AVRUtils_IOWRITE0(info[7], AVRUtils__BITISSET(value, 3));
		AVRUtils_IOWRITE0(info[9], AVRUtils__BITISSET(value, 4));
		AVRUtils_IOWRITE0(info[11], AVRUtils__BITISSET(value, 5));
	}

	AVRUtils__INLINE	void		io__write7(AVRUtils__IO_t data, uint8_t value) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOWRITE0(info[1], AVRUtils__BITISSET(value, 0));
		AVRUtils_IOWRITE0(info[3], AVRUtils__BITISSET(value, 1));
		AVRUtils_IOWRITE0(info[5], AVRUtils__BITISSET(value, 2));
		AVRUtils_IOWRITE0(info[7], AVRUtils__BITISSET(value, 3));
		AVRUtils_IOWRITE0(info[9], AVRUtils__BITISSET(value, 4));
		AVRUtils_IOWRITE0(info[11], AVRUtils__BITISSET(value, 5));
		AVRUtils_IOWRITE0(info[13], AVRUtils__BITISSET(value, 6));
	}

	AVRUtils__INLINE	void		io__write8(AVRUtils__IO_t data, uint8_t value) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOWRITE0(info[1], AVRUtils__BITISSET(value, 0));
		AVRUtils_IOWRITE0(info[3], AVRUtils__BITISSET(value, 1));
		AVRUtils_IOWRITE0(info[5], AVRUtils__BITISSET(value, 2));
		AVRUtils_IOWRITE0(info[7], AVRUtils__BITISSET(value, 3));
		AVRUtils_IOWRITE0(info[9], AVRUtils__BITISSET(value, 4));
		AVRUtils_IOWRITE0(info[11], AVRUtils__BITISSET(value, 5));
		AVRUtils_IOWRITE0(info[13], AVRUtils__BITISSET(value, 6));
		AVRUtils_IOWRITE0(info[15], AVRUtils__BITISSET(value, 7));
	}

	AVRUtils__INLINE	void		io__write(uint8_t num, AVRUtils__IO_t data, uint8_t value) {
		// Multiplex function call
		AVRUtils__MUX8(num, io__write, data, value);
	}

	#undef AVRUtils_IOWRITE0

	#if defined(AVRUtils__TEST) && AVRUtils__TEST == 2
		#define AVRUtils__TEST_PA1	io__sfr(A, 1)
		#define AVRUtils__TEST_PC2	io__sfr(C, 2)
		#define AVRUtils__TEST_PD7	io__sfr(D, 7)
		#define AVRUtils__TEST_PE6	io__sfr(E, 6)
		#define AVRUtils__TEST_PA	io__bus(4, AVRUtils__TEST_PA1, AVRUtils__TEST_PC2, AVRUtils__TEST_PD7, AVRUtils__TEST_PE6)

		AVRUtils__INLINE void		io__write__test1(void) {
			PORTA |= _BV(PA1);
			PORTC |= _BV(PC2);
			PORTD |= _BV(PD7);
			PORTE |= _BV(PE6);
		}

		AVRUtils__INLINE void		io__write__test2(void) {
			// Test single bits
			io__write(AVRUtils__TEST_PA1, 1);
			io__write(AVRUtils__TEST_PC2, 1);
			io__write(AVRUtils__TEST_PD7, 1);
			io__write(AVRUtils__TEST_PE6, 1);
		}

		AVRUtils__INLINE void		io__write__test3(void) {
			// Test bus with single bit
			io__write(io__bus(1, AVRUtils__TEST_PA1), 1);
			io__write(io__bus(1, AVRUtils__TEST_PC2), 1);
			io__write(io__bus(1, AVRUtils__TEST_PD7), 1);
			io__write(io__bus(1, AVRUtils__TEST_PE6), 1);
		}

		AVRUtils__INLINE void		io__write__test4(void) {
			// Test bus
			io__write(AVRUtils__TEST_PA, 0x0F);
		}
	#endif

#endif
