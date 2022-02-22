objects = src/main.o \
		  src/geometry/line.o src/geometry/draw.o \
		  src/geometry/polygon.o \
		  src/tga/TgaImage.o
CXX = g++
CPPFLAGS = -Isrc/ -g

# Name of the output program
filename = plotter

image: $(objects)
	g++ -o bin/$(filename) $(objects) $(CPPFLAGS)

src/main.o:
src/tga/TgaImage.o: src/tga/TgaImage.h
src/geometry/draw.o: src/tga/TgaImage.h src/geometry/draw.h
src/geometry/polygon.o: src/geometry/line.h src/geometry/polygon.h
src/geometry/line.o: src/geometry/line.h

.PHONY: clean
clean:
	rm bin/$(filename) $(objects)
