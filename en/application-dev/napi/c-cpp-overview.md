# C/C++ Library Mechanisms

The OpenHarmony NDK provides industry standard libraries [libc](../reference/native-lib/musl.md) and [libc++](../reference/native-lib/cpp.md). This topic describes the mechanisms of these libraries in OpenHarmony. Understanding these mechanisms helps you avoid pitfalls during NDK development.

##  C++ Compatibility

In OpenHarmony, the system library and application native library use the C++ standard library. For details, see [libc++](../reference/native-lib/cpp.md). The C++ standard library on which the system library depends is upgraded with the image version, and the C++ standard library on which the application native library depends is upgraded with the SDK version used for compilation. Since both the C++ standard libraries have multiple major versions, the different update approach may cause ABI compatibility issues. To solve this problem, OpenHarmony distinguishes the C++ standard libraries on which the system library and application native library depend.

- System library: uses **libc++.so**, which is released with the system image.
- Application native library: uses **libc++_shared.so**, which is released with the application.

The two libraries use different C++ namespaces. libc++.so uses __h, and libc++_shared.so uses __n1.

> **NOTE**
>
> The C++ standard libraries of the system and applications cannot be used together. Native APIs can only be C APIs, which are used to isolate the C++ running environment. If the version of libc++_shared.so in the HAR package is different from that of the application, incompatibility may occur. To solve this problem, use the same SDK version to update the HAR package.

**Known C++ Compatibility Issues**

When the application is started or dlopen is executed, the error message " `symbol not found, s=__emutls_get_address`" is displayed in the HiLog. This is because libc++_shared.so of API 9 and earlier versions does not have this symbol, but libc++_shared.so of API 11 and later versions has this symbol. To solve this problem, update the SDK version of the app or HAR package.

##  musl libc Dynamic Linker

### Linker Namespace
Different from the namespace in C++, a linker namespace (also referred to as ns) is a mechanism provided by the dynamic linker to isolate shared libraries within different namespaces. For example, the system native library can load the native library in the system directories, such as **/system/lib64** or **/vendor/lib64**; a common application can load only the common application native library and NDK library, but cannot directly load the system native library.

When the dynamic linker loads the shared library specified in the compilation dependency (DT_NEEDED) or calls `dlopen` to load the specified shared library, the dynamic linker needs to be associated with a specific NS.

OpenHarmony has the following types of linker namespaces:

- Default ns: default namespace created for locating the .so files in **/system/lib{abi}** and **/vendor/lib{abi}** when the dynamic linker stats.

- NDK ns: default namespace created for exposing the NDK interfaces in .so files in **/system/lib{abi}/ndk** when the dynamic linker stats.

- App ns: namespace created when an application is started. It directs to the application installation path (sandbox path), that is, the .so file used to load the application.

The namespace mechanism restricts the invocation between the application native library and the system native library, as shown in the following figure.

 The default ns and NDK ns can access all .so files of each other, but cannot access the .so files of the app ns.
 The app ns can access all .so files of the NDK ns, but cannot access the .so files of the default ns.

![](figures/dl_namespace.png)

### rpath
Run-time path (rpath) is a mechanism for specifying the runtime search path of a shared library. This mechanism allows a runtime search path to be embedded in an executable file or shared library. The dynamic linker uses this path to find required libraries.

The namespace mechanism allows an application to load only the native libraries in its installation directory (for example, **libs/arm64** on the ARM64 platform). If an application needs to load multiple native libraries, the native library in the newly created directory cannot be loaded. In this case, you can use the rpath mechanism to specify the search path during compilation.

For example, **libhello.so** in the application installation directory **lib/arm64** depends on **libworld.so** in the newly created directory **lib/arm64/module**. Set **rpath** in the **CMakeList.txt** file of the application and compile the file, and run **readelf** to view the rpath of **libhello.so**. As shown in the following figure, **$ORIGIN** indicates the path of **libhello.so**. The application can load **libworld.so** in the **module** directory during running.
```
SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
SET(CMAKE_INSTALL_RPATH "\${ORIGIN}/module")
```
![](figures/dl_rpath.png)

### dlclose
You can use **dlclose** to uninstall a dynamic library.

### symbol-version
symbol-version is a symbol retrieval mechanism provided by libc for symbol relocation in dynamic linking. It supports relocation of the symbols of different versions and helps solve the problem of duplicate symbols. For details, see <a href="https://www.gnu.org/software/gnulib/manual/html_node/LD-Version-Scripts.html">LD Version Scripts (GNU Gnulib)</a>.

### Fortified Check of the FD in select()
If the file descriptor (**fd**) passed in **FD_SET** or **FD_CLR** is not within the value range [0, 1024), abort crash will be triggered.

If the **fd** value passed in **FD_ISSET** is not within the value range [0, 1024), **false** will be returned.

