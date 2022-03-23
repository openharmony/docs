# Standard Libraries Supported by Native APIs



## Introduction



**Table 1** Standard libraries supported by OpenHarmony

| Library     | Description                                                        |
| :-------- | :----------------------------------------------------------- |
| C standard library  | C11 standard library implemented by [libc, libm, and libdl](https://en.cppreference.com/w/c/header).      |
| C++ standard library ([libc++](https://libcxx.llvm.org/))| An implementation of the C++ standard library.  |
| [OpenSL ES](https://www.khronos.org/registry/OpenSL-ES/)| An embedded cross-platform audio processing library.|
| [zlib](https://zlib.net/)     | A general data compression library implemented in C/C++.|

## C Standard Library



C11 standard library implemented by [libc, libm, and libdl](https://en.cppreference.com/w/c/header).

libc: provides thread-related functions and a majority of standard functions.

libm: provides basic mathematical functions.

libdl: provides functions related to dynamic linking, such as dlopen.

**Version**

1.2.0

**Capabilities**

C standard library includes a set of header files in accordance with standard C and provides common functions, such as the functions related to input/output (I/O) and string control.

**<font size=5>musl</font>**

[Native API Symbols Not Exported](musl-peculiar-symbol.md)

## C++ Standard Library



[libc++](https://libcxx.llvm.org/) is an implementation of the C++ standard library.

**Version**

10.0.1

**Capabilities**

The C++11 and C++14 standards are supported, and the C++17 and C++20 standards are on the way.

## OpenSL ES



[OpenSL ES](https://www.khronos.org/registry/OpenSL-ES/) is an embedded cross-platform audio processing library.



## zlib



[zlib](https://zlib.net/) is a general data compression library implemented in C/C++.
