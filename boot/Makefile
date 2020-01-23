CC	=	cc
LD	=	ld
OBJCP	=	objcopy

INCD	=	../include

CFLAGS	=	-O -Wall -nostdinc -nostdlib -fno-builtin	\
		-fno-guess-branch-probability -mno-mmx -mno-3dnow	\
		-mno-sse -mno-sse2 -mno-sse3	\
		-Wcast-align -Wbad-function-cast -Wmissing-declarations	\
		-Wmissing-prototypes -Wnested-externs	\
		-Wstrict-prototypes -m32
LDFLAGS	=	-N -e start -static -melf_i386
OBJCPFLAGS	=	-S -O binary

ASRCS	=	$(wildcard *.S)
CSRCS	=	$(wildcard *.c)
OBJS	=	$(ASRCS:.S=.o)
OBJS	+=	$(CSRCS:.c=.o)
ELFS	=	$(ASRCS:.S=.elf)
BINS	=	$(ASRCS:.S=.bin)

all: bootsect.bin	\
	osboot.bin	\
	loader.bin

dis: osboot.bin
	objdump -D -b binary -mi386 -Maddr16,data16,intel osboot.bin
bootsect.elf: bootsect.o
	$(LD) $(LDFLAGS) -Ttext 0x0600 $< -o $@
osboot.elf: osboot.o
	$(LD) $(LDFLAGS) -Ttext 0x0600 $< -o $@
loader.elf: loader.o
	$(LD) $(LDFLAGS) -Ttext 0x1000 $< -o $@

%.bin:%.elf
	$(OBJCP) $(OBJCPFLAGS) $< $@
%.o:%.S
	$(CC) $(CFLAGS) -I $(INCD) -c -o $@ $<
%.o:%.c
	$(CC) $(CFLAGS) -I $(INCD) -c -o $@ $<

clean:
	-rm $(OBJS)
	-rm $(ELFS)
	-rm $(BINS)

.PHONY: clean
