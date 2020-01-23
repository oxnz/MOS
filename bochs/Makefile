all:

disk.img: vdisk.dump
	#dd if=/dev/zero of=disk.img bs=512 count=20480
	bximage -hd -size=128 -mode=flat -q $@
	sfdisk $@ < $<

setup: disk.img
	@sudo losetup -P /dev/loop0 disk.img
	@sudo dd if=../boot/bootsect.bin of=/dev/loop0 bs=446 count=1
	@sudo mkfs.vfat -F 32 /dev/loop0p1
	@sudo dd if=../boot/osboot.bin of=/dev/loop0p1 \
		bs=1 \
		skip=90 \
		conv=notrunc \
		seek=90
	@sudo mount /dev/loop0p1 /mnt/

update: ../boot/loader.bin \
	../kernel/kernel.bin
	@sudo mkdir -p /mnt/boot
	@sudo cp ../boot/loader.bin /mnt/boot/loader16.bin
	@sudo cp ../kernel/kernel.bin /mnt/boot/kernel00.mos

unload:
	@sudo umount /mnt
	@sudo losetup -d /dev/loop0

debug:
	bochs-bin -qf config

.PHONY: setup debug
