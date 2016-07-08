compiled with:
avr-gcc -mmcu=atmega2560 -flto -Os -g -I./

example_bus.obj:     file format elf32-avr


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
  f8:	0c 94 07 01 	jmp	0x20e	; 0x20e <_exit>

000000fc <__bad_interrupt>:
  fc:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>

00000100 <main>:
	}

	AVRUtils__INLINE	void		io__setDirection8(AVRUtils__IO_t data, uint8_t direction) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOSETDIRECTION0(info[1], direction);
 100:	80 91 0a 01 	lds	r24, 0x010A
 104:	8d 7f       	andi	r24, 0xFD	; 253
 106:	80 93 0a 01 	sts	0x010A, r24
		AVRUtils_IOSETDIRECTION0(info[3], direction);
 10a:	23 98       	cbi	0x04, 3	; 4
		AVRUtils_IOSETDIRECTION0(info[5], direction);
 10c:	80 98       	cbi	0x10, 0	; 16
		AVRUtils_IOSETDIRECTION0(info[7], direction);
 10e:	81 98       	cbi	0x10, 1	; 16
		AVRUtils_IOSETDIRECTION0(info[9], direction);
 110:	84 98       	cbi	0x10, 4	; 16
		AVRUtils_IOSETDIRECTION0(info[11], direction);
 112:	87 98       	cbi	0x10, 7	; 16
		AVRUtils_IOSETDIRECTION0(info[13], direction);
 114:	80 91 07 01 	lds	r24, 0x0107
 118:	8d 7f       	andi	r24, 0xFD	; 253
 11a:	80 93 07 01 	sts	0x0107, r24
		AVRUtils_IOSETDIRECTION0(info[15], direction);
 11e:	80 91 07 01 	lds	r24, 0x0107
 122:	8f 7e       	andi	r24, 0xEF	; 239
 124:	80 93 07 01 	sts	0x0107, r24
	}

	AVRUtils__INLINE	void		io__setDirection8(AVRUtils__IO_t data, uint8_t direction) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOSETDIRECTION0(info[1], direction);
 128:	80 91 01 01 	lds	r24, 0x0101
 12c:	80 61       	ori	r24, 0x10	; 16
 12e:	80 93 01 01 	sts	0x0101, r24
		AVRUtils_IOSETDIRECTION0(info[3], direction);
 132:	80 91 01 01 	lds	r24, 0x0101
 136:	88 60       	ori	r24, 0x08	; 8
 138:	80 93 01 01 	sts	0x0101, r24
		AVRUtils_IOSETDIRECTION0(info[5], direction);
 13c:	6b 9a       	sbi	0x0d, 3	; 13
		AVRUtils_IOSETDIRECTION0(info[7], direction);
 13e:	9d 9a       	sbi	0x13, 5	; 19
		AVRUtils_IOSETDIRECTION0(info[9], direction);
 140:	6d 9a       	sbi	0x0d, 5	; 13
		AVRUtils_IOSETDIRECTION0(info[11], direction);
 142:	6c 9a       	sbi	0x0d, 4	; 13
		AVRUtils_IOSETDIRECTION0(info[13], direction);
 144:	39 9a       	sbi	0x07, 1	; 7
		AVRUtils_IOSETDIRECTION0(info[15], direction);
 146:	3b 9a       	sbi	0x07, 3	; 7

	AVRUtils__INLINE	uint8_t		io__read8(AVRUtils__IO_t data) {
		AVRUtils__IO_bus_t info = data;
		uint8_t retValue				= 0;

		retValue |= AVRUtils_IOREAD0(info[1])  << 0;
 148:	90 91 09 01 	lds	r25, 0x0109
 14c:	96 95       	lsr	r25
 14e:	91 70       	andi	r25, 0x01	; 1
		retValue |= AVRUtils_IOREAD0(info[3])  << 1;
 150:	1b 9b       	sbis	0x03, 3	; 3
 152:	02 c0       	rjmp	.+4      	; 0x158 <main+0x58>
 154:	82 e0       	ldi	r24, 0x02	; 2
 156:	01 c0       	rjmp	.+2      	; 0x15a <main+0x5a>
 158:	80 e0       	ldi	r24, 0x00	; 0
 15a:	89 2b       	or	r24, r25
		retValue |= AVRUtils_IOREAD0(info[5])  << 2;
 15c:	78 9b       	sbis	0x0f, 0	; 15
 15e:	02 c0       	rjmp	.+4      	; 0x164 <main+0x64>
 160:	94 e0       	ldi	r25, 0x04	; 4
 162:	01 c0       	rjmp	.+2      	; 0x166 <main+0x66>
 164:	90 e0       	ldi	r25, 0x00	; 0
 166:	98 2b       	or	r25, r24
		retValue |= AVRUtils_IOREAD0(info[7])  << 3;
 168:	79 9b       	sbis	0x0f, 1	; 15
 16a:	02 c0       	rjmp	.+4      	; 0x170 <main+0x70>
 16c:	88 e0       	ldi	r24, 0x08	; 8
 16e:	01 c0       	rjmp	.+2      	; 0x172 <main+0x72>
 170:	80 e0       	ldi	r24, 0x00	; 0
 172:	89 2b       	or	r24, r25
		retValue |= AVRUtils_IOREAD0(info[9])  << 4;
 174:	7c 9b       	sbis	0x0f, 4	; 15
 176:	02 c0       	rjmp	.+4      	; 0x17c <main+0x7c>
 178:	30 e1       	ldi	r19, 0x10	; 16
 17a:	01 c0       	rjmp	.+2      	; 0x17e <main+0x7e>
 17c:	30 e0       	ldi	r19, 0x00	; 0
 17e:	83 2b       	or	r24, r19
		retValue |= AVRUtils_IOREAD0(info[11]) << 5;
 180:	7f 9b       	sbis	0x0f, 7	; 15
 182:	02 c0       	rjmp	.+4      	; 0x188 <main+0x88>
 184:	20 e2       	ldi	r18, 0x20	; 32
 186:	01 c0       	rjmp	.+2      	; 0x18a <main+0x8a>
 188:	20 e0       	ldi	r18, 0x00	; 0
 18a:	82 2b       	or	r24, r18
		retValue |= AVRUtils_IOREAD0(info[13]) << 6;
 18c:	90 91 06 01 	lds	r25, 0x0106
 190:	91 ff       	sbrs	r25, 1
 192:	02 c0       	rjmp	.+4      	; 0x198 <main+0x98>
 194:	90 e4       	ldi	r25, 0x40	; 64
 196:	01 c0       	rjmp	.+2      	; 0x19a <main+0x9a>
 198:	90 e0       	ldi	r25, 0x00	; 0
 19a:	89 2b       	or	r24, r25
		retValue |= AVRUtils_IOREAD0(info[15]) << 7;
 19c:	90 91 06 01 	lds	r25, 0x0106
 1a0:	94 ff       	sbrs	r25, 4
 1a2:	02 c0       	rjmp	.+4      	; 0x1a8 <main+0xa8>
 1a4:	90 e8       	ldi	r25, 0x80	; 128
 1a6:	01 c0       	rjmp	.+2      	; 0x1aa <main+0xaa>
 1a8:	90 e0       	ldi	r25, 0x00	; 0
 1aa:	89 2b       	or	r24, r25
	}

	AVRUtils__INLINE	void		io__write8(AVRUtils__IO_t data, uint8_t value) {
		AVRUtils__IO_bus_t info = data;

		AVRUtils_IOWRITE0(info[1], AVRUtils__BITISSET(value, 0));
 1ac:	90 91 02 01 	lds	r25, 0x0102
 1b0:	80 ff       	sbrs	r24, 0
 1b2:	02 c0       	rjmp	.+4      	; 0x1b8 <main+0xb8>
 1b4:	90 61       	ori	r25, 0x10	; 16
 1b6:	01 c0       	rjmp	.+2      	; 0x1ba <main+0xba>
 1b8:	9f 7e       	andi	r25, 0xEF	; 239
 1ba:	90 93 02 01 	sts	0x0102, r25
		AVRUtils_IOWRITE0(info[3], AVRUtils__BITISSET(value, 1));
 1be:	90 91 02 01 	lds	r25, 0x0102
 1c2:	81 ff       	sbrs	r24, 1
 1c4:	02 c0       	rjmp	.+4      	; 0x1ca <main+0xca>
 1c6:	98 60       	ori	r25, 0x08	; 8
 1c8:	01 c0       	rjmp	.+2      	; 0x1cc <main+0xcc>
 1ca:	97 7f       	andi	r25, 0xF7	; 247
 1cc:	90 93 02 01 	sts	0x0102, r25
		AVRUtils_IOWRITE0(info[5], AVRUtils__BITISSET(value, 2));
 1d0:	82 ff       	sbrs	r24, 2
 1d2:	02 c0       	rjmp	.+4      	; 0x1d8 <main+0xd8>
 1d4:	73 9a       	sbi	0x0e, 3	; 14
 1d6:	01 c0       	rjmp	.+2      	; 0x1da <main+0xda>
 1d8:	73 98       	cbi	0x0e, 3	; 14
		AVRUtils_IOWRITE0(info[7], AVRUtils__BITISSET(value, 3));
 1da:	83 ff       	sbrs	r24, 3
 1dc:	02 c0       	rjmp	.+4      	; 0x1e2 <main+0xe2>
 1de:	a5 9a       	sbi	0x14, 5	; 20
 1e0:	01 c0       	rjmp	.+2      	; 0x1e4 <main+0xe4>
 1e2:	a5 98       	cbi	0x14, 5	; 20
		AVRUtils_IOWRITE0(info[9], AVRUtils__BITISSET(value, 4));
 1e4:	84 ff       	sbrs	r24, 4
 1e6:	02 c0       	rjmp	.+4      	; 0x1ec <main+0xec>
 1e8:	75 9a       	sbi	0x0e, 5	; 14
 1ea:	01 c0       	rjmp	.+2      	; 0x1ee <main+0xee>
 1ec:	75 98       	cbi	0x0e, 5	; 14
		AVRUtils_IOWRITE0(info[11], AVRUtils__BITISSET(value, 5));
 1ee:	85 ff       	sbrs	r24, 5
 1f0:	02 c0       	rjmp	.+4      	; 0x1f6 <main+0xf6>
 1f2:	74 9a       	sbi	0x0e, 4	; 14
 1f4:	01 c0       	rjmp	.+2      	; 0x1f8 <main+0xf8>
 1f6:	74 98       	cbi	0x0e, 4	; 14
		AVRUtils_IOWRITE0(info[13], AVRUtils__BITISSET(value, 6));
 1f8:	86 ff       	sbrs	r24, 6
 1fa:	02 c0       	rjmp	.+4      	; 0x200 <main+0x100>
 1fc:	41 9a       	sbi	0x08, 1	; 8
 1fe:	01 c0       	rjmp	.+2      	; 0x202 <main+0x102>
 200:	41 98       	cbi	0x08, 1	; 8
		AVRUtils_IOWRITE0(info[15], AVRUtils__BITISSET(value, 7));
 202:	87 ff       	sbrs	r24, 7
 204:	02 c0       	rjmp	.+4      	; 0x20a <main+0x10a>
 206:	43 9a       	sbi	0x08, 3	; 8
 208:	9f cf       	rjmp	.-194    	; 0x148 <main+0x48>
 20a:	43 98       	cbi	0x08, 3	; 8
 20c:	9d cf       	rjmp	.-198    	; 0x148 <main+0x48>

0000020e <_exit>:
 20e:	f8 94       	cli

00000210 <__stop_program>:
 210:	ff cf       	rjmp	.-2      	; 0x210 <__stop_program>
