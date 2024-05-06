# musl libc

## Overview
The C standard library (libc) provides standard header files and common library implementations (such as input/output processing and string handling) in C language programming.

OpenHarmony uses musl as the libc. musl is a lightweight, fast, simple, and free open-source libc. For details, see [musl libc Reference Manual](http://musl.libc.org/manual.html).

For details about the differences between musl and glibc, see [Functional differences from glibc](https://wiki.musl-libc.org/functional-differences-from-glibc.html).

## libc Components

C11 is implemented by [libc, libm, and libdl](https://en.cppreference.com/w/c/header). 

libc: provides thread-related interfaces and a majority of standard interfaces.

libm: provides mathematical library interfaces. Currently, OpenHarmony provides a link to libm, and the interfaces are defined in libc.

libdl: provides dynamic linker interfaces such as dlopen. Currently, OpenHarmony provides a link to libdl, and the interfaces are defined in libc.

## musl Version

1.2.0

OpenHarmony 4.0 supports musl 1.2.3.

## Supported Capabilities
OpenHarmony provides header files and library interfaces that are compatible (not fully compatible) with C99, C11, and POSIX, and supports Armv7-A, Arm64, and x86_64 architectures.

To better adapt to the basic features of OpenHarmony devices, such as high performance, low memory, high security, lightweight, and multi-form support, OpenHarmony has optimized the musl library and removed the interfaces that are not applicable to embedded devices.

### New Capabilities
1. The dynamic loader supports isolation by namespace. The dynamic libraries that can be loaded by **dlopen()** are restricted by the system namespace. For example, the system dynamic libraries cannot be opened.
2. **dlclose()** can be used to unload a dynamic library. This capability is not supported by musl.
3. The symbol-versioning is supported.
4. **dlopen()** can directly load uncompressed files in a .zip package.

### Debugging Capabilities
The libc provides dynamic enabling of debug logging (disabled by default). The debug logs help you learn about exceptions of the libc. With this function, you only need to set **param**, which eliminates the need for rebuilding the libc. However, you are advised not to enable debug logging in official versions because it affects the running performance.

#### 1. musl.log
Set **musl.log.enable** to **true** to enable printing of musl debug logs. You need to enable musl.log before printing other logs.
```
param set musl.log.enable true
```

#### 2. Loader logging
The loader starts applications and invokes **dlopen** and **dlclose** in the libc. To view exceptions during the loading process, you need to enable the loader logging function. The following describes common operations.
* Enable the loader logging for all applications. Exercise caution when enabling this function because a large number of logs will be generated.
```
param set musl.log.ld.app true
```
* Enable the loader logging for an application specified by {app_name}.
```
param set musl.log.ld.all false
param set musl.log.ld.app.{app_name} true
```
* Enable the loader logging for all applications except the specified application.
```
param set musl.log.ld.all true
param set musl.log.ld.app.{app_name} false
```

## musl APIs Not Supported 

[Native API Symbols Not Exported](musl-peculiar-symbol.md)

[Restricted musl libc APIs](guidance-on-ndk-libc-interfaces-affected-by-permissions.md)



