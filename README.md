# FRACTAL
Relatively simple example of the mandelbrot set, using the formula z = z^2+1, outputting to a ppx.
An excuse to demonstrate pthreading knowledge.

### Usage
As of now, image dimensions and other assorted settings are found inside the plane.h file as macro constants.
It will generate an image in the ppm image format labelled "out.ppm" which can be viewed with a regular image viewer.

### Roadmap
- [ ] Generate a fractal in ppm
- [ ] Add command line options
- [ ] Add pthreads support
- [ ] Optimizaiton

### Current issues
- Fractal is not generating properly, only seeing a circle on the plane
