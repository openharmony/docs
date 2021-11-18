# Kernel<a name="EN-US_TOPIC_0000001169850498"></a>

-   [Basic Kernel](#section263912372168)
    -   [What are the differences between APIs provided by LiteOS-A and LiteOS-M?](#section447571122918)
    -   [How do I analyze thread stack overflow?](#section8623141711293)

-   [File System](#section098519592162)
    -   [What should I do when the Hi3516 board fails to open the same file in write mode \(LiteOS-A\)?](#section517972255311)
    -   [What hardware platforms are supported by the LiteOS kernel?](#section868413518533)
    -   [What chip architectures are supported by the LiteOS kernel?](#section1131661465417)

-   [Third-party Components](#section971818231178)
    -   [What third-party components are supported by OpenHarmony?](#section74138185411)
    -   [What should I do if the key length verification fails when OpenSSL is used on OpenHarmony?](#section10564614135516)
    -   [Does setsockopt support SO\_RCVBUF and SO\_SNDBUF?](#section2093373215556)

-   [Compilation and Linking](#section10955302179)
    -   [How do I run an application developed by ARM Linux on LiteOS-A?](#section1164175713557)
    -   [What system is used for OpenHarmony compilation? What compiler is used?](#section132287223567)
    -   [For a third-party component that is independently compiled into a static library and used on LiteOS-M, what should I do when the component's global variable value is incorrect or the system is suspended after the component's function is called?](#section15189154225619)
    -   [What should I do if the message "use VFP register arguments, xxx.o does not" is displayed when LiteOS-A generates a target executable file?](#section193571012578)
    -   [What should I do when calling clock\_gettime obtains an incorrect time?](#section8973152015717)


## Basic Kernel<a name="section263912372168"></a>

### What are the differences between APIs provided by LiteOS-A and LiteOS-M?<a name="section447571122918"></a>

Basic kernel APIs are different. LiteOS-A provides the standard Portable Operating System Interface \(POSIX\), and LiteOS-M provides standard POSIX and Common Microcontroller Software Interface Standard \(CMSIS\) interfaces. To support cross-platform functions, standard interfaces such as POSIX are recommended for third-party adaptation.

### How do I analyze thread stack overflow?<a name="section8623141711293"></a>

**Symptom**

The system is abnormal, and the message "CURRENT task  _ThreadName_  stack overflow!" is displayed.

**Solution**

1.  When creating the thread, double the thread stack size. If the problem does not recur after multiple attempts, the task stack size is insufficient and needs to be increased.
2.  If the problem persists after the thread stack size is increased, check whether an ultra-large array is defined in the thread or whether recursive invoking exists in the process.
3.  If the preceding causes are excluded, check whether memory corruption occurs.

## File System<a name="section098519592162"></a>

### What should I do when the Hi3516 board fails to open the same file in write mode \(LiteOS-A\)?<a name="section517972255311"></a>

When a file is already open, it is not allowed to open the file in write mode again, because the Hi3516 board uses the FAT file system.

### What hardware platforms are supported by the LiteOS kernel?<a name="section868413518533"></a>

LiteOS-A supports the Hi3516 and Hi3518 development boards. LiteOS-M supports the Hi3861 development board, STM32F103, STM32F429IGTb, and Nucleo\_f767zi. For details, see the  **README.md**  file in the  **kernel/liteos\_m**  directory.

### What chip architectures are supported by the LiteOS kernel?<a name="section1131661465417"></a>

LiteOS-M supports RISC-V, Cortex-M3, Cortex-M4, Cortex-M7, Cortex-M33, and Arm 9, and will support c-sky and Xtensa. LiteOS-A supports ARMv7-A and will support ARMv8-A. Any new update will be released in the OpenHarmony community.

## Third-party Components<a name="section971818231178"></a>

### What third-party components are supported by OpenHarmony?<a name="section74138185411"></a>

Open-source components \(such as mbedTLS and LwIP\) and third-party libraries have been provided and can be directly used. In addition, standard POSIX is provided for adaptation.

### What should I do if the key length verification fails when OpenSSL is used on OpenHarmony?<a name="section10564614135516"></a>

Check whether the architecture type \(such as ARM and x86\) and the number of system bits \(32-bit and 64-bit\) are correctly selected in OpenSSL compilation options.

### Does setsockopt support SO\_RCVBUF and SO\_SNDBUF?<a name="section2093373215556"></a>

No. It does not support SO\_RCVBUF or SO\_SNDBUF.

## Compilation and Linking<a name="section10955302179"></a>

### How do I run an application developed by ARM Linux on LiteOS-A?<a name="section1164175713557"></a>

The application must be recompiled using the cross-compiler provided in OpenHarmony before it can run.

### What system is used for OpenHarmony compilation? What compiler is used?<a name="section132287223567"></a>

LiteOS-A is compiled in the Linux environment by using the LLVM compiler. LiteOS-M can be compiled in the Linux or Windows environment by using compilers such as IAR, Keil, and GCC.

### For a third-party component that is independently compiled into a static library and used on LiteOS-M, what should I do when the component's global variable value is incorrect or the system is suspended after the component's function is called?<a name="section15189154225619"></a>

Check whether address-irrelevant compilation options, such as  **-fPIE**,  **-fpie**,  **-fPIC**, and  **-fpic**, exist in the third-party component compilation options. If yes, delete them and recompile the third-party component into a static library.

### What should I do if the message "use VFP register arguments, xxx.o does not" is displayed when LiteOS-A generates a target executable file?<a name="section193571012578"></a>

Check whether the  **-mfloat-abi=xxx**,  **-mcpu=xxx**, and  **-mfpu=xxx**  compilation options are added during the compilation of  **xxx.o**. If not, add them.

### What should I do when calling clock\_gettime obtains an incorrect time?<a name="section8973152015717"></a>

In  **struct timespec**,  **tv\_sec**  is  **time\_t**, which is of the long long type, and the print control character is  **%lld**. Check whether the print control character in use is correct.

