objs := start.o main.o

led.bin: $(objs)
	arm-linux-gnueabihf-ld -Timx6ul.lds -o led.elf $^
	arm-linux-gnueabihf-objcopy -O binary -S led.elf $@
	arm-linux-gnueabihf-objdump -D -m arm led.elf > led.dis

%.o: %.s
	arm-linux-gnueabihf-gcc -Wall -nostdlib -c -o $@ $<

%.o: %.S
	arm-linux-gnueabihf-gcc -Wall -nostdlib -c -o $@ $<

%.o: %.c
	arm-linux-gnueabihf-gcc -Wall -nostdlib -c -o $@ $<

.PHONY: clean

clean:
	rm -rf *.o *.bin *.elf *.dis
