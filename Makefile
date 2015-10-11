TARGET = VitaScreenFlasher
OBJS   = main.o warning.o

LIBS = -lvita2d -lSceDisplay_stub -lSceGxm_stub -lSceCommonDialog_stub -lSceCtrl_stub -lpng -lz -lm

PREFIX  = arm-vita-eabi
CC      = $(PREFIX)-gcc
CFLAGS  = -Wl,-q -Wall -O3
ASFLAGS = $(CFLAGS)

all: $(TARGET).velf

%.velf: %.elf
	$(PREFIX)-strip -g $<
	vita-elf-create $< $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

clean:
	@rm -rf $(TARGET).velf $(TARGET).elf $(OBJS)
