# libc

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

From OpenHarmony 4.0, musl 1.2.3 is supported.

## Supported Capabilities
OpenHarmony provides header files and library interfaces that are compatible (not fully compatible) with C99, C11, and POSIX, and supports Armv7-A, Arm64, and x86_64 architectures.

To better adapt to the basic features of OpenHarmony devices, such as high performance, low memory, high security, lightweight, and multi-form support, OpenHarmony has optimized the musl library and removed the interfaces that are not applicable to embedded devices.

### New Capabilities
1. The dynamic loader supports isolation by namespace. The dynamic libraries that can be loaded by **dlopen()** are restricted by the system namespace. For example, the system dynamic libraries cannot be opened.
2. **dlclose()** can be used to unload a dynamic library. This capability is not supported by musl.
3. The symbol-versioning is supported.
4. **dlopen()** can directly load uncompressed files in a .zip package.

### Debugging Capabilities
The libc provides dynamic settings of the basic log functions (disabled by default) for developers to view internal exceptions of the libc. You can set the **param** to enable or disable the log functions, without recompiling the libc. However, you are advised not to use the log functions in official release versions because they affect the running performance.

#### 1. musl.log
Set **musl.log.enable** to **true** to enable the **musl.log** function. To print other logs, you need to enable this function first.
```
setparam musl.log.enable true
```

#### 2. Loader log function
The loader starts applications and invokes dlopen() and dlclose() in libc. To view exceptions in the dynamic loading process, enable the loader log function.
* Enable the loader log of all applications (exercise caution when using this function).
```
param set musl.log.ld.app true
```
* Enable the loader log of the specified application. {app_name} specifies the target application.
```
param set musl.log.ld.all false
param set musl.log.ld.app.{app_name} true
```
* Enable the loader log of all applications except the specified application.
```
param set musl.log.ld.all true
param set musl.log.ld.app.{app_name} false
```

## Interfaces Not Supported by musl
[Native API Symbols Not Exported](musl-peculiar-symbol.md)
[Native API Symbols That May Fail to Be Invoked Due to Permission Control](musl-permission-control-symbol.md)

