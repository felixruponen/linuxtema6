CC = gcc
CFlags = -Wall -std=c99

LibFlags = -fPIC
MathFlag = -lm

Output = electrotest
Installpath = /usr/local/bin/
Librarypath = /usr/lib/

all: main

main: lib 
	$(CC) $(CFlags) src/main.c -o $(Output) -L lib/ -l power -l component -l resistance $(MathFlag) -Wl,-rpath,./lib/,-rpath,$(Librarypath)

lib: libresistance libpower libcomponent
	export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH

libresistance:
	mkdir -p obj/
	mkdir -p lib/
	$(CC) -c src/libresistance/libresistance.c -I src/libresistance/ -o obj/libresistance.o $(MathFlag) $(CFlags)
	$(CC) $(LibFlags) -shared obj/libresistance.o -o lib/libresistance.so

libpower:
	mkdir -p obj/
	mkdir -p lib/
	$(CC) -c src/libpower/libpower.c -I src/libpower/ -o obj/libpower.o $(CFlags)
	$(CC) $(LibFlags) -shared obj/libpower.o -o lib/libpower.so

libcomponent:
	mkdir -p obj/
	mkdir -p lib/
	$(CC) -c src/libcomponent/libcomponent.c -o obj/libcomponent.o -fPIC $(MathFlag) $(CFlags) 
	$(CC) $(LibFlags) -shared obj/libcomponent.o -o lib/libcomponent.so

install:
	sudo cp $(Output) $(Installpath)
	sudo cp lib/* $(Librarypath)

uninstall:
	sudo rm $(Installpath)$(Output)
	sudo rm $(Librarypath)libcomponent.so
	sudo rm $(Librarypath)libpower.so
	sudo rm $(Librarypath)libresistance.so

clean:
	rm -rf obj lib $(Output)

.PHONY: all main install uninstall clean




