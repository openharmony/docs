# Native API中支持的标准库

## 简介
OHOS采用musl作为C标准库，musl库是一个轻量，快速，简单，免费的开源库。


## 标准C库

[libc、libm、libdl](https://zh.cppreference.com/w/c/header)组合实现C11标准C库。

libc：包含线程相关接口，以及大部分标准接口。

libm：数学库函数接口，当前在OHOS中是一个链接，实际都在libc中定义。

libdl：dlopen等动态链接器接口，当前在OHOS中是一个链接，实际都在libc中定义。

**版本**

1.2.0

从OHOS4.0开始，版本升级到1.2.3

**支持的能力**

C标准函数库是在C语言程序设计中，所有符合标准的头文件的集合，以及常用的函数库实现程序（如I/O输入输出和字符串控制）。

**musl**

[native api中没有导出的符号列表](musl-peculiar-symbol.md)

[native api由于权限管控可能调用失败的符号列表](musl-permission-control-symbol.md)


<!--no_check-->