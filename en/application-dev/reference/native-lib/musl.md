# musl libc

## Overview
The C standard library (libc) provides standard header files and common library implementations (such as input/output processing and string handling) in C language programming.

OpenHarmony uses musl as the libc. musl is a lightweight, fast, simple, and free open-source libc. For details, see [musl libc Reference Manual](http://musl.libc.org/manual.html).

For details about the differences between musl and glibc, see [Functional differences from glibc](https://wiki.musl-libc.org/functional-differences-from-glibc.html).

## libc Components

C11 is implemented by [libc, libm, and libdl](https://en.cppreference.com/w/c/header). 

- libc: provides thread-related interfaces and a majority of standard interfaces.

- libm: provides mathematical library interfaces. Currently, OpenHarmony provides a link to libm, and the interfaces are defined in libc.

- libdl: provides dynamic linker interfaces such as dlopen. Currently, OpenHarmony provides a link to libdl, and the interfaces are defined in libc.


## musl Version

- 1.2.0
- 1.2.3 from OpenHarmony 4.0
- 1.2.5 from OpenHarmony 5.0

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

#### musl.log
Set **musl.log.enable** to **true** to enable printing of musl debug logs. You need to enable musl.log before printing other logs.
```
param set musl.log.enable true
```

#### Loader Logging
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

## Character Encoding Formats Supported by iconv

The following lists the character encoding formats and aliases supported by musl.
> **NOTE**
>
> The character conversion can be successful only when the source character encoding format is correct and the target character encoding format is supported.
> musl does not support the following target encoding formats: gb18030, gbk, gb2312, big5, and euckr.

| Encoding Format | Alias                  | Supported by musl|
|:--      |    :--                   |  :--:  |
|utf8     |                          |  Yes  |
|wchart   |                          |  Yes  |
|ucs2be   |                          |  Yes  |
|ucs2le   |                          |  Yes  |
|utf16be  |                          |  Yes  |
|utf16le  |                          |  Yes  |
|ucs4be   |utf32be                   |  Yes  |
|ucs4le   |utf32le                   |  Yes  |
|ascii    |usascii, iso646, iso646us |  Yes  |
|utf16    |                          |  Yes  |
|ucs4     |utf32                     |  Yes  |
|ucs2     |                          |  Yes  |
|eucjp    |                          |  Yes  |
|shiftjis |sjis, cp932               |  Yes  |
|iso2022jp|                          |  Yes  |
|gb18030  |                          |  Yes  |
|gbk      |                          |  Yes  |
|gb2312   |                          |  Yes  |
|big5     |bigfive, cp950, big5hkscs |  Yes  |
|euckr    |ksc5601, ksx1001, cp949   |  Yes  |
|iso88591 |latin1                    |  Yes  |
|iso88592 |                          |  Yes  |
|iso88593 |                          |  Yes  |
|iso88594 |                          |  Yes  |
|iso88595 |                          |  Yes  |
|iso88596 |                          |  Yes  |
|iso88597 |                          |  Yes  |
|iso88598 |                          |  Yes  |
|iso88599 |                          |  Yes  |
|iso885910|                          |  Yes  |
|iso885911|tis620                    |  Yes  |
|iso885913|                          |  Yes  |
|iso885914|                          |  Yes  |
|iso885915|latin9                    |  Yes  |
|iso885916|                          |  Yes  |
|cp1250   |windows1250               |  Yes  |
|cp1251   |windows1251               |  Yes  |
|cp1252   |windows1252               |  Yes  |
|cp1253   |windows1253               |  Yes  |
|cp1254   |windows1254               |  Yes  |
|cp1255   |windows1255               |  Yes  |
|cp1256   |windows1256               |  Yes  |
|cp1257   |windows1257               |  Yes  |
|cp1258   |windows1258               |  Yes  |
|koi8r    |                          |  Yes  |
|koi8u    |                          |  Yes  |
|cp437    |                          |  Yes  |
|cp850    |                          |  Yes  |
|cp866    |                          |  Yes  |
|cp1047   |ibm1047                   |  Yes  |

## musl APIs Not Supported

[Native API Symbols Not Exported](musl-peculiar-symbol.md)

[Restricted musl libc APIs](guidance-on-ndk-libc-interfaces-affected-by-permissions.md)


<!--no_check-->
