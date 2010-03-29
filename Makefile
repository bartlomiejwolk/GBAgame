# --- Project details ---
PROJ	:= crcproj
EXT	:= gba
# project directory
UDIR	:= ~/devkitpro/$(PROJ)
# list of all .c files to be compiled
CFILES	:= 
CPPFILES	:= $(UDIR)/source/main.cpp $(UDIR)/source/gameengine.cpp $(UDIR)/source/gamestate.cpp $(UDIR)/source/statemanager.cpp $(UDIR)/source/text.cpp $(UDIR)/source/timer.cpp
# List of object files. Every .c file will become object file
COBJS	:= $(CFILES:.c=.o) 
CPPOBJS	:= $(CPPFILES:.cpp=.o)
# Files returned to the linker. $(SOBJS) may be included
#OBJS	:= $(COBJS) $(CPPOBJS)

CROSS	:= $(DEVKITARM)/bin/arm-eabi-
# path to gnu c++ compiler
CC		:= $(DEVKITARM)/bin/arm-eabi-g++
LD		:= $(DEVKITARM)/bin/arm-eabi-g++ 
CP		:= $(DEVKITARM)/bin/arm-eabi-gcc
FIX		:= $(DEVKITARM)/bin/gbafix
OBJCOPY	:= $(CROSS)objcopy
# path to folder with tonc library (inside are folders "include" and "lib")
LIBTONC := $(DEVKITPRO)/tonc/code/tonclib
# path to "include" folder within tonc's library
INCLUDE	:= -I$(LIBTONC)/include -I$(CURDIR)/include 
# compiler option - path to "lib" folder within tonc's library
LIBPATHS:= -L$(LIBTONC)/lib
# compiler option - adds "libtonc.a"  
LIBS	:= -ltonc
DEBUG	:= -g
# -O2 (optimalization) has been removed for gdb to work better
CFLAGS 	:= $(INCLUDE) $(LIBTONC) $(LIBS) $(DEBUG) -Wall -mthumb -mthumb-interwork -gdwarf-2
LDFLAGS	:= $(LIBPATHS) $(LIBS) $(DEBUG) -Wall -specs=gba.specs -mthumb -mthumb-interwork 

# --- Build steps ---
all : clean build 

build : $(PROJ).$(EXT)

$(PROJ).$(EXT) : $(PROJ).elf
	$(OBJCOPY) -v -O binary $< $@
	$(FIX) $@

$(PROJ).elf : $(CPPOBJS) $(COBJS)
	$(LD) $^ $(LDFLAGS) -o $@

$(COBJS) : %.o : %.c
	$(CP) -c $< $(CFLAGS) -o $@

$(CPPOBJS) : %.o : %.cpp
	$(CC) -c $< $(CFLAGS) -o $@

clean :
#	@rm -fv source/*.o
	@rm -fv *.elf
	@rm -fv *.gba


tar:
	tar cfv crcproj.tar *
