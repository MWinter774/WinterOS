echo *************Makefile:*************
cd kernel/
make clean
make all
cd ..
echo '***********************************'
if grub-file --is-x86-multiboot kernel/WinterOS.bin; then
	echo Multiboot confirmed!
	cp kernel/WinterOS.bin configurations/boot
	grub-mkrescue -o WinterOS.iso configurations
	qemu-system-i386 -cdrom WinterOS.iso
else
	echo The OS is not multiboot!
fi
