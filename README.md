# FRACTAL
Relatively simple example of the mandelbrot set, using the formula z = z^2+z0 (where z0 is 
the position of the pixel), outputting to a ppx. An excuse to demonstrate pthreading knowledge.

### Usage
As of now, image dimensions and other assorted settings are found inside the plane.h file as macro constants.
It will generate an image in the ppm image format labelled "out.ppm" which can be viewed with a regular image viewer.

### Roadmap
- [x] Generate a fractal in ppm
- [ ] Add pthreads support
- [ ] Optimizaiton

### Issues
- pthreading, of course, didn't work first try. Seems to be an indexing error?
