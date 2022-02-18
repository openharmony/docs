# 内核常见问题<a name="ZH-CN_TOPIC_0000001169850498"></a>

-   [基础内核](#section263912372168)
    -   [LiteOS-A和LiteOS-M内核对外API的差异](#section447571122918)
    -   [如何分析线程栈溢出](#section8623141711293)

-   [文件系统](#section098519592162)
    -   [Hi3516开源板以写的模式打开同一个文件失败（LiteOS-A）](#section517972255311)
    -   [LiteOS内核已支持哪些硬件平台](#section868413518533)
    -   [LiteOS内核已支持哪几款芯片架构](#section1131661465417)

-   [三方组件](#section971818231178)
    -   [OpenHarmony已支持哪些三方组件](#section74138185411)
    -   [在OpenHarmony上使用OpenSSL，出现秘钥长度校验不正确](#section10564614135516)
    -   [setsockopt是否支持SO\_RCVBUF和SO\_SNDBUF选项](#section2093373215556)

-   [编译链接](#section10955302179)
    -   [Arm Linux开发的应用程序，OpenHarmony如何在LiteOS-A上运行](#section1164175713557)
    -   [OpenHarmony在什么系统下编译，使用什么编译器](#section132287223567)
    -   [LiteOS-M上使用单独编译成静态库的三方组件，出现三方组件中的全局变量值不正确，或调用三方组件的函数后系统卡死](#section15189154225619)
    -   [LiteOS-A生成目标可执行文件时，提示 use  VFP register arguments，xxx.o does not](#section193571012578)
    -   [clock\_gettime接口获取的时间打印不对](#section8973152015717)


## 基础内核<a name="section263912372168"></a>

### LiteOS-A和LiteOS-M内核对外API的差异<a name="section447571122918"></a>

基础内核API存在差异，但是LiteOS-A提供标准POSIX接口，LiteOS-M提供标准POSIX和CMSIS接口。如果要支持跨平台，三方适配建议使用POSIX等标准接口。

### 如何分析线程栈溢出<a name="section8623141711293"></a>

**问题现象**

系统异常，提示CURRENT task xxx stack overflow！

**解决措施**

1.  创建xxx线程的时候成倍加大栈空间，多次尝试如果问题不复现，则说明任务栈不够，需要调整；
2.  如果成倍加大线程栈，问题依旧复现，则排查xxx线程中是否定义超大数组，或者流程是否存在递归调用；
3.  确认无前述问题，则需要排查是否存在踩内存的情况。

## 文件系统<a name="section098519592162"></a>

### Hi3516开源板以写的模式打开同一个文件失败（LiteOS-A）<a name="section517972255311"></a>

Hi3516开源板使用FAT文件系统，不允许该操作。

### LiteOS内核已支持哪些硬件平台<a name="section868413518533"></a>

开源版本LiteOS-A已支持Hi3516/Hi3518开发板；LiteOS-M已支持Hi3861开发板、STM32F103、野火挑战者STM32F429IGTb、Nucleo\_f767zi等，详细查看kernel/liteos\_m目录下的README\_zh.md文件。

### LiteOS内核已支持哪几款芯片架构<a name="section1131661465417"></a>

LiteOS-M已支持risc-v、Cortex-m3\\m4\\m7\\m33、arm9、c-sky、xtensa；LiteOS-A已支持armv7-a，待支持armv8-a，请关注开源社区更新。

## 三方组件<a name="section971818231178"></a>

### OpenHarmony已支持哪些三方组件<a name="section74138185411"></a>

已提供mbedtls、lwip等开源组件和三方库，可以直接使用；另外提供标准的POSIX接口，可以自行适配。

### 在OpenHarmony上使用OpenSSL，出现秘钥长度校验不正确<a name="section10564614135516"></a>

OpenSSL编译选项中要注意架构类型（ARM，X86等）和系统位数（32、64位）是否选择正确。

### setsockopt是否支持SO\_RCVBUF和SO\_SNDBUF选项<a name="section2093373215556"></a>

不支持。

## 编译链接<a name="section10955302179"></a>

### Arm Linux开发的应用程序，OpenHarmony如何在LiteOS-A上运行<a name="section1164175713557"></a>

需要用开源版本提供的交叉编译器重新编译应用程序，才可以运行。

### OpenHarmony在什么系统下编译，使用什么编译器<a name="section132287223567"></a>

LiteOS-A在linux环境进行编译，使用LLVM编译器；LiteOS-M在Linux或Windows环境进行编译，使用IAR、Keil、GCC等编译工具。

### LiteOS-M上使用单独编译成静态库的三方组件，出现三方组件中的全局变量值不正确，或调用三方组件的函数后系统卡死<a name="section15189154225619"></a>

检查三方组件编译选项中是否有-fPIE -fpie -fPIC -fpic等地址无关编译选项，如果有，则去掉，重新编译成库使用。

### LiteOS-A生成目标可执行文件时，提示 use  VFP register arguments，xxx.o does not<a name="section193571012578"></a>

请确认xxx.o编译时是否添加-mfloat-abi=xxx -mcpu=xxx -mfpu=xxx编译选项，若没有，则需要添加。

### clock\_gettime接口获取的时间打印不对<a name="section8973152015717"></a>

struct timespec结构中tv\_sec为time\_t，而time\_t为long long类型，打印控制符为%lld，请确认实际打印控制符是否正确。

