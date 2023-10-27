all: clean compile link run

compile:
	g++ -c main.cpp -I"C:\C++ Libraries\SFML-2.5.1\include" -DSFML_STATIC

link: 
	g++ main.o -o main -L"C:\C++ Libraries\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -lsfml-main

# Remove -mwindows when testing

clean: 
	rm -f main *.o

run:
	.\main.exe