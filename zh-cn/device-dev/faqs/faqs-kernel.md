# 内核常见问题


## 基础内核


### LiteOS-A和LiteOS-M内核对外API的差异

基础内核API存在差异，但是LiteOS-A提供标准POSIX接口，LiteOS-M提供标准POSIX和CMSIS接口。如果要支持跨平台，三方适配建议使用POSIX等标准接口。


### 如何分析线程栈溢出

**问题现象**

系统异常，提示CURRENT task xxx stack overflow！

**解决措施**

1. 创建xxx线程的时候成倍加大栈空间，多次尝试如果问题不复现，则说明任务栈不够，需要调整；

2. 如果成倍加大线程栈，问题依旧复现，则排查xxx线程中是否定义超大数组，或者流程是否存在递归调用；

3. 确认无前述问题，则需要排查是否存在踩内存的情况。


## 文件系统


### Hi3516开源板以写的模式打开同一个文件失败（LiteOS-A）

Hi3516开源板使用FAT文件系统，不允许该操作。


### LiteOS内核已支持哪些硬件平台

开源版本LiteOS-A已支持Hi3516/Hi3518开发板；LiteOS-M已支持Hi3861开发板、STM32F103、野火挑战者STM32F429IGTb、Nucleo_f767zi等，详细查看kernel/liteos_m目录下的README_zh.md文件。


### LiteOS内核已支持哪几款芯片架构

LiteOS-M已支持risc-v、Cortex-m3\m4\m7\m33、arm9，待支持c-sky、xtensa；LiteOS-A已支持armv7-a，待支持armv8-a，请关注开源社区更新。


## 三方组件


### 已支持哪些三方组件

已提供mbedtls、lwip等开源组件和三方库，可以直接使用；另外提供标准的POSIX接口，可以自行适配。


### 在上使用OpenSSL，出现秘钥长度校验不正确

OpenSSL编译选项中要注意架构类型（ARM，X86等）和系统位数（32、64位）是否选择正确。


### setsockopt是否支持SO_RCVBUF和SO_SNDBUF选项

不支持。


## 编译链接


### Arm Linux开发的应用程序，如何在LiteOS-A上运行

需要用开源版本提供的交叉编译器重新编译应用程序，才可以运行。


### 在什么系统下编译，使用什么编译器

LiteOS-A在linux环境进行编译，使用LLVM编译器；LiteOS-M在Linux或Windows环境进行编译，使用IAR、Keil、GCC等编译工具。


### LiteOS-M上使用单独编译成静态库的三方组件，出现三方组件中的全局变量值不正确，或调用三方组件的函数后系统卡死

检查三方组件编译选项中是否有-fPIE -fpie -fPIC -fpic等地址无关编译选项，如果有，则去掉，重新编译成库使用。


### LiteOS-A生成目标可执行文件时，提示 use  VFP register arguments，xxx.o does not

请确认xxx.o编译时是否添加-mfloat-abi=xxx -mcpu=xxx -mfpu=xxx编译选项，若没有，则需要添加。


### clock_gettime接口获取的时间打印不对

struct timespec结构中tv_sec为time_t，而time_t为long long类型，打印控制符为%lld，请确认实际打印控制符是否正确。
