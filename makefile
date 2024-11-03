# $@ = target file
# $< = first dependency
# $^ = all dependencies

# First rule is the one executed when no parameters are fed to the Makefile
all: run

dummy_kernel.bin: enter_kernel.o dummy_kernel.o
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

enter_kernel.o: enter_kernel.asm
	nasm $< -f elf -o $@

dummy_kernel.o: dummy_kernel.c
	gcc -m32 -ffreestanding -fno-pie -c $< -o $@

bootable.bin: bootable.asm
	nasm $< -f bin -o $@

os-image.bin: bootable.bin dummy_kernel.bin
	cat $^ > $@

run: os-image.bin
	qemu-system-i386 -fda $<

clean:
	$(RM) *.bin *.o *.dis