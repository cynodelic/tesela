# Examples
Here are provided some examples of Tesela's usage. For compiling them, use the `make` command.

## Tips
- Write `#define CYNODELIC_TESELA_VERBOSE` for showing (in console) some of the methods and functions.
- Write `#define CYNODELIC_TESELA_DISABLE_OPENMP` for avoiding Tesela's use of OpenMP (if it exists).
- Use `#define CYNODELIC_TESELA_DEFAULT_JPEG_QUALITY [0-100]` for setting the quality of the JPEG output image(s) to write.

These definitions must be written before including the library's header.
