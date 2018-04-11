#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/WinterOS.kernel isodir/boot/WinterOS.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "WinterOS" {
	multiboot /boot/WinterOS.kernel
}
EOF
grub-mkrescue -o WinterOS.iso isodir
