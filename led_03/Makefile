objs 		:= start.o main.o
prefix 		:= arm-linux-gnueabihf
gcc 		:= $(prefix)-gcc
ld 			:= $(prefix)-ld
objcopy		:= $(prefix)-objcopy
objdump		:= $(prefix)-objdump
compile_arg := -Wall -nostdlib -c -O2

led.bin: $(objs)
	$(ld) -Timx6ul.lds -o led.elf $^
	$(objcopy) -O binary -S led.elf $@
	$(objdump) -D -m arm led.elf > led.dis

%.o: %.s
	$(gcc) $(compile_arg) -o $@ $<

%.o: %.S
	$(gcc) $(compile_arg) -o $@ $<

%.o: %.c
	$(gcc) $(compile_arg) -o $@ $<

.PHONY: clean
clean:
	rm -rf *.o *.bin *.elf *.dis *.imx
