# Native Standard Libraries Supported by OpenHarmony

## Overview

**Table 1** Standard libraries supported by OpenHarmony

| Library     | Description                                                        |
| :-------- | :----------------------------------------------------------- |
| C standard library  | C11 standard library implemented by [libc, libm, and libdl](https://en.cppreference.com/w/c/header).      |
| C++ standard library ([libc++](https://libcxx.llvm.org/))| An implementation of the C++ standard library.  |
| Open Sound Library for Embedded Systems ([OpenSL ES](https://www.khronos.org/registry/OpenSL-ES/))| An embedded, cross-platform audio processing library.|
| [zlib](https://zlib.net/)    | A general data compression library implemented in C/C++.|
| [EGL](https://www.khronos.org/egl/)  | A standard software interface between rendering APIs and the underlying native window system.|
| Open Graphics Library for Embedded Systems ([OpenGL ES](https://www.khronos.org/opengles/))| A cross-platform software interface for rendering 3D graphics on embedded and mobile systems.|

## C Standard Library

The C standard library is a C11 standard library implemented by:

- libc: provides thread-related functions and a majority of standard functions.


- libm: provides basic mathematical functions.


- libdl: provides functions related to dynamic linking, such as **dlopen**.


**Version**

1.2.0

**Capabilities**

C standard library includes a set of header files in accordance with standard C and provides common functions, such as the functions related to input/output (I/O) and string control.

**musl**

[Native API Symbols Not Exported](musl-peculiar-symbol.md)

## libc++

[libc++](https://libcxx.llvm.org/) is an implementation of the C++ standard library.

**Version**

10.0.1

**Capabilities**

The C++11 and C++14 standards are supported, and the C++17 and C++20 standards are on the way.

## OpenSL ES

[OpenGL ES](https://www.khronos.org/opengles/) is an embedded, cross-platform audio processing library.

**Capabilities**

[OpenSL ES Interfaces Supported by Native APIs](../third_party_opensles/opensles.md)

## zlib

[zlib](https://zlib.net/) is a general data compression library implemented in C/C++.

## EGL

EGL is an interface between Khronos rendering APIs (such as OpenGL ES and OpenVG) and the underlying native window system. OpenHarmony supports EGL.

**Symbols Exported from the Standard Library**

[EGL Symbols Exported from Native APIs](../third_party_opengl/egl-symbol.md)

## OpenGL ES

OpenGL is a cross-platform software interface for 3D graphics processing. [OpenGL ES](https://www.khronos.org/opengles/) is a OpenGL specification for embedded devices. OpenHarmony supports OpenGL ES 3.0.

**Capabilities**

OpenGL ES 3.0

**Symbols Exported from the Standard Library**

[OpenGL ES 3.0 Symbols Exported from Native APIs](../third_party_opengl/openglesv3-symbol.md)
