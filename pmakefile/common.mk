MAJOR=0
MINOR=0
BUILD=$(shell cat version.build)
DEFINES=-DMAJOR=$(MAJOR) -DMINOR=$(MINOR) -D BUILD=$(BUILD)
MAIN_FILE=main.c
SOURCES=
PROGRAM_NAME=test

all: f1.o f2.o f3.o
	gcc $(MAIN_FILE) $(SOURCES:.c=.o) -o $(PROGRAM_NAME) $(DEFINES)
	echo $$(($(BUILD)+1)) > version.build

f1.o:
	gcc f1.c -c

f2.o:
	gcc f2.c -c

f3.o:
	gcc f3.c -c

asm:
	gcc $(MAIN_FILE) -o $(MAIN_FILE:.c=.asm) -S $(DEFINES)

obj:
	gcc $(MAIN_FILE) $(DEFINES) -c

clean:
	rm $(PROGRAM_NAME)
	rm *.o
