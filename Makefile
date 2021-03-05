.SILENT:

CC = "/c/SysGCC/raspberry/bin/arm-linux-gnueabihf-g++.exe"
USR = /c/SysGCC/raspberry/arm-linux-gnueabihf/sysroot/usr/
INCLUDE = -I$(USR)include/
LINKDIR = -L$(USR)lib/
LINKS = -lwiringPi -lpthread

FILES = src/Main.cpp src/Motor.cpp src/Robot.cpp

all: build transfer
build: compile link
	echo "Successful Build"
transfer:
	scp main.x pi@10.0.0.56:/home/pi
compile:
	$(CC) -c -Wall -Werror $(FILES) $(INCLUDE)  
link:
	$(CC) $(wildcard *.o) -o main.x $(LINKDIR) $(LINKS)
pch:
	$(CC) src/Pch.h
clean:
	rm -f *.o *.x
