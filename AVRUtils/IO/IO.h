/*!
 *	@file		IO/IO.h
 */
#if !defined(AVRUtils__IO_IO_H)
	#define AVRUtils__IO_IO_H	1

	#include <AVRUtils/common.h>

	#define AVRUtils__IOSFR(_port, _pin)	\
		((volatile void *const[4]){&DDR ## _port, &PORT ## _port, &PIN ## _port, (volatile void *)P ## _port ## _pin})

	#define io__sfr(_port, _pin)			\
		0, AVRUtils__IOSFR(_port, _pin)

	#define AVRUtil__BUS(_num, ...)			\
		((volatile void *const*const[_num * 2]){__VA_ARGS__})

	#define io__bus(_num, ...)				\
		_num, AVRUtil__BUS(_num, __VA_ARGS__)

	typedef 	volatile const void *									AVRUtils__IO_t;
	typedef		volatile uint8_t *const volatile *const					AVRUtils__IO_pin_t;
	typedef		volatile uint8_t *const volatile *const volatile *const	AVRUtils__IO_bus_t;

	// local defines
	#define AVRUtils_DDR(_info)		(_info[0])
	#define AVRUtils_PORT(_info)	(_info[1])
	#define AVRUtils_PIN(_info)		(_info[2])
	#define AVRUtils_POS(_info)		((intptr_t)_info[3])
	// -- end local defines

	#define IO__OUTPUT		1u
	#define IO__INPUT		0u

	// Load io__setDirection
	#define AVRUtils_INTERN 1
		#include <AVRUtils/IO/setDirection.h>
	#undef AVRUtils_INTERN

	// Load io__write
	#define AVRUtils_INTERN 2
		#include <AVRUtils/IO/write.h>
	#undef AVRUtils_INTERN

	// Load io__read
	#define AVRUtils_INTERN 3
		#include <AVRUtils/IO/read.h>
	#undef AVRUtils_INTERN

	// local defines
	#undef AVRUtils_DDR
	#undef AVRUtils_PORT
	#undef AVRUtils_PIN
	#undef AVRUtils_POS
	// -- end local defines

#endif
