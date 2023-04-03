# Native API中支持的标准库

## 简介

**表1** OpenHarmony支持的标准库

| 名称      | 简介                                                         |
| :-------- | :----------------------------------------------------------- |
| 标准C库   | [libc、libm、libdl](https://zh.cppreference.com/w/c/header)组合实现C11标准C库。      |
| 标准C++库 | [libc++](https://libcxx.llvm.org/) 是C++标准库的一种实现。   |
| OpenSL ES | [OpenSL ES](https://www.khronos.org/registry/OpenSL-ES/)是一个嵌入式跨平台的音频处理库。 |
| zlib      | [Zlib](https://zlib.net/)是基于C/C++语言实现的一个通用的数据压缩库。 |
| EGL   | [EGL](https://www.khronos.org/egl/)是渲染API与底层原生窗口系统之间的一种标准的软件接口。 |
| OpenGL ES | [OpenGL ES](https://www.khronos.org/opengles/)是一个嵌入式跨平台的为 3D 图形处理硬件指定标准的软件接口。 |

## 标准C库

[libc、libm、libdl](https://zh.cppreference.com/w/c/header)组合实现C11标准C库。

libc：包含线程相关接口，以及大部分标准接口。

libm：数学库函数接口。

libdl：dlopen等动态链接器接口。

**版本**

1.2.0

**支持的能力**

C标准函数库是在C语言程序设计中，所有符合标准的头文件的集合，以及常用的函数库实现程序（如I/O输入输出和字符串控制）。

**musl**

[native api中没有导出的符号列表](musl-peculiar-symbol.md)

## 标准C++库

[libc++](https://libcxx.llvm.org/)是C++标准库的一种实现。

**版本**

10.0.1

**支持的能力**

C++11、C++14标准已完全支持，C++17和C++20标准正在完善。

## OpenSL ES

[OpenSL ES](https://www.khronos.org/registry/OpenSL-ES/)是一个嵌入式跨平台的音频处理库。

**支持的能力**

[Native api中支持的OpenSL ES接口列表](../third_party_opensles/opensles.md)

## zlib

[Zlib](https://zlib.net/)是基于C/C++语言实现的一个通用的数据压缩库。

## EGL

EGL 是Khronos渲染API (如OpenGL ES 或 OpenVG) 与底层原生窗口系统之间的接口。OpenHarmony 现已支持 EGL。

**标准库中导出的符号列表**

[native api中导出的EGL符号列表](../third_party_opengl/egl-symbol.md)

## OpenGL ES

OpenGL 是一种跨平台的图形 API，用于为 3D 图形处理硬件指定标准的软件接口。[OpenGL ES](https://www.khronos.org/opengles/) 是 OpenGL 规范的一种形式，适用于嵌入式设备。OpenHarmony 现已支持 OpenGL ES 3.0。

**支持的能力**

OpenGL ES 3.0

**标准库中导出的符号列表**

[native api中导出的OpenGL ES 3.0符号列表](../third_party_opengl/openglesv3-symbol.md)