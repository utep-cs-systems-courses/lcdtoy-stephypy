# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as -mcpu=msp430 --traditional-format -mP

all: button.elf 

#additional rules for files
button.elf: ${COMMON_OBJECTS} p2_interrupt_handler.o song.o switches.o catMain.o wdInterruptHandler.o buzzer.o stateMachines.o cat.o lcddraw.o lcdutils.o font-5x7.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf
