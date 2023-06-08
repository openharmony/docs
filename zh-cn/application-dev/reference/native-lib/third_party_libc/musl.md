# libc标准库

## 简介
C标准函数库在C语言程序设计中，提供符合标准的头文件，以及常用的库函数实现（如I/O输入输出和字符串控制）。

OpenHarmony采用musl作为C标准库，musl库是一个轻量，快速，简单，免费的开源libc库，详细介绍参考[musl官方参考手册](http://musl.libc.org/manual.html)。

musl与glibc的差异点请参考[musl与glibc功能对比](https://wiki.musl-libc.org/functional-differences-from-glibc.html)。

## 标准C库组件介绍

[libc、libm、libdl](https://zh.cppreference.com/w/c/header)组合实现C11标准C库。

libc：包含线程相关接口，以及大部分标准接口。

libm：数学库函数接口，当前在OpenHarmony中是一个链接，实际都在libc中定义。

libdl：dlopen等动态链接器接口，当前在OpenHarmony中是一个链接，实际都在libc中定义。

## musl版本号

1.2.0

从OpenHarmony4.0开始，版本升级到1.2.3

## 支持的能力
提供兼容C99,C11,POSIX标准的头文件，以及库函数接口，但不是完全兼容；支持armv7a，arm64, x86_64三种架构的支持；

为了更好的适配OpenHarmony设备的高性能，低内存，高安全，轻量化，支持多种形态设备的基本特征；在musl开源库的基础上进行了优化，增强，对不适用嵌入式设备的接口进行了裁剪。

### 新增能力
1. 动态加载器支持命名空间隔离能力，应用可以dlopen加载的动态库受系统命名空间限制（比如，无法打开系统侧动态库）。
2. 支持dlclose真实卸载动态库能力，musl的开源版本不支持。
3. 支持symbol-versioning功能。
4. dlopen支持直接加载zip包中未压缩的文件。

### 调试能力
提供了基础的log调试能力，方便开发者需要查看libc库内部异常。维测log的提供动态开关功能，不需要重新编译。在正式发布版本中，不建议使用，会影响运行性能。

#### 1. musl.log功能
设置musl.log.enable属性为true，打开musl的log打印。打印其他日志，需要先打开此开关。
```
setparam musl.log.enable true
```

#### 2. 加载器log功能
调试程序引导，dlopen，dlclose等加载器接口，需要打开加载器log。用法如下：
* 使能全部应用的加载器log，谨慎使用
```
setparam musl.log.ld.app true
```
* 使能指定应用的加载器log，{app_name}需要替换成真实需要打印log的应用名字
```
setparam musl.log.ld.all false
setparam musl.log.ld.app.{app_name} true
```
* 打印全部应用除指定名字应用外的加载器日志
```
setparam musl.log.ld.all true
setparam musl.log.ld.app.{app_name} false
```

## musl不支持接口列表
[native api中没有导出的符号列表](musl-peculiar-symbol.md)
[native api由于权限管控可能调用失败的符号列表](musl-permission-control-symbol.md)


<!--no_check-->