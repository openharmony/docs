# Kernel


## Basic Kernel


### What are the differences between APIs provided by LiteOS-A and LiteOS-M?

Basic kernel APIs are different. LiteOS-A provides the standard Portable Operating System Interface (POSIX), and LiteOS-M provides standard POSIX and Common Microcontroller Software Interface Standard (CMSIS) interfaces. To support cross-platform functions, standard interfaces such as POSIX are recommended for third-party adaptation.


### How do I analyze thread stack overflow?

**Symptom**

The system is abnormal, and the message "CURRENT task *ThreadName* stack overflow!" is displayed.

**Solution**

1. When creating the thread, double the thread stack size. If the problem does not recur after multiple attempts, the task stack size is insufficient and needs to be increased.

2. If the problem persists after the thread stack size is increased, check whether an ultra-large array is defined in the thread or whether recursive invoking exists in the process.

3. If the preceding causes are excluded, check whether memory corruption occurs.


## File System


### What should I do when the Hi3516 board fails to open the same file in write mode (LiteOS-A)?

When a file is already open, it is not allowed to open the file in write mode again, because the Hi3516 board uses the FAT file system.


### What hardware platforms are supported by the LiteOS kernel?

LiteOS-A supports the Hi3516 and Hi3518 development boards. LiteOS-M supports the Hi3861 development board, STM32F103, STM32F429IGTb, and Nucleo_f767zi. For details, see the **README.md** file in the **kernel/liteos_m** directory.


### What chip architectures are supported by the LiteOS kernel?

LiteOS-M supports RISC-V, Cortex-M3, Cortex-M4, Cortex-M7, Cortex-M33, and Arm 9, and will support c-sky and Xtensa. LiteOS-A supports ARMv7-A and will support ARMv8-A. Any new update will be released in the OpenHarmony community.


## Third-party Components


### Which third-party components are supported?

Open-source components (such as mbedTLS and lwIP) and third-party libraries have been provided and can be directly used. In addition, standard POSIX is provided for adaptation.


### What should I do if the key length verification fails when OpenSSL is used?

Check whether the architecture type (such as ARM and x86) and the number of system bits (32-bit and 64-bit) are correctly selected in OpenSSL compilation options.


### Does setsockopt support SO_RCVBUF and SO_SNDBUF?

No. **setsockopt** does not support **SO_RCVBUF** or **SO_SNDBUF**.


## Compilation and Linking


### How do I run an application developed by ARM Linux on LiteOS-A?

The application must be recompiled using the cross-compiler provided before it can run.


### What operating system is used for compilation? What compiler is used?

LiteOS-A is compiled in the Linux environment by using the LLVM compiler. LiteOS-M can be compiled in the Linux or Windows environment by using compilers such as IAR, Keil, and GCC.


### For a third-party component that is independently compiled into a static library and used on LiteOS-M, what should I do when the component's global variable value is incorrect or the system is suspended after the component's function is called?

Check whether address-irrelevant compilation options, such as **-fPIE**, **-fpie**, **-fPIC**, and **-fpic**, exist in the third-party component compilation options. If yes, delete them and recompile the third-party component into a static library.


### What should I do if the message "use VFP register arguments, xxx.o does not" is displayed when LiteOS-A generates a target executable file?

Check whether the **-mfloat-abi=xxx**, **-mcpu=xxx**, and **-mfpu=xxx** compilation options are added during the compilation of **xxx.o**. If not, add them.


### What should I do when calling clock_gettime obtains an incorrect time?

In **struct timespec**, **tv_sec** is **time_t**, which is of the long long type, and the print control character is **%lld**. Check whether the print control character in use is correct.
