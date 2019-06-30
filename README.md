# Tesela
A header-only C++14 library for image input/output and processing.

## Requirements

- A C++14-compatible compiler
- OpenMP (optional)

### For input/output
- [libjpeg](http://libjpeg.sourceforge.net/)
- [zlib](https://zlib.net/)
- [libpng](http://www.libpng.org/pub/png/libpng.html)
- [libtiff](http://www.libtiff.org/)

## Building and installation

This library is header-only, so no building is necessary for installing it. However, the examples, unit tests and documentation can be built. This is done with [CMake](http://cmake.org/).

Run `mkdir build && cd build && cmake [options] .. && make` (or your equivalent) for building.

### Setting the paths for the image libraries

Use `-DPATH_TO_JPEG_LIBRARY=path/to/your/libjpeg`, `-DPATH_TO_PNG_LIBRARY=path/to/your/libpng` and `-DPATH_TO_TIFF_LIBRARY=path/to/your/libtiff` to set the paths to such libraries, if avaliable.

The `include` and `lib` directories are assumed to be contained into the directories corresponding to said libraries.

### Allowing input/output

This is done using the `-DCYNODELIC_TESELA_ALLOW_IO=1` command, assuming the paths to the image libraries are set.

### Building the examples

Use the `-DCYNODELIC_TESELA_BUILD_EXAMPLES=1` option for building the examples.

### Building and running the tests

Use the `-DCYNODELIC_TESELA_BUILD_TEST=1` option for building the unit tests. Also, the I/O related test program is built if the I/O option is enabled.

Run the tests using `make test`.

### Building the documentation

The documentation is generated with [Doxygen](http://www.doxygen.nl/), if avaliable. Use the `-DCYNODELIC_TESELA_BUILD_DOC=1` for allowing its generation.

### Installing the library

The installation path is set using the `-DCMAKE_INSTALL_PREFIX=path/to/your/libraries` option.
Run `make install` to install the library, as well as its documentation.

The documentation will be installed in `path/to/your/libraries/doc/cynodelic/tesela`.

## To-do

- Add more test cases for the filters, if possible
- Add other filters (e.g. convolution matrix)
- Add a bicubic scaling algorithm
- Rotation of images

## License
This library is licensed under the Boost Software License.
