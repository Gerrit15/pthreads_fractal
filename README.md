# FRACTAL
Relatively simple example of the mandelbrot set, using the formula z = z^2+z0 (where z0 is 
the position of the pixel), outputting to a ppx. An excuse to demonstrate pthreading knowledge.

### Usage
As of now, image dimensions and other assorted settings are found inside the plane.h file as macro constants.
It will generate an image in the ppm image format labelled "out.ppm" which can be viewed with a regular image viewer.

### Roadmap
- [x] Generate a fractal in ppm
- [x] Add pthreads support
- [ ] Optimizaiton
- [ ] Command line arguments

### Note on optimization scope
There are many, many ways to optimize this. Such as not using C++, or only rendering the top half of the fractal and mirroring.
However, the focus of this project is on threading, so any optimizations will be directed there, such as thread pooling and cache locality.
