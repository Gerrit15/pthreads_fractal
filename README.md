# FRACTAL
Relatively simple example of the mandelbrot set, using the formula z = z^2+z0 (where z0 is 
the position of the pixel), outputting to a ppx. An excuse to demonstrate pthreading knowledge.

### Usage
As of now, image dimensions and other assorted settings are found inside the plane.h file as macro constants.
It will generate an image in the ppm image format labelled "out.ppm" which can be viewed with a regular image viewer.
Command line arguments: 
- -s, the scale. defaults to 32. Dimensions of the image will be 30\*scale x 23\*scale
- -t, the number of threads. Defaults to 5
- -o, the outfile path. The name of the image to be generated. Defaults to "out.ppm"
- -i, the maximum iteration depth. How many 'recursions' can we do before we call it. Defaults to 100
- -h, displays help


### Roadmap
- [x] Generate a fractal in ppm
- [x] Add pthreads support
- [x] Optimizaiton
- [x] Command line arguments
- [x] Coloring
- [ ] Anything but png
- [ ] More optimization

### Note on optimization scope
There are many, many ways to optimize this. Such as not using C++, or only rendering the top half of the fractal and mirroring.
However, the focus of this project is on threading, so any optimizations will be directed there, such as thread pooling and cache locality.
