.SILENT:

FILES = csrc/main.cpp
INCLUDE = -Iinclude/WiringPi/wiringPi
LINKS = -Llib -lwiringPi # -lpthread

all: build run
build: compile link
run:
	./main.x
compile:
	armg++ -c -Wall -Werror $(FILES) $(INCLUDE)  
link:
	armg++ main.o -o main.x $(LINKS)
pch:
	armg++ csrc/pch.hpp
clean:
	rm -f *.o *.x

# -mfloat-abi=hard -mcpu=cortex-a7 -mfpu=neon-vfpv4