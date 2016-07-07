/*!
 *	@file		IO/read.h
 */
#if !defined(AVRUtils_INTERN) || AVRUtils_INTERN != 3
	#error "Do not directly include this file. Include <AVRUtils/IO.h> instead!"
#endif

#if !defined(AVRUtils__IO_READ_H)
	#define AVRUtils__IO_READ_H	1
// local defines
#define AVRUtils_DDR(_info)		(_info[0])
#define AVRUtils_PORT(_info)	(_info[1])
#define AVRUtils_PIN(_info)		(_info[2])
#define AVRUtils_POS(_info)		((intptr_t)_info[3])

	// ~~UC
	#define AVRUtils_IOREAD0(_info)																		\
		AVRUtils__BITISSET(*((AVRUtils__IO_pin_t)_info)[2], (intptr_t)((AVRUtils__IO_pin_t)_info)[3])

	AVRUtils__INLINE	uint8_t		io__read0(AVRUtils__IO_t data) {
		AVRUtils__IO_pin_t info = data;

		return AVRUtils_IOREAD0(info);
	}

	AVRUtils__INLINE	uint8_t		io__read1(AVRUtils__IO_t data) {
		AVRUtils__IO_bus_t info = data;

		return AVRUtils_IOREAD0(info[1]);
	}

	AVRUtils__INLINE	uint8_t		io__read2(AVRUtils__IO_t data) {
		AVRUtils__IO_bus_t info = data;
		uint8_t retValue				= 0;

		retValue |= AVRUtils_IOREAD0(info[1]) << 0;
		retValue |= AVRUtils_IOREAD0(info[3]) << 1;

		return retValue;
	}

	AVRUtils__INLINE	uint8_t		io__read3(AVRUtils__IO_t data) {
		AVRUtils__IO_bus_t info = data;
		uint8_t retValue				= 0;

		retValue |= AVRUtils_IOREAD0(info[1]) << 0;
		retValue |= AVRUtils_IOREAD0(info[3]) << 1;
		retValue |= AVRUtils_IOREAD0(info[5]) << 2;

		return retValue;
	}

	AVRUtils__INLINE	uint8_t		io__read4(AVRUtils__IO_t data) {
		AVRUtils__IO_bus_t info = data;
		uint8_t retValue				= 0;

		retValue |= AVRUtils_IOREAD0(info[1]) << 0;
		retValue |= AVRUtils_IOREAD0(info[3]) << 1;
		retValue |= AVRUtils_IOREAD0(info[5]) << 2;
		retValue |= AVRUtils_IOREAD0(info[7]) << 3;

		return retValue;
	}

	AVRUtils__INLINE	uint8_t		io__read5(AVRUtils__IO_t data) {
		AVRUtils__IO_bus_t info = data;
		uint8_t retValue				= 0;

		retValue |= AVRUtils_IOREAD0(info[1]) << 0;
		retValue |= AVRUtils_IOREAD0(info[3]) << 1;
		retValue |= AVRUtils_IOREAD0(info[5]) << 2;
		retValue |= AVRUtils_IOREAD0(info[7]) << 3;
		retValue |= AVRUtils_IOREAD0(info[9]) << 4;

		return retValue;
	}

	AVRUtils__INLINE	uint8_t		io__read6(AVRUtils__IO_t data) {
		AVRUtils__IO_bus_t info = data;
		uint8_t retValue				= 0;

		retValue |= AVRUtils_IOREAD0(info[1])  << 0;
		retValue |= AVRUtils_IOREAD0(info[3])  << 1;
		retValue |= AVRUtils_IOREAD0(info[5])  << 2;
		retValue |= AVRUtils_IOREAD0(info[7])  << 3;
		retValue |= AVRUtils_IOREAD0(info[9])  << 4;
		retValue |= AVRUtils_IOREAD0(info[11]) << 5;

		return retValue;

	}

	AVRUtils__INLINE	uint8_t		io__read7(AVRUtils__IO_t data) {
		AVRUtils__IO_bus_t info = data;
		uint8_t retValue				= 0;

		retValue |= AVRUtils_IOREAD0(info[1])  << 0;
		retValue |= AVRUtils_IOREAD0(info[3])  << 1;
		retValue |= AVRUtils_IOREAD0(info[5])  << 2;
		retValue |= AVRUtils_IOREAD0(info[7])  << 3;
		retValue |= AVRUtils_IOREAD0(info[9])  << 4;
		retValue |= AVRUtils_IOREAD0(info[11]) << 5;
		retValue |= AVRUtils_IOREAD0(info[13]) << 6;

		return retValue;

	}

	AVRUtils__INLINE	uint8_t		io__read8(AVRUtils__IO_t data) {
		AVRUtils__IO_bus_t info = data;
		uint8_t retValue				= 0;

		retValue |= AVRUtils_IOREAD0(info[1])  << 0;
		retValue |= AVRUtils_IOREAD0(info[3])  << 1;
		retValue |= AVRUtils_IOREAD0(info[5])  << 2;
		retValue |= AVRUtils_IOREAD0(info[7])  << 3;
		retValue |= AVRUtils_IOREAD0(info[9])  << 4;
		retValue |= AVRUtils_IOREAD0(info[11]) << 5;
		retValue |= AVRUtils_IOREAD0(info[13]) << 6;
		retValue |= AVRUtils_IOREAD0(info[15]) << 7;

		return retValue;
	}

	AVRUtils__INLINE	uint8_t		io__read(uint8_t num, AVRUtils__IO_t data) {
		// Multiplex function call
		AVRUtils__MUX8RET(num, io__read, data);
	}

	#undef AVRUtils_IOREAD0

	// ~~UC
	#if defined(AVRUtils__TEST) && AVRUtils__TEST == 3
		#define AVRUtils__TEST_PA1	io__sfr(A, 1)
		#define AVRUtils__TEST_PC2	io__sfr(C, 2)
		#define AVRUtils__TEST_PD7	io__sfr(D, 7)
		#define AVRUtils__TEST_PE6	io__sfr(E, 6)
		#define AVRUtils__TEST_PA	io__bus(4, AVRUtils__TEST_PA1, AVRUtils__TEST_PC2, AVRUtils__TEST_PD7, AVRUtils__TEST_PE6)

		AVRUtils__INLINE uint8_t		io__read__test1(void) {
			uint8_t retValue = 0;

			retValue |= ((PINA & _BV(PA1)) > 0 ? 1 : 0) << 0;
			retValue |= ((PINC & _BV(PC2)) > 0 ? 1 : 0) << 1;
			retValue |= ((PIND & _BV(PD7)) > 0 ? 1 : 0) << 2;
			retValue |= ((PINE & _BV(PE6)) > 0 ? 1 : 0) << 3;

			return retValue;
		}

		AVRUtils__INLINE uint8_t		io__read__test2(void) {
			uint8_t retValue = 0;

			retValue |= (io__read(AVRUtils__TEST_PA1)) << 0;
			retValue |= (io__read(AVRUtils__TEST_PC2)) << 1;
			retValue |= (io__read(AVRUtils__TEST_PD7)) << 2;
			retValue |= (io__read(AVRUtils__TEST_PE6)) << 3;

			return retValue;
		}

		AVRUtils__INLINE uint8_t		io__read__test3(void) {
			uint8_t retValue = 0;

			retValue = io__read(AVRUtils__TEST_PA);

			return retValue;
		}
	#endif

#endif
