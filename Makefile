KERNEL_VERSION := 001
KERNEL_FORMAT := elf32
LD_FLAGS := -m elf_i386 -T link.ld -o kernel
GCC_FLAGS := -m32 -c kernel.c -o kc.o
SRC := kasm.o kc.o

all: kernel
	@mv kernel kernel-$(KERNEL_VERSION) 

kernel: kasm.o kc.o
	ld $(LD_FLAGS) $(SRC) 

kasm.o:
	nasm -f $(KERNEL_FORMAT) kernel.asm -o kasm.o

kc.o:
	gcc $(GCC_FLAGS)

.PHONY: all
