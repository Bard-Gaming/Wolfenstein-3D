# Carpet Lib

## Project Description
Carpet lib is a 3D game engine written in C
using the CSFML library and no other external
libraries.

## Compile Instructions
To compile the standard (optimized) version of Carpet lib,
simply run make:

```bash
make
```

To compile a version with debug symbols enabled,
use the ``debug`` rule:

```bash
make debug
```

To compile a version with the address sanitizer
enabled, run with the ``sanitize`` rule:

```bash
make sanitize
```
_Note: this should only be done for testing purposes._

When you're done, you can use the ``clean`` rule
to delete any temporary files, or the ``fclean``
rule to delete all built files.
