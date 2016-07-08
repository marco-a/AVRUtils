compiled with:
avr-gcc -mmcu=atmega2560 -flto -Os -g -I./

example.obj:     file format elf32-avr


Disassembly of section .text:

00000000 <__vectors>:
Removed for readability

000000e4 <__ctors_end>:
  e4:	11 24       	eor	r1, r1
  e6:	1f be       	out	0x3f, r1	; 63
  e8:	cf ef       	ldi	r28, 0xFF	; 255
  ea:	d1 e2       	ldi	r29, 0x21	; 33
  ec:	de bf       	out	0x3e, r29	; 62
  ee:	cd bf       	out	0x3d, r28	; 61
  f0:	00 e0       	ldi	r16, 0x00	; 0
  f2:	0c bf       	out	0x3c, r16	; 60
  f4:	0e 94 80 00 	call	0x100	; 0x100 <main>
  f8:	0c 94 8e 00 	jmp	0x11c	; 0x11c <_exit>

000000fc <__bad_interrupt>:
  fc:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>

00000100 <main>:
		} while (0)

	AVRUtils__INLINE	void		io__setDirection0(AVRUtils__IO_t data, uint8_t direction) {
		AVRUtils__IO_pin_t info = data;

		AVRUtils_IOSETDIRECTION0(info, direction);
 100:	3b 9a       	sbi	0x07, 3	; 7
 102:	80 91 07 01 	lds	r24, 0x0107
 106:	8f 7e       	andi	r24, 0xEF	; 239
 108:	80 93 07 01 	sts	0x0107, r24
		AVRUtils__BITISSET(*((AVRUtils__IO_pin_t)_info)[2], (intptr_t)((AVRUtils__IO_pin_t)_info)[3])

	AVRUtils__INLINE	uint8_t		io__read0(AVRUtils__IO_t data) {
		AVRUtils__IO_pin_t info = data;

		return AVRUtils_IOREAD0(info);
 10c:	80 91 06 01 	lds	r24, 0x0106
		} while (0)

	AVRUtils__INLINE	void		io__write0(AVRUtils__IO_t data, uint8_t value) {
		AVRUtils__IO_pin_t info = data;

		AVRUtils_IOWRITE0(info, value);
 110:	84 ff       	sbrs	r24, 4
 112:	02 c0       	rjmp	.+4      	; 0x118 <main+0x18>
 114:	43 9a       	sbi	0x08, 3	; 8
 116:	fa cf       	rjmp	.-12     	; 0x10c <main+0xc>
 118:	43 98       	cbi	0x08, 3	; 8
 11a:	f8 cf       	rjmp	.-16     	; 0x10c <main+0xc>

0000011c <_exit>:
 11c:	f8 94       	cli

0000011e <__stop_program>:
 11e:	ff cf       	rjmp	.-2      	; 0x11e <__stop_program>
