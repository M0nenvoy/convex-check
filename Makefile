objects = src/geometry/line.o src/geometry/draw.o \
		  src/geometry/polygon.o \
		  src/tga/TgaImage.o

# Plotters path
pp = src/plotters

CXX = g++
CPPFLAGS = -Isrc/ -g


$(pp)/simple/simple.o: 				$(pp)/const.h
$(pp)/simple/convex.o: 				$(pp)/const.h
$(pp)/simple/check_convex.o: 		$(pp)/const.h
$(pp)/check_convex/check_convex.o: 	$(pp)/const.h

src/tga/TgaImage.o: src/tga/TgaImage.h
src/geometry/draw.o: src/tga/TgaImage.h src/geometry/draw.h
src/geometry/polygon.o: src/geometry/line.h src/geometry/polygon.h
src/geometry/line.o: src/geometry/line.h

# Default
simple: $(objects) $(pp)/simple/simple.o
	g++ $(pp)/simple/simple.o -o bin/simple $(objects) $(CPPFLAGS)

.PHONY: check_convex
check_convex: $(objects) $(pp)/check_convex/check_convex.o
	g++ -o bin/check_convex $(pp)/check_convex/check_convex.o $(objects) $(CPPFLAGS)

.PHONY: convex
convex: $(objects) $(pp)/convex/convex.o
	g++ -o bin/convex $(pp)/convex/convex.o $(objects) $(CPPFLAGS)

.PHONY: clean
clean:
	rm $(objects) $(pp)/*/*.o
