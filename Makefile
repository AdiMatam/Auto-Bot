.SILENT:

ROOT    = "~/cross/cross-pi-gcc-8.3.0-0"
CC      = $(ROOT)/bin/arm-linux-gnueabihf-g++
INCLUDE = -I .
LINKDIR = -L$(ROOT)/arm-linux-gnueabihf/libc/lib
LINKS   = -lwiringPi -lpthread -lrt -lcrypt

FILES = src/Main.cpp src/Motor.cpp src/Robot.cpp
OUT   = Main.x

all: build transfer
build: compile link
	echo "Successful Build"
transfer:
	scp $(OUT) pi@10.0.0.56:/home/pi
compile:
	$(CC) -c -Wall -Werror $(FILES) $(INCLUDE)  
link:
	$(CC) $(wildcard *.o) -o $(OUT) $(LINKDIR) $(LINKS)
pch:
	$(CC) src/Pch.h
clean:
	rm -f *.o *.x

# CC = "/c/SysGCC/raspberry/bin/arm-linux-gnueabihf-g++.exe"
# USR = /c/SysGCC/raspberry/arm-linux-gnueabihf/sysroot/usr/
# INCLUDE = -I$(USR)include/
# LINKDIR = -L$(USR)lib/
# LINKS = -lwiringPi -lpthread