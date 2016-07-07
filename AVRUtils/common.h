/*!
 *	@file		common.h
 */
#if !defined(AVRUtils__COMMON_H)
	#define AVRUtils__COMMON_H	1

	#define AVRUtils__INLINE	__attribute__((__always_inline__)) inline

	#define AVRUtils__UNUSED	__attribute__((__unused__))

	#include <stdint.h>
	#include <avr/io.h>

	#define AVRUtils__VOID(_expr)	_expr

	/*!
	 *	Selects the correct function according to the number
	 *	of bits.
	 *	This is a helper function, see AVRUtils__MUX8RET and 
	 *	AVRUtils__MUX8.
	 */
	#define AVRUtils__FNMUX8(_num, _fn, _ret, ...)				\
		switch (_num) {											\
			case 0 : _ret(_fn ## 0(__VA_ARGS__)); break;		\
			case 1 : _ret(_fn ## 1(__VA_ARGS__)); break;		\
			case 2 : _ret(_fn ## 2(__VA_ARGS__)); break;		\
			case 3 : _ret(_fn ## 3(__VA_ARGS__)); break;		\
			case 4 : _ret(_fn ## 4(__VA_ARGS__)); break;		\
			case 5 : _ret(_fn ## 5(__VA_ARGS__)); break;		\
			case 6 : _ret(_fn ## 6(__VA_ARGS__)); break;		\
			case 7 : _ret(_fn ## 7(__VA_ARGS__)); break;		\
			default: _ret(_fn ## 8(__VA_ARGS__)); break;		\
		}

	/*!
	 *	Selects the correct function according to `_NUM`.
	 *	Returns a value.
	 */
	#define AVRUtils__MUX8RET(_num, _fn, ...)					\
		AVRUtils__FNMUX8(_num, _fn, return, __VA_ARGS__)

	/*!
	 *	Selects the correct function according to `_NUM`.
	 *	Returns nothing.
	 */
	#define AVRUtils__MUX8(_num, _fn, ...)						\
		AVRUtils__FNMUX8(_num, _fn, AVRUtils__VOID, __VA_ARGS__)

	/*!
	 *	Checks the bit at position `_POS` isset in `_byte`.
	 */
	#define AVRUtils__BITISSET(_byte, _pos)	\
		((((_byte) & (1u << (_pos))) > 0u) ? 1 : 0)

#endif
