
./example.o:     file format elf32-avr


Disassembly of section .text:

00000000 <__vectors>:
   0:	0c 94 72 00 	jmp	0xe4	; 0xe4 <__ctors_end>
   4:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
   8:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
   c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  10:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  14:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  18:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  1c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  20:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  24:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  28:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  2c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  30:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  34:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  38:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  3c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  40:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  44:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  48:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  4c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  50:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  54:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  58:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  5c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  60:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  64:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  68:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  6c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  70:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  74:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  78:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  7c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  80:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  84:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  88:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  8c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  90:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  94:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  98:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  9c:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  a0:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  a4:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  a8:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  ac:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  b0:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  b4:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  b8:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  bc:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  c0:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  c4:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  c8:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  cc:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  d0:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  d4:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  d8:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  dc:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>
  e0:	0c 94 7e 00 	jmp	0xfc	; 0xfc <__bad_interrupt>

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
 100:	3b 9a       	sbi	0x07, 3	; 7
 102:	80 91 07 01 	lds	r24, 0x0107
 106:	8f 7e       	andi	r24, 0xEF	; 239
 108:	80 93 07 01 	sts	0x0107, r24
 10c:	80 91 06 01 	lds	r24, 0x0106
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
