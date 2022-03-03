## Plotters

The collection of plotters that draw tga images. Every plotter can be supplied
with an array of 2d points and draw an image using them.  
For example **simple** plotter will draw lines connecting those points. And
**convex** plotter will perform the Graham Scan and draw the convex hull.

## Use
- Compile via Makefile specifying the name of the wanted plotter
```
make convex
```
- Run supplying points via cmd arguments
```
bin/convex 100 100 200 100 100 200

## List of plotters

- [simple](src/plotters/simple/README.md)
- [convex](src/plotters/convex/README.md)
- [check_convex](src/plotters/check_convex/README.md)
