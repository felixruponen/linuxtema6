CC = gcc
CFlags = -Wall -std=c99

LibFlags = -fPIC
MathFlag = -lm

Output = electrotest
Installpath = /usr/bin/
Librarypath = /usr/lib/
Libpath = /lib/

all: main

main: lib 
	$(CC) $(CFlags) src/main.c -o $(Output) -L lib/ -l power -l component -l resistance $(MathFlag) -Wl,-rpath,$(Libpath),-rpath,$(Librarypath)

lib: libresistance libpower libcomponent
	export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH

libresistance:
	mkdir -p obj/
	mkdir -p lib/
	$(CC) -c src/libresistance/libresistance.c -I src/libresistance/ -o obj/libresistance.o $(MathFlag) $(CFlags)
	$(CC) -shared obj/libresistance.o -o lib/libresistance.so

libpower:
	mkdir -p obj/
	mkdir -p lib/
	$(CC) -c src/libpower/libpower.c -I src/libpower/ -o obj/libpower.o $(CFlags)
	$(CC) -shared obj/libpower.o -o lib/libpower.so

libcomponent:
	mkdir -p obj/
	mkdir -p lib/
	$(CC) -c src/libcomponent/libcomponent.c -o obj/libcomponent.o -fPIC $(MathFlag) $(CFlags) 
	$(CC) -shared obj/libcomponent.o -o lib/libcomponent.so

install:
	sudo cp $(Output) $(Installpath)
	sudo cp lib/libcomponent.so $(Librarypath)
	sudo cp lib/libpower.so $(Librarypath)
	sudo cp lib/libresistance.so $(Librarypath)
	sudo cp -s $(Librarypath)libcomponent.so $(Libpath)libcomponent.so
	sudo cp -s $(Librarypath)libpower.so $(Libpath)libpower.so
	sudo cp -s $(Librarypath)libresistance.so $(Libpath)libresistance.so

uninstall:
	sudo rm $(Installpath)$(Output)
	sudo rm $(Libpath)libcomponent.so
	sudo rm $(Libpath)libpower.so
	sudo rm $(Libpath)libresistance.so
	sudo rm $(Librarypath)libcomponent.so
	sudo rm $(Librarypath)libpower.so
	sudo rm $(Librarypath)libresistance.so

clean:
	rm -rf obj lib $(Output)

.PHONY: all main install uninstall clean




