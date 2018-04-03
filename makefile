# Here is a simple Make Macro.
LINK_TARGET = app.exe

BDIR = build

# Here is a Make Macro that uses the backslash to extend to multiple lines.
OBJS = $(BDIR)/app.o $(BDIR)/complex.o $(BDIR)/args.o $(BDIR)/pixel.o $(BDIR)/julia.o $(BDIR)/utils.o

# Compile flags
LFLAGS = -lm
CFLAGS = -g -Iheaders -Wall

all : directories $(LINK_TARGET)

directories:
	mkdir -p build

$(LINK_TARGET) : $(OBJS)
	gcc -o $@ build/app.o build/complex.o build/args.o build/pixel.o build/julia.o build/utils.o $(LFLAGS)


build/app.o : src/app.c
	gcc $(CFLAGS) -c src/app.c -o build/app.o

build/complex.o : src/complex.c
	gcc $(CFLAGS) -c src/complex.c -o build/complex.o

build/args.o : src/args.c
	gcc $(CFLAGS) -c src/args.c -o build/args.o

build/pixel.o : src/pixel.c
	gcc $(CFLAGS) -c src/pixel.c -o build/pixel.o

build/julia.o : src/julia.c
	gcc $(CFLAGS) -c src/julia.c -o build/julia.o

build/utils.o : src/utils.c
	gcc $(CFLAGS) -c src/utils.c -o build/utils.o


clean:
	rm -f $(OBJS) $(LINK_TARGET)

# These are Dependency Rules, which are rules without any command.
# Dependency Rules indicate that if any file to the right of the colon changes,
# the target to the left of the colon should be considered out-of-date.
# The commands for making an out-of-date target up-to-date may be found elsewhere
# (in this case, by the Pattern Rule above).
# Dependency Rules are often used to capture header file dependencies.
#Main.o : Main.h Test1.h Test2.h
#Test1.o : Test1.h Test2.h
#Test2.o : Test2.h