all: compile link run

compile:
	g++ -Isrc/include -c *.cpp

link:
	g++ *.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lopengl32

run:
	./main