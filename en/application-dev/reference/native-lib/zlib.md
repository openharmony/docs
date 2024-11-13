# zlib

## Introduction

[zlib](https://zlib.net/) is a general data compression library implemented in C/C++.

## Supported Capabilities

The zlib library provides in-momery data compression and decompression. By employing the deflate algorithm, it is possible to select from various compression levels to optimize the compression performance for a range of data types. It also provides control over processor and memory usage. If the buffer is large enough, the compression process can be completed in a single step. In cases where the buffer is not large enough, the compression can be completed through multiple iterations of calling the compression interfaces.

By default, the zlib interfaces use the zlib format ([RFC1950](https://www.rfc-editor.org/rfc/rfc1950)). In addition, the zlib library provides interfaces that start with gz to read and write gzip files ([RFC1952](https://www.rfc-editor.org/rfc/rfc1952)). The zlib format is designed for efficient use in memory and communication channels, ensuring both compactness and swift performance. The gzip format is designed for the compression of individual files. Its header is larger than that of zlib in order to maintain directory information. gzip uses a check method that, while different, is comparatively slower than the one used by zlib.

The decoder within the zlib library checks the integrity of compressed data. Therefore, the library will not crash even in the case of corrupted input.

## Introducing zlib

To use zlib capabilities, include the following header file:

```c
#include <zlib.h>
```

Add the following dynamic link library to **CMakeLists.txt**:

```
libz.so
```

## Supported APIs

For details, see [zlib](https://www.zlib.net/manual.html).
