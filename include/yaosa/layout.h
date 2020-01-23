#ifndef	__LAYOUT_H__
#define __LAYOUT_H__

#define	IDT_ADDR	0x0000
#define	IDT_CNT		0x0100

#define	GDT_ADDR	0x10000
#define	GDT_CNT		0x2000

#define	PGD_ADDR	GDT_ADDR+GDT_CNT*8
#define	PG_TBL		PGD_ADDR+0x1000

#define	KCODE_SEL	0x10
#define	KDATA_SEL	0x11
#define	KSTACK_SEL	0x12

#endif//__LAYOUT_H__
