LDSCRIPT   = ../libopencm3/lib/stm32/f4/stm32f405x6.ld
LIBNAME    = opencm3_stm32f4
ARCH_FLAGS = -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
DEFINES    = -DSTM32F4
OBJS       = stm32f4_wrapper.o

all: example_test.bin \
		 example_speed.bin


%.bin: %.elf
	$(OBJCOPY) -Obinary $(*).elf $(*).bin

example_test.elf: example.s example_test.o $(OBJS) $(LDSCRIPT)
		$(LD) -o $@ example.s example_test.o $(OBJS) $(LDFLAGS) -l$(LIBNAME)

example_speed.elf: example.s example_speed.o $(OBJS) $(LDSCRIPT)
		$(LD) -o $@ example.s example_speed.o $(OBJS) $(LDFLAGS) -l$(LIBNAME)


include ../common/make.mk


