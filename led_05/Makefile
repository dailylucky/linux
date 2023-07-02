CROSS_COMPILE		?= arm-linux-gnueabihf-
TARGET				?= led

CC 					:= $(CROSS_COMPILE)gcc
LD 					:= $(CROSS_COMPILE)ld
OBJCOPY 			:= $(CROSS_COMPILE)objcopy
OBJDUMP				:= $(CROSS_COMPILE)objdump

INCDIRS				:= imx6ul \
					   bsp/clk \
					   bsp/led \
					   bsp/delay

SRCDIRS				:= project \
					   bsp/clk \
					   bsp/led \
					   bsp/delay

INCLUDE				:= $(patsubst %, -I %, $(INCDIRS))

SFIELS				:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.S))
CFIELS				:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

SFILENDIR			:= $(notdir $(SFIELS))
CFILENDIR			:= $(notdir $(CFIELS))

SOBJS				:= $(patsubst %, obj/%, $(SFILENDIR:.S=.o))
COBJS				:= $(patsubst %, obj/%, $(CFILENDIR:.c=.o))
OBJS				:= $(SOBJS) $(COBJS)

VPATH				:= $(SRCDIRS)

.PHONY: clean print

$(TARGET).bin: $(OBJS)
	$(LD) -Timx6ul.lds -o $(TARGET).elf $^
	$(OBJCOPY) -O binary -S $(TARGET).elf $@
	$(OBJDUMP) -D -m arm $(TARGET).elf > $(TARGET).dis

$(SOBJS): obj/%.o: %.S
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<

$(COBJS): obj/%.o: %.c
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<

clean:
	rm -rf $(TARGET).elf $(TARGET).dis $(TARGET).bin $(OBJS) *.imx

print:
	@echo INCDIRS: $(INCDIRS)
	@echo SRCDIRS: $(SRCDIRS)
	@echo INCLUDE: $(INCLUDE)
	@echo SFIELS: $(SFIELS)
	@echo CFIELS: $(CFIELS)
	@echo SFILENDIR: $(SFILENDIR)
	@echo CFILENDIR: $(CFILENDIR)
	@echo SOBJS: $(SOBJS)
	@echo COBJS: $(COBJS)
	@echo OBJS: $(OBJS)