### Globalization
Since API version 12, **locale** in **newlocale()** and **setlocale()** can be set to any of the following values: **C**, **C.UTF-8**, **en_US**, **en_US.UTF-8**, **zh_CN**, and **zh_CN.UTF-8**. **strtod_l**, **wcstod_l**, and **localeconv** support the **locale** values **zh_CN** and **zh_CN.UTF-8**. Note that **strtod_l()** and **wcstod_l()** do not support conversion of hexadecimal numbers and floating-point numbers.

### fdsan
File descriptor sanitizer ([fdsan](./fdsan.md)) helps detect the user-after-close and double-close issues of FDs.

##  Signal Usage
To avoid conflicts with system reserved signals, comply with the following rules when using signals:
- Signals 1 to 34 are reserved for internal use.
- Signals 35 to 45: These signals have been occupied by internal modules (such as memory, DFX, runtime, and system services) of the system by API 19. To avoid conflicts with system behavior and unexpected problems, do not use signals within this range.
- The value of SIGRTMIN and __libc_current_sigrtmin is 35, indicating the start number of real-time signals that can be used by the application. (The application can use only signals whose number is 46 or greater.)

The internal signal usage statistics of HarmonyOS are as follows:

| ID| Name     | Remarks            | ID| Name                                       | Remarks                     |
|------|-----------|-----------------|------|--------------------------------------------|---------------------------|
| 1    | SIGHUP    |  Control Terminal Suspension   | 24   | SIGXCPU                                    | The CPU time limit is exceeded.         | 
| 2    | SIGINT    |  Interrupted          | 25   | SIGXFSZ                                    | The file size exceeds the upper limit.           |
| 3    | SIGQUIT   |  Keyboard exit       | 26   | SIGVTALRM                                  | Virtual timer                |
| 4    | SIGILL    |  Invalid instruction       | 27   | SIGPROF                                    | The profiling timer expires.      |
| 5    | SIGTRAP   |  Debugging Breakpoints       | 28   | SIGWINCH                                   | Terminal window size change          |
| 6    | SIGABRT   |  Abort signal       | 29   | SIGIO                                      | I/O availability notification              |
| 7    | SIGBUS    |  Bus error       | 30   | SIGPWR                                     | Power Failure                  |
| 8    | SIGFPE    |  Arithmetic exception       | 31   | SIGSYS                                     | Illegal system call              |
| 9    | SIGKILL   |  Forcible termination       | 32   | SIGTIMER                                   | Timer timing signal            |
| 10   | SIGUSR1   |  User-defined signal 1| 33   | SIGCANCEL                                  | Thread cancellation signal              |
| 11   | SIGSEGV   |  Invalid memory access    | 34   | SIGSYNCCALL                                | Synchronous invocation signal              |
| 12   | SIGUSR2   |  User-defined signal 2| 35   | MUSL_SIGNAL_NATIVE_REMOTE (SIGRTMIN + 0)   | System retention                  |
| 13   | SIGPIPE   |  Pipe damage        | 36   | MUSL_SIGNAL_HOOK (SIGRTMIN + 1)            | System retention                 |
| 14   | SIGALRM   |  Timer signal      | 37   | MUSL_SIGNAL_UNHOOK (SIGRTMIN + 2)          | System retention                 |
| 15   | SIGTERM   |  Program termination request    | 38   | MUSL_SIGNAL_NATIVE_LOCAL (SIGRTMIN + 3)    | System retention                 |
| 16   | SIGSTKFLT |  Coprocessor stack error   | 39  | MUSL_SIGNAL_JSHEAP (SIGRTMIN + 4)          | System retention                 |
| 17   | SIGCHLD   |  Subprocess exit/stop  | 40  | MUSL_SIGNAL_JSHEAP_PRIV (SIGRTMIN + 5)     | System retention                 |
| 18   | SIGCONT   |  Continue        | 41   | MUSL_SIGNAL_SAMPLE_STACK (SIGRTMIN + 6)    | System retention                 |
| 19   | SIGSTOP   |  Forcibly Stop        | 42   | MUSL_SIGNAL_LEAK_STACK (SIGRTMIN + 7)      | System retention                 |
| 20   | SIGTSTP   |  Stop inputting on the terminal.  | 43   | MUSL_SIGNAL_RECYCLE_JEMALLOC (SIGRTMIN + 8) | System retention                 |
| 21   | SIGTTIN   |  Background read terminal      | 44   | MUSL_SIGNAL_MEMCHECK (SIGRTMIN + 9)         | System retention                 |
| 22   | SIGTTOU   |  Background write terminal      | 45   | MUSL_SIGNAL_FDTRACK (SIGRTMIN + 10)         | System retention                 |
| 23   | SIGURG    |  The socket has urgent data. |   -  |                          -                  |                 -        |
